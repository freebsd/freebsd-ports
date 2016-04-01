# Created by: Nick Hilliard <nick@foobar.org>
# $FreeBSD$

PORTNAME=	wysiwyg
DISTVERSION=	7.x-2.0
CATEGORIES=	www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Allows implementation of WYSIWYG editors for editing Drupal content

#LICENSE from bsd.drupal.mk

USES=		drupal:7,module

OPTIONS_DEFINE=	TINYMCE3 CKEDITOR YUI DOCS

TINYMCE3_DESC=	Install TinyMCE3 Editor
CKEDITOR_DESC=	Install CKEditor
YUI_DESC=	Install Yahoo UI Editor

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTINYMCE3}
RUN_DEPENDS+=	${LOCALBASE}/www/tinymce:www/tinymce3
PLIST_FILES+=	${DRUPAL_MODLIB}/tinymce
.endif

.if ${PORT_OPTIONS:MCKEDITOR}
RUN_DEPENDS+=	${LOCALBASE}/www/ckeditor:www/ckeditor
PLIST_FILES+=	${DRUPAL_MODLIB}/ckeditor
.endif

.if ${PORT_OPTIONS:MYUI}
RUN_DEPENDS+=	${LOCALBASE}/www/yui:www/yahoo-ui
PLIST_FILES+=	${DRUPAL_MODLIB}/yui
.endif

MODULE_FILES=	editors/css/openwysiwyg.css \
		editors/css/tinymce-2.css \
		editors/css/tinymce-3.css \
		editors/js/ckeditor-3.0.js \
		editors/js/fckeditor-2.6.js \
		editors/js/fckeditor.config.js \
		editors/js/jwysiwyg.js \
		editors/js/markitup.js \
		editors/js/nicedit.js \
		editors/js/none.js \
		editors/js/openwysiwyg.js \
		editors/js/tinymce-2.js \
		editors/js/tinymce-3.js \
		editors/js/whizzywig-56.js \
		editors/js/whizzywig-60.js \
		editors/js/whizzywig.js \
		editors/js/wymeditor.js \
		editors/js/yui.js \
		editors/ckeditor.inc \
		editors/fckeditor.inc \
		editors/jwysiwyg.inc \
		editors/markitup.inc \
		editors/nicedit.inc \
		editors/openwysiwyg.inc \
		editors/tinymce.inc \
		editors/whizzywig.inc \
		editors/wymeditor.inc \
		editors/yui.inc \
		wysiwyg-dialog-page.tpl.php \
		wysiwyg.admin.inc \
		wysiwyg.api.js \
		wysiwyg.api.php \
		wysiwyg.dialog.inc \
		wysiwyg.info \
		wysiwyg.init.js \
		wysiwyg.install \
		wysiwyg.js \
		wysiwyg.module \
		plugins/break/images/break.gif \
		plugins/break/images/breaktext.gif \
		plugins/break/images/spacer.gif \
		plugins/break/break.css \
		plugins/break/break.js \
		plugins/break/langs/ca.js \
		plugins/break/langs/de.js \
		plugins/break/langs/en.js \
		plugins/break/langs/es.js \
		plugins/break.inc \
		translations/wysiwyg.pot \
		translations/da.po \
		translations/de.po \
		translations/el.po \
		translations/fi.po \
		translations/fr.po \
		translations/hu.po \
		translations/tr.po \
		translations/uk.po

MODULE_DIRS=	editors/css editors/js editors plugins/break/images \
		plugins/break/langs plugins/break plugins translations

DOC_FILES=	CHANGELOG.txt README.txt LICENSE.txt

post-install:
.if ${PORT_OPTIONS:MTINYMCE3}
	${LN} -fs ${PREFIX}/www/tinymce ${STAGEDIR}${PREFIX}/${DRUPAL_MODLIB}
.endif
.if ${PORT_OPTIONS:MCKEDITOR}
	${LN} -fs ${PREFIX}/www/CKEditor ${STAGEDIR}${PREFIX}/${DRUPAL_MODLIB}/ckeditor
.endif
.if ${PORT_OPTIONS:MYUI}
	${LN} -fs ${PREFIX}/www/yahoo ${STAGEDIR}${PREFIX}/${DRUPAL_MODLIB}/yui
.endif

.include <bsd.port.mk>
