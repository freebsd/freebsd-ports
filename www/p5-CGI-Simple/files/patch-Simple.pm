--- Simple.pm.orig	Wed Nov 10 21:54:26 2004
+++ Simple.pm	Wed Nov 10 21:55:06 2004
@@ -1061,11 +1061,11 @@
 
 1;
 
-=head2 NAME
+=head1 NAME
 
 CGI::Simple - A Simple totally OO CGI interface that is CGI.pm compliant
 
-=head2 SYNOPSIS
+=head1 SYNOPSIS
 
     use CGI::Simple;
     $CGI::Simple::POST_MAX = 1024;       # max upload via post default 100kB
@@ -1153,7 +1153,7 @@
 
     dienice( $q->cgi_error ) if $q->cgi_error;
 
-=head2 DESCRIPTION
+=head1 DESCRIPTION
 
 CGI::Simple provides a relatively lightweight drop in replacement for CGI.pm.
 It shares an identical OO interface to CGI.pm for parameter parsing, file
@@ -1169,12 +1169,12 @@
 In practical testing this module loads and runs about twice as fast as CGI.pm
 depending on the precise task.
 
-=head2 CALLING CGI::Simple ROUTINES USING THE OBJECT INTERFACE
+=head1 CALLING CGI::Simple ROUTINES USING THE OBJECT INTERFACE
 
 Here is a very brief rundown on how you use the interface. Full details
 follow.
 
-=head3 First you need to initialize an object
+=head2 First you need to initialize an object
 
 Before you can call a CGI::Simple method you must create a CGI::Simple object.
 You do that by using the module and then calling the new() constructor:
@@ -1184,7 +1184,7 @@
 
 It is traditional to call your object $q for query or perhaps $cgi.
 
-=head3 Next you call methods on that object
+=head2 Next you call methods on that object
 
 Once you have your object you can call methods on it using the -> arrow
 syntax For example to get the names of all the parameters passed to your
@@ -1236,7 +1236,7 @@
    $q->param(-name=>'veggie',-value=>'tomato');
    $q->param(-name=>'veggie',-value=>['tomato','tomahto','potato','potahto']);
 
-=head2 CALLING CGI::Simple ROUTINES USING THE FUNCTION INTERFACE
+=head1 CALLING CGI::Simple ROUTINES USING THE FUNCTION INTERFACE
 
 For convenience a functional interface is provided by the
 CGI::Simple::Standard module. This hides the OO details from you and allows
@@ -1258,7 +1258,7 @@
 When (if) you read the following docs and are using the functional interface
 just pretend the $q-> is not there.
 
-=head3 Selecting which methods to load
+=head2 Selecting which methods to load
 
 When you use the functional interface Perl needs to be able to find the
 functions you call. The simplest way of doing this is to use autoloading as
@@ -1277,7 +1277,7 @@
 notation. This will import the ':func_set' function set and the specific
 function 'some_func'.
 
-=head3 To Autoload or not to Autoload, that is the question.
+=head2 To Autoload or not to Autoload, that is the question.
 
 If you do not have a AUTOLOAD sub in you script it is generally best to use
 the '-autoload' option. Under autoload you can use any method you want but
@@ -1295,7 +1295,7 @@
 
     use CGI::Simple::Standard qw(param header);
 
-=head3 Setting globals using the functional interface
+=head2 Setting globals using the functional interface
 
 Where you see global variables being set using the syntax:
 
@@ -1307,9 +1307,9 @@
 
 ################ The Core Methods ################
 
-=head2 THE CORE METHODS
+=head1 THE CORE METHODS
 
-=head3 new() Creating a new query object
+=head2 new() Creating a new query object
 
 The first step in using CGI::Simple is to create a new query object using
 the B<new()> constructor:
@@ -1370,14 +1370,14 @@
 
     $empty_query = new CGI::Simple({});
 
-=head3 keywords() Fetching a list of keywords from a query
+=head2 keywords() Fetching a list of keywords from a query
 
     @keywords = $q->keywords;
 
 If the script was invoked as the result of an <ISINDEX> search, the
 parsed keywords can be obtained as an array using the B<keywords()> method.
 
-=head3 param() Fetching the names of all parameters passed to your script
+=head2 param() Fetching the names of all parameters passed to your script
 
     @names = $q->param;
 
