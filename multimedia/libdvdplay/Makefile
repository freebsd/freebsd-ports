# New ports collection makefile for:	libdvdplay
# Date created:		Sat Feb 8 00:47:21 UTC 2003
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libdvdplay
PORTVERSION=	1.0.1
PORTREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	http://download.videolan.org/pub/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Portable abstraction library for DVD navigation

LIB_DEPENDS=	dvdread.4:${PORTSDIR}/multimedia/libdvdread

USE_AUTOTOOLS=	libtool:22
USE_BZIP2=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-dvdread-tree=${LOCALBASE}/include
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib"
MAKE_JOBS_SAFE=	yes

.include <bsd.port.mk>
