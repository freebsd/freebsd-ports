# options.tcl --
#
# This file contains defaults for all the options. These are just the
# built in defaults.
#
#
#  TkRat software and its included text is Copyright 1996,1997,1998
#  by Martin Forss.ANin
#
#  Postilion software and its included text and images
#  Copyright (C) 1998 Nic Bernstein
#
#  The full text of the legal notices is contained in the files called
#  COPYING and COPYRIGHT.TkRat, included with this distribution.
#
#  This program is free software; you can redistribute it and/or
#  modify it under the terms of the GNU General Public License
#  as published by the Free Software Foundation; either version 2
#  of the License, or (at your option) any later version.
# 
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with this program; if not, write to the Free Software
#  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

# OptionsInit --
#
# Initialize the options to their default values
#
# Arguments:

proc OptionsInit {} {
    global env option postilion_version icons mailbox address mboxview

    # Last run version
    set option(last_version) ""

    # The date of the last version used
    set option(last_version_date) 0

    # Want information about changes?
    set option(info_changes) 1

    # UI language
    set option(language) en

    # Search path for global configuration files
    set option(global_config_path) $env(CONFIG_DIR)

    # Personal config directory
    set option(postilion_dir) ~/.postilion

    # Database directory
    set option(dbase_dir) ~/.postilion/db

    # Directory to backup database messages to
    set option(dbase_backup) ~/.postilion/backup

    # Directory to store outgoing messages
    set option(send_cache) ~/.postilion/send

    # Delivery mode
    set option(delivery_mode) direct

    # whether to display the button bar
    set option(button_bar) 1

    # style of buttons to use (text or image)
    set option(image_buttons) 1

    # whether to display the sync button
    set option(sync_but) 0

    # what the sync button should do
    set option(sync_oper) 0

    # paths and files to use for images
    set option(image_path) $env(LIBDIR)/images

    # the up-arrow button
    set icons(upabut) $option(image_path)/uparrow.gif
    # the down-arrow button
    set icons(dnabut) $option(image_path)/dnarrow.gif
    # the move button
    set icons(mvbut) $option(image_path)/mailbox.gif
    # the delete button
    set icons(delbut) $option(image_path)/trash.gif
    # the compose button
    set icons(compbut) $option(image_path)/compose.gif
    # the find message button
    set icons(fndbut) $option(image_path)/find.gif
    # the synchronize button
    set icons(updbut) $option(image_path)/sync.gif
    # the reply button
    set icons(repbut) $option(image_path)/reply.gif
    # the reply-all button
    set icons(rallbut) $option(image_path)/replyall.gif
    # the forward button
    set icons(fwrdbut) $option(image_path)/forward.gif
    # the send image
    set icons(sndbut) $option(image_path)/send.gif
    # the send/save image
    set icons(savbut) $option(image_path)/sendsave.gif
    # the Spell check image
    set icons(spllbut) $option(image_path)/spell.gif
    # the attach-file image
    set icons(atchbut) $option(image_path)/attach-mini.gif
    # the attach-keys image
    set icons(keybut) $option(image_path)/keys.gif
    # the encrypt image
    set icons(mcryptbut) $option(image_path)/pgp-mini.gif
    # the sign image
    set icons(msignbut) $option(image_path)/sign-mini.gif
    # the PGP icon
    set icons(mlockbut) $option(image_path)/keys-mini.gif
    # the DSN icon
    set icons(mrecpbut) $option(image_path)/recp-mini.gif
    # the encrypt image
    set icons(cryptbut) $option(image_path)/pgp.gif
    # the sign image
    set icons(signbut) $option(image_path)/sign.gif
    # the PGP icon
    set icons(lockbut) $option(image_path)/keys.gif
    # the DSN icon
    set icons(recpbut) $option(image_path)/receipt.gif
    # the detach-file image
    set icons(dtchbut) $option(image_path)/detach-mini.gif
    # the base mbox icon
    set icons(mbox_base) $option(image_path)/mailbox.gif
    # the addresses icon
    set icons(addrbut) $option(image_path)/addresses.gif

    # information for the mailbox widget
    # how many list boxes?
    set mailbox(num_lbs) 3

    # Width of listboxes in the mailbox widget
    set mailbox(lbwidth) 20

    # do we  handle the hierarchy as a path or not?
    # ie: for mailboxes, we need to keep track of how we got there,
    # for addresses, we only care about the address, not how the user stores it
    set mailbox(path) 1

    # if this hierarchy uses a path, what is the path seperator
    set mailbox(seperator) :

    # the font to use for the headers in the mailbox widget
    set mailbox(head_font) "-*-helvetica-bold-r-*-*-12-*-*-*-*-*-*-*"
    
    # A placekeeper
    set mailbox(current) {}

    # information for the mboxview widget
    # Is it visible?
    set option(mboxvis) 0

    # how many list boxes?
    set mboxview(num_lbs) 3

    # Width of listboxes in the mboxview widget
    set mboxview(lbwidth) 20

    # the font to use for the headers in the mboxview widget
    set mboxview(head_font) "-*-helvetica-bold-r-*-*-12-*-*-*-*-*-*-*"
    
    # A placekeeper
    set mboxview(current) {}

    # information for the address widget
    # how many list boxes?
    set address(num_lbs) 2

    # Width of listboxes in the address widget
    set address(lbwidth) {}

    # do we  handle the hierarchy as a path or not?
    # ie: for mailboxes, we need to keep track of how we got there,
    # for addresses, we only care about the address, not how the user stores it
    set address(path) 0

    # if this hierarchy uses a path, what is the path seperator
    set address(seperator) :

    # the font to use for the headers in the address widget
    set address(head_font) "-*-helvetica-bold-r-*-*-12-*-*-*-*-*-*-*"
    
    # A placekeeper
    set address(current) {}

    # Whether to enable Offix DND support, must be 1 or 0
    set option(DND) 0

    # How long to wait between expiring the database (in days)
    set option(expire_interval) 7

    # Directory for message hold
    set option(hold_dir) ~/.postilion/hold

    # Userprocedures file
    set option(userproc) ~/.postilion/userproc

    # Main window name
    set option(main_window_name) "Postilion v$postilion_version"

    # Main window geometry
    set option(main_geometry) +0+50

    # Icon name
    set option(icon_name) "Postilion v$postilion_version"

    # Command to get default folder
    set option(default_folder) "INBOX file {} /var/spool/mail/$env(USER)"

    # Format of list of messages
    set option(list_format) "%4S %6d  %-24n %4B %s"

    # How many headers we should show
    set option(show_header) selected

    # Which the selected headers are:
    set option(show_header_selection) {From Subject Date To CC Reply-To}

    # How many old directories we should remember
    set option(prev_dir) 10

    # Default permissions mask
    set option(permissions) 0600

    # Prefix for date type dynaminc folders
    set option(date-prefix) sent

    # Geometry of compose window
    set option(compose_geometry) +0+50

    # Which headers to compose
    set option(compose_headers) {To Subject Cc}

    # Which custom headers
    set option(custom_headers) {}

    # Which editor to use (%s will be expanded to a filename)
    set option(editor) "emacs %s"

    # Which domain we should pretend we are from
    set option(masquerade_as) {}

    # Which domain we are in
    set option(domain) {}

    # List of SMTP hosts
    set option(smtp_hosts) {localhost}

    # Default sening protocol
    set option(sendprot) smtp

    # Default sending program
    set option(sendprog) /usr/lib/sendmail

    # Can the sending program handle eightbit data
    set option(sendprog_8bit) false

    # Default character set for tcl
    set option(charset) iso-8859-1

    # Leader string for replies
    set option(reply_lead) {>}

    # Width of listboxes in vfolderdef window
    set option(vfoldername_width) 15

    # True (1) if we should show the watcher
    set option(watcher_enable) 1

    # Time between checking for new mail in different folders
    set option(watcher_time) {{std 30} {dbase 0}}

    # Geometry of watcher
    set option(watcher_geometry) -140+0

    # Watcher window name
    set option(watcher_name) Watcher

    # Watcher max height
    set option(watcher_max_height) 10

    # Font in watcher
    set option(watcher_font) 5x7

    # How many messages the watcher shall show
    set option(watcher_show) new

    # How many times the bell should be run when new messages arive
    set option(watcher_bell) 2

    # Format of list of messages in watcher
    set option(watcher_format) "%4S %-24n %s"

    # Print command
    set option(print_command) "lpr %s"

    # Headers to print
    set option(print_header) selected

    # Should we print non-text attachments
    set option(print_non_text) 0

    # Directory for temporary files
    set option(tmp) /tmp

    # Subject for replies to messages without subject
    set option(no_subject) "Re: (no subject)"

    # Default signature file
    set option(signature) ~/.signature

    # Default folder sort method
    set option(folder_sort) folder

    # Should we advance the message cursur when flaging messages
    set option(adv_on_flag) 0

    # Message attribution
    set option(attribution) "On %d, %n wrote:"

    # Forwarded tag
    set option(forwarded_message) "------ Forwarded message ------"

    # File typing
    set option(typetable) { {*text* text/plain}
	{*XPM* image/pixmap}
	{*GIF* image/gif}
	{*JPEG* image/jpeg}
	{*JPG* image/jpeg}
	{*TIF* image/tiff}
	{*TIFF* image/tiff}
	{"*8-bit u-law*" audio/basic}
	{*PostScript* application/postscript}
	{*data* application/octet-stream}}

    # True if we want to see ALL messages from c-client (including babble)
    set option(see_bable) 0

    # True if we have looked for alias files
    set option(scan_aliases) 0

    # Number of messages to remember
    set option(num_messages) 10

    # True if we should lookup usernames in the local passwd-list
    set option(lookup_name) true

    # Default database expiration type
    set option(def_extype) remove

    # Default clock time format (12 or 24)
    set option(clock_format) 24

    # Default database expiration time
    set option(def_exdate) +365

    # How many messages are required for one chunk (in dbase backup)
    set option(chunksize) 100

    # Where we should store dsn files
    set option(dsn_directory) ~/.postilion/DSN

    # If we should default to request DSN
    set option(dsn_request) 0

    # If we should remove delivery reports from folders
    set option(dsn_snarf_reports) 0

    # How many days each DSN entry should be kept in the list
    set option(dsn_expiration) 7

    # How verbose we should be when recieving DSN's
    set option(dsn_verbose) {{failed notify} {delayed status} {delivered status} {relayed status} {expanded none}}

    # Which windows to display at startup
    set option(start_win) [list [list mailboxes 0] [list compose 0] \
			       [list address 0] [list folder 1]]

    # Whether to use a single NeXT style menu (1), or per-window menus (0)
    set option(next_menu) 0

    # Which message we should select when a folder is opened
    set option(start_selection) first_new

    # How long log messages should show (in ms)
    set option(log_timeout) 3

    # The default reply_to address
    set option(reply_to) ""

    # The font size we use
    set option(fontsize) 12

    # Folder window key combination
    set option(folder_key_compose) <Key-m>
    set option(folder_key_quit) <Alt-Key-F4>
    set option(folder_key_nextu) <Key-Tab>
    set option(folder_key_sync) <Control-Key-s>
    set option(folder_key_update) <Control-Key-u>
    set option(folder_key_delete) <Key-d>
    set option(folder_key_undelete) <Key-u>
    set option(folder_key_flag) <Key-g>
    set option(folder_key_seen) <Key-s>
    set option(folder_key_ans) <Key-a>
    set option(folder_key_next) {<Key-Right> <Shift-Key-Down> <Key-n>}
    set option(folder_key_prev) {<Key-Left> <Shift-Key-Up> <Key-p>}
    set option(folder_key_replya) <Key-R>
    set option(folder_key_replys) <Key-r>
    set option(folder_key_replyq) <Key-q>
    set option(folder_key_replyqa) <Key-Q>
    set option(folder_key_forward_i) <Key-f>
    set option(folder_key_forward_a) <Key-F>
    set option(folder_key_bounce) <Key-b>
    set option(folder_key_home) {<Key-0> <Key-F27>}
    set option(folder_key_bottom) {<Key-F33> <Key-End>}
    set option(folder_key_pagedown) {<Key-space> <Key-F35> <Key-z>}
    set option(folder_key_pageup) {<Key-BackSpace> <Key-F29> <Control-b>}
    set option(folder_key_linedown) {<Key-Down>}
    set option(folder_key_lineup) {<Key-Up>}
    set option(folder_key_cycle_header) <Key-h>
    set option(folder_key_find) <Key-l>
    set option(folder_key_select_all) <Key-A>
    set option(folder_key_deselect_all) <Key-c>

    # Compose window key combinations
    set option(compose_key_send) <Control-s>
    set option(compose_key_abort) <Alt-Key-F4>
    set option(compose_key_editor) <Control-o>
    set option(compose_key_undo) <Control-u>
    set option(compose_key_cut) {<Shift-Delete> <Control-x>}
    set option(compose_key_cut_all) <Control-W>
    set option(compose_key_copy) {<Control-Insert> <Control-c>}
    set option(compose_key_paste) {<Shift-Insert> <Control-v>}
    set option(compose_key_replys) <Control-r>
    set option(compose_key_replyq) <Control-q>
    set option(compose_key_replya) <Control-R>
    set option(compose_key_replyqa) <Control-Q>
    set option(compose_key_insert) <Control-i>

    # If we should check for stolen mail
    set option(mail_steal) 1

    # Data for netscape inbox
    set option(ms_netscape_pref_file) $env(HOME)/.netscape/preferences
    set option(ms_netscape_mtime) 0

    # True if we should remember the window positions
    set option(keep_pos) 1

    # The default From: address (may be empty)
    set option(from) {}

    # True if we should let the user specify from address.
    set option(use_from) 1

    # The level of verboseness we should use when talking SMTP
    set option(smtp_verbose) 1

    # If we should try to send multiple letters though one channel
    set option(smtp_reuse) 1

    # The color set
    set option(color_set) {gray67 black}

    # The background color for the compose and message "paper"
    set option(paper_color) white

    # True if we should cache passwords
    set option(cache_passwd) 1

    # Which icon to set for the application
    set icons(app_icon) $option(image_path)/postilion.gif

    # the compose window icon
    set icons(compicon) $option(image_path)/compicon.gif

    # the addressbook window icon
    set icons(addrwin) $option(image_path)/addrbook.gif

    # the preferences window icon
    set icons(prefwin) $option(image_path)/preficon.gif

    # the help window icon
    set icons(helpwin) $option(image_path)/helpicon.gif

    # the mailbox window icon
    set icons(mboxwin) $option(image_path)/mboxicon.gif

    # the browser window icon
    set icons(brwswin) $option(image_path)/brwsicon.gif

    # the dimple image
    set icons(dimple) $option(image_path)/dimple.gif

    # the down dimple image
    set icons(down) $option(image_path)/down.gif

    # the up dimple image
    set icons(up) $option(image_path)/up.gif

    # the no-dimple image
    set icons(none) $option(image_path)/none.gif

    # The default expression mode
    set option(expression_mode) basic

    # If we should start up in iconic mode
    set option(iconic) 0

    # If the compose editor should warn about cutting all text etc
    set option(compose_warn) 1

    # Length of message list
    set option(message_llength) 14

    # Mailcap path
    set option(mailcap_path) {~/.mailcap:/etc/mailcap:/usr/etc/mailcap:/usr/local/etc/mailcap}

    # Terminal command
    set option(terminal) "xterm -e sh -c"

    # Imap port
    set option(imap_port) 143

    # SMTP timeout
    set option(smtp_timeout) 120

    # Should we send even though we have a bad hostname?
    set option(force_send) 0

    # Should we quote the original message when replying (1=no, 0=yes)?
    set option(quote) 0

    # Should we skip the signature of the message we are replying to
    set option(skip_sig) true

    # Are we PGP capable?
    if [info exists env(PGPPATH)] {
	set pgpdir $env(PGPPATH)
    } else {
	set pgpdir ~/.pgp
    }
    if {0 < [string length "$env(PGP)"] &&
	    1 == [file readable $pgpdir/pubring.pgp] &&
	    1 == [file readable $pgpdir/secring.pgp]} {
	set option(pgp_enable) 1
    } else {
	set option(pgp_enable) 0
    }

    # Path to pgp program
    set option(pgp_prog) $env(PGP)

    # Extra pgp options
    set option(pgp_args) {}

    # If we should make a copy of attached files
    set option(copy_attached) 1

    # If we should sign outgoing letters
    set option(pgp_sign) 0

    # If we should encrypt outgoing letters
    set option(pgp_encrypt) 0

    # Default url viewer
    set option(url_viewer) netscape

    # Name (and path) of netscape executable
    set option(netscape) netscape

    # Extra arguments for netscape
    set option(netscape_args) -install

    # Color of URL
    set option(url_color) blue

    # Message list colors
    set option(new_msg_col) green
    set option(sel_msg_col) white
    set option(fnd_msg_col) white
    set option(flg_msg_col) red
    set option(del_msg_col) yellow
    set option(seen_msg_col) black
    set option(ans_msg_col) blue

    # System wide aliases
    set option(system_aliases) "System postilion $env(CONFIG_DIR)/aliases"
    set option(use_system_aliases) 1

    # System wide mailboxes
    set option(system_mailboxes) "$env(CONFIG_DIR)/sysvfolderdef"
    set option(use_system_mboxes) 1

    # Personal alias lists
    set option(addrbooks) {{Personal postilion ~/.postilion/aliases}}

    # Default alias book
    set option(default_book) Personal

    # Default browse mode
    set option(browse) folder

    # Default sort mode
    set option(sort_mode) folder

    # Default list format mode
    set option(list_mode) folder

    # Default signature mode
    set option(sig_mode) folder

    # Default start selection mode
    set option(strsel_mode) folder

    # Default From mode
    set option(from_mode) folder

    # Default reply to mode
    set option(reply_mode) folder

    # Caching data
    set option(cache_pgp) 1
    set option(cache_pgp_timeout) 300
    set option(cache_passwd) 1
    set option(cache_passwd_timeout) 300
    set option(cache_conn) 1
    set option(cache_conn_timeout) 10

    # URL protocols
    set option(urlprot) {http shttp ftp news telnet}

    # Balloon help
    set option(show_balhelp) 1

    # Balloon help delay
    set option(balhelp_delay) 500

    # Message finding fields
    set option(msgfind_format) "%s%n%b%D"

    # Should we warn about tk version 8.2
    set option(warn_tk82) 1

    ## Ispell options
    # Turn Ispell On/Off
    set option(ispellon) 1

    # Re-Verify after Adds?
    set option(ispellRecheckAfterAdd) 1

    # Spell Check 'Text' only?
    set option(ispelltextOnly) 1

    # Default speller invocation
    set option(ispelldefaultCommand) "ispell -a -S"

    # Other Invocations
    set option(ispellotherCommands) " German  { ispell -a -d deutsch } \
		French { ispell -a -d francais } \
                English { ispell -a -d english } "

    # Menu popup bound to:
    set option(ispellpopupBinding) "ButtonPress-3"

    # Miss-spelled word style
    set option(ispellviewStyle) underline

    # color for fgcolor and bgcolor
    set option(ispellviewStyle-Color) red

    # Style if 'other' is selected
    set option(ispellviewStyle-Other) "-underline t -foreground red"

    # Automatically expunge on folder close
    set option(expunge_on_close) 0
}

