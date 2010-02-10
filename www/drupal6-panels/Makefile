# New ports collection makefile for:	drupal6-panels
# Date created:		09 Feb 2010
# Whom:			anderson@cnpm.embrapa.br
#
# $FreeBSD$
#

PORTNAME=	panels
DISTVERSION=	6.x-3.3
CATEGORIES=	www
MASTER_SITES=	http://ftp.drupal.org/files/projects/

MAINTAINER=	anderson@cnpm.embrapa.br
COMMENT=	Drupal 6.x panels module

DRUPAL6_MODULE=	yes

MODULE_DIRS=	translations templates plugins/task_handlers \
		plugins/styles/corners plugins/styles \
		plugins/layouts/twocol_stacked \
		plugins/layouts/twocol_bricks \
		plugins/layouts/twocol \
		plugins/layouts/threecol_33_34_33_stacked \
		plugins/layouts/threecol_33_34_33 \
		plugins/layouts/threecol_25_50_25_stacked \
		plugins/layouts/threecol_25_50_25 \
		plugins/layouts/onecol \
		plugins/layouts/flexible \
		plugins/layouts plugins/cache \
		plugins panels_node \
		panels_mini/plugins/content_types \
		panels_mini/plugins panels_mini \
		panels_export js includes \
		images help docs css

MODULE_FILES=	css/panels-dashboard.css \
		css/panels.css \
		css/panels_admin.css \
		css/panels_dnd.css \
		css/panels_page.css \
		docs/docs.inc \
		docs/doxygen.css \
		docs/sample_plugin_ct.inc \
		panels.info \
		panels.install \
		panels.module \
		panels2.doxy \
		help/api.html \
		help/display.html \
		help/pane.html \
		help/panels.help.ini \
		help/plugin-layout.html \
		help/plugin-style.html \
		images/arrow-active.png \
		images/arrow-down-light.png \
		images/bg-content-modal.png \
		images/bg-shade-dark.png \
		images/bg-shade-light.png \
		images/bg-shade-medium.png \
		images/bg-shade-white-lrg.png \
		images/blank.gif \
		images/close.gif \
		images/delete.png \
		images/go-down.png \
		images/go-right.png \
		images/go-up.png \
		images/icon-addcontent.png \
		images/icon-cache.png \
		images/icon-configure.png \
		images/icon-delete.png \
		images/icon-draggable.png \
		images/no-icon.png \
		images/icon-hidepane.png \
		images/icon-showpane.png \
		images/portlet-collapsed.png \
		images/portlet-expanded.png \
		images/screenshot-1.jpg \
		images/screenshot-2.jpg \
		images/screenshot-3.jpg \
		images/screenshot-4.jpg \
		images/sky.png \
		images/sprite.png \
		images/throbber.gif \
		images/user-trash.png \
		includes/callbacks.inc \
		includes/common.inc \
		includes/display-edit.inc \
		includes/display-layout.inc \
		includes/display-render.inc \
		includes/plugins.inc \
		js/display_editor.js \
		js/layout.js \
		js/panels-base.js \
		js/panels.js \
		panels_export/panels_export.module \
		panels_mini/plugins/content_types/icon_panels_mini.png \
		panels_mini/plugins/content_types/panels_mini.inc \
		panels_mini/panels_mini.admin.inc \
		panels_mini/panels_mini.info \
		panels_mini/panels_mini.install \
		panels_mini/panels_mini.module \
		panels_node/panels_node.info \
		panels_node/panels_node.install \
		panels_node/panels_node.module \
		plugins/cache/simple.inc \
		plugins/layouts/flexible/flexible-admin.css \
		plugins/layouts/flexible/flexible-admin.js \
		plugins/layouts/flexible/flexible.css \
		plugins/layouts/flexible/flexible.inc \
		plugins/layouts/flexible/flexible.png \
		plugins/layouts/flexible/grippie-vertical.png \
		plugins/layouts/onecol/onecol.css \
		plugins/layouts/onecol/onecol.inc \
		plugins/layouts/onecol/onecol.png \
		plugins/layouts/onecol/panels-onecol.tpl.php \
		plugins/layouts/threecol_25_50_25/panels-threecol-25-50-25.tpl.php \
		plugins/layouts/threecol_25_50_25/threecol_25_50_25.css \
		plugins/layouts/threecol_25_50_25/threecol_25_50_25.inc \
		plugins/layouts/threecol_25_50_25/threecol_25_50_25.png \
		plugins/layouts/threecol_25_50_25_stacked/panels-threecol-25-50-25-stacked.tpl.php \
		plugins/layouts/threecol_25_50_25_stacked/threecol_25_50_25_stacked.css \
		plugins/layouts/threecol_25_50_25_stacked/threecol_25_50_25_stacked.inc \
		plugins/layouts/threecol_25_50_25_stacked/threecol_25_50_25_stacked.png \
		plugins/layouts/threecol_33_34_33/panels-threecol-33-34-33.tpl.php \
		plugins/layouts/threecol_33_34_33/threecol_33_34_33.css \
		plugins/layouts/threecol_33_34_33/threecol_33_34_33.inc \
		plugins/layouts/threecol_33_34_33/threecol_33_34_33.png \
		plugins/layouts/threecol_33_34_33_stacked/panels-threecol-33-34-33-stacked.tpl.php \
		plugins/layouts/threecol_33_34_33_stacked/threecol_33_34_33_stacked.css \
		plugins/layouts/threecol_33_34_33_stacked/threecol_33_34_33_stacked.inc \
		plugins/layouts/threecol_33_34_33_stacked/threecol_33_34_33_stacked.png \
		plugins/layouts/twocol/panels-twocol.tpl.php \
		plugins/layouts/twocol/twocol.css \
		plugins/layouts/twocol/twocol.inc \
		plugins/layouts/twocol/twocol.png \
		plugins/layouts/twocol_bricks/panels-twocol-bricks.tpl.php \
		plugins/layouts/twocol_bricks/twocol_bricks.css \
		plugins/layouts/twocol_bricks/twocol_bricks.inc \
		plugins/layouts/twocol_bricks/twocol_bricks.png \
		plugins/layouts/twocol_stacked/panels-twocol-stacked.tpl.php \
		plugins/layouts/twocol_stacked/twocol_stacked.css \
		plugins/layouts/twocol_stacked/twocol_stacked.inc \
		plugins/layouts/twocol_stacked/twocol_stacked.png \
		plugins/styles/corners/corner-bits.png \
		plugins/styles/corners/panels-rounded-corners-box.tpl.php \
		plugins/styles/corners/rounded_corners.inc \
		plugins/styles/corners/shadow-b.png \
		plugins/styles/corners/shadow-l.png \
		plugins/styles/corners/shadow-r.png \
		plugins/styles/corners/shadow-t.png \
		plugins/styles/block.inc \
		plugins/styles/default.inc \
		plugins/styles/list.inc \
		plugins/styles/naked.inc \
		plugins/task_handlers/panel_context.inc \
		templates/panels-dashboard.tpl.php \
		templates/panels-pane.tpl.php \
		translations/panels.de.po \
		translations/panels.fr.po \
		translations/panels.ja.po \
		translations/panels.pot \

DOC_FILES=	D6UPDATE.txt API.txt CHANGELOG.txt INSTALL.txt \
		KNOWN_ISSUES.txt README.txt TODO.txt LICENSE.txt

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/drupal5/bsd.drupal.mk"
.include <bsd.port.post.mk>
