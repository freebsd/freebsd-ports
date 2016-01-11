# Created by: Eygene Ryabinkin <rea-fbsd@codelabs.ru>
# $FreeBSD$

PORTNAME=	print
DISTVERSION=	6.x-1.0-rc5
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://ftp.drupal.org/files/projects/

MAINTAINER=	rea@FreeBSD.org
COMMENT=	Drupal 6 module that add printer-friendly pages

USES=		drupal:6,module
MODULE_DIRS=	icons translations
MODULE_FILES=	icons/mail_icon.gif icons/pdf_icon.gif icons/print_icon.gif \
		print-rtl.css print.admin.inc print.css print.info \
		print.install print.module print.pages.inc print.pdf.inc \
		print.tpl.php print_mail.admin.inc print_mail.inc \
		print_mail.info print_mail.install print_mail.module \
		print_pdf.admin.inc print_pdf.info print_pdf.install \
		print_pdf.module \
		translations/print.pot translations/ca.po \
		translations/cs.po translations/da.po translations/de.po \
		translations/es.po translations/fi.po translations/fr.po \
		translations/hu.po translations/id.po translations/it.po \
		translations/ja.po translations/nb.po translations/nl.po \
		translations/pl.po translations/pt-br.po \
		translations/pt-pt.po translations/ro.po \
		translations/ru.po translations/sk.po translations/sv.po \
		translations/tr.po translations/uk.po
DOC_FILES=	CHANGELOG.txt CREDITS.txt INSTALL.txt \
		LICENSE.txt MAINTAINERS.txt README.txt
OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
