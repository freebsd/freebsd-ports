# This translation file is the Russian translation"
# (c) 2003, Alex Semenyaka <alexs@snark.rinet.ru>

$String{"Benutzung"} = <<EOF;

Использование:   muttprint [опции]... [-f файл]
 
Опции:

ОБРАТИТЕ ВНИМАНИЕ: Эти опции перекрывают установленные в файлах ~/.muttprintrc
и /etc/Muttprintrc.

-h, --help
       Эта подсказка.

-v, --version
       Напечатать текущую версию Muttprint.

-f [file], --file [file]
       Читать исходное сообщение из данного файла, а не со стандартного ввода.

-p [printername], --printer [printername]
       Использовать указанный принтер.
       "-" обозначает стандартынй вывод.
       Для печати в файл используйте TO_FILE:/path/to/file
	   
-i [file], --penguin [file]
       Задать картинку, которая будет печататься на первой странице.

-x, --x-face | -nox, --nox-face
       Включить/выключить печать X-Faces.

-t [number], --speed [number]
       Время в секундах, которой нужно принтеру для печати одной страницы.
		   
-w [number], --wait [number]
       Время между печатью чётных и нечётных страниц при дуплексной печати.

-F [fontname], --font [fontname]
       Семейство фотнов для печати. Возможные значения:
       Latex, Latex-bright, Times, Utopia, Palatino, Charter и Bookman
	   
-H, --headrule | -noH, --noheadrule
       Включить или выключить печать верхних направляющих
	   
-b, --footrule | -nob, --nofootrule
       Включить или выключить печать нижних направляющих
	   
-S Style | --frontstyle Style
       Выбрать стиль печати заголовка на первой странице:
       plain, border (по умолчанию), fbox, shadowbox, ovalbox, Ovalbox,
       doublebox, grey, greybox. 
       За их подробными описаниями обратитесь к руководству пользователя.

-a [headers], --printed-headers [headers]
       Поля заголовка письма, которые следует печатать. Подробности смотрите
       в руководстве пользователя.
       Пример: /Date/_To_From_*Subject*

-P [paperformat], --paper [paperformat]
       Формат печати: "letter" (США) или "A4" (Европа).

-l [language], --lang [language]
       Язык сообщений и печати

-c [charset], --charset [charset]
       Набор символов: latin1, latin2, latin3, latin4, latin5, latin9,
       auto (по поводу использования "auto" смотрите руководство).

-e [string], --date [string]
       original: печатать дату как в заголовке
       local:    пытаться перевести её к локальному формату и временной зоне

-E [string], --date-format [string]
       Формат печати даты; подробности в мануале к strftime(3)

-A [string], --addressformat [string]
       Определяет формат почтовых адресов в заголовке. Подробности смотрите в
       страничке man и руководстве пользователя.

-n [string], --verbatimnormal [string]
       Используется для форматирования обычного текста. Подробности смотрите в
       страничке man и руководстве пользователя.

-V [string], --verbatimsig [string]
       Используется для форматирования подписи.

-D, --debug | -noD, --nodebug
       Запись отладочной информации в журнальный файл /tmp/muttprint.log.

-d, --duplex | -nod, --noduplex
       Разрешает или запрещает дуплексную печать.

-g [number], --topmargin [number]
       Верхнее поле, в миллиметрах.

-G [number], --bottommargin [number]
       Нижнее поле, в миллиметрах.

-j [number], --leftmargin [number]
       Левое поле, в миллиметрах.

-J [number], --rightmargin [number]
       Правое поле, в миллиметрах.

-2 | -1
       Печатать 2 страницы на одном листе. Соответствует "экономному режиму".

-s, --rem_sig | -nos, --norem_sig
       Удалять подпись (отделённую "-- ") при печати.

-q, --rem_quote | -noq, --norem_quote
       Удалять цитирование при печати.

-z [size], --fontsize [size]
       Размер шрифта: 10pt, 11pt, 12pt (допустимы только эти значения)

-W [number], --wrapmargin [number]
       Указывает, насколько длинными могут быть строки.
	   
-r [file], --rcfile [file]
       Задаёт дополнительный конфигурационный файл.

EOF

$String{"Lizenz"} = "Эта программа распространяется на условиях
GPL и может свободно копироваться.
";

$String{"Bugs"} = "Об ошибках сообщайте <Bernhard.Walle\@gmx.de>.\n";

$String{"FileNotFound"} = "Указанный файл не найден.\n";

@String{"From", "To", "Subject", "CC", "Date", "Page", "of", "Newsgroups"} =
("From:", "To:", "Subject:", "Carbon Copy:", "Date:", "стр.", "из", "Newsgroups:");

$LPack = "english,russian";
$charset = "koi8-r";
