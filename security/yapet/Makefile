# New ports collection makefile for:	yapet
# Date created:		01 March 2008
# Whom:			Rafael Ostertag <rafi@guengel.ch>
#
# $FreeBSD$
#

PORTNAME=	yapet
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.guengel.ch/myapps/yapet/downloads/

PATCH_SITES=	http://www.guengel.ch/myapps/yapet/downloads/patches/
PATCHFILES=	yapet_gcc43-0.2.diff yapet_crs_bs-0.2.diff
PATCH_DIST_STRIP=-p1

MAINTAINER=	rafi@guengel.ch
COMMENT=	A curses based password manager

MAN1=		yapet.1
MANCOMPRESSED=	no

GNU_CONFIGURE=	yes

USE_OPENSSL=	yes

.include <bsd.port.mk>
