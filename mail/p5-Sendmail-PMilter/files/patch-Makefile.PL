--- Makefile.PL.orig	2024-02-03 16:33:42 UTC
+++ Makefile.PL
@@ -1,42 +1,6 @@ use ExtUtils::MakeMaker;
 use 5.008004;
 use ExtUtils::MakeMaker;
 
-my $install = ( ExtUtils::MakeMaker::prompt(<<EOT . 'Do you wish to install the Sendmail::PMilter package?' => 'yes' ) );
-
-Sendmail::PMilter provides access to the message processing hooks in a
-running Mail Transfer Agent (Sendmail or Postfix), so that filters
-('milters') which process mail can be written entirely in Perl.  Mail
-processing according to SMTP takes place at a number of well-defined
-stages ('connect', 'helo', etc.) during the exchange of the message
-between client and server.  At each stage, the sets of data available
-(the connecting IP, sender address etc.) and the permissible actions
-(rewrite a message header, ACCEPT a message, REJECT it etc.) are also
-well-defined and are to some extent configurable.
-
-Filters built to use Sendmail::PMilter can examine all the information
-made available by the MTA and can take any of the permitted actions at
-any stage of mail processing.  Filters can be implemented much more
-quickly in Perl than in a low-level language like C, and the Perl code
-does not necessarily need to be thread-safe.  All mail is essentially
-text, and Perl is a very powerful tool for text processing.  A milter
-coded in Perl has full access to all Perl library functions, system
-utilities, standard modules, modules installed from CPAN, modules of
-your own; a Perl milter can do with a message more or less anything
-that you might reasonably want to do.
-
-The interface to the running MTA follows the 'milter protocol'.  This
-protocol is driven by the MTA.  It is effected by messages of a simple
-structure which are passed between the MTA and the milter via a socket
-connection.  Over the years the Milter Protocol has progressed through
-several versions, and seems (February 2024) to be extremely stable at
-Milter Protocol Version 6.
-
-Choose "yes" below to install Sendmail::PMilter from this package.
-
-EOT
-
-if( $install ne 'yes' ) { print "Not installing.\n"; exit; }
-
 my %PM = (
         'lib/Sendmail/PMilter.pm'           =>  '$(INST_LIBDIR)/PMilter.pm',
         'lib/Sendmail/PMilter/Context.pm'   =>  '$(INST_LIBDIR)/PMilter/Context.pm'