# OptionsRead --
#
# Searches the filesystem for postilionrc files
#
# Arguments:

proc OptionsRead {} {
    global option globalOption env ispellVars

    # Read global files
    foreach dir $option(global_config_path) {
	if [file readable $dir/postilionrc] {
	    source $dir/postilionrc
	}
    }
    # Take copy of global options
    foreach name [array names option] {
	set globalOption($name) $option($name)
    }
    # Read local modifications
    if [file readable $option(postilion_dir)/postilionrc] {
	source $option(postilion_dir)/postilionrc
    }
    # Set Ispell preferences array
    foreach pick {on RecheckAfterAdd textOnly defaultCommand
	otherCommands popupBinding viewStyle viewStyle-Color 
	viewStyle-Other} {
	set ispellVars($pick) $option(ispell$pick)
    }
}

# SaveOptions --
#
# Saves the users changes to the global options to disk.
#
# Arguments:

proc SaveOptions {} {
    global option globalOption

    # Warning message
    set message {#
# BEWARE of making changes to this file. It is automatically generated.
# You can change the values in this file via the preferences window. 
# This file can only contain "set option(<optname>) <value>" lines,
# everything else will be destroyed when the file is regenerated.
}

    set fh [open $option(postilion_dir)/postilionrc w]
    puts $fh $message
    foreach name [array names globalOption] {
	if [string compare $option($name) $globalOption($name)] {
	    puts $fh "set option($name) [list $option($name)]"
	}
    }
    close $fh
}

