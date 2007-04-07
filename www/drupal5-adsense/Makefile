# New ports collection makefile for:	drupal5-adsense
# Date created:				3 Apr 2007
# Whom:					Nick Hilliard <nick@foobar.org>
#
# $FreeBSD$
#

PORTNAME=	adsense
DISTVERSION=	5.x-1.3
CATEGORIES=	www
MASTER_SITES=	http://ftp.osuosl.org/pub/drupal/files/projects/

MAINTAINER=	nick@foobar.org
COMMENT=	Allows web site owners to display ads on their site using Google AdSense

DRUPAL5_MODULE=	yes
MODULE_FILES=	adsense.info adsense.install adsense.module adsense_click.js \
		adsense_help.inc
DOC_FILES=	LICENSE.txt README.txt

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/drupal5/bsd.drupal.mk"
.include <bsd.port.post.mk>
