# New ports collection makefile for:	osdclock
# Date created:		2004-08-06
# Whom:			Roman Bogorodskiy <bogorodskiy@inbox.ru>
#
# $FreeBSD$
#

PORTNAME=	osdclock
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	x11-clocks
MASTER_SITES=	http://leftorium.net/software/
DISTNAME=	osd_clock-${PORTVERSION}

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Small clock which uses libxosd to render text to the root window

LIB_DEPENDS=	xosd.4:${PORTSDIR}/misc/xosd

USE_GETOPT_LONG=yes
USE_GCC=	3.4
USE_REINPLACE=	yes
USE_X_PREFIX=	yes
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} -I${X11BASE}/include" \
		LDFLAGS="${LDFLAGS} -L${X11BASE}/lib ${PTHREAD_LIBS}" \
		PREFIX="${PREFIX}"

PLIST_FILES=	bin/osd_clock
MAN1=		osd_clock.1

post-install:
	${STRIP_CMD} ${PREFIX}/bin/osd_clock

.include <bsd.port.mk>
