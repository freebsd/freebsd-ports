# New ports collection makefile for:	drupal6-wysiwyg
# Date created:				2 June 2009
# Whom:					Nick Hilliard <nick@foobar.org>
#
# $FreeBSD$
#

PORTNAME=	wysiwyg
DISTVERSION=	6.x-2.0-alpha1
CATEGORIES=	www

MAINTAINER=	nick@foobar.org
COMMENT=	Allows implementation of WYSIWYG editors for editing Drupal content

TINYMCEDIR=	www/tinymce

# we support either tinymce2 or tinymce3
RUN_DEPENDS+=	${LOCALBASE}/${TINYMCEDIR}:${PORTSDIR}/www/tinymce3

PLIST_FILES+=	${DRUPAL_MODDIR}/tinymce

DRUPAL6_MODULE=	yes
MODULE_FILES=	editors/css/markitup-1.css \
		editors/css/tinymce-2.css \
		editors/css/tinymce-3.css \
		editors/js/fckeditor-2.6.js \
		editors/js/fckeditor.config.js \
		editors/js/jwysiwyg.js \
		editors/js/markitup.js \
		editors/js/nicedit.js \
		editors/js/none.js \
		editors/js/tinymce-2.js \
		editors/js/tinymce-3.js \
		editors/js/whizzywig.js \
		editors/js/yui.js \
		editors/fckeditor.inc \
		editors/jwysiwyg.inc \
		editors/markitup.inc \
		editors/nicedit.inc \
		editors/tinymce.inc \
		editors/whizzywig.inc \
		editors/yui.inc \
		wysiwyg-dialog-page.tpl.php \
		wysiwyg.admin.inc \
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
		translations/fr.po \
		translations/hu.po \
		translations/sv.po \
		translations/tr.po

MODULE_DIRS=	editors/css editors/js editors plugins/break/images \
		plugins/break/langs plugins/break plugins translations

DOC_FILES=	CHANGELOG.txt README.txt LICENSE.txt

post-install:
	${LN} -s ${PREFIX}/${TINYMCEDIR} ${PREFIX}/${DRUPAL_MODDIR}

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/drupal5/bsd.drupal.mk"
.include <bsd.port.post.mk>
