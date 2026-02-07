<?php
/**
* Polish (pl) translation file.
* Based on phpScheduleIt translation file.
* This also serves as the base translation file from which to derive
*  all other translations.
*
* @author Samuel Tran <stran2005@users.sourceforge.net>
* @author Brian Wong <bwsource@users.sourceforge.net>
* @author Nicolas Peyrussie <peyrouz@users.sourceforge.net>
* @version 04-03-07
* @package Languages
*
* Copyright (C) 2005 - 2007 MailZu
* License: GPL, see LICENSE
*
* $Id$
*/
///////////////////////////////////////////////////////////
// INSTRUCTIONS
///////////////////////////////////////////////////////////
// This file contains all of the strings that are used throughout phpScheduleit.
// Please save the translated file as '2 letter language code'.lang.php.  For example, en.lang.php.
// 
// To make phpScheduleIt available in another language, simply translate each
//  of the following strings into the appropriate one for the language.  If there
//  is no direct translation, please provide the closest translation.  Please be sure
//  to make the proper additions the /config/langs.php file (instructions are in the file).
//  Also, please add a help translation for your language using en.help.php as a base.
//
// You will probably keep all sprintf (%s) tags in their current place.  These tags
//  are there as a substitution placeholder.  Please check the output after translating
//  to be sure that the sentences make sense.
//
// + Please use single quotes ' around all $strings.  If you need to use the ' character, please enter it as \'
// + Please use double quotes " around all $email.  If you need to use the " character, please enter it as \"
//
// + For all $dates please use the PHP strftime() syntax
//    http://us2.php.net/manual/en/function.strftime.php
//
// + Non-intuitive parts of this file will be explained with comments.  If you
//    have any questions, please email lqqkout13@users.sourceforge.net
//    or post questions in the Developers forum on SourceForge
//    http://sourceforge.net/forum/forum.php?forum_id=331297
///////////////////////////////////////////////////////////

////////////////////////////////
/* Do not modify this section */
////////////////////////////////
global $strings;			  //
global $email;				  //
global $dates;				  //
global $charset;			  //
global $letters;			  //
global $days_full;			  //
global $days_abbr;			  //
global $days_two;			  //
global $days_letter;		  //
global $months_full;		  //
global $months_abbr;		  //
global $days_letter;		  //
/******************************/

// Charset for this language
// 'iso-8859-1' will work for most languages
$charset = 'utf-8';

/***
  DAY NAMES
  All of these arrays MUST start with Sunday as the first element 
   and go through the seven day week, ending on Saturday
***/
// The full day name
$days_full = array('Niedziela', 'Poniedziałek', 'Wtorek', 'Środa', 'Czwartek', 'Piątek', 'Sobota');
// The three letter abbreviation
$days_abbr = array('Nie', 'Pon', 'Wto', 'Śro', 'Czw', 'Pią', 'Sob');
// The two letter abbreviation
$days_two  = array('Nd', 'Pn', 'Wt', 'Śr', 'Cz', 'Pi', 'So');
// The one letter abbreviation
$days_letter = array('N', 'P', 'W', 'Ś', 'C', 'T', 'S');

/***
  MONTH NAMES
  All of these arrays MUST start with January as the first element
   and go through the twelve months of the year, ending on December
***/
// The full month name
$months_full = array('Styczeń', 'Luty', 'Marzec', 'Kwiecień', 'Maj', 'Czerwiec', 'Lipiec', 'Sierpień', 'Wrzesień', 'Październik', 'Listopad', 'Grudzień');
// The three letter month name
$months_abbr = array('Sty', 'Lut', 'Mar', 'Kwi', 'Maj', 'Cze', 'Lip', 'Sie', 'Wrz', 'Paź', 'Lis', 'Gru');

// All letters of the alphabet starting with A and ending with Z
$letters = array ('A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z');

/***
  DATE FORMATTING
  All of the date formatting must use the PHP strftime() syntax
  You can include any text/HTML formatting in the translation
***/
// General date formatting used for all date display unless otherwise noted
$dates['general_date'] = '%d/%m/%Y';
// General datetime formatting used for all datetime display unless otherwise noted
// The hour:minute:second will always follow this format
$dates['general_datetime'] = '%d/%m/%Y @';
$dates['header'] = '%A, %B %d, %Y';

