# New ports collection makefile for:	drupal5-views
# Date created:				25 Jul 2007
# Whom:					Geoff Glasson <g_glasson@jimali.dyndns.org>
#
# $FreeBSD$
#

PORTNAME=	views
DISTVERSION=	6.x-2.0-rc1
CATEGORIES=	www
MASTER_SITES=	http://ftp.drupal.org/files/projects/

MAINTAINER=	rea-fbsd@codelabs.ru
COMMENT=	Controls how content lists are generated

DRUPAL6_MODULE=	yes
MODULE_DIRS=	css docs help/images help images includes js \
		modules theme translations views_export
MODULE_FILES=	css/views-admin.css css/views-list.css \
		css/views-tabs.css css/views.css  docs/docs.php \
		views.info views.install views.module views2.doxy \
		views_ui.info views_ui.module \
		help/images/node-term_node-term_data-large.png \
		help/images/node-term_node-term_data.png \
		help/images/style-breakdown-large.png \
		help/images/style-breakdown.png \
		help/images/views1-admin-large.png \
		help/images/views1-admin.png \
		help/images/views1-changeviewtype-large.png \
		help/images/views1-changeviewtype.png \
		help/images/views2-addaview-large.png \
		help/images/views2-addaview.png \
		help/images/views2-adddisplay-large.png \
		help/images/views2-adddisplay.png \
		help/images/views2-addfields-large.png \
		help/images/views2-addfields.png \
		help/images/views2-addfieldsajax-large.png \
		help/images/views2-addfieldsajax.png \
		help/images/views2-admin-large.png \
		help/images/views2-admin.png \
		help/images/views2-changedisplaystyle-large.png \
		help/images/views2-changedisplaystyle.png \
		help/images/views2-fieldspreview-large.png \
		help/images/views2-fieldspreview.png \
		help/images/views2-newview-large.png \
		help/images/views2-newview.png \
		help/images/views2-rearrangefields-large.png \
		help/images/views2-rearrangefields.png \
		help/images/views2-tablestyle-large.png \
		help/images/views2-tablestyle.png \
		help/about.html help/analyze-theme.html \
		help/api-handlers.html help/api-plugins.html \
		help/api-tables.html help/api.html help/argument.html \
		help/display-attachment.html help/display-block.html \
		help/display-default.html help/display-feed.html \
		help/display-page.html help/display.html help/embed.html \
		help/field.html help/filter.html help/getting-started.html \
		help/menu.html help/new.html help/overrides.html \
		help/path.html help/relationship.html help/sort.html \
		help/style-comment-rss.html help/style-fields.html \
		help/style-grid.html help/style-list.html \
		help/style-node-rss.html help/style-node.html \
		help/style-row.html help/style-rss.html \
		help/style-summary-unformatted.html help/style-summary.html \
		help/style-table.html help/style-unformatted.html \
		help/style.html help/theme-css.html \
		help/updating.html help/using-theme.html \
		help/view-type.html help/views.help.ini \
		images/arrow-active.png images/sprites.png \
		images/status-active.gif \
		includes/admin.inc includes/ajax.inc \
		includes/argument.handlers.inc includes/base.inc \
		includes/cache.inc includes/convert.inc \
		includes/field.handlers.inc includes/filter.handlers.inc \
		includes/form.inc includes/handlers.inc \
		includes/join.handlers.inc includes/plugins.inc \
		includes/query.inc includes/relationship.handlers.inc \
		includes/sort.handlers.inc includes/tabs.inc \
		includes/view.inc js/ajax_view.js js/ajax.js js/dependent.js \
		js/base.js js/tabs.js modules/book.views.inc modules/comment.views.inc \
		modules/comment.views_default.inc modules/node.views.inc \
		modules/node.views_convert.inc modules/node.views_default.inc \
		modules/poll.views.inc modules/profile.views.inc \
		modules/search.views.inc modules/search.views_default.inc \
		modules/statistics.views.inc \
		modules/statistics.views_default.inc \
		modules/system.views.inc modules/taxonomy.views.inc \
		modules/taxonomy.views_default.inc \
		modules/upload.views.inc modules/user.views.inc \
		modules/views.views.inc \
		theme/theme.inc theme/views-exposed-form.tpl.php \
		theme/views-more.tpl.php theme/views-ui-edit-item.tpl.php \
		theme/views-ui-edit-tab.tpl.php theme/views-ui-edit-view.tpl.php \
		theme/views-ui-list-views.tpl.php theme/views-view-field.tpl.php \
		theme/views-view-fields.tpl.php theme/views-view-grid.tpl.php \
		theme/views-view-list.tpl.php theme/views-view-row-comment.tpl.php \
		theme/views-view-row-node.tpl.php theme/views-view-rss.tpl.php \
		theme/views-view-summary-unformatted.tpl.php \
		theme/views-view-summary.tpl.php theme/views-view-table.tpl.php \
		theme/views-view-unformatted.tpl.php \theme/views-view.tpl.php \
		translations/views.pot translations/de.po \
		views_export/views_export.css \
		views_export/views_export.info views_export/views_export.module
DOC_FILES=	LICENSE.txt README.txt CHANGELOG.txt \
		documentation-standards.txt

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/drupal5/bsd.drupal.mk"
.include <bsd.port.post.mk>