@@ -1394,7 +1394,7 @@
 parameters are defined in the form (however, this isn't part
 of the spec, and so isn't guaranteed).
 
-=head3 param() Fetching the value or values of a simple named parameter
+=head2 param() Fetching the value or values of a simple named parameter
 
     @values = $q->param('foo');
 
@@ -1417,7 +1417,7 @@
 query object. If you try to access them via param you will get an undef
 return value.
 
-=head3 param() Setting the values of a named parameter
+=head2 param() Setting the values of a named parameter
 
     $q->param('foo','an','array','of','values');
 
@@ -1433,7 +1433,7 @@
 
     $q->param(-name=>'foo',-value=>'the value');
 
-=head3 add_param() Setting the values of a named parameter
+=head2 add_param() Setting the values of a named parameter
 
 You nay also use the new method B<add_param> to add parameters. This is an
 alias to the _add_param() internal method that actually does all the work.
@@ -1448,7 +1448,7 @@
 argument is absent of false the values will be appended. If true the values
 will overwrite any existing ones
 
-=head3 append() Appending values to a named parameter
+=head2 append() Appending values to a named parameter
 
    $q->append(-name=>'foo',-values=>['yet','more','values']);
 
@@ -1457,12 +1457,12 @@
 Otherwise the parameter is created.  Note that this method only
 recognizes the named argument calling syntax.
 
-=head3 import_names() Importing all parameters into a namespace.
+=head2 import_names() Importing all parameters into a namespace.
 
 This method was silly, non OO and has been deleted. You can get all the params
 as a hash using B<Vars> or via all the other accessors.
 
-=head3 delete() Deleting a parameter completely
+=head2 delete() Deleting a parameter completely
 
     $q->delete('foo');
 
@@ -1473,7 +1473,7 @@
 If you are using the function call interface, use B<Delete()> instead to
 avoid conflicts with Perl's built-in delete operator.
 
-=head3 delete_all() Deleting all parameters
+=head2 delete_all() Deleting all parameters
 
     $q->delete_all();
 
@@ -1485,12 +1485,12 @@
 B<delete_all> however there is no reason to use this, even in the
 function call interface.
 
-=head3 param_fetch() Direct access to the parameter list
+=head2 param_fetch() Direct access to the parameter list
 
 This method is provided for CGI.pm compatibility only. It returns an
 array ref to the values associated with a named param. It is deprecated.
 
-=head3 Vars() Fetching the entire parameter list as a hash
+=head2 Vars() Fetching the entire parameter list as a hash
 
     $params = $q->Vars;  # as a tied hash ref
     print $params->{'address'};
@@ -1525,7 +1525,7 @@
 You can change the character used to do the multiple value packing by passing
 it to B<Vars()> as an argument as shown.
 
-=head3 url_param() Access the QUERY_STRING regardless of 'GET' or 'POST'
+=head2 url_param() Access the QUERY_STRING regardless of 'GET' or 'POST'
 
 The B<url_param()> method makes the QUERY_STRING data available regardless
 of whether the REQUEST_METHOD was 'GET' or 'POST'. You can do anything
@@ -1536,7 +1536,7 @@
 is parsed into a new CGI::Simple object which is stored within the current
 object. B<url_param> then just calls B<param()> on this new object.
 
-=head3 parse_query_string() Add QUERY_STRING data to 'POST' requests
+=head2 parse_query_string() Add QUERY_STRING data to 'POST' requests
 
 When the REQUEST_METHOD is 'POST' the default behavior is to ignore
 name/value pairs or keywords in the $ENV{'QUERY_STRING'}. You can override
@@ -1551,7 +1551,7 @@
 
 This is a new method in CGI::Simple that is not available in CGI.pm
 
-=head3 save() Saving the state of an object to file
+=head2 save() Saving the state of an object to file
 
     $q->save(\*FILEHANDLE)
 
@@ -1588,7 +1588,7 @@
 
 ################ Uploading Files ###################
 
-=head2 FILE UPLOADS
+=head1 FILE UPLOADS
 
 File uploads are easy with CGI::Simple. You use the B<upload()> method.
 Assuming you have the following in your HTML:
@@ -1609,7 +1609,7 @@
 and saved in temporary files. These files will be deleted when your script.cgi
 exits so if you want to keep them you will need to proceed as follows.
 
-=head3 upload() The key file upload method
+=head2 upload() The key file upload method
 
 The B<upload()> method is quite versatile. If you call B<upload()> without
 any arguments it will return a list of uploaded files in list context and
@@ -1663,7 +1663,7 @@
 'upload_field_name' then you will only get the last uploaded file from
 these fields.
 
-=head3 upload_info() Get the details about uploaded files
+=head2 upload_info() Get the details about uploaded files
 
 The B<upload_info()> method is a new method. Called without arguments it
 returns the number of uploaded files in scalar context and the names of
@@ -1685,7 +1685,7 @@
 
 Note: The old CGI.pm B<uploadInfo()> method has been deleted.
 
-=head3 $POST_MAX and $DISABLE_UPLOADS
+=head2 $POST_MAX and $DISABLE_UPLOADS
 
 CGI.pm has a default setting that allows infinite size file uploads by
 default. In contrast file uploads are disabled by default in CGI::Simple
@@ -1731,7 +1731,7 @@
 
     use CGI::Simple qw( -default ..... );
 
-=head3 binmode() and Win32
+=head2 binmode() and Win32
 
 If you are using CGI::Simple be sure to call B<binmode()> on any handle that
 you create to write the uploaded file to disk. Calling B<binmode()> will do
@@ -1742,9 +1742,9 @@
 
 ################ Miscellaneous Methods ################
 
-=head2 MISCELANEOUS METHODS
+=head1 MISCELANEOUS METHODS
 
-=head3 escapeHTML() Escaping HTML special characters
+=head2 escapeHTML() Escaping HTML special characters
 
 In HTML the < > " and & chars have special meaning and need to be
 escaped to &lt; &gt; &quot; and &amp; respectively.
@@ -1755,36 +1755,36 @@
 
 If the optional second argument is supplied then newlines will be escaped to.
 
-=head3 unescapeHTML() Unescape HTML special characters
+=head2 unescapeHTML() Unescape HTML special characters
 
 This performs the reverse of B<escapeHTML()>.
 
     $unescaped = $q->unescapeHTML( $HTML_escaped_string );
 
-=head3 url_decode() Decode a URL encoded string
+=head2 url_decode() Decode a URL encoded string
 
 This method will correctly decode a url encoded string.
 
     $decoded = $q->url_decode( $encoded );
 
-=head3 url_encode() URL encode a string
+=head2 url_encode() URL encode a string
 
 This method will correctly URL encode a string.
 
     $encoded = $q->url_encode( $string );
 
-=head3 parse_keywordlist() Parse a supplied keyword list
+=head2 parse_keywordlist() Parse a supplied keyword list
 
     @keywords = $q->parse_keywordlist( $keyword_list );
 
 This method returns a list of keywords, correctly URL escaped and split out
 of the supplied string
 
-=head3 put() Send output to browser
+=head2 put() Send output to browser
 
 CGI.pm alias for print. $q->put('Hello World!') will print the usual
 
-=head3 print() Send output to browser
+=head2 print() Send output to browser
 
 CGI.pm alias for print. $q->print('Hello World!') will print the usual
 
@@ -1792,7 +1792,7 @@
 
 ################# Cookie Methods ################
 
-=head2 HTTP COOKIES
+=head1 HTTP COOKIES
 
 Netscape browsers versions 1.1 and higher, and all versions of
 Internet Explorer, support a so-called "cookie" designed to help
@@ -1848,7 +1848,7 @@
 
 =back
 
-=head3 cookie() A simple access method to cookies
+=head2 cookie() A simple access method to cookies
 
 The interface to HTTP cookies is the B<cookie()> method:
 
@@ -1942,7 +1942,7 @@
     # vice-versa
     $q->param( -name=>'answers', -value=>[$q->cookie('answers')] );
 
-=head3 raw_cookie()
+=head2 raw_cookie()
 
 Returns the HTTP_COOKIE variable, an HTTP extension implemented by
 Netscape browsers version 1.1 and higher, and all versions of Internet
@@ -1961,7 +1961,7 @@
 
 ################# Header Methods ################
 
-=head2 CREATING HTTP HEADERS
+=head1 CREATING HTTP HEADERS
 
 Normally the first thing you will do in any CGI script is print out an
 HTTP header.  This tells the browser what type of document to expect,
@@ -1970,7 +1970,7 @@
 manipulated for special purposes, such as server push and pay per view
 pages.
 
-=head3 header() Create simple or complex HTTP headers
+=head2 header() Create simple or complex HTTP headers
 
     print $q->header;
 
@@ -2094,7 +2094,7 @@
 suggested name for the saved file.  In order for this to work, you may
 have to set the B<-type> to 'application/octet-stream'.
 
-=head3 no_cache() Preventing browser caching of scripts
+=head2 no_cache() Preventing browser caching of scripts
 
 Most browsers will not cache the output from CGI scripts. Every time
 the browser reloads the page, the script is invoked anew. However some
@@ -2119,14 +2119,14 @@
 Both the Pragma: no-cache header field and an Expires header that corresponds
 to the current time (ie now) will be sent.
 
-=head3 cache() Preventing browser caching of scripts
+=head2 cache() Preventing browser caching of scripts
 
 The somewhat ill named B<cache()> method is a legacy from CGI.pm. It operates
 the same as the new B<no_cache()> method. The difference is/was that when set
 it results only in the Pragma: no-cache line being printed.
 Expires time data is not sent.
 
-=head3 redirect() Generating a redirection header
+=head2 redirect() Generating a redirection header
 
     print $q->redirect('http://somewhere.else/in/movie/land');
 
@@ -2157,7 +2157,7 @@
 
 =cut
 
-=head2 PRAGMAS
+=head1 PRAGMAS
 
 There are a number of pragmas that you can specify in your use CGI::Simple
 statement. Pragmas, which are always preceded by a hyphen, change the way
@@ -2262,7 +2262,7 @@
 
 ############### NPH Scripts ################
 
-=head2 USING NPH SCRIPTS
+=head1 USING NPH SCRIPTS
 
 NPH, or "no-parsed-header", scripts bypass the server completely by
 sending the complete HTTP header directly to the browser.  This has
@@ -2319,7 +2319,7 @@
 
 ################# Server Push Methods #################
 
-=head2 SERVER PUSH
+=head1 SERVER PUSH
 
 CGI.pm provides four simple functions for producing multipart
 documents of the type needed to implement server push.  These
@@ -2358,7 +2358,7 @@
 multipart section with B<multipart_final()> rather than with
 B<multipart_end()>.
 
-=head3 multipart_init() Initialize the multipart system
+=head2 multipart_init() Initialize the multipart system
 
     multipart_init(-boundary=>$boundary);
 
@@ -2366,14 +2366,14 @@
 what MIME boundary string to use to separate parts of the document.
 If not provided, CGI.pm chooses a reasonable boundary for you.
 
-=head3 multipart_start() Start a new part of the multipart document
+=head2 multipart_start() Start a new part of the multipart document
 
     multipart_start(-type=>$type)
 
 Start a new part of the multipart document using the specified MIME
 type.  If not specified, text/html is assumed.
 
-=head3 multipart_end() End a multipart part
+=head2 multipart_end() End a multipart part
 
     multipart_end()
 
@@ -2382,14 +2382,14 @@
 document when B<multipart_final()> should be called instead of
 B<multipart_end()>.
 
-=head3 multipart_final()
+=head2 multipart_final()
 
     multipart_final()
 
 End all parts.  You should call B<multipart_final()> rather than
 B<multipart_end()> at the end of the last part of the multipart document.
 
-=head3 CGI::Push
+=head2 CGI::Push
 
 Users interested in server push applications should also have a look
 at the B<CGI::Push> module.
@@ -2398,7 +2398,7 @@
 
 ################# Debugging Methods ################
 
-=head2 DEBUGGING
+=head1 DEBUGGING
 
 If you are running the script from the command line or in the perl
 debugger, you can pass the script a list of keywords or
@@ -2448,7 +2448,7 @@
 
     your_script.pl "name1='I am a long value'" "name2=two\ words"
 
-=head3 Dump() Dumping the current object details
+=head2 Dump() Dumping the current object details
 
 The B<Dump()> method produces a string consisting of all the
 query's object attributes formatted nicely as a nested list.  This dump
@@ -2501,7 +2501,7 @@
 
     print $q->Dump(\%ENV);
 
-=head3 PrintEnv() Dumping the environment
+=head2 PrintEnv() Dumping the environment
 
 You can get a similar browser friendly dump of the current %ENV hash using:
 
@@ -2544,7 +2544,7 @@
         };
 
 