/***
  STRING TRANSLATIONS
  All of these strings should be translated from the English value (right side of the equals sign) to the new language.
  - Please keep the keys (between the [] brackets) as they are.  The keys will not always be the same as the value.
  - Please keep the sprintf formatting (%s) placeholders where they are unless you are sure it needs to be moved.
  - Please keep the HTML and punctuation as-is unless you know that you want to change it.
***/
$strings['hours'] = 'godziny';
$strings['minutes'] = 'minuty';
// The common abbreviation to hint that a user should enter the month as 2 digits
$strings['mm'] = 'mm';
// The common abbreviation to hint that a user should enter the day as 2 digits
$strings['dd'] = 'dd';
// The common abbreviation to hint that a user should enter the year as 4 digits
$strings['yyyy'] = 'yyyy';
$strings['am'] = 'am';
$strings['pm'] = 'pm';

$strings['Administrator'] = 'Administrator';
$strings['Welcome Back'] = '%s, witaj ponownie';
$strings['Log Out'] = 'Wyloguj';
$strings['Help'] = 'Pomoc';

$strings['Admin Email'] = 'Email administratora';

$strings['Default'] = 'Domyślny';
$strings['Reset'] = 'Reset';
$strings['Edit'] = 'Edytuj';
$strings['Delete'] = 'Skasuj';
$strings['Cancel'] = 'Anuluj';
$strings['View'] = 'Podgląd';
$strings['Modify'] = 'Modyfikacja';
$strings['Save'] = 'Zachowaj';
$strings['Back'] = 'Powrót';
$strings['BackMessageIndex'] = 'Powrót do Wiadomości';
$strings['ToggleHeaders'] = 'Przełącz nagłówki';
$strings['ViewOriginal'] = 'Obejrzyj w oryginale';
$strings['Next'] = 'Następna';
$strings['Close Window'] = 'Zamknij okno';
$strings['Search'] = 'Szukaj';
$strings['Clear'] = 'Wyczyść';

$strings['Days to Show'] = 'Dni do pokazania';
$strings['Reservation Offset'] = 'Reservation Offset';
$strings['Hidden'] = 'Ukryte';
$strings['Show Summary'] = 'Pokaż podsumowanie';
$strings['Add Schedule'] = 'Dodaj Schedule';
$strings['Edit Schedule'] = 'Edytuj Schedule';
$strings['No'] = 'Nie';
$strings['Yes'] = 'Tak';
$strings['Name'] = 'Nazwa';
$strings['First Name'] = 'Imię';
$strings['Last Name'] = 'Nazwisko';
$strings['Resource Name'] = 'Nazwa Żródła';
$strings['Email'] = 'Email';
$strings['Institution'] = 'Instytucja';
$strings['Phone'] = 'Telefon';
$strings['Password'] = 'Hasło';
$strings['Permissions'] = 'Uprawnienia';
$strings['View information about'] = 'Zobacz informację o %s %s';
$strings['Send email to'] = 'Wyślij email do %s %s';
$strings['Reset password for'] = 'Reset hasła dla %s %s';
$strings['Edit permissions for'] = 'Edycja uprawnień dla %s %s';
$strings['Position'] = 'Pozycja';
$strings['Password (6 char min)'] = 'Hasło (minimum %s znaków)';	// @since 1.1.0
$strings['Re-Enter Password'] = 'Wprowadź hasło ponownie';

$strings['Date'] = 'Data';
$strings['Email Users'] = 'Wyślij email do użytkowników';
$strings['Subject'] = 'Temat';
$strings['Message'] = 'Wiadomość';
$strings['Send Email'] = 'Wyślij Email';
$strings['problem sending email'] = 'Niestety wystąpił błąd podczas wysyłania emaila. Proszę spróbować ponownie później.';
$strings['The email sent successfully.'] = 'Wysłanie emaila zakończone sukcesem.';
$strings['Email address'] = 'Adres email';
$strings['Please Log In'] = 'Proszę się zalogować';
$strings['Keep me logged in'] = 'Pamiętaj moje dane logowania <br/>(wymagane ciasteczka)';
$strings['Password'] = 'Hasło';
$strings['Log In'] = 'Zaloguj';
$strings['Get online help'] = 'Dostęp do pomocy';
$strings['Language'] = 'Język';
$strings['(Default)'] = '(Domyślnie)';

