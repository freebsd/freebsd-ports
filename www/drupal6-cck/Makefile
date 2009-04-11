# New ports collection makefile for:	drupal6-cck
# Date created:		28 jul	2008
# Whom:			Eygene Ryabinkin <rea-fbsd@codelabs.ru>
#
# $FreeBSD$
#

PORTNAME=	cck
DISTVERSION=	6.x-2.2
CATEGORIES=	www
MASTER_SITES=	http://ftp.drupal.org/files/projects/

MAINTAINER=	rea-fbsd@codelabs.ru
COMMENT=	Drupal 6 Content Construction Kit module

DRUPAL6_MODULE=	yes
MODULE_DIRS=	help \
		includes/views/handlers includes/views includes \
		modules/content_copy/translations modules/content_copy \
		modules/content_multigroup/translations \
		modules/content_multigroup \
		modules/content_permissions/translations \
		modules/content_permissions \
		modules/fieldgroup/translations modules/fieldgroup  \
		modules/nodereference/help \
		modules/nodereference/translations modules/nodereference \
		modules/number/help \
		modules/number/translations modules/number \
		modules/optionwidgets/help \
		modules/optionwidgets/translations modules/optionwidgets \
		modules/text/help modules/text/translations modules/text \
		modules/userreference/help \
		modules/userreference/translations modules/userreference \
		modules tests theme \
		translations/help/de translations/help translations