-=head3 cgi_error() Retrieving CGI::Simple error messages
+=head2 cgi_error() Retrieving CGI::Simple error messages
 
 Errors can occur while processing user input, particularly when
 processing uploaded files.  When these errors occur, CGI::Simple will stop
@@ -2565,28 +2565,28 @@
 
 ############### Accessor Methods ################
 
-=head2 ACCESSOR METHODS
+=head1 ACCESSOR METHODS
 
-=head3 version() Get the CGI::Simple version info
+=head2 version() Get the CGI::Simple version info
 
     $version = $q->version();
 
 The B<version()> method returns the value of $VERSION
 
-=head3 nph() Enable/disable NPH (Non Parsed Header) mode
+=head2 nph() Enable/disable NPH (Non Parsed Header) mode
 
     $q->nph(1);  # enable NPH mode
     $q->nph(0);  # disable NPH mode
 
 The B<nph()> method enables and disables NPH headers. See the NPH section.
 
-=head3 all_parameters() Get the names/values of all parameters
+=head2 all_parameters() Get the names/values of all parameters
 
     @all_parameters = $q->all_parameters();
 
 The B<all_parameters()> method is an alias for B<param()>
 
-=head3 charset() Get/set the current character set.
+=head2 charset() Get/set the current character set.
 
     $charset = $q->charset(); # get current charset
     $q->charset('utf-42');    # set the charset