$strings['Email Administrator'] = 'Wyślij email do administrator';

$strings['N/A'] = 'Niedostępne';
$strings['Summary'] = 'Podsumowanie';

$strings['View stats for schedule'] = 'Zobacz statystyki dla wykazu:';
$strings['At A Glance'] = 'W skrócie';
$strings['Total Users'] = 'Wszystkich użytkowników:';
$strings['Total Resources'] = 'Wszystkich zasobów:';
$strings['Total Reservations'] = 'Wszystkich Rezerwacji:';
$strings['Max Reservation'] = 'Maksimum Rezerwacji:';
$strings['Min Reservation'] = 'Minimum Rezerwacji:';
$strings['Avg Reservation'] = 'Średnio Rezerwacji:';
$strings['Most Active Resource'] = 'Najbardziej aktywne źródła:';
$strings['Most Active User'] = 'Najbardziej aktywni użytkownicy:';
$strings['System Stats'] = 'Statystyki systemowe';
$strings['phpScheduleIt version'] = 'Wersja phpScheduleIt:';
$strings['Database backend'] = 'Baza danych:';
$strings['Database name'] = 'Nazwa bazy danych:';
$strings['PHP version'] = 'Wersja PHP:';
$strings['Server OS'] = 'System operacyjny serwera:';
$strings['Server name'] = 'Nazwa serwera:';
$strings['phpScheduleIt root directory'] = 'Katalog główny (root) phpScheduleIt:';
$strings['Using permissions'] = 'Using permissions:';
$strings['Using logging'] = 'Using logging:';
$strings['Log file'] = 'Plik logu:';
$strings['Admin email address'] = 'Adres email administracyjny:';
$strings['Tech email address'] = 'Adres email techniczny:';
$strings['CC email addresses'] = 'Adresy email do Cc (do wiadomości):';
$strings['Reservation start time'] = 'Czas rozpoczęcia rezerwacji:';
$strings['Reservation end time'] = 'Czas zakończenia rezerwacji:';
$strings['Days shown at a time'] = 'Pokazana liczba dni:';
$strings['Reservations'] = 'Rezerwacje';
$strings['Return to top'] = 'Powrót na początek';
$strings['for'] = 'dla';

$strings['Per page'] = 'na stronę:';
$strings['Page'] = 'Strona:';

$strings['You are not logged in!'] = 'Nie jesteś zalogowany!';

$strings['Setup'] = 'Setup';
$strings['Invalid User Name/Password.'] = 'Niepoprawny login/hasło.';

$strings['Valid username is required'] = 'Wymagana poprawna nazwa użytkownika';

$strings['Close'] = 'Zamknij';

$strings['Admin'] = 'Admin';

$strings['My Quick Links'] = 'Moje szybkie odnośniki';

