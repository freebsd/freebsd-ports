package App::Acmeman::Source::Unconfigured;

use strict;
use warnings;
use parent 'App::Acmeman::Source';
use App::Acmeman::Log qw(:all);

sub new {
	my $self;
	eval {
		require App::Acmeman::Source;
		$self = new App::Acmeman::Source;
	};
	if ($@) {
		(my $s = $@) =~ s{ at /.+$}{};
		error("No domain source configured");
		print STDERR <<EOT;
You are seeing this error because you use the default configuration
file template and the default source "apache" cannot be loaded.

Please edit your configuration file (/usr/local/etc/acmeman.conf) and
change the \"source\" line appropriately.

For your information, the error reported by the "apache" module was:

$s
EOT
;
		exit(78);
	}
	error("Using default domain source \"apache\"", prefix => 'note');
	return $self;
}

1;
