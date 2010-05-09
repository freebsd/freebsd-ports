# New ports collection makefile for:	drupal5-gsitemap
# Date created:				26 Mar 2007
# Whom:					Nick Hilliard <nick@foobar.org>
#
# $FreeBSD$
#

PORTNAME=	tinymce
DISTVERSION=	5.x-1.11
CATEGORIES=	www

MAINTAINER=	nick@foobar.org
COMMENT=	A Drupal module which implements the TinyMCE WYSIWYG content editor

TINYMCEDIR=	www/tinymce
TINYMCE_MODDIR=	${PORTNAME:C|^|${DRUPAL_MODDIR}/|}

RUN_DEPENDS+=	${LOCALBASE}/${TINYMCEDIR}/jscripts/tiny_mce/tiny_mce.js:${PORTSDIR}/www/tinymce

PLIST_FILES+=	${DRUPAL_MODDIR}/tinymce

DRUPAL5_MODULE=	yes

MODULE_DIRS=	plugins/drupalbreak/images plugins/drupalbreak/langs \
		plugins/drupalbreak plugins po themes

MODULE_FILES=	plugin_reg.php \
		plugins/drupalbreak/README.txt \
		plugins/drupalbreak/drupalbreak.css \
		plugins/drupalbreak/editor_plugin.js \
		plugins/drupalbreak/editor_plugin_src.js \
		plugins/drupalbreak/images/drupalbreak.gif \
		plugins/drupalbreak/images/drupalbreaktext.gif \
		plugins/drupalbreak/images/drupalpagebreak.gif \
		plugins/drupalbreak/images/drupalpagebreaktext.gif \
		plugins/drupalbreak/langs/en.js \
		po/da.po \
		po/de.po \
		po/el.po \
		po/fr.po \
		po/hu.po \
		po/tinymce.pot \
		po/tr.po \
		themes/tinymce_compact.js \
		themes/tinymce_full.js \
		themes/tinymce_simple.js \
		tinymce.info \
		tinymce.install \
		tinymce.module

DOC_FILES=	CHANGELOG.TXT INSTALL.txt LICENSE.txt README.TXT

post-install:
	@${LN} -s ${PREFIX}/${TINYMCEDIR} ${PREFIX}/${TINYMCE_MODDIR}

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/drupal5/bsd.drupal.mk"
.include <bsd.port.post.mk>
