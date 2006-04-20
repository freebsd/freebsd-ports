# $Id: Net-Akismet-podcheck.t 135 2006-01-27 17:54:46Z roam $
# Before `make install' is performed this script should be runnable with
# `make test'. After `make install' it should work as `perl Net-Akismet-coverage.t'

use Pod::Checker;
use Test;
plan tests => 6;

my ($c, $res);

$c = new Pod::Checker '-warnings' => 1;
ok($c);
$res = $c->parse_from_file('lib/Net/Akismet.pm', \*STDERR);
if ($res == -1) {
	warn "No POD data found in Net::Akismet\n";
}
ok(!$res);
ok($c->num_errors() == 0 && $c->num_warnings() == 0);

$c = new Pod::Checker '-warnings' => 5;
ok($c);
$res = $c->parse_from_file('lib/Net/Akismet.pm', \*STDERR);
if ($res == -1) {
	warn "No POD data found in Net::Akismet\n";
}
ok(!$res);
ok($c->num_errors() == 0 && $c->num_warnings() == 0);
