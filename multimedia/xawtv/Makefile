# New ports collection makefile for:   xawtv
# Date created:        03 March 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=       xawtv
PORTVERSION=	3.37
CATEGORIES=     graphics
MASTER_SITES=   http://www.strusel007.de/linux/xawtv/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	greid@ukug.uk.freebsd.org

LIB_DEPENDS=	Xaw3d.${XAWVER}:${PORTSDIR}/x11-toolkits/Xaw3d \
		png.4:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}

GNU_CONFIGURE=	yes

USE_X_PREFIX=	yes

SEDFILES=	. font i2c man src radio contrib/cc webcam oldstuff/vtx \
		libng libvbi http

MAN1=		alevtd.1 fbtv.1 propwatch.1 rootv.1 showriff.1 v4l-conf.1 \
		v4lctl.1 webcam.1 xawtv-remote.1 xawtv.1

post-configure:
.for M in ${SEDFILES}
	@(${SED} -e 's,^CFLAGS=,CFLAGS+=,g' ${WRKSRC}/$M/Makefile | \
		${SED} -e 's,-O2,,g' > ${WRKSRC}/foo && ${MV} ${WRKSRC}/foo ${WRKSRC}/$M/Makefile)
.endfor

post-install:
.for F in led-koi8.pcf led-latin1.pcf led-latin2.pcf
	@gzip ${PREFIX}/lib/X11/fonts/misc/$F
.endfor

.include <bsd.port.mk>
