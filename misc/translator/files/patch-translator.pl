
$FreeBSD$

--- translator.pl.orig
+++ translator.pl
@@ -2,20 +2,19 @@
 # nifty front-end to Altavista's Babel Fish.
 # $Id: translator.pl,v 1.13 2003/12/19 11:50:02 jodrell Exp $
 use WWW::Babelfish;
-use IO::Scalar;
 use threads;
 use threads::shared;
+use Thread::Queue;
 use File::Basename qw(basename);
-use Data::Dumper;
 use strict;
 
 #
 # these are shared between the main thread and the worker:
 #
-my @queue	: shared;
+my $input_queue = new Thread::Queue;
+my $output_queue = new Thread::Queue;
+
 my @errors	: shared;
-my $finished	: shared;
-my $output	: shared;
 my $source	: shared;
 my $dest	: shared;
 my $running	: shared;
@@ -30,9 +29,6 @@
 #
 # set up the application:
 #
-$finished = 0;
-$pending  = 0;
-
 my $NAME	= 'Translator';
 my $VERSION	= '0.1.0';
 my $RCFILE	= sprintf('%s/.%src', $ENV{HOME}, lc($NAME));
@@ -80,24 +76,25 @@
 # places output into the $output array, and we need to keep the entry up to date:
 #
 Glib::Timeout->add(50, sub {
-	if ($pending == 1) {
-		$app->get_widget('output')->get_buffer->set_text($output) ;
-		$pending = 0;
+	if (defined(my $output = $output_queue->dequeue_nb)) {
+		$app->get_widget('output')->get_buffer->set_text($output);
 	}
-	if ($running == 1) {
-		$app->get_widget('main_window')->get_root_window->set_cursor($busy);
-		$app->get_widget('translate_button')->set_sensitive(0);
-		$app->get_widget('input')->set_editable(0);
-	} else {
-		$app->get_widget('main_window')->get_root_window->set_cursor($normal);
-		$app->get_widget('translate_button')->set_sensitive(1);
-		$app->get_widget('input')->set_editable(1);
+
+	{
+		lock($running);
+		$app->get_widget('main_window')->get_root_window->set_cursor($running ? $busy: $normal);
+		$app->get_widget('translate_button')->set_sensitive(! $running);
+		$app->get_widget('input')->set_editable(! $running);
 	}
-	if (scalar(@errors) > 0) {
-		my $error_dialog = Gtk2::MessageDialog->new($app->get_widget('main_window'), 'modal', 'error', 'ok', shift(@errors));
-		$error_dialog->set_icon($app->get_widget('main_window')->get_icon);
-		$error_dialog->signal_connect('response', sub { $error_dialog->destroy });
-		$error_dialog->show_all;
+
+	{
+		lock(@errors);
+		if (scalar(@errors) > 0) {
+			my $error_dialog = Gtk2::MessageDialog->new($app->get_widget('main_window'), 'modal', 'error', 'ok', shift(@errors));
+			$error_dialog->set_icon($app->get_widget('main_window')->get_icon);
+			$error_dialog->signal_connect('response', sub { $error_dialog->destroy });
+			$error_dialog->show_all;
+		}
 	}
 	return 1;
 });
@@ -107,46 +104,60 @@
 Gtk2->main;
 
 sub worker {
-	my $fish = WWW::Babelfish->new;
+	my $fish = WWW::Babelfish->new(agent => 'Mozilla/8.0');
 	$fish->{ua}->timeout(10);
-	while ($finished == 0) {
-		if (scalar(@queue) > 0) {
+	while (my $input = $input_queue->dequeue) {
+		my $output = '';
+		{
+			lock($running);
 			$running = 1;
-			$output = '';
-			my $input = shift(@queue);
-			my $fh = IO::Scalar->new(\$output);
+		}
+		open my $fh, ">", \$output or die;
+		{
+			lock($proxy);
 			if ($proxy ne '') {
 				$fish->{proxy} = $proxy;
 				$fish->{ua}->proxy('http', 'http://'.$proxy.'/');
 			}
+		}
+		{
+			lock($source);
+			lock($dest);
 			if (!$fish->translate(
 				source		=> $source,
 				destination	=> $dest,
 				ofh		=> $fh,
 				text		=> $input,
 			)) {
+				lock(@errors);
 				push(@errors, "Error: $!");
 			}
-			$pending = 1;
-		} else {
+		}
+		{
+			lock($running);
 			$running = 0;
-			threads->yield;
 		}
+		$output_queue->enqueue($output);
 	}
-	return 1;
 }
 
 sub close_program {
 	save_options();
-	$finished = 1;
+	$input_queue->enqueue(undef);	# terminate the worker thread
 	Gtk2->main_quit;
 	$worker->join;	
 	exit;
 }
 
 sub translate {
-	$source = $app->get_widget('from_combo')->entry->get_text;
-	$dest   = $app->get_widget('to_combo')->entry->get_text;
+	{
+		lock($source);
+		$source = $app->get_widget('from_combo')->entry->get_text;
+	}
+	{
+		lock($dest);
+		$dest   = $app->get_widget('to_combo')->entry->get_text;
+	}
 	my $input = $app->get_widget('input')->get_buffer->get_text(
 		$app->get_widget('input')->get_buffer->get_start_iter,
 		$app->get_widget('input')->get_buffer->get_end_iter,
@@ -159,9 +170,12 @@
 		} else {
 			$message = 'Please enter some text to translate.';
 		}
-		push(@errors, $message);
+		{
+			lock(@errors);
+			push(@errors, $message);
+		}
 	} else {
-		push(@queue, $input);
+		$input_queue->enqueue($input);
 	}
 	return 1;
 }
@@ -284,6 +298,7 @@
 }
 
 sub source_changed {
+	lock($source);
 	$source = $app->get_widget('from_combo')->entry->get_text;
 	return undef if ($source eq '');
 	$app->get_widget('to_combo')->set_popdown_strings(sort(keys(%{$pairs->{$source}})));
@@ -292,6 +307,7 @@
 
 sub set_proxy {
 	if ($client->get_bool($use_proxy_key) == 1) {
+		lock($proxy);
 		$proxy = sprintf(
 			'%s:%d',
 			$client->get_string($proxy_host),
