# Created by: Nick Hilliard <nick@foobar.org>
# $FreeBSD$

PORTNAME=	wysiwyg
DISTVERSION=	7.x-2.3
PORTREVISION=	1
CATEGORIES=	www

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Allows implementation of WYSIWYG editors for editing Drupal content

LICENSE=	GPLv2

USES=		drupal:7,module

MODULE_FILES=	editors/css/tinymce-3.css \
		editors/css/tinymce-4.css \
		editors/js/ckeditor-3.0.js \
		editors/js/epiceditor.js \
		editors/js/fckeditor-2.6.js \
		editors/js/fckeditor.config.js \
		editors/js/jwysiwyg.js \
		editors/js/markitup.js \
		editors/js/nicedit.js \
		editors/js/none.js \
		editors/js/tinymce-3.js \
		editors/js/tinymce-4.js \
		editors/js/whizzywig-56.js \
		editors/js/whizzywig-60.js \
		editors/js/whizzywig.js \
		editors/js/wymeditor.js \
		editors/js/yui.js \
		editors/ckeditor.inc \
		editors/epiceditor.inc \
		editors/fckeditor.inc \
		editors/jwysiwyg.inc \
		editors/markitup.inc \
		editors/nicedit.inc \
		editors/tinymce.inc \
		editors/whizzywig.inc \
		editors/wymeditor.inc \
		editors/yui.inc \
		wysiwyg-dialog-page.tpl.php \
		wysiwyg.admin.inc \
		wysiwyg.api.js \
		wysiwyg.api.php \
		wysiwyg.dialog.inc \
		wysiwyg.features.inc \
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
		plugins/break.inc

MODULE_DIRS=	editors/css editors/js editors plugins/break/images \
		plugins/break/langs plugins/break plugins

DOC_FILES=	CHANGELOG.txt README.txt LICENSE.txt

OPTIONS_DEFINE=	TINYMCE CKEDITOR DOCS

CKEDITOR_DESC=	Install CKEditor
CKEDITOR_RUN_DEPENDS=	CKEditor>0:www/ckeditor
CKEDITOR_PLIST_FILES=	${DRUPAL_MODLIB}/ckeditor

TINYMCE_DESC=	Install TinyMCE Editor
TINYMCE_RUN_DEPENDS=	tinymce>0:www/tinymce
TINYMCE_PLIST_FILES=	${DRUPAL_MODLIB}/tinymce

post-install-TINYMCE-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${DRUPAL_MODLIB}
	${LN} -fs ${PREFIX}/www/tinymce ${STAGEDIR}${PREFIX}/${DRUPAL_MODLIB}

post-install-CKEDITOR-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${DRUPAL_MODLIB}
	${LN} -fs ${PREFIX}/www/CKEditor ${STAGEDIR}${PREFIX}/${DRUPAL_MODLIB}/ckeditor

.include <bsd.port.mk>
