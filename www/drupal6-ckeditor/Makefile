# Created by: Anderson Soares Ferreira <anderson@cnpm.embrapa.br>
# $FreeBSD$

PORTNAME=	ckeditor
DISTVERSION=	6.x-1.1
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://ftp.drupal.org/files/projects/:1 \
		http://download.cksource.com/CKEditor/CKEditor/CKEditor%203.3/:2
DISTFILES=	ckeditor-6.x-1.1.tar.gz:1 \
		ckeditor_3.3.tar.gz:2
EXTRACT_ONLY=	ckeditor-6.x-1.1.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Drupal 6.x Ckeditor WYSIWYG HTML editor

USES=		drupal:6,module

MODULE_DIRS=	translations plugins/mediaembed/images \
		plugins/mediaembed plugins/linktonode/jscripts \
		plugins/linktonode/images plugins/linktonode/dialogs \
		plugins/linktonode/css plugins/linktonode \
		plugins/linktomenu/jscripts plugins/linktomenu/images \
		plugins/linktomenu/dialogs plugins/linktomenu/css \
		plugins/linktomenu plugins/imce/images \
		plugins/imce plugins/drupalbreaks/images \
		plugins/drupalbreaks plugins \
		includes ckeditor/themes/default \
		ckeditor/themes ckeditor/skins/v2/images \
		ckeditor/skins/v2 ckeditor/skins/office2003/images \
		ckeditor/skins/office2003 ckeditor/skins/kama/images \
		ckeditor/skins/kama ckeditor/skins \
		ckeditor/plugins/wsc/dialogs ckeditor/plugins/wsc \
		ckeditor/plugins/uicolor/yui/assets ckeditor/plugins/uicolor/yui \
		ckeditor/plugins/uicolor/lang ckeditor/plugins/uicolor/dialogs \
		ckeditor/plugins/uicolor ckeditor/plugins/templates/templates/images \
		ckeditor/plugins/templates/templates ckeditor/plugins/templates/dialogs \
		ckeditor/plugins/templates ckeditor/plugins/tabletools/dialogs \
		ckeditor/plugins/tabletools ckeditor/plugins/table/dialogs \
		ckeditor/plugins/table ckeditor/plugins/styles/styles \
		ckeditor/plugins/styles ckeditor/plugins/specialchar/dialogs \
		ckeditor/plugins/specialchar ckeditor/plugins/smiley/images \
		ckeditor/plugins/smiley/dialogs ckeditor/plugins/smiley \
		ckeditor/plugins/showblocks/images ckeditor/plugins/showblocks \
		ckeditor/plugins/scayt/dialogs ckeditor/plugins/scayt \
		ckeditor/plugins/pastetext/dialogs ckeditor/plugins/pastetext \
		ckeditor/plugins/pastefromword/filter ckeditor/plugins/pastefromword \
		ckeditor/plugins/pagebreak/images ckeditor/plugins/pagebreak \
		ckeditor/plugins/liststyle/dialogs ckeditor/plugins/liststyle \
		ckeditor/plugins/link/images ckeditor/plugins/link/dialogs \
		ckeditor/plugins/link ckeditor/plugins/image/dialogs \
		ckeditor/plugins/image ckeditor/plugins/iframedialog \
		ckeditor/plugins/forms/images ckeditor/plugins/forms/dialogs \
		ckeditor/plugins/forms ckeditor/plugins/flash/images \
		ckeditor/plugins/flash/dialogs ckeditor/plugins/flash \
		ckeditor/plugins/find/dialogs ckeditor/plugins/find \
		ckeditor/plugins/div/dialogs ckeditor/plugins/div \
		ckeditor/plugins/dialog ckeditor/plugins/colordialog/dialogs \
		ckeditor/plugins/colordialog ckeditor/plugins/clipboard/dialogs \
		ckeditor/plugins/clipboard ckeditor/plugins/about/dialogs \
		ckeditor/plugins/about ckeditor/plugins/a11yhelp/lang \
		ckeditor/plugins/a11yhelp/dialogs ckeditor/plugins/a11yhelp \
		ckeditor/plugins ckeditor/lang \
		ckeditor/images ckeditor/adapters ckeditor

