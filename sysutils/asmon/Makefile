# New ports collection makefile for:	asmon
# Date created:		27 Sep 1999
# Whom:			jack
#
# $FreeBSD$
#

PORTNAME=	asmon
PORTVERSION=	0.60
PORTREVISION=	1
CATEGORIES=	sysutils afterstep
MASTER_SITES=	${MASTER_SITE_AFTERSTEP}
MASTER_SITE_SUBDIR=	apps/asmon

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A swallowable applet monitors the CPU usage, memory and swap, etc

USE_XPM=	yes
USE_X_PREFIX=	yes

BUILD_WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/asmon
CFLAGS+=	-I${X11BASE}/include
USE_GMAKE=	yes
ALL_TARGET=	clean asmon
MAKE_ARGS+=	LIBDIR="-L${X11BASE}/lib" \
		SOLARIS_LIBS=-lkvm

PLIST_FILES=	bin/asmon

post-patch:
	${REINPLACE_CMD} -e 's:gcc:${CC} ${CFLAGS}:' ${BUILD_WRKSRC}/Makefile

do-install:
	${INSTALL} ${COPY} ${STRIP} -o ${BINOWN} -g kmem -m 2755 ${WRKSRC}/asmon/asmon ${PREFIX}/bin

.include <bsd.port.mk>
