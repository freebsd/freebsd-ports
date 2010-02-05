# New ports collection makefile for:	drupal6-nodewords
# Date created:				08 Nov 2008
# Whom:					Nick Hilliard <nick@netability.ie>
#
# $FreeBSD$
#

PORTNAME=	nodewords
DISTVERSION=	6.x-1.9
PORTREVISION=	1
CATEGORIES=	www

MAINTAINER=	nick@foobar.org
COMMENT=	A drupal module which allows the end-user to set meta tags for nodes

BROKEN=		does not install

DRUPAL6_MODULE=	yes
MODULE_DIRS=	basic_metatags extra_metatags site_verification translations
MODULE_FILES=	basic_metatags/basic_metatags.info basic_metatags/basic_metatags.install \
		basic_metatags/basic_metatags.metatags.inc \
		basic_metatags/basic_metatags.module \
		nodewords.admin.inc nodewords.info nodewords.install nodewords.module \
		extra_metatags/extra_metatags.info \
		extra_metatags/extra_metatags.install \
		extra_metatags/extra_metatags.metatags.inc \
		extra_metatags/extra_metatags.module \
		site_verification/site_verification.info \
		site_verification/site_verification.install \
		site_verification/site_verification.metatags.inc \
		site_verification/site_verification.module translations/de.po \
		translations/fr.po translations/ja.po translations/ru.po \
		translations/nodewords.pot

DOC_FILES=	CHANGELOG.txt README.txt

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/drupal5/bsd.drupal.mk"
.include <bsd.port.post.mk>
