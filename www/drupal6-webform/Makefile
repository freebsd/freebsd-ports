# New ports collection makefile for:	drupal6-webform
# Date created:				2 June 2009
# Whom:					Nick Hilliard <nick@foobar.org>
#
# $FreeBSD$
#

PORTNAME=	webform
DISTVERSION=	6.x-2.7
CATEGORIES=	www

MAINTAINER=	nick@foobar.org
COMMENT=	Drupal module to allow easy creation of forms

DRUPAL6_MODULE=	yes

MODULE_FILES=	components/date.inc components/email.inc \
		components/fieldset.inc components/file.inc \
		components/grid.inc components/hidden.inc \
		components/markup.inc components/pagebreak.inc \
		components/select.inc components/textarea.inc \
		components/textfield.inc components/time.inc \
		webform-confirmation.tpl.php webform-form.tpl.php \
		webform-mail.tpl.php webform.css webform.info \
		webform.install webform.js webform.module \
		webform_components.inc webform_export.inc webform_report.inc \
		webform_submissions.inc tests/components.test \
		tests/permissions.test tests/submission.test \
		tests/webform.test translations/webform.pot \
		translations/cs.po translations/da.po translations/de.po \
		translations/el.po translations/es.po translations/fr.po \
		translations/he.po translations/hu.po translations/it.po \
		translations/ja.po translations/nl.po translations/ru.po \
		translations/sk.po translations/sv.po

MODULE_DIRS=	components tests translations

DOC_FILES=	CHANGELOG.txt INSTALL.txt README.txt THEMING.txt LICENSE.txt

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/drupal5/bsd.drupal.mk"
.include <bsd.port.post.mk>
