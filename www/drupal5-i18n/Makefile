# New ports collection makefile for:	drupal5-i18n
# Date created:				26 Jan 2007
# Whom:					Nick Hilliard <nick@foobar.org>
#
# $FreeBSD$
#

PORTNAME=	i18n
DISTVERSION=	5.x-2.5
PORTREVISION=	1
CATEGORIES=	www

MAINTAINER=	nick@foobar.org
COMMENT=	An internationalisation module for the Drupal CMS

DRUPAL5_MODULE=	yes

MODULE_DIRS=	contrib/po contrib experimental flags i18nblocks/po \
		i18nblocks i18nprofile/po i18nprofile i18nviews/po i18nviews \
		po translation/po translation

MODULE_FILES=	contrib/po/da.po contrib/README.txt \
		contrib/i18n_db_update_v45_to_v46.mysql \
		contrib/i18nmenu.info contrib/i18nmenu.module \
		contrib/i18npanels.info contrib/i18npanels.module \
		contrib/i18ntaxonomy.info contrib/i18ntaxonomy.install \
		contrib/i18ntaxonomy.module i18n.info i18n.install \
		i18n.module experimental/README.txt \
		experimental/i18ncontent.info \
		experimental/i18ncontent.module \
		experimental/i18nstrings.info \
		experimental/i18nstrings.install \
		experimental/i18nstrings.module experimental/i18nsync.info \
		experimental/i18nsync.install experimental/i18nsync.module \
		flags/ar.png flags/ca.png flags/cs.png flags/da.png \
		flags/de.png flags/el.png flags/en.png flags/es.png \
		flags/eu.png flags/fi.png flags/fr.png flags/ga.png \
		flags/gl.png flags/he.png flags/hu.png flags/it.png \
		flags/ja.png flags/km.png flags/lb.png flags/nl.png \
		flags/ru.png flags/sk.png flags/sl.png flags/sv.png \
		flags/tr.png flags/uk.png flags/vi.png i18nblocks/po/da.po \
		i18nblocks/i18nblocks.info i18nblocks/i18nblocks.install \
		i18nblocks/i18nblocks.module i18nprofile/po/da.po \
		i18nprofile/i18nprofile.info i18nprofile/i18nprofile.install \
		i18nprofile/i18nprofile.module i18nviews/po/da.po \
		i18nviews/i18nviews.info i18nviews/i18nviews.module \
		po/i18n.pot po/ca.po po/da.po po/de.po po/es.po po/fr.po \
		po/gl.po po/it.po po/pt.po po/ru.po translation/po/da.po \
		translation/translation.info translation/translation.module

DOC_FILES=	CHANGELOG.txt CREDITS.txt INSTALL.txt LICENSE.txt README.txt

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/drupal5/bsd.drupal.mk"
.include <bsd.port.post.mk>
