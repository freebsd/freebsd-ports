DSPAM CGI

   The CGI will need to function in the same group as the dspam agent.  The
   best way to do this is to create a separate virtualhost specifically for
   the CGI and assign it to run in the MTA group.  If you are using
   procmail, additional configuration may also be necessary (see below).
   Please note that Apache users running under suexec do NOT take on the 
   identity of the groups specified in /etc/group; e.g. you will need to 
   specifically assign the group in httpd.conf.

   NOTE: Because the DSPAM CGI is a script, DSPAM will not retain its 
         privileges when called. If you are running procmail, this will become
         a problem as procmail requires root privileges to deliver. The easiest
         hack around this is to create a procmail.dspam binary and make it
         setuid root, then make it executable only by the mail group (or 
         whatever group DSPAM and the CGI run in).

   The DSPAM CGI has a minimal configuration inside the dspam.cgi file. You'll
   want to check dspam.cgi and make sure all of the settings are correct. In
   most cases, the only that will be necessary to change are the large-scale
   or domain-scale flags.

   Once you've configured the CGI, there are two more things you'll want to do.
   
   1. Edit templates/nav_performance.html
      Change yourdomain to whatever your domain name is.

   2. Make any changes to default.prefs. This will set the default preferences
      for a user. The file should reflect your system wide defaults. An example
      is provided in the cgi directory...

trainingMode=TEFT
spamAction=quarantine
spamSubject=[SPAM]
enableBNR=on
enableWhitelist=on

     By default, the parameters specified on the commandline will be used. If,
     however, a preference is found for the particular user those preferences
     will override the commandline. As a result, you'll want to remove any
     options from the CGI that you don't want users to set (possibly
     training mode).

   If you plan on leaving DSPAM's logging function enabled, and would like to
   produce pretty graphs for your users, the graph.cgi script requires the
   following be installed on your machine:

   - GD Graphics Library (http://www.boutell.com/gd/)
   - The following PERL modules:
     (http://www.perl.com/CPAN/modules/by-module/GD/)

     . GD
     . GD-Graph3d
     . GDGraph
     . GDTextUtil

