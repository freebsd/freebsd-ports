# New ports collection makefile for:	drupal5-gsitemap
# Date created:				26 Mar 2007
# Whom:					Nick Hilliard <nick@foobar.org>
#
# $FreeBSD$
#

PORTNAME=	tinymce
DISTVERSION=	5.x-1.x-dev
PORTREVISION=	20070306
CATEGORIES=	www
MASTER_SITE_SUBDIR=	pav/drupal

MAINTAINER=	nick@foobar.org
COMMENT=	A Drupal module which implements the TinyMCE WYSIWYG editor for content editing

TINYMCEDIR=	www/tinymce
TINYMCE_MODDIR=	${PORTNAME:C|^|${DRUPAL_MODDIR}/|}

RUN_DEPENDS+=	${PREFIX}/${TINYMCEDIR}/jscripts/tiny_mce/tiny_mce.js:${PORTSDIR}/www/tinymce

SUB_FILES+=	pkg-message
SUB_LIST+=	TINYMCEDIR="${PREFIX}/${TINYMCEDIR}" \
		TINYMCE_MODDIR="${TINYMCE_MODDIR:C|^|${PREFIX}/|}"

DRUPAL5_MODULE=	yes

MODULE_DIRS=	plugins/drupalbreak/images plugins/drupalbreak/langs \
		plugins/drupalbreak plugins themes

MODULE_FILES=	plugins/drupalbreak/images/drupalbreak.gif \
		plugins/drupalbreak/images/drupalbreaktext.gif \
		plugins/drupalbreak/images/drupalpagebreak.gif \
		plugins/drupalbreak/images/drupalpagebreaktext.gif \
		plugins/drupalbreak/README.txt \
		plugins/drupalbreak/drupalbreak.css \
		plugins/drupalbreak/editor_plugin.js \
		plugins/drupalbreak/editor_plugin_src.js \
		plugins/drupalbreak/langs/en.js themes/tinymce_compact.js \
		themes/tinymce_full.js themes/tinymce_simple.js \
		plugin_reg.php tinymce.info tinymce.install tinymce.module
DOC_FILES=	CHANGELOG.TXT INSTALL.txt LICENSE.txt README.TXT

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/drupal5/bsd.drupal.mk"
.include <bsd.port.post.mk>
