# New ports collection makefile for:	drupal5-nice_menus
# Date created:				20 October 2006
# Whom:					Nick Hilliard <nick@foobar.org>
#
# $FreeBSD$
#

PORTNAME=	nice_menus
DISTVERSION=	5.x-1.x-dev
PORTREVISION=	20070609
CATEGORIES=	www
MASTER_SITES=	http://ftp.osuosl.org/pub/drupal/files/projects/

MAINTAINER=	nick@foobar.org
COMMENT=	CSS / Javascript pull-down menus for Drupal

BROKEN=		Checksum mismatch

DRUPAL5_MODULE=	yes

MODULE_FILES=	arrow-down.png arrow-left.png arrow-right.png ie.css \
		nice_menus.css nice_menus.info nice_menus.js \
		nice_menus.module

DOC_FILES=	README.txt UPGRADE.txt LICENSE.txt

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/drupal5/bsd.drupal.mk"
.include <bsd.port.post.mk>
