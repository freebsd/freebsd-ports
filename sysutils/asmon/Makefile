# Created by: jack
# $FreeBSD$

PORTNAME=	asmon
PORTVERSION=	0.61
PORTREVISION=	3
CATEGORIES=	sysutils afterstep
MASTER_SITES=	AFTERSTEP/apps/asmon

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Swallowable applet monitors the CPU usage, memory, and swap, etc

LICENSE=	GPLv2

BROKEN_armv6=		fails to compile: asmon.c: variable has incomplete type 'struct vmmeter'
BROKEN_armv7=		fails to compile: asmon.c: variable has incomplete type 'struct vmmeter'
BROKEN_mips=		fails to compile: asmon.c: storage size of 'sum' isn't known
BROKEN_mips64=		fails to compile: asmon.c: storage size of 'sum' isn't known
BROKEN_powerpc64=	fails to compile: asmon.c: storage size of 'sum' isn't known

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