MODULE_FILES=	help/add-existing-field.html \
		help/add-existing-field.png \
		help/add-new-field.html \
		help/add-new-field.png \
		help/add-new-group.html \
		help/add-new-group.png \
		help/add-new.png \
		help/add.html \
		help/content.help.ini \
		help/drag-groups.png \
		help/drag-new.png \
		help/draggable.png \
		help/fields.html \
		help/group-node-display.png \
		help/group-node-edit-form.png \
		help/manage-fields.html \
		help/rearrange.html \
		help/remove.html \
		help/theme-field-templates.html \
		help/theme-formatters.html \
		help/theme-node-templates.html \
		help/theme.html \
		help/theme.png \
		content.info \
		content.install \
		content.js \
		content.module \
		includes/views/handlers/content_handler_argument.inc \
		includes/views/handlers/content_handler_argument_many_to_one.inc \
		includes/views/handlers/content_handler_argument_numeric.inc \
		includes/views/handlers/content_handler_argument_string.inc \
		includes/views/handlers/content_handler_field.inc \
		includes/views/handlers/content_handler_field_multiple.inc \
		includes/views/handlers/content_handler_filter_float.inc \
		includes/views/handlers/content_handler_filter_many_to_one.inc \
		includes/views/handlers/content_handler_filter_numeric.inc \
		includes/views/handlers/content_handler_filter_string.inc \
		includes/views/handlers/content_handler_relationship.inc \
		includes/views/handlers/content_handler_sort.inc \
		includes/views/handlers/content_plugin_display_simple.inc \
		includes/views/handlers/content_plugin_style_php_array_ac.inc \
		includes/views/content.views.inc \
		includes/views/content.views_convert.inc \
		includes/content.admin.inc \
		includes/content.crud.inc \
		includes/content.devel.inc \
		includes/content.diff.inc \
		includes/content.node_form.inc \
		includes/content.panels.inc \
		includes/content.rules.inc \
		includes/content.token.inc \
		modules/content_copy/translations/modules-content_copy.de.po \
		modules/content_copy/translations/modules-content_copy.fr.po \
		modules/content_copy/translations/modules-content_copy.hu.po \
		modules/content_copy/translations/modules-content_copy.pot \
		modules/content_copy/content_copy.info \
		modules/content_copy/content_copy.module \
		modules/content_copy/content_copy_export_form.tpl.php \
		modules/content_multigroup/translations/content_multigroup.de.po \
		modules/content_multigroup/translations/modules-content_multigroup.pot \
		modules/content_multigroup/README.txt \
		modules/content_multigroup/content_multigroup.css \
		modules/content_multigroup/content_multigroup.module \
		modules/content_permissions/translations/modules-content_permissions.de.po \
		modules/content_permissions/translations/modules-content_permissions.fr.po \
		modules/content_permissions/translations/modules-content_permissions.hu.po \
		modules/content_permissions/translations/modules-content_permissions.pot \
		modules/content_permissions/content_permissions.info \
		modules/content_permissions/content_permissions.install \
		modules/content_permissions/content_permissions.module \
		modules/fieldgroup/translations/modules-fieldgroup.de.po \
		modules/fieldgroup/translations/modules-fieldgroup.fr.po \
		modules/fieldgroup/translations/modules-fieldgroup.hu.po \
		modules/fieldgroup/translations/modules-fieldgroup.pot \
		modules/fieldgroup/fieldgroup-rtl.css \
		modules/fieldgroup/fieldgroup-simple.tpl.php \
		modules/fieldgroup/fieldgroup.css \
		modules/fieldgroup/fieldgroup.info \
		modules/fieldgroup/fieldgroup.install \
		modules/fieldgroup/fieldgroup.module \
		modules/fieldgroup/fieldgroup.panels.inc \
		modules/nodereference/help/nodereference.help.ini \
		modules/nodereference/help/nodereference.html \
		modules/nodereference/nodereference.info \
		modules/nodereference/nodereference.install \
		modules/nodereference/nodereference.module \
		modules/nodereference/nodereference.rules.inc \
		modules/nodereference/translations/modules-nodereference.de.po \
		modules/nodereference/translations/modules-nodereference.fr.po \
		modules/nodereference/translations/modules-nodereference.hu.po \
		modules/nodereference/translations/modules-nodereference.pot \
		modules/number/help/number.help.ini \
		modules/number/help/number.html \
		modules/number/number.info \
		modules/number/number.install \
		modules/number/number.module \
		modules/number/translations/modules-number.de.po \
		modules/number/translations/modules-number.fr.po \
		modules/number/translations/modules-number.hu.po \
		modules/number/translations/modules-number.pot \
		modules/optionwidgets/help/optionwidgets.help.ini \
		modules/optionwidgets/help/optionwidgets.html \
		modules/optionwidgets/optionwidgets.info \
		modules/optionwidgets/optionwidgets.install \
		modules/optionwidgets/optionwidgets.module \
		modules/optionwidgets/translations/modules-optionwidgets.de.po \
		modules/optionwidgets/translations/modules-optionwidgets.fr.po \
		modules/optionwidgets/translations/modules-optionwidgets.hu.po \
		modules/optionwidgets/translations/modules-optionwidgets.pot \
		modules/text/help/text.help.ini \
		modules/text/help/text.html \
		modules/text/text.info \
		modules/text/text.install \
		modules/text/text.module \
		modules/text/translations/modules-text.de.po \
		modules/text/translations/modules-text.fr.po \
		modules/text/translations/modules-text.hu.po \
		modules/text/translations/modules-text.pot \
		modules/userreference/help/userreference.help.ini \
		modules/userreference/help/userreference.html \
		modules/userreference/userreference.info \
		modules/userreference/userreference.install \
		modules/userreference/userreference.module \
		modules/userreference/userreference.rules.inc \
		modules/userreference/translations/modules-userreference.de.po \
		modules/userreference/translations/modules-userreference.fr.po \
		modules/userreference/translations/modules-userreference.hu.po \
		modules/userreference/translations/modules-userreference.pot \
		tests/content.crud.test \
		theme/content-admin-display-overview-form.tpl.php \
		theme/content-admin-field-overview-form.tpl.php \
		theme/content-field.tpl.php \
		theme/content-module-rtl.css \
		theme/content-module.css \
		theme/theme.inc \
		translations/help/de/add-existing-field.html \
		translations/help/de/add-existing-field.png \
		translations/help/de/add-new-field.html \
		translations/help/de/add-new-field.png \
		translations/help/de/add-new-group.html \
		translations/help/de/add-new-group.png \
		translations/help/de/add-new.png \
		translations/help/de/add.html \
		translations/help/de/content.help.ini \
		translations/help/de/drag-groups.png \
		translations/help/de/drag-new.png \
		translations/help/de/group-node-display.png \
		translations/help/de/group-node-edit-form.png \
		translations/help/de/manage-fields.html \
		translations/help/de/rearrange.html \
		translations/help/de/remove.html \
		translations/help/de/theme-formatters.html \
		translations/help/de/theme.html \
		translations/content.de.po \
		translations/content.fr.po \
		translations/content.pot \
		translations/es.po \
		translations/examples.fr.po \
		translations/general.de.po \
		translations/general.fr.po \
		translations/general.pot \
		translations/hu.po \
		translations/includes-views-handlers.de.po \
		translations/includes-views-handlers.pot \
		translations/includes-views.de.po \
		translations/includes-views.pot \
		translations/includes.de.po \
		translations/includes.fr.po \
		translations/includes.pot \
		translations/it.po \
		translations/ja.po \
		translations/nl.po \
		translations/pt.po \
		translations/ru.po \
		translations/theme.de.po \
		translations/theme.pot \
		translations/vi.po
DOC_FILES=	CHANGELOG.txt DEVELOPER.txt LICENSE.txt README.txt \
		UPGRADE.txt

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/drupal5/bsd.drupal.mk"
.include <bsd.port.post.mk>
