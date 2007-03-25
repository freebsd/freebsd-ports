# New ports collection makefile for:	drupal-i18n
# Date created:				26 Jan 2007
# Whom:					Nick Hilliard <nick@foobar.org>
#
# $FreeBSD$
#

PORTNAME=	i18n
DISTVERSION=	4.7.x-1.0
PORTREVISION=	20061208
CATEGORIES=	www security
MASTER_SITE_SUBDIR=	pav/drupal

MAINTAINER=	nick@foobar.org
COMMENT=	An internationalisation module for the Drupal CMS

DRUPAL_MODULE=	yes
DRUPAL_MODSUBDIR=	i18n
MODULE_FILES=	translation.module i18n.module i18n.install i18n.inc \
		i18nprofile/i18nprofile.install \
		i18nprofile/i18nprofile.module \
		flags/ca.png flags/cs.png flags/de.png flags/en.png \
		flags/es.png flags/eu.png flags/fi.png flags/fr.png \
		flags/gl.png flags/he.png flags/hu.png flags/it.png \
		flags/ja.png flags/km.png flags/nl.png flags/ru.png \
		flags/sk.png flags/sv.png

MODULE_DIRS=	flags i18nprofile
DOC_FILES=	CHANGELOG.txt CREDITS.txt HOWTO.txt INSTALL.txt LICENSE.txt README.txt

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/drupal5/bsd.drupal.mk"
.include <bsd.port.post.mk>
