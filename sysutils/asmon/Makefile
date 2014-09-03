# Created by: jack
# $FreeBSD$

PORTNAME=	asmon
PORTVERSION=	0.61
PORTREVISION=	3
CATEGORIES=	sysutils afterstep
MASTER_SITES=	${MASTER_SITE_AFTERSTEP}
MASTER_SITE_SUBDIR=	apps/asmon

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Swallowable applet monitors the CPU usage, memory, and swap, etc

LICENSE=	GPLv2

USE_XORG=	xpm x11

BUILD_WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}/asmon
CFLAGS+=	-I${LOCALBASE}/include
USES=		gmake
USE_CSTD=	gnu89
ALL_TARGET=	asmon
MAKE_ARGS+=	LIBDIR="-L${LOCALBASE}/lib" \
		SOLARIS_LIBS=-lkvm

PLIST_FILES=	"@(,kmem,) bin/asmon"

post-patch:
	${REINPLACE_CMD} -e 's:gcc:${CC} ${CFLAGS}:' ${BUILD_WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/asmon/asmon ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
