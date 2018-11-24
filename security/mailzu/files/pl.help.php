<?php
/**
* English (en) help translation file.
* This also serves as the base translation file from which to derive
*  all other translations.
*  
* @author Brian Wong <bwsource@users.sourceforge.net>
* @translator Your Name <your@email.com>
* @version 01-08-05
* @package Languages
*
* Copyright (C) 2003 - 2007 MailZu
* License: GPL, see LICENSE
*
* $Id$
*/
///////////////////////////////////////////////////////////
// INSTRUCTIONS
///////////////////////////////////////////////////////////
// This file contains all the help file for MailZu.  Please save the translated
//  file as '2 letter language code'.help.php.  For example, en.help.php.
// 
// To make MailZu help available in another language, simply translate this
//  file into your language.  If there is no direct translation, please provide the
//  closest translation.
//
// This will be included in the body of the help file.
//
// Please keep the HTML formatting unless you need to change it.  Also, please try
//  to keep the HTML XHTML 1.0 Transitional complaint.
///////////////////////////////////////////////////////////
?>
<div align="center"> 
  <h3><a name="top" id="top"></a>Wprowadzenie do MailZu</h3>
  <p><a href="http://mailzu.net" target="_blank">http://mailzu.net</a></p>
  <table width="100%" border="0" cellspacing="0" cellpadding="5" style="border: solid #CCCCCC 1px">
    <tr> 
      <td bgcolor="#FAFAFA"> 
        <ul>
          <li><b><a href="#getting_started">Rozpoczęcie pracy</a></b></li>
          <ul>
            <li><a href="#logging_in">Logowanie</a></li>
            <li><a href="#language">Wybór mojego języka</a></li>
            <li><a href="#getting_support">Uzyskanie wsparcia</a></li>
          </ul>
          <li><a href="#using_mailzu"><b>Używanie MailZu</b></a></li>
          <ul>
            <li><a href="#quick_links">Moje szybkie odnośniki</a></li>
            <li><a href="#msg_summary">Podsumowanie wiadomości</a></li>
            <li><a href="#msg_index">Indeksy wiadomości</a></li>
            <li><a href="#search">Szukanie wiadomości</a></li>
            <li><a href="#msg_view">Podgląd wiadomości</a></li>
          </ul>
        </ul>
		<hr width="95%" size="1" noshade="noshade" />
        <h4><a name="getting_started" id="getting_started"></a>Rozpoczęcie pracy</h4>
        <p> At the top of each page you will see a welcome message and today's date.
          If a previous user is displayed in the welcome message, click &quot;Log 
          Out&quot; to clear out any cookies they were using and <a href="#logging_in">log 
          in</a> as yourself. 
          Clicking the &quot;Help&quot; link brings a pop-up help window. Clicking
          the &quot;Email Administrator&quot; link will open a new mail addressed to the system's
          administrator.</p>
          <p align="right"><a href="#top">Top</a></p>
        <h5><a name="logging_in" id="logging_in"></a>Logging In</h5>
        <p>To log in, users must provide their login id and password. The login id
	  may be your fully-qualified email address ('user@example.com') or simply
	  your username ('user'). The administrator shall inform you of the correct
	  form to use. Selecting the &quot;Keep Me Logged In&quot; option will use 
          cookies to identify you each time you return to the quarantine, bypassing 
          the need to log in each time. <i>You should only use this option if 
          you are the only person using MailZu on your computer.</i> After 
          logging in, you will be redirected to the <a href="#message_summary">
          Message Summary</a>.</p>
        <p align="right"><a href="#top">Top</a></p>
        <h5><a name="language" id="language"></a>Selecting My Language</h5>
        <p>On the login page, there will be a pull down menu with all of the
          available language translations that your administrator has included.
          Please select the language that you prefer and all MailZu text
          will be translated. This will not translate any text related to actual
	  email messages; it will only translate the application text. You will 
	  need to log out to select a different language.</p>
        <p align="right"><a href="#top">Top</a></p>        
        <h5><a name="getting_support" id="getting_support"></a>Getting
          Help</h5>
        <p>If you you need assistance with viewing your quarantined messages or any
	  issue whatsoever, feel free to use the &quot;Email
          Administrator&quot; link located in <a href="#quick_links">My Quick Links</a>.</p>
        <p align="right"><a href="#top">Top</a></p>        <p align="right">&nbsp;</p>
        <hr width="95%" size="1" noshade="noshade" />
        <h4><a name="using_mailzu" id="using_mailzu"></a>Using MailZu</h4>
        <p>MailZu allows the user to view quarantined messages based on the type of messages. 
	   The most prevalent types of messages which will be quarantined are those that are 
	   considered spam, or contain a banned attachment.
        <p align="right"><a href="#top">Top</a></p>
        <h5><a name="quick_links" id="quick_links"></a>My Quick Links</h5>
        <p>The Quick Links table will provide you with common application links.
	  The first, &quot;Quarantine Summary&quot; will give an overview of your message 
	  quarantines.</p>
	<p> &quot;My Quarantine&quot; will take you to
          an index of your unsolicited bulk email and banned attachments.</p>
        <p>&quot;Email Administrator&quot; is a quick way to contact your support
	  staff if you require assistance.</p>
        <p>&quot;Help&quot; gives you this document.</p>
        <p>The final link, &quot;Log Out&quot; will log you out of your current
          session and return you to the log in screen.</p>
        <p align="right"><a href="#top">Top</a></p>
        <h5><a name="msg_summary" id="msg_summary"></a>Message Summary</h5>
	<p> The message summary is the default page after login. It gives you a quick count of
	  how many messages you have in your quarantine and their type.
        <p align="right"><a href="#top">Top</a></p>
        <h5><a name="msg_index" id="msg_index"></a>Message Indexes</h5>
        <p> Message indices show all the email for selected quarantined. 
	  For each email quarantined, the index will show the From, Subject, and Date. Depending
	  on the quarantine currently in view, the index may show more information.</p>
        <p>To sort your index by a specific field, click on the field title. Clicking the field
	   title again will reverse the sort.</p> 
	<p>Several buttons are available for handling the messages shown in the index. The 
	  'Release/Request' action removes the message from the index and delivers the email as 
   	  if it had never been quarantined. The 'Delete' action only removes the message from the 
	  index. These buttons perform the action on the messages selected through the checkboxes. 
	  The 'Delete All' button ignores the state of the checkboxes and removes all messages in
	  the quarantine selected.</p>
	<p>When viewing your pending requests you can withdraw the request by clicking 
	   'Cancel Request'. The message will no longer be queued for administrator review.
	</p>
        <p align="right"><a href="#top">Top</a></p>
        <h5><a name="search" id="search"></a>Message Search</h5>
        <p>Using the search function is a quick way to find a message you believe has been
	   quarantined. You can search for a message by specifying either who its from, or
	   what the subject is, or both. The search is not case sensitive.</p>
        <p align="right"><a href="#top">Top</a></p> 
	<h5><a name="msg_view" id="msg_view"></a>Message View</h5>
        <p>The Message View allows you to see the contents of the message to help
	   determine if the message is legitimate. This view offers other options such
	   as to display the original plain text email and see additional message headers.
	</p>
        <p align="right"><a href="#top">Top</a></p>        <p align="right">&nbsp;</p>

        <hr width="95%" size="1" noshade="noshade" />
      </td>
    </tr>
  </table>
</div>
