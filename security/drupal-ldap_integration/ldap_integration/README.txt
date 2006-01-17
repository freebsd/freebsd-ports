ldap_integration.module for Drupal 4.6
--------------------------------------
status: STABLE


 - BRIEFING

  This module allows users to authenticate against an admin-defined LDAP
directory. Additionally, users can read and modify their LDAP entries, being
the administrator able to limit it.


 - INSTALLATION

  Add the module files to the /modules/ directory of your Drupal
installation. Those are:

        * ldap_integration.module
        * zcallbacks.module
        * ldap_integration/conf.php
        * ldap_integration/LDAPInterface.php

  Activate BOTH *ldap_integration* and *zcallbacks* modules in Drupal's
modules page (/admin/modules).


 - SETUP

  Prior to its use, administrators must set some variables in the preferences
page, located at /admin/settings/ldap_integration.

  -login string format

  Drupal requires authentication from external sources to be in the form
user@server, being 'external sources' any different from Drupal's own
user database: LDAP directories, HTTP authentification, Jabber and, in
general, any other authentification form provided by third-party modules.
  Since this restriction can be annoying in some configurations (for example,
those where all users log in from that same source and everyone of them has
a login string on the form username@longname.foracommonserver.com), this
module provides a way to circumvent it. Just unset the 'Logins must be
on the form user@server' checkbox in the settings page.

  -"pattern" and "replacement"

  Parameters should be quite straightforward to set, except those called
'LDAP login pattern' and 'LDAP login replacement' which refer to the way
Drupal converts Drupal logins into LDAP logins, via regular expressions.
Further explanation follows.

  In Drupal, logins to external authentification sources (not Drupal's
own database) must be in the form jdoe@foo.bar. This means that every login
through this module must have that form.
  On the other hand, logins to LDAP directories are in the form of a DN,
i.e. something similar to: uid=jdoe,dc=foo,dc=bar .

  So, the admin must set the way Drupal logins convert into LDAP logins. This
os defined through the 'LDAP login pattern' and 'LDAP login replacement'
parameters in preferences.

  For help on defining these parameters, refer to the relevant entry on the
PHP manual: http://www.php.net/manual/en/function.preg-replace.php

  -directory-specific attributes

  Besides, how Drupal should understand LDAP attributes is defined by
'ldap_attributes' and 'ldap_drupal_mappings' global variables, found
on the ldap_integration/conf.php file.
  'ldap_attributes' tells Drupal what kind of data is stored in each
attribute, so it can present it with adequate names and forms in users'
pages.
  'ldap_drupal_mappings' defines how Drupal's own user fields should be
mapped to LDAP attributes, provided the 'Should Drupal account fields
be mapped to LDAP attributes?' setting is properly set in the module
configuration page.

  -Drupal roles

  Users can be granted Drupal roles automatically when logging in as
LDAP users. These roles must already exist in Drupal's configuration and
are checked anytime users log in from a LDAP source. However, once they
have been granted, they can only be denied manually from Drupal's admin
interface.
  There are two ways of doing this: based in the users' DN and based in the
values of one of their LDAP attributes.
  In the former case, the setting uses a regular expression much in the
same fashion as described above for mapping login names to DNs. A regular
expression is defined for the DN and each one of its *parenthesized*
sub-expressions is considered a role.
  In the latter case, roles are just read from an attribute wich can be
multivalued.

  -"The Writer" and "The Reader" users
  
  In order to perform some operations, such as providing of new passwords to
those who forgot theirs, or enabling users to modify their LDAP entry, DN and
password, two special users must be set in ldap_integration/conf.php.

  If you don't care much about security, you can set both of them to be the
administrator but, as I'm sure security is your priority #1, you should set
them to accounts specially created for that matter.


 - USE

  The authentication facility needs no further configuration. For the LDAP
user data reading and editing, the administrator can set what can be read and
what can be modified by the user, by editing the relevant preferences. 


 - ISSUES

  -new passwords generation

  New passwords will only be generated if the users requesting it have
logged in at least once before.

  This is due to Drupal creating entries in its 'users' table for storing
info about every user, including those authentified through modules. Drupal
then looks the user up in the database whenever password generation is needed.

  -security related:

  As can be deduced from above, on the section about "The Writer" and "The
Reader", the file ldap_integration/conf.php should not fall in the wrong
hands.

  -conflicts:

  Due to the way I have had to hack this authentication through Drupal,
there might be conflicts with other modules, specially, but I'd not venture
to restrict to, with other auth modules.

  If anyone experiences any conflict, please let me know so I can think
of a possible solution.

  -language

  English is not the author's mother language. Corrections are not
only welcome, but encouraged.
 

 - CREDITS

  Author:
    - Pablo Brasero Moreno <pablobm at gmail (com)> (http://pablobm.com)
  Sponsorship:
    - VIZ Media (http://www.viz.com)
  Based upon the original code by:
    - Moshe Weitzman <weitzman at tejasa (com)>
  Several patches
    - Steve Francis (sfrancis @drupal.org)
    - Douglas A. Galindo
    - Klaus H. ("Perfect Stranger" @drupal.org)
  Initial AD authentication code:
    - allrite (http://allrite.net)
  Invaluable testing by:
    - Jose Luis Jimenez
    - Francisco Javier Sanchez Zurdo
    - And all those who gave me any feedback
