# Ports collection makefile for:	drupal7-vulnscan
# Date created:				28 Mar 2012
# Whom:					Shawn Webb <bsdports@wayfair.com>
#
# $FreeBSD$
#

PORTNAME=	vulnscan
DISTVERSION=	7.x-0.1
CATEGORIES=	www
MASTER_SITES=	http://0xfeedface.org/~shawn/freebsd/ports/distfiles/

MAINTAINER=	bsdports@wayfair.com
COMMENT=	Drupal 7 module frontend for Skipfish

LICENSE=	BSD

USE_DRUPAL=	yes

.include <bsd.port.options.mk>

DRUPAL_MODULE=	yes
DRUPAL_VERSION=	7
MODULE_FILES=	vulnscan.info \
		vulnscan.module \
		scan.inc \
		view.inc \
		vulnscan.admin.inc \
		vulnscan.install \
		helpers.inc

.include <bsd.port.mk>
