# New ports collection makefile for:	libdivxdecore developer version
# Date created:		03 Feb 20001
# Whom:			Mario S F Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libdivxdecore
PORTVERSION=	0.4.0.48
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://download.projectmayo.com/dnload/divxcore/
PKGNAMESUFFIX=	-devel
DISTNAME=	decore48src

MAINTAINER=	lioux@FreeBSD.org

BUILD_DEPENDS=	${NONEXISTENT}:${LIBDIVXDECORE_PORT}:patch

WRKSRC=		${WRKDIR}/${LIBDIVXDECORE_PORT_WRKSRC:C/.+\///}

USE_ZIP=	yes
EXTRACT_BEFORE_ARGS=	-a
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
PLIST_SUB=	LIB_VERSION="${LIB_VERSION}"

LIB_VERSION=	0

post-extract:
	@${CP} -Rp ${LIBDIVXDECORE_PORT_WRKSRC} ${WRKDIR}
	@${MV} ${WRKSRC}/src ${WRKSRC}/src.old
	@${MV} ${WRKDIR}/decore/src ${WRKSRC}/src
	@${CP} ${WRKSRC}/src.old/Makefile.* ${WRKSRC}/src

post-install:
	@${LN} -sf ${PORTNAME}.so ${PREFIX}/lib/${PORTNAME}.so.${LIB_VERSION}

.include <bsd.port.pre.mk>

#LIBDIVXDECORE_PORT=	${PORTSDIR}/graphics/libdivxdecore
LIBDIVXDECORE_PORT=	${.CURDIR}/../libdivxdecore
LIBDIVXDECORE_PORT_WRKSRC!=	cd ${LIBDIVXDECORE_PORT} && ${MAKE} -V WRKSRC

# We will inherit most of the comment files from the non-devel
# version
PLIST=	${LIBDIVXDECORE_PORT}/pkg-plist
DESCR=	${LIBDIVXDECORE_PORT}/pkg-descr

.include <bsd.port.post.mk>
