# temp fix for mp2-09... make a dummy Apache->request
require Apache::RequestUtil;
no warnings 'redefine';
my $sub = *Apache::request{CODE};
*Apache::request = sub {
     my $r;
     eval { $r = $sub->('Apache'); };
     # warn $@ if $@;
     return $r;
};