# ReadUserproc --
#
# Source the users userproc file with some caution
#
# Arguments:

proc ReadUserproc {} {
    global option t
    if [file readable $option(userproc)] {
	if [catch "source $option(userproc)" message] {
	    Popup "$t(error_in_userproc): $message"
	}
    }
}

# InitFonts --
#
# Initializes the default fonts
#
# These initializations can be overridden in the local configuration files.
# See the ../CONFIGURATION file for details.
#
# Arguments:

proc InitFonts {} {
    AddFont iso-8859-1 8 {} *-courier-medium-r-normal-*-8-*-iso8859-1
    AddFont iso-8859-1 8 {bold} *-courier-bold-r-normal-*-8-*-iso8859-1
    AddFont iso-8859-1 8 {italic} *-courier-medium-o-normal-*-8-*-iso8859-1
    AddFont iso-8859-1 8 {bold italic} *-courier-bold-o-normal-*-8-*-iso8859-1
    AddFont iso-8859-1 10 {} *-courier-medium-r-normal-*-10-*-iso8859-1
    AddFont iso-8859-1 10 {bold} *-courier-bold-r-normal-*-10-*-iso8859-1
    AddFont iso-8859-1 10 {italic} *-courier-medium-o-normal-*-10-*-iso8859-1
    AddFont iso-8859-1 10 {bold italic} *-courier-bold-o-normal-*-10-*-iso8859-1
    AddFont iso-8859-1 12 {} *-courier-medium-r-normal-*-12-*-iso8859-1
    AddFont iso-8859-1 12 {bold} *-courier-bold-r-normal-*-12-*-iso8859-1
    AddFont iso-8859-1 12 {italic} *-courier-medium-o-normal-*-12-*-iso8859-1
    AddFont iso-8859-1 12 {bold italic} *-courier-bold-o-normal-*-12-*-iso8859-1
    AddFont iso-8859-1 14 {} *-courier-medium-r-normal-*-14-*-iso8859-1
    AddFont iso-8859-1 14 {bold} *-courier-bold-r-normal-*-14-*-iso8859-1
    AddFont iso-8859-1 14 {italic} *-courier-medium-o-normal-*-14-*-iso8859-1
    AddFont iso-8859-1 14 {bold italic} *-courier-bold-o-normal-*-14-*-iso8859-1
    AddFont iso-8859-1 18 {} *-courier-medium-r-normal-*-18-*-iso8859-1
    AddFont iso-8859-1 18 {bold} *-courier-bold-r-normal-*-18-*-iso8859-1
    AddFont iso-8859-1 18 {italic} *-courier-medium-o-normal-*-18-*-iso8859-1
    AddFont iso-8859-1 18 {bold italic} *-courier-bold-o-normal-*-18-*-iso8859-1
    AddFont iso-8859-1 24 {} *-courier-medium-r-normal-*-24-*-iso8859-1
    AddFont iso-8859-1 24 {bold} *-courier-bold-r-normal-*-24-*-iso8859-1
    AddFont iso-8859-1 24 {italic} *-courier-medium-o-normal-*-24-*-iso8859-1
    AddFont iso-8859-1 24 {bold italic} *-courier-bold-o-normal-*-24-*-iso8859-1
}

# InitCharsetAliases
#
# Initialize the aliases of charcter sets
#
# Arguments:

proc InitCharsetAliases {} {
    global charsetAlias option

    # These are predefined (remember to only use lowercase letters)
    set charsetAlias(bar) iso-8859-1

    # Read global files
    foreach dir $option(global_config_path) {
	if [file readable $dir/charsetAliases] {
	    source $dir/charsetAliases
	}
    }
    # Read local modifications
    if [file readable $option(postilion_dir)/charsetAliases] {
	source $option(postilion_dir)/charsetAliases
    }
}

proc InitImages {} {
    global icons

    foreach name [array names icons] {
	if {[file readable $icons($name)]} {
	    image create photo $name -file $icons($name)
	}
    }
}
