# New ports collection makefile for:	libdvdplay
# Date created:		Sat Feb 8 00:47:21 UTC 2003
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libdvdplay
PORTVERSION=	1.0.1
CATEGORIES=	multimedia
MASTER_SITES=	http://www.videolan.org/pub/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTVERSION}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Portable abstraction library for DVD navigation

LIB_DEPENDS=	dvdread.3:${PORTSDIR}/multimedia/libdvdread

USE_BZIP2=	yes
USE_SIZE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-dvdread-tree=${LOCALBASE}/include
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
