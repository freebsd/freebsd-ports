# Created by: jack

PORTNAME=	asmon
PORTVERSION=	0.61
PORTREVISION=	3
CATEGORIES=	sysutils afterstep
MASTER_SITES=	AFTERSTEP/apps/asmon

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Swallowable applet monitors the CPU usage, memory, and swap, etc

LICENSE=	GPLv2

BROKEN_FreeBSD_12=	fails to compile: read_mem.c: invalid use of undefined type 'struct vmmeter'
BROKEN_FreeBSD_13=	fails to compile: read_mem.c: invalid use of undefined type 'struct vmmeter'
BROKEN_FreeBSD_14=	fails to compile: read_mem.c: invalid use of undefined type 'struct vmmeter'
BROKEN_mips=		fails to compile: asmon.c: storage size of 'sum' isn't known
BROKEN_mips64=		fails to compile: asmon.c: storage size of 'sum' isn't known

DEPRECATED=	Fails to build on modern FreeBSD
EXPIRATION_DATE=	2021-12-27

USES=		gmake xorg
USE_CSTD=	gnu89
USE_XORG=	xpm x11

BUILD_WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}/asmon
CFLAGS+=	-I${LOCALBASE}/include
ALL_TARGET=	asmon
MAKE_ARGS+=	LIBDIR="-L${LOCALBASE}/lib" \
		SOLARIS_LIBS=-lkvm

PLIST_FILES=	"@(,kmem,) bin/asmon"

post-patch:
	${REINPLACE_CMD} -e 's:gcc:${CC} ${CFLAGS}:' ${BUILD_WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/asmon/asmon ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
