# New ports collection makefile for:	drupal5-i18n
# Date created:				26 Jan 2007
# Whom:					Nick Hilliard <nick@foobar.org>
#
# $FreeBSD$
#

PORTNAME=	i18n
DISTVERSION=	5.x-2.1
CATEGORIES=	www
MASTER_SITES=	http://ftp.osuosl.org/pub/drupal/files/projects/

MAINTAINER=	nick@foobar.org
COMMENT=	An internationalisation module for the Drupal CMS

DRUPAL5_MODULE=	yes

MODULE_DIRS=	contrib experimental flags i18nblocks i18nprofile \
		i18nviews translation

MODULE_FILES=	contrib/i18nmenu.info contrib/i18nmenu.module \
		contrib/i18ntaxonomy.info contrib/i18ntaxonomy.install \
		contrib/i18ntaxonomy.module i18n.info i18n.install \
		i18n.module experimental/README.txt \
		experimental/i18ncontent.info \
		experimental/i18ncontent.module \
		experimental/i18nstrings.info \
		experimental/i18nstrings.install \
		experimental/i18nstrings.module experimental/i18nsync.info \
		experimental/i18nsync.install experimental/i18nsync.module \
		experimental/ttext.info experimental/ttext.install \
		experimental/ttext.module flags/ar.png flags/ca.png \
		flags/cs.png flags/de.png flags/en.png flags/es.png \
		flags/eu.png flags/fi.png flags/fr.png flags/ga.png \
		flags/gl.png flags/he.png flags/hu.png flags/it.png \
		flags/ja.png flags/km.png flags/nl.png flags/ru.png \
		flags/sk.png flags/sv.png i18nblocks/i18nblocks.info \
		i18nblocks/i18nblocks.install i18nblocks/i18nblocks.module \
		i18nprofile/i18nprofile.info i18nprofile/i18nprofile.install \
		i18nprofile/i18nprofile.module i18nviews/i18nviews.info \
		i18nviews/i18nviews.module translation/translation.info \
		translation/translation.module

DOC_FILES=	CHANGELOG.txt CREDITS.txt INSTALL.txt LICENSE.txt README.txt

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/drupal5/bsd.drupal.mk"
.include <bsd.port.post.mk>
