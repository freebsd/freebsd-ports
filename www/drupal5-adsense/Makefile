# New ports collection makefile for:	drupal5-adsense
# Date created:				3 Apr 2007
# Whom:					Nick Hilliard <nick@foobar.org>
#
# $FreeBSD$
#

PORTNAME=	adsense
DISTVERSION=	5.x-3.2
PORTREVISION=	1
CATEGORIES=	www

MAINTAINER=	nick@foobar.org
COMMENT=	Allows web site owners to display ads on their site using Google AdSense

DRUPAL5_MODULE=	yes
MODULE_FILES=	adsense.admin.inc adsense.info adsense.install \
		adsense.module cse/help/adsense_cse.help.inc \
		cse/adsense_cse.admin.inc cse/adsense_cse.info \
		cse/adsense_cse.install cse/adsense_cse.js \
		cse/adsense_cse.module cse/adsense_cse.results.inc \
		help/adsense.help.inc help/adsense_id_help.inc \
		includes/adsense.search_options.inc \
		managed/help/adsense_managed.help.inc \
		managed/adsense_managed.admin.inc \
		managed/adsense_managed.info managed/adsense_managed.install \
		managed/adsense_managed.module po/adsense.pot po/ru.po
MODULE_DIRS=	cse/help cse help includes managed/help managed po
DOC_FILES=	LICENSE.txt README.txt

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/drupal5/bsd.drupal.mk"
.include <bsd.port.post.mk>