MODULE_FILES=	translations/fr.po translations/es.po translations/de.po \
		translations/ckeditor.pot \
		plugins/mediaembed/plugin.js \
		plugins/mediaembed/images/placeholder.gif \
		plugins/mediaembed/images/icon.gif \
		plugins/linktonode/plugin.js \
		plugins/linktonode/jscripts/functions.js \
		plugins/linktonode/images/loading.gif \
		plugins/linktonode/images/linktonode.gif \
		plugins/linktonode/images/descendant.gif \
		plugins/linktonode/dialogs/link.js \
		plugins/linktonode/css/linktocontent.css \
		plugins/linktomenu/plugin.js \
		plugins/linktomenu/jscripts/functions.js \
		plugins/linktomenu/images/loading.gif \
		plugins/linktomenu/images/linktomenu.gif \
		plugins/linktomenu/images/descendant.gif \
		plugins/linktomenu/dialogs/link.js \
		plugins/linktomenu/css/linktocontent.css \
		plugins/imce/plugin.js \
		plugins/imce/images/icon.gif \
		plugins/drupalbreaks/plugin.js \
		plugins/drupalbreaks/images/pagebreak.gif \
		plugins/drupalbreaks/images/drupalpagebreak.gif \
		plugins/drupalbreaks/images/drupalbreak.gif \
		includes/filemanager.config.php \
		includes/ckeditor.utils.js \
		includes/ckeditor.user.inc \
		includes/ckeditor.popup.html \
		includes/ckeditor.page.inc \
		includes/ckeditor.lib.inc \
		includes/ckeditor.drush.inc \
		includes/ckeditor.admin.js \
		includes/ckeditor.admin.inc \
		ckeditor/themes/default/theme.js \
		ckeditor/skins/v2/templates.css \
		ckeditor/skins/v2/skin.js \
		ckeditor/skins/v2/images/toolbar_start.gif \
		ckeditor/skins/v2/images/sprites_ie6.png \
		ckeditor/skins/v2/images/sprites.png \
		ckeditor/skins/v2/images/noimage.png \
		ckeditor/skins/v2/images/mini.gif \
		ckeditor/skins/v2/images/dialog_sides_rtl.png \
		ckeditor/skins/v2/images/dialog_sides.png \
		ckeditor/skins/v2/images/dialog_sides.gif \
		ckeditor/skins/v2/icons.png \
		ckeditor/skins/v2/editor.css \
		ckeditor/skins/v2/dialog.css \
		ckeditor/skins/office2003/templates.css \
		ckeditor/skins/office2003/skin.js \
		ckeditor/skins/office2003/images/sprites_ie6.png \
		ckeditor/skins/office2003/images/sprites.png \
		ckeditor/skins/office2003/images/noimage.png \
		ckeditor/skins/office2003/images/mini.gif \
		ckeditor/skins/office2003/images/dialog_sides_rtl.png \
		ckeditor/skins/office2003/images/dialog_sides.png \
		ckeditor/skins/office2003/images/dialog_sides.gif \
		ckeditor/skins/office2003/icons.png \
		ckeditor/skins/office2003/editor.css \
		ckeditor/skins/office2003/dialog.css \
		ckeditor/skins/kama/templates.css \
		ckeditor/skins/kama/skin.js \
		ckeditor/skins/kama/images/toolbar_start.gif \
		ckeditor/skins/kama/images/sprites_ie6.png \
		ckeditor/skins/kama/images/sprites.png \
		ckeditor/skins/kama/images/noimage.png \
		ckeditor/skins/kama/images/mini.gif \
		ckeditor/skins/kama/images/dialog_sides_rtl.png \
		ckeditor/skins/kama/images/dialog_sides.png \
		ckeditor/skins/kama/images/dialog_sides.gif \
		ckeditor/skins/kama/icons.png \
		ckeditor/skins/kama/editor.css \
		ckeditor/skins/kama/dialog.css \
		ckeditor/plugins/wsc/dialogs/wsc.js \
		ckeditor/plugins/wsc/dialogs/wsc.css \
		ckeditor/plugins/wsc/dialogs/tmpFrameset.html \
		ckeditor/plugins/wsc/dialogs/ciframe.html \
		ckeditor/plugins/uicolor/yui/yui.js \
		ckeditor/plugins/uicolor/yui/assets/yui.css \
		ckeditor/plugins/uicolor/yui/assets/picker_thumb.png \
		ckeditor/plugins/uicolor/yui/assets/picker_mask.png \
		ckeditor/plugins/uicolor/yui/assets/hue_thumb.png \
		ckeditor/plugins/uicolor/yui/assets/hue_bg.png \
		ckeditor/plugins/uicolor/uicolor.gif \
		ckeditor/plugins/uicolor/plugin.js \
		ckeditor/plugins/uicolor/lang/en.js \
		ckeditor/plugins/uicolor/dialogs/uicolor.js \
		ckeditor/plugins/templates/templates/images/template3.gif \
		ckeditor/plugins/templates/templates/images/template2.gif \
		ckeditor/plugins/templates/templates/images/template1.gif \
		ckeditor/plugins/templates/templates/default.js \
		ckeditor/plugins/templates/dialogs/templates.js \
		ckeditor/plugins/tabletools/dialogs/tableCell.js \
		ckeditor/plugins/table/dialogs/table.js \
		ckeditor/plugins/styles/styles/default.js \
		ckeditor/plugins/specialchar/dialogs/specialchar.js \
		ckeditor/plugins/smiley/images/wink_smile.gif \
		ckeditor/plugins/smiley/images/whatchutalkingabout_smile.gif \
		ckeditor/plugins/smiley/images/tounge_smile.gif \
		ckeditor/plugins/smiley/images/thumbs_up.gif \
		ckeditor/plugins/smiley/images/thumbs_down.gif \
		ckeditor/plugins/smiley/images/teeth_smile.gif \
		ckeditor/plugins/smiley/images/shades_smile.gif \
		ckeditor/plugins/smiley/images/sad_smile.gif \
		ckeditor/plugins/smiley/images/regular_smile.gif \
		ckeditor/plugins/smiley/images/omg_smile.gif \
		ckeditor/plugins/smiley/images/lightbulb.gif \
		ckeditor/plugins/smiley/images/kiss.gif \
		ckeditor/plugins/smiley/images/heart.gif \
		ckeditor/plugins/smiley/images/envelope.gif \
		ckeditor/plugins/smiley/images/embaressed_smile.gif \
		ckeditor/plugins/smiley/images/devil_smile.gif \
		ckeditor/plugins/smiley/images/cry_smile.gif \
		ckeditor/plugins/smiley/images/confused_smile.gif \
		ckeditor/plugins/smiley/images/broken_heart.gif \
		ckeditor/plugins/smiley/images/angry_smile.gif \
		ckeditor/plugins/smiley/images/angel_smile.gif \
		ckeditor/plugins/smiley/dialogs/smiley.js \
		ckeditor/plugins/showblocks/images/block_pre.png \
		ckeditor/plugins/showblocks/images/block_p.png \
		ckeditor/plugins/showblocks/images/block_h6.png \
		ckeditor/plugins/showblocks/images/block_h5.png \
		ckeditor/plugins/showblocks/images/block_h4.png \
		ckeditor/plugins/showblocks/images/block_h3.png \
		ckeditor/plugins/showblocks/images/block_h2.png \
		ckeditor/plugins/showblocks/images/block_h1.png \
		ckeditor/plugins/showblocks/images/block_div.png \
		ckeditor/plugins/showblocks/images/block_blockquote.png \
		ckeditor/plugins/showblocks/images/block_address.png \
		ckeditor/plugins/scayt/dialogs/toolbar.css \
		ckeditor/plugins/scayt/dialogs/options.js \
		ckeditor/plugins/pastetext/dialogs/pastetext.js \
		ckeditor/plugins/pastefromword/filter/default.js \
		ckeditor/plugins/pagebreak/images/pagebreak.gif \
		ckeditor/plugins/liststyle/plugin.js \
		ckeditor/plugins/liststyle/dialogs/liststyle.js \
		ckeditor/plugins/link/images/anchor.gif \
		ckeditor/plugins/link/dialogs/link.js \
		ckeditor/plugins/link/dialogs/anchor.js \
		ckeditor/plugins/image/dialogs/image.js \
		ckeditor/plugins/iframedialog/plugin.js \
		ckeditor/plugins/forms/images/hiddenfield.gif \
		ckeditor/plugins/forms/dialogs/textfield.js \
		ckeditor/plugins/forms/dialogs/textarea.js \
		ckeditor/plugins/forms/dialogs/select.js \
		ckeditor/plugins/forms/dialogs/radio.js \
		ckeditor/plugins/forms/dialogs/hiddenfield.js \
		ckeditor/plugins/forms/dialogs/form.js \
		ckeditor/plugins/forms/dialogs/checkbox.js \
		ckeditor/plugins/forms/dialogs/button.js \
		ckeditor/plugins/flash/images/placeholder.png \
		ckeditor/plugins/flash/dialogs/flash.js \
		ckeditor/plugins/find/dialogs/find.js \
		ckeditor/plugins/div/dialogs/div.js \
		ckeditor/plugins/dialog/dialogDefinition.js \
		ckeditor/plugins/colordialog/dialogs/colordialog.js \
		ckeditor/plugins/clipboard/dialogs/paste.js \
		ckeditor/plugins/about/dialogs/logo_ckeditor.png \
		ckeditor/plugins/about/dialogs/about.js \
		ckeditor/plugins/a11yhelp/lang/he.js \
		ckeditor/plugins/a11yhelp/lang/en.js \
		ckeditor/plugins/a11yhelp/dialogs/a11yhelp.js \
		ckeditor/lang/zh.js \
		ckeditor/lang/zh-cn.js \
		ckeditor/lang/vi.js \
		ckeditor/lang/uk.js \
		ckeditor/lang/tr.js \
		ckeditor/lang/th.js \
		ckeditor/lang/sv.js \
		ckeditor/lang/sr.js \
		ckeditor/lang/sr-latn.js \
		ckeditor/lang/sl.js \
		ckeditor/lang/sk.js \
		ckeditor/lang/ru.js \
		ckeditor/lang/ro.js \
		ckeditor/lang/pt.js \
		ckeditor/lang/pt-br.js \
		ckeditor/lang/pl.js \
		ckeditor/lang/no.js \
		ckeditor/lang/nl.js \
		ckeditor/lang/nb.js \
		ckeditor/lang/ms.js \
		ckeditor/lang/mn.js \
		ckeditor/lang/lv.js \
		ckeditor/lang/lt.js \
		ckeditor/lang/ko.js \
		ckeditor/lang/km.js \
		ckeditor/lang/ja.js \
		ckeditor/lang/it.js \
		ckeditor/lang/is.js \
		ckeditor/lang/hu.js \
		ckeditor/lang/hr.js \
		ckeditor/lang/hi.js \
		ckeditor/lang/he.js \
		ckeditor/lang/gu.js \
		ckeditor/lang/gl.js \
		ckeditor/lang/fr.js \
		ckeditor/lang/fr-ca.js \
		ckeditor/lang/fo.js \
		ckeditor/lang/fi.js \
		ckeditor/lang/fa.js \
		ckeditor/lang/eu.js \
		ckeditor/lang/et.js \
		ckeditor/lang/es.js \
		ckeditor/lang/eo.js \
		ckeditor/lang/en.js \
		ckeditor/lang/en-gb.js \
		ckeditor/lang/en-ca.js \
		ckeditor/lang/en-au.js \
		ckeditor/lang/el.js \
		ckeditor/lang/de.js \
		ckeditor/lang/da.js \
		ckeditor/lang/cy.js \
		ckeditor/lang/cs.js \
		ckeditor/lang/ca.js \
		ckeditor/lang/bs.js \
		ckeditor/lang/bn.js \
		ckeditor/lang/bg.js \
		ckeditor/lang/ar.js \
		ckeditor/lang/af.js \
		ckeditor/lang/_translationstatus.txt \
		ckeditor/lang/_languages.js \
		ckeditor/images/spacer.gif \
		ckeditor/contents.css \
		ckeditor/config.js \
		ckeditor/ckeditor_source.js \
		ckeditor/ckeditor_php5.php \
		ckeditor/ckeditor_php4.php \
		ckeditor/ckeditor_basic_source.js \
		ckeditor/ckeditor_basic.js \
		ckeditor/ckeditor.php \
		ckeditor/ckeditor.pack \
		ckeditor/ckeditor.js \
		ckeditor/ckeditor.asp \
		ckeditor/adapters/jquery.js \
		ckeditor/.htaccess \
		ckeditor.styles.js \
		ckeditor.module \
		ckeditor.install \
		ckeditor.info \
		ckeditor.css \
		ckeditor.config.js

DOC_DIRS=	ckeditor

DOC_FILES=	ckeditor/LICENSE.html ckeditor/INSTALL.html \
		ckeditor/CHANGES.html \
		TROUBLESHOOTING.txt README.txt \
		LICENSE.txt CHANGELOG.txt

OPTIONS_DEFINE=	DOCS

post-extract:
	@cd ${WRKSRC} && ${TAR} xf ${DISTDIR}/${DIST_SUBDIR}/ckeditor_3.3.tar.gz

.include <bsd.port.mk>