@@ -2594,13 +2594,13 @@
 The B<charset()> method gets the current charset value if no argument is
 supplied or sets it if an argument is supplied.
 
-=head3 crlf() Get the system specific line ending sequence
+=head2 crlf() Get the system specific line ending sequence
 
     $crlf = $q->crlf();
 
 The B<crlf()> method returns the system specific line ending sequence.
 
-=head3 globals() Get/set the value of the remaining global variables
+=head2 globals() Get/set the value of the remaining global variables
 
     $globals = $q->globals('FATAL');     # get the current value of $FATAL
     $globals = $q->globals('FATAL', 1 ); # set croak mode on cgi_error()
@@ -2610,20 +2610,20 @@
 makes no difference as they must be set prior to calling the new constructor
 but there might be reason the change the value of others.
 
-=head3 auth_type() Get the current authorization/verification method
+=head2 auth_type() Get the current authorization/verification method
 
     $auth_type = $q->auth_type();
 
 The B<auth_type()> method returns the value of $ENV{'AUTH_TYPE'} which should
 contain the authorization/verification method in use for this script, if any.
 
-=head3 content_length() Get the content length submitted in a POST
+=head2 content_length() Get the content length submitted in a POST
 
     $content_length = $q->content_length();
 
 The B<content_length()> method returns the value of $ENV{'AUTH_TYPE'}
 
