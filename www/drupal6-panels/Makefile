# Created by: anderson@cnpm.embrapa.br
# $FreeBSD$

PORTNAME=	panels
DISTVERSION=	6.x-3.5
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://ftp.drupal.org/files/projects/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Drupal 6.x panels module

USES=		drupal:6,module

MODULE_DIRS=	translations templates plugins/task_handlers \
		plugins/styles/corners plugins/styles \
		plugins/layouts/twocol_stacked \
		plugins/layouts/twocol_bricks \
		plugins/layouts/twocol \
		plugins/layouts/threecol_33_34_33_stacked \
		plugins/layouts/threecol_33_34_33 \
		plugins/layouts/threecol_25_50_25_stacked \
		plugins/layouts/threecol_25_50_25 \
		plugins/layouts/onecol plugins/layouts/flexible \
		plugins/layouts plugins/cache plugins \
		panels_stylizer/plugins/styles \
		panels_stylizer/plugins/style_bases/region/region_rounded_shadow \
		panels_stylizer/plugins/style_bases/region/region_plain_box \
		panels_stylizer/plugins/style_bases/region \
		panels_stylizer/plugins/style_bases/pane/pane_rounded_shadow \
		panels_stylizer/plugins/style_bases/pane/pane_plain_box \
		panels_stylizer/plugins/style_bases/pane \
		panels_stylizer/plugins/style_bases panels_stylizer/plugins \
		panels_stylizer panels_node panels_mini/plugins/content_types \
		panels_mini/plugins panels_mini panels_export \
		js includes images help css

