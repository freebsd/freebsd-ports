# New ports collection makefile for:	drupal-nice_menus
# Date created:				20 October 2006
# Whom:					Nick Hilliard <nick@foobar.org>
#
# $FreeBSD$
#

PORTNAME=	nice_menus
DISTVERSION=	${DRUPAL_VERSION}
PORTREVISION=	20060811
CATEGORIES=	www security
MASTER_SITE=	http://ftp.osuosl.org/pub/drupal/files/projects/

MAINTAINER=	nick@foobar.org
COMMENT=	Access control system for the Drupal CMS based on Taxonomy classification

DRUPAL_MODULE=	yes
MODULE_FILES=	arrow-down.png arrow-left.png arrow-right.png \
		nice_menus.css nice_menus.js nice_menus.module
DOC_FILES=	LICENSE.txt README.txt

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/drupal5/bsd.drupal.mk"
.include <bsd.port.post.mk>