-=head3 content_type() Get the content_type of data submitted in a POST
+=head2 content_type() Get the content_type of data submitted in a POST
 
     $content_type = $q->content_type();
 
@@ -2631,26 +2631,26 @@
 a POST, generally 'multipart/form-data' or
 'application/x-www-form-urlencoded' as supplied in $ENV{'CONTENT_TYPE'}
 
-=head3 document_root() Get the document root
+=head2 document_root() Get the document root
 
     $document_root = $q->document_root();
 
 The B<document_root()> method returns the value of $ENV{'DOCUMENT_ROOT'}
 
-=head3 gateway_interface() Get the gateway interface
+=head2 gateway_interface() Get the gateway interface
 
     $gateway_interface = $q->gateway_interface();
 
 The B<gateway_interface()> method returns the value of
 $ENV{'GATEWAY_INTERFACE'}
 
-=head3 path_translated() Get the value of path translated
+=head2 path_translated() Get the value of path translated
 
     $path_translated = $q->path_translated();
 
 The B<path_translated()> method returns the value of $ENV{'PATH_TRANSLATED'}
 
-=head3 referer() Spy on your users
+=head2 referer() Spy on your users
 
     $referer = $q->referer();
 
@@ -2658,14 +2658,14 @@
 the URL of the page the browser was viewing prior to fetching your script.
 Not available for all browsers.
 
-=head3 remote_addr() Get the remote address
+=head2 remote_addr() Get the remote address
 
     $remote_addr = $q->remote_addr();
 
 The B<remote_addr()> method returns the value of $ENV{'REMOTE_ADDR'} or
 127.0.0.1 (localhost) if this is not defined.
 
-=head3 remote_host() Get a value for remote host
+=head2 remote_host() Get a value for remote host
 
     $remote_host = $q->remote_host();
 
@@ -2673,13 +2673,13 @@
 defined. If this is not defined it returns $ENV{'REMOTE_ADDR'} If this is not
 defined it returns 'localhost'
 
-=head3 remote_ident() Get the remote identity
+=head2 remote_ident() Get the remote identity
 
     $remote_ident = $q->remote_ident();
 
 The B<remote_ident()> method returns the value of $ENV{'REMOTE_IDENT'}
 
-=head3 remote_user() Get the remote user
+=head2 remote_user() Get the remote user
 
     $remote_user = $q->remote_user();
 
@@ -2687,7 +2687,7 @@
 for user verification, if this script is protected. The value comes from
 $ENV{'REMOTE_USER'}
 
-=head3 request_method() Get the request method
+=head2 request_method() Get the request method
 
     $request_method = $q->request_method();
 
@@ -2695,7 +2695,7 @@
 script, usually one of 'POST', 'GET' or 'HEAD' as supplied by
 $ENV{'REQUEST_METHOD'}
 
-=head3 script_name() Get the script name
+=head2 script_name() Get the script name
 
     $script_name = $q->script_name();
 
@@ -2703,28 +2703,28 @@
 defined. Otherwise it returns Perl's script name from $0. Failing this it
 returns a null string ''
 
-=head3 server_name() Get the server name
+=head2 server_name() Get the server name
 
     $server_name = $q->server_name();
 
 The B<server_name()> method returns the value of $ENV{'SERVER_NAME'} if defined
 or 'localhost' otherwise
 
