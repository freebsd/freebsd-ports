# New ports collection makefile for:	drupal6-cck
# Date created:		28 jul	2008
# Whom:			Eygene Ryabinkin <rea-fbsd@codelabs.ru>
#
# $FreeBSD$
#

PORTNAME=	cck
DISTVERSION=	6.x-2.0-rc4
CATEGORIES=	www
MASTER_SITES=	http://ftp.drupal.org/files/projects/

MAINTAINER=	rea-fbsd@codelabs.ru
COMMENT=	Drupal 6 Content Construction Kit module

DRUPAL6_MODULE=	yes
MODULE_DIRS=	examples includes \
		modules/content_copy/translations modules/content_copy \
		modules/content_permissions/translations \
		modules/content_permissions \
		modules/fieldgroup/translations modules/fieldgroup  \
		modules/nodereference/translations modules/nodereference \
		modules/number/translations modules/number \
		modules/optionwidgets/translations modules/optionwidgets \
		modules/text/translations modules/text \
		modules/userreference/translations modules/userreference \
		modules tests theme translations
DOC_DIRS=	theme
MODULE_FILES=	content.info content.install content.js content.module \
		examples/example_field.php examples/simple_field.php \
		includes/content.admin.inc includes/content.crud.inc \
		includes/content.devel.inc includes/content.diff.inc \
		includes/content.node_form.inc includes/content.token.inc \
		includes/content.views.inc includes/content.views_convert.inc \
		modules/content_copy/translations/modules-content_copy.de.po \
		modules/content_copy/translations/modules-content_copy.fr.po \
		modules/content_copy/translations/modules-content_copy.pot \
		modules/content_copy/content_copy.info \
		modules/content_copy/content_copy.module \
		modules/content_permissions/translations/modules-content_permissions.de.po \
		modules/content_permissions/translations/modules-content_permissions.fr.po \
		modules/content_permissions/translations/modules-content_permissions.pot \
		modules/content_permissions/content_permissions.info \
		modules/content_permissions/content_permissions.install \
		modules/content_permissions/content_permissions.module \
		modules/fieldgroup/translations/modules-fieldgroup.de.po \
		modules/fieldgroup/translations/modules-fieldgroup.fr.po \
		modules/fieldgroup/translations/modules-fieldgroup.pot \
		modules/fieldgroup/fieldgroup.css \
		modules/fieldgroup/fieldgroup.info \
		modules/fieldgroup/fieldgroup.install \
		modules/fieldgroup/fieldgroup.module \
		modules/fieldgroup/fieldgroup.tpl.php \
		modules/nodereference/translations/modules-nodereference.de.po \
		modules/nodereference/translations/modules-nodereference.fr.po \
		modules/nodereference/translations/modules-nodereference.pot \
		modules/nodereference/nodereference.css \
		modules/nodereference/nodereference.info \
		modules/nodereference/nodereference.install \
		modules/nodereference/nodereference.module \
		modules/nodereference/nodereference.views.inc \
		modules/number/translations/modules-number.de.po \
		modules/number/translations/modules-number.fr.po \
		modules/number/translations/modules-number.pot \
		modules/number/number.info \
		modules/number/number.install \
		modules/number/number.module \
		modules/optionwidgets/translations/modules-optionwidgets.de.po \
		modules/optionwidgets/translations/modules-optionwidgets.fr.po \
		modules/optionwidgets/translations/modules-optionwidgets.pot \
		modules/optionwidgets/optionwidgets.info \
		modules/optionwidgets/optionwidgets.install \
		modules/optionwidgets/optionwidgets.module \
		modules/text/translations/modules-text.de.po \
		modules/text/translations/modules-text.fr.po \
		modules/text/translations/modules-text.pot \
		modules/text/text.info \
		modules/text/text.install \
		modules/text/text.module \
		modules/userreference/translations/modules-userreference.de.po \
		modules/userreference/translations/modules-userreference.fr.po \
		modules/userreference/translations/modules-userreference.pot \
		modules/userreference/userreference.info \
		modules/userreference/userreference.install \
		modules/userreference/userreference.module \
		tests/content.crud.test \
		theme/content-field.tpl.php theme/content.css \
		translations/content.de.po translations/content.fr.po \
		translations/content.pot translations/es.po \
		translations/examples.de.po translations/examples.fr.po \
		translations/examples.pot translations/general.de.po \
		translations/general.fr.po translations/general.pot \
		translations/includes.de.po translations/includes.fr.po \
		translations/includes.pot \
		translations/it.po translations/ja.po \
		translations/nl.po translations/pt.po \
		translations/ru.po translations/vi.po
DOC_FILES=	CHANGELOG.txt DEVELOPER.txt LICENSE.txt README.txt \
		UPGRADE.txt theme/README.txt

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/drupal5/bsd.drupal.mk"
.include <bsd.port.post.mk>
