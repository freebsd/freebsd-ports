=begin

= quickml server: How to coexist with other MTA

Last Update: 2002-04-28 (Release date: 2002-04-28)


== Configurate quickml server

1. Create user `quickml' and group `quickml' on the UNIX host to 
   quickml server.

2. Configure quickmlrc as below:

  Config = {
    :user => 'quickml',
    :group => 'quickml',
    :port => 10025,
    :bind_address => "127.0.0.1",

== Configure DNS

Set MX record of the domain name that is for quickml service
(ex. foobar.com) to the host running quickml server.

== Configure MTA

=== Case of qmail

1. Add

  foobar.com

to /var/qmail/control/rcpthosts.

2. Add

  foobar.com:localhost:10025

to /var/qmail/control/smtproutes.

=== Case of Postfix

1. Add

  foobar.com smtp:[localhost:10025]

to /etc/postfix/transport.

2. Add

  transport_maps = hash:/etc/transport

to /etc/postfix/main.cf, and execute commands as below.

  # postmap transport
  # postfix reload

== Acknowledgement

This document is courtesy of imformation from
((<Mr. Taku Kudo|URL:http://cl.aist-nara.ac.jp/~taku-ku/>)).

== Translation

The original version of this document is written in Japanese by
((<Mr. Satoru Takabayashi|URL:http://namazu.org/~satoru/>)).
Translation of this document is by
((<Yuichiro AIZAWA|URL:http://www.mdbl.sfc.keio.ac.jp/~yaizawa/>))
and
Takashi OTA.

=end