-=head3 server_port() Get the port the server is listening on
+=head2 server_port() Get the port the server is listening on
 
     $server_port = $q->server_port();
 
 The B<server_port()> method returns the value $ENV{'SERVER_PORT'} if defined or
 80 if not.
 
-=head3 server_protocol() Get the current server protocol
+=head2 server_protocol() Get the current server protocol
 
     $server_protocol = $q->server_protocol();
 
 The B<server_protocol()> method returns the value of $ENV{'SERVER_PROTOCOL'} if
 defined or 'HTTP/1.0' otherwise
 
-=head3 server_software() Get the server software
+=head2 server_software() Get the server software
 
     $server_software = $q->server_software();
 
@@ -2733,7 +2733,7 @@
 Linux, FTPs to www.apache.org, installs Apache, and then restores your system
 from tape. Well maybe not, but it's a nice thought.
 
-=head3 user_name() Get a value for the user name.
+=head2 user_name() Get a value for the user name.
 
     $user_name = $q->user_name();
 
@@ -2744,7 +2744,7 @@
 Technically the B<user_name()> method returns the value of $ENV{'HTTP_FROM'}
 or failing that $ENV{'REMOTE_IDENT'} or as a last choice $ENV{'REMOTE_USER'}
 
-=head3 user_agent() Get the users browser type
+=head2 user_agent() Get the users browser type
 
     $ua = $q->user_agent();          # return the user agent
     $ok = $q->user_agent('mozilla'); # return true if user agent 'mozilla'
@@ -2753,14 +2753,14 @@
 called without an argument or true or false if the $ENV{'HTTP_USER_AGENT'}
 matches the passed argument. The matching is case insensitive and partial.
 
-=head3 virtual_host() Get the virtual host
+=head2 virtual_host() Get the virtual host
 
     $virtual_host = $q->virtual_host();
 
 The B<virtual_host()> method returns the value of  $ENV{'HTTP_HOST'} if defined
 or $ENV{'SERVER_NAME'} as a default. Port numbers are removed.
 
-=head3 path_info() Get any extra path info set to the script
+=head2 path_info() Get any extra path info set to the script
 
     $path_info = $q->path_info();
 
@@ -2777,7 +2777,7 @@
 but incorrect.  The best thing to do is to avoid using additional
 path information in CGI scripts destined for use with IIS.
 
-=head3 Accept() Get the browser MIME types
+=head2 Accept() Get the browser MIME types
 
     $Accept = $q->Accept();
 
