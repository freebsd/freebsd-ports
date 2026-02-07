--- lib/facter/custom_facts/util/config.rb.orig	2020-08-31 03:41:56 UTC
+++ lib/facter/custom_facts/util/config.rb
@@ -43,6 +43,7 @@ module LegacyFacter
                                                      [File.join(windows_dir, 'PuppetLabs', 'facter', 'facts.d')]
                                                    else
                                                      [
+                                                       '/usr/local/etc/facter/facts.d/',
                                                        '/etc/puppetlabs/facter/facts.d',
                                                        '/etc/facter/facts.d/',
                                                        '/opt/puppetlabs/facter/facts.d'
