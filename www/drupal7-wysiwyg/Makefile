# Ports collection makefile for:	drupal7-wysiwyg
# Date created:				2 June 2009
# Whom:					Nick Hilliard <nick@foobar.org>
#
# $FreeBSD$
#

PORTNAME=	wysiwyg
DISTVERSION=	7.x-2.0
CATEGORIES=	www

MAINTAINER=	nick@foobar.org
COMMENT=	Allows implementation of WYSIWYG editors for editing Drupal content

#LICENSE from bsd.drupal.mk

OPTIONS=	TINYMCE3	"Install TinyMCE3 Editor" off \
		CKEDITOR	"Install CKEditor" off \
		YUI		"Install Yahoo UI Editor" off

.include <bsd.port.options.mk>

.if defined(WITH_TINYMCE3)
RUN_DEPENDS+=	${LOCALBASE}/www/tinymce:${PORTSDIR}/www/tinymce3
PLIST_FILES+=	${DRUPAL_MODLIB}/tinymce
.endif

.if defined(WITH_CKEDITOR)
RUN_DEPENDS+=	${LOCALBASE}/www/ckeditor:${PORTSDIR}/www/ckeditor
PLIST_FILES+=	${DRUPAL_MODLIB}/ckeditor
.endif

.if defined(WITH_YUI)
RUN_DEPENDS+=	${LOCALBASE}/www/yui:${PORTSDIR}/www/yahoo-ui
PLIST_FILES+=	${DRUPAL_MODLIB}/yui
.endif

DRUPAL_MODULE=	yes
DRUPAL_VERSION=	7
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
.if defined(WITH_TINYMCE3)
	${LN} -fs ${PREFIX}/www/tinymce ${PREFIX}/${DRUPAL_MODLIB}
.endif
.if defined(WITH_CKEDITOR)
	${LN} -fs ${PREFIX}/www/CKEditor ${PREFIX}/${DRUPAL_MODLIB}/ckeditor
.endif
.if defined(WITH_YUI)
	${LN} -fs ${PREFIX}/www/yahoo ${PREFIX}/${DRUPAL_MODLIB}/yui
.endif

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/Mk/bsd.drupal.mk"
.include <bsd.port.post.mk>