@@ -2788,13 +2788,13 @@
 (don't want) to 1.0.  Glob types (e.g. text/*) in the browser's accept
 list are handled correctly.
 
-=head3 accept() Alias for Accept()
+=head2 accept() Alias for Accept()
 
     $accept = $q->accept();
 
 The B<accept()> Method is an alias for Accept()
 
-=head3 http() Get a range of HTTP related information
+=head2 http() Get a range of HTTP related information
 
     $http = $q->http();
 
@@ -2811,7 +2811,7 @@
    $requested_language = $q->http('Accept_language');
    $requested_language = $q->http('HTTP_ACCEPT_LANGUAGE');
 
-=head3 https() Get a range of HTTPS related information
+=head2 https() Get a range of HTTPS related information
 
     $https = $q->https();
 
@@ -2819,14 +2819,14 @@
 without an argument it returns the value of $ENV{'HTTPS'} which will be
 true if a HTTPS connection is in use and false otherwise.
 
-=head3 protocol() Get the current protocol
+=head2 protocol() Get the current protocol
 
     $protocol = $q->protocol();
 
 The B<protocol()> method returns 'https' if a HTTPS connection is in use or the
 B<server_protocol()> minus version numbers ('http') otherwise.
 
-=head3 url() Return the script's URL in several formats
+=head2 url() Return the script's URL in several formats
 
     $full_url      = $q->url();
     $full_url      = $q->url(-full=>1);
@@ -2882,7 +2882,7 @@
 
 =back
 
-=head3 self_url() Get the scripts complete URL
+=head2 self_url() Get the scripts complete URL
 
     $self_url = $q->self_url();
 
@@ -2890,7 +2890,7 @@
 
    $self->url( '-path_info'=>1, '-query'=>1, '-full'=>1 );
 
-=head3 state() Alias for self_url()
+=head2 state() Alias for self_url()
 
     $state = $q->state();
 
@@ -2900,7 +2900,7 @@
 
 ################# cgi-lib.pl Compatibility Methods #################
 
-=head2 COMPATIBILITY WITH cgi-lib.pl 2.18
+=head1 COMPATIBILITY WITH cgi-lib.pl 2.18
 
 To make it easier to port existing programs that use cgi-lib.pl all
 the subs within cgi-lib.pl are available in CGI::Simple.  Using the
@@ -2965,7 +2965,7 @@
 
 ############### Compatibility with mod_perl ################
 
-=head2 COMPATIBILITY WITH mod_perl
+=head1 COMPATIBILITY WITH mod_perl
 
 This module uses Selfloader and the __DATA__ token to ensure that only code
 that is used gets complied. This optimises performance but means that it
@@ -2986,7 +2986,7 @@
 
 ############### Compatibility with CGI.pm ################
 
-=head2 COMPATIBILITY WITH CGI.pm
+=head1 COMPATIBILITY WITH CGI.pm
 
 I has long been suggested that the CGI and HTML parts of CGI.pm should be
 split into separate modules (even the author suggests this!), CGI::Simple
@@ -3020,7 +3020,7 @@
     3165: Problem:'fillBuffer' $self->fillBuffer($FILLUNIT);
     ....
 
-=head2 DIFFERENCES FROM CGI.pm
+=head1 DIFFERENCES FROM CGI.pm
 
 CGI::Simple is strict and warnings compliant. SelfLoader is used to load only
 the required code. You can easily optimize code loading simply by moving the
@@ -3053,7 +3053,7 @@
 some minor changes and tweaks have been made. They will likely be
 insignificant to most users but here are the gory details.
 
-=head3 Globals Variables
+=head2 Globals Variables
 
 The list of global variables has been pruned by 75%. Here is the complete
 list of the global variables used:
@@ -3169,7 +3169,7 @@
 tempfile requirements. The rest of the globals are HTML related, export
 related, hand rolled autoload related or serve obscure purposes in CGI.pm
 
-=head3 Changes to pragmas
+=head2 Changes to pragmas
 
 There are some new pragmas available. See the pragmas section for details.
 The following CGI.pm pragmas are not available:
@@ -3188,13 +3188,13 @@
 and remove the __DATA__ token. Tempfiles are now private by default and the
 other pragmas are HTML related.
 
-=head3 Filehandles
+=head2 Filehandles
 
 Unlike CGI.pm which tries to accept all filehandle like objects only \*FH
 and $fh are accepted by CGI::Simple as file accessors for B<new()> and B<save()>.
 IO::File objects work fine.
 
-=head3 Hash interface
+=head2 Hash interface
 
     %hash = $q->Vars();     # pack values with "\0";
     %hash = $q->Vars(",");  # comma separate values
@@ -3204,17 +3204,17 @@
 supplied the default "\0" (null byte) will be used. Null bytes are dangerous
 things for C based code (ie Perl).
 
-=head3 cgi-lib.pl
+=head2 cgi-lib.pl
 
 All the cgi-lib.pl 2.18 routines are supported. Unlike CGI.pm all the
 subroutines from cgi-lib.pl are included. They have been GOLFED down to
 25 lines but they all work pretty much the same as the originals.
 
-=head2 CGI::Simple COMPLETE METHOD LIST
+=head1 CGI::Simple COMPLETE METHOD LIST
 
 Here is a complete list of all the CGI::Simple methods.
 
-=head3 Guts (hands off, except of course for new)
+=head2 Guts (hands off, except of course for new)
 
     _initialize_globals
     _use_cgi_pm_global_settings
@@ -3232,7 +3232,7 @@
     _save_tmpfile
     _read_data
 
-=head3 Core Methods
+=head2 Core Methods
 
     param
     add_param
@@ -3251,13 +3251,13 @@
     parse_query_string
     parse_keywordlist
 
-=head3 Save and Restore from File Methods
+=head2 Save and Restore from File Methods
 
     _init_from_file
     save
     save_parameters
 
-=head3 Miscellaneous Methods
+=head2 Miscellaneous Methods
 
     url_decode
     url_encode
@@ -3266,33 +3266,33 @@
     put
     print
 
-=head3 Cookie Methods
+=head2 Cookie Methods
 
     cookie
     raw_cookie
 
-=head3 Header Methods
+=head2 Header Methods
 
     header
     cache
     no_cache
     redirect
 
-=head3 Server Push Methods
+=head2 Server Push Methods
 
     multipart_init
     multipart_start
     multipart_end
     multipart_final
 
-=head3 Debugging Methods
+=head2 Debugging Methods
 
     read_from_cmdline
     Dump
     as_string
     cgi_error
 
-=head3 cgi-lib.pl Compatibility Routines - all 2.18 functions available
+=head2 cgi-lib.pl Compatibility Routines - all 2.18 functions available
 
     _shift_if_ref
     ReadParse
@@ -3310,7 +3310,7 @@
     CgiDie
     CgiError
 
-=head3 Accessor Methods
+=head2 Accessor Methods
 
     version
     nph
@@ -3348,7 +3348,7 @@
     self_url
     state
 
-=head2 NEW METHODS IN CGI::Simple
+=head1 NEW METHODS IN CGI::Simple
 
 There are a few new methods in CGI::Simple as listed below. The highlights are
 the B<parse_query_string()> method to add the QUERY_STRING data to your object if
@@ -3360,7 +3360,7 @@
 argument as shown in the synopsis. If this is supplied the uploaded file will
 be written to there automagically.
 
-=head3 Internal Routines
+=head2 Internal Routines
 
     _initialize_globals()
     _use_cgi_pm_global_settings()
@@ -3375,7 +3375,7 @@
     _save_tmpfile()
     _read_data()
 
-=head3 New Public Methods
+=head2 New Public Methods
 
     add_param()             # adds a param/value(s) pair +/- overwrite
     upload_info()           # uploaded files MIME type and size
@@ -3385,7 +3385,7 @@
     no_cache()              # add both the Pragma: no-cache
                             # and Expires/Date => 'now' to header
 
-=head3  cgi-lib.pl methods added for completeness
+=head2  cgi-lib.pl methods added for completeness
 
     _shift_if_ref()         # internal hack reminiscent of self_or_default :-)
     MyBaseUrl()
@@ -3396,7 +3396,7 @@
     CgiDie()
     CgiError()
 
-=head3 New Accessors
+=head2 New Accessors
 
     crlf()                  # returns CRLF sequence
     globals()               # global vars now stored in $q object - get/set
@@ -3404,13 +3404,13 @@
     document_root()         # returns $ENV{'DOCUMENT_ROOT'}
     gateway_interface()     # returns $ENV{'GATEWAY_INTERFACE'}
 
-=head2 METHODS IN CGI.pm NOT IN CGI::Simple
+=head1 METHODS IN CGI.pm NOT IN CGI::Simple
 
 Here is a complete list of what is not included in CGI::Simple. Basically all
 the HTML related stuff plus large redundant chunks of the guts. The check.pl
 script in the /misc dir will check to see if a script is using any of these.
 
-=head3 Guts - rearranged, recoded, renamed and hacked out of existence
+=head2 Guts - rearranged, recoded, renamed and hacked out of existence
 
     initialize_globals()
     compile()
@@ -3431,7 +3431,7 @@
     read_from_client()
     import_names()     # I dislike this and left it out, so shoot me.
 
-=head3 HTML Related
+=head2 HTML Related
 
     autoEscape()
     URL_ENCODED()
@@ -3469,7 +3469,7 @@
     nosticky()
     default_dtd()
 
-=head3 Upload Related
+=head2 Upload Related
 
 CGI::Simple uses anonymous tempfiles supplied by IO::File to spool uploaded
 files to.
@@ -3479,7 +3479,7 @@
     uploadInfo()        # relied on FH access, replaced with upload_info()
 
 
-=head3 Really Private Subs (marked as so)
+=head2 Really Private Subs (marked as so)
 
     previous_or_default()
     register_parameter()
@@ -3489,7 +3489,7 @@
     asString()
     compare()
 
-=head3 Internal Multipart Parsing Routines
+=head2 Internal Multipart Parsing Routines
 
     read_multipart()
     readHeader()
@@ -3498,16 +3498,16 @@
     fillBuffer()
     eof()
 
-=head2 EXPORT
+=head1 EXPORT
 
 Nothing.
 
-=head2 BUGS
+=head1 BUGS
 
 As this is 0.01 there are almost bound to be some. Not recommended for
 production use.
 
-=head2 AUTHOR INFORMATION
+=head1 AUTHOR INFORMATION
 
 Copyright 2001 Dr James Freeman E<lt>jfreeman@tassie.net.auE<gt>
 
@@ -3522,7 +3522,7 @@
 remotely browser dependent, please provide information about the
 affected browsers as well.
 
-=head2 CREDITS
+=head1 CREDITS
 
 Lincoln D. Stein (lstein@cshl.org) and everyone else who worked on the
 original CGI.pm upon which this module is heavily based
@@ -3533,7 +3533,7 @@
 failures as well as Perlmonks:
 tommyw, grinder, Jaap, vek, erasei, jlongino and strider_corinth
 
-=head2 SEE ALSO
+=head1 SEE ALSO
 
 B<CGI>, L<CGI::Simple::Standard>, L<CGI::Simple::Cookie>,
 L<CGI::Simple::Util>
