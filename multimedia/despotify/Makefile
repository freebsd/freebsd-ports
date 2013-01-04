# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	despotify
PORTVERSION=	0.0.${SVN_REV}
DISTVERSIONPREFIX=	svn
CATEGORIES=	multimedia
MASTER_SITES=	CRITICAL

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A command-line client for spotify

DEPRECATED=	API no longer supported
EXPIRATION_DATE=	2013-02-04

LIB_DEPENDS=	vorbis:${PORTSDIR}/audio/libvorbis \
		ao:${PORTSDIR}/audio/libao
BUILD_DEPENDS=	libtool:${PORTSDIR}/devel/libtool

USE_GMAKE=	yes
USE_LDCONFIG=	yes

SVN_REV=	521

WRKSRC=		${WRKDIR}/${PORTNAME}/src

CFLAGS+=	-L${LOCALBASE}/lib -I${LOCALBASE}/include
LDFLAGS+=	-lpthread -lao -L${LOCALBASE}/lib

MAKE_ENV+=	V=1 LDFLAGS="${LDFLAGS}" INSTALL_PREFIX=${PREFIX}

.include <bsd.port.mk>