MODULE_FILES=	translations/panels.pot \
		translations/panels.ja.po \
		translations/panels.fr.po \
		translations/panels.de.po \
		templates/panels-pane.tpl.php \
		templates/panels-dashboard.tpl.php \
		plugins/task_handlers/panel_context.inc \
		plugins/styles/naked.inc \
		plugins/styles/list.inc \
		plugins/styles/default.inc \
		plugins/styles/corners/shadow-t.png \
		plugins/styles/corners/shadow-r.png \
		plugins/styles/corners/shadow-l.png \
		plugins/styles/corners/shadow-b.png \
		plugins/styles/corners/rounded_corners.inc \
		plugins/styles/corners/panels-rounded-corners-box.tpl.php \
		plugins/styles/corners/corner-bits.png \
		plugins/styles/block.inc \
		plugins/layouts/twocol_stacked/twocol_stacked.png \
		plugins/layouts/twocol_stacked/twocol_stacked.inc \
		plugins/layouts/twocol_stacked/twocol_stacked.css \
		plugins/layouts/twocol_stacked/panels-twocol-stacked.tpl.php \
		plugins/layouts/twocol_bricks/twocol_bricks.png \
		plugins/layouts/twocol_bricks/twocol_bricks.inc \
		plugins/layouts/twocol_bricks/twocol_bricks.css \
		plugins/layouts/twocol_bricks/panels-twocol-bricks.tpl.php \
		plugins/layouts/twocol/twocol.png \
		plugins/layouts/twocol/twocol.inc \
		plugins/layouts/twocol/twocol.css \
		plugins/layouts/twocol/panels-twocol.tpl.php \
		plugins/layouts/threecol_33_34_33_stacked/threecol_33_34_33_stacked.png \
		plugins/layouts/threecol_33_34_33_stacked/threecol_33_34_33_stacked.inc \
		plugins/layouts/threecol_33_34_33_stacked/threecol_33_34_33_stacked.css \
		plugins/layouts/threecol_33_34_33_stacked/panels-threecol-33-34-33-stacked.tpl.php \
		plugins/layouts/threecol_33_34_33/threecol_33_34_33.png \
		plugins/layouts/threecol_33_34_33/threecol_33_34_33.inc \
		plugins/layouts/threecol_33_34_33/threecol_33_34_33.css \
		plugins/layouts/threecol_33_34_33/panels-threecol-33-34-33.tpl.php \
		plugins/layouts/threecol_25_50_25_stacked/threecol_25_50_25_stacked.png \
		plugins/layouts/threecol_25_50_25_stacked/threecol_25_50_25_stacked.inc \
		plugins/layouts/threecol_25_50_25_stacked/threecol_25_50_25_stacked.css \
		plugins/layouts/threecol_25_50_25_stacked/panels-threecol-25-50-25-stacked.tpl.php \
		plugins/layouts/threecol_25_50_25/threecol_25_50_25.png \
		plugins/layouts/threecol_25_50_25/threecol_25_50_25.inc \
		plugins/layouts/threecol_25_50_25/threecol_25_50_25.css \
		plugins/layouts/threecol_25_50_25/panels-threecol-25-50-25.tpl.php \
		plugins/layouts/onecol/panels-onecol.tpl.php \
		plugins/layouts/onecol/onecol.png \
		plugins/layouts/onecol/onecol.inc \
		plugins/layouts/onecol/onecol.css \
		plugins/layouts/flexible/grippie-vertical.png \
		plugins/layouts/flexible/flexible.png \
		plugins/layouts/flexible/flexible.inc \
		plugins/layouts/flexible/flexible.css \
		plugins/layouts/flexible/flexible-admin.js \
		plugins/layouts/flexible/flexible-admin.css \
		plugins/cache/simple.inc \
		panels_stylizer/plugins/styles/stylizer.inc \
		panels_stylizer/plugins/style_bases/region/region_rounded_shadow/region_rounded_shadow.inc \
		panels_stylizer/plugins/style_bases/region/region_rounded_shadow/region-rounded-shadow.tpl.php \
		panels_stylizer/plugins/style_bases/region/region_rounded_shadow/region-rounded-shadow.css \
		panels_stylizer/plugins/style_bases/region/region_rounded_shadow/icon.png \
		panels_stylizer/plugins/style_bases/region/region_rounded_shadow/box-shadow.png \
		panels_stylizer/plugins/style_bases/region/region_rounded_shadow/box-color.png \
		panels_stylizer/plugins/style_bases/region/region_plain_box/region_plain_box.inc \
		panels_stylizer/plugins/style_bases/region/region_plain_box/region-plain-box.tpl.php \
		panels_stylizer/plugins/style_bases/region/region_plain_box/region-plain-box.css \
		panels_stylizer/plugins/style_bases/region/region_plain_box/icon.png \
		panels_stylizer/plugins/style_bases/pane/pane_rounded_shadow/pane_rounded_shadow.inc \
		panels_stylizer/plugins/style_bases/pane/pane_rounded_shadow/pane-rounded-shadow.tpl.php \
		panels_stylizer/plugins/style_bases/pane/pane_rounded_shadow/pane-rounded-shadow.css \
		panels_stylizer/plugins/style_bases/pane/pane_rounded_shadow/icon.png \
		panels_stylizer/plugins/style_bases/pane/pane_rounded_shadow/box-shadow.png \
		panels_stylizer/plugins/style_bases/pane/pane_rounded_shadow/box-color.png \
		panels_stylizer/plugins/style_bases/pane/pane_plain_box/pane_plain_box.inc \
		panels_stylizer/plugins/style_bases/pane/pane_plain_box/pane-plain-box.tpl.php \
		panels_stylizer/plugins/style_bases/pane/pane_plain_box/pane-plain-box.css \
		panels_stylizer/plugins/style_bases/pane/pane_plain_box/icon.png \
		panels_stylizer/panels_stylizer.module \
		panels_stylizer/panels_stylizer.install \
		panels_stylizer/panels_stylizer.info \
		panels_stylizer/panels_stylizer.admin.inc \
		panels_stylizer/panels-style.js \
		panels_stylizer/panels-style.css \
		panels_node/panels_node.module \
		panels_node/panels_node.install \
		panels_node/panels_node.info \
		panels_mini/plugins/content_types/panels_mini.inc \
		panels_mini/plugins/content_types/icon_panels_mini.png \
		panels_mini/panels_mini.module \
		panels_mini/panels_mini.install \
		panels_mini/panels_mini.info \
		panels_mini/panels_mini.admin.inc \
		panels_export/panels_export.module \
		panels.module \
		panels.install \
		panels.info \
		js/panels.js \
		js/panels-base.js \
		js/layout.js \
		js/display_editor.js \
		includes/plugins.inc \
		includes/display-render.inc \
		includes/display-layout.inc \
		includes/display-edit.inc \
		includes/common.inc \
		includes/callbacks.inc \
		images/user-trash.png \
		images/throbber.gif \
		images/sprite.png \
		images/sky.png \
		images/screenshot-4.jpg \
		images/screenshot-3.jpg \
		images/screenshot-2.jpg \
		images/screenshot-1.jpg \
		images/portlet-expanded.png \
		images/portlet-collapsed.png \
		images/no-icon.png \
		images/icon-showpane.png \
		images/icon-hidepane.png \
		images/icon-draggable.png \
		images/icon-delete.png \
		images/icon-configure.png \
		images/icon-cache.png \
		images/icon-addcontent.png \
		images/go-up.png \
		images/go-right.png \
		images/go-down.png \
		images/delete.png \
		images/close.gif \
		images/blank.gif \
		images/bg-shade-white-lrg.png \
		images/bg-shade-medium.png \
		images/bg-shade-light.png \
		images/bg-shade-dark.png \
		images/bg-content-modal.png \
		images/arrow-down-light.png \
		images/arrow-active.png \
		help/plugin-style.html \
		help/plugin-layout.html \
		help/panels.help.ini \
		help/pane.html \
		help/display.html \
		help/api.html \
		css/panels_page.css \
		css/panels_dnd.css \
		css/panels_admin.css \
		css/panels.css \
		css/panels-dashboard.css

DOC_FILES=	README.txt LICENSE.txt \
		KNOWN_ISSUES.txt INSTALL.txt \
		D6UPDATE.txt CHANGELOG.txt
OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