$strings['Go to first page'] = 'Idź na pierwszą stronę';
$strings['Go to last page'] = 'Idź na ostatnią stronę';
$strings['Sort by descending order'] = 'Uporządkuj malejąco';
$strings['Sort by ascending order'] = 'Uporządkuj rosnąco';
$strings['Spam Quarantine'] = 'Kwarantanna spamów';
$strings['Message View'] = 'Podgląd wiadomości';
$strings['Attachment Quarantine'] = 'Kwarantanna załączników';
$strings['No such content type'] = 'Nierozpoznana zawartość (content type)';
$strings['No message was selected'] = 'Nie wybrano wiadomości...';
$strings['Unknown action type'] = 'Nieznany rodzaj akcji...';
$strings['A problem occured when trying to release the following messages'] = 'Wystąpił błąd w trakcie uwalniania wiadomości';
$strings['A problem occured when trying to delete the following messages'] = 'Wystąpił błąd w trakcie kasowania wiadomości';
$strings['Please release the following messages'] = 'Proszę uwolnić następujące wiadomości';
$strings['To'] = 'Do';
$strings['From'] = 'Od';
$strings['Subject'] = 'Temat';
$strings['Date'] = 'Data';
$strings['Score'] = 'Punkty';
$strings['Mail ID'] = 'ID wiadomości';
$strings['Status'] = 'Status';
$strings['Print'] = 'Drukuj';
$strings['CloseWindow'] = 'Zamknij';
$strings['Unknown server type'] = 'Nieznany type serwera...';
$strings['Showing messages'] = "Wyświetlenie wiadomości %s do %s &nbsp;&nbsp; (%s wszystkich)\r\n";
$strings['View this message'] = 'Zobacz wiadomość';
$strings['Message Unavailable'] = 'Wiadomość niedostępna';
$strings['My Quarantine'] = 'Moja kwarantanna';
$strings['Site Quarantine'] = 'Kwarantanna systemu';
$strings['Message Processing'] = 'Przetwarzanie wiadomości';
$strings['Quarantine Summary'] = 'Podsumowanie kwarantanny';
$strings['Site Quarantine Summary'] = 'Podsumowanie kwarantanny systemu';
$strings['Login'] = 'Login';
$strings['spam(s)'] = 'spam(ów)';
$strings['attachment(s)'] = 'załącznik(ów)';
$strings['pending release request(s)'] = 'przetwarzanie żądania(ń) uwolnienia';
$strings['virus(es)'] = 'wirus(ów)';
$strings['bad header(s)'] = 'zły(ch) nagłów-ek/ków';
$strings['You have to type some text'] = 'Musisz podać jakikolwiek tekst';
$strings['Release'] = 'Zwolnij';
$strings['Release/Request release'] = 'Zwolnij wiadomości oczekujące w kolejce';
$strings['Request release'] = 'Prośba o zwolnienie';
$strings['Delete'] = 'Skasuj';
$strings['Delete All'] = 'Skasuj wszystko';
$strings['Send report and go back'] = 'Wyśłanie raportu i powrót';
$strings['Go back'] = "Powrót";
$strings['Select All'] = "Wybierz wszystko";
$strings['Clear All'] = "Wyczyść wszystko";
$strings['Access Denied'] = "Dostęp zabroniony";
$strings['My Pending Requests'] = "My Pending Requests";
$strings['Site Pending Requests'] = "Site Pending Requests";
$strings['Cancel Request'] = "Anuluj prośbę";
$strings['User is not allowed to login'] = "Brak uprawnień do zalogowania dla użytkownika";
$strings['Authentication successful'] = "Uwierzytelnienie poprawne";
$strings['Authentication failed'] = "Uwierzytelnienie niepoprawne";
$strings['LDAP connection failed'] = "Połączenie LDAP/AD nie powiodło się";
$strings['Logout successful'] = "Wylogowanie poprawne";
$strings['IMAP Authentication: no match'] = "IMAP Authentication: no match";
$strings['Search for messages whose:'] = "Szukaj wiadomości, które:";
$strings['Content Type'] = "Content Type";
$strings['Clear search results'] = "Wyczyść wyniki wyszukiwania";
$strings['contains'] = "zawiera";
$strings['doesn\'t contain'] = "nie zawiera";
$strings['equals'] = "";
$strings['doesn\'t equal'] = "różny od";
$strings['All'] = "Wszystko";
$strings['Spam'] = "Spam";
$strings['Banned'] = "Niepoprawny załącznik";
$strings['Virus'] = "Wirus";
$strings['Viruses'] = "Viruses";
$strings['Bad Header'] = "Bad Header";
$strings['Bad Headers'] = "Bad Headers";
$strings['Pending Requests'] = "Pending Requests";
$strings['last'] = "ostatnie";
$strings['first'] = "pierwsze";
$strings['previous'] = "poprzedni";
$strings['There was an error executing your query'] = 'There was an error executing your query:';
$strings['There are no matching records.'] = 'There are no matching records.';
$strings['Domain'] = 'Domena';
$strings['Total'] = 'Wszystko';
$strings['X-Amavis-Alert'] = 'X-Amavis-Alert';
$strings['Loading Summary...'] = 'Loading Summary...';
$strings['Retrieving Messages...'] = 'Retrieving Messages...';
?>
