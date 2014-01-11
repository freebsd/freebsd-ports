# Created by: Roman Bogorodskiy <bogorodskiy@inbox.ru>
# $FreeBSD$

PORTNAME=	osdclock
PORTVERSION=	0.5
PORTREVISION=	9
CATEGORIES=	x11-clocks
MASTER_SITES=	http://leftorium.net/software/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	novel
DISTNAME=	osd_clock-${PORTVERSION}

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Small clock which uses libxosd to render text to the root window

LIB_DEPENDS=	xosd.4:${PORTSDIR}/misc/xosd

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib ${PTHREAD_LIBS}" \
		PREFIX="${PREFIX}"

PLIST_FILES=	bin/osd_clock man/man1/osd_clock.1.gz

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/osd_clock

.include <bsd.port.mk>
