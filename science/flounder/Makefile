# ex:ts=8
# Ports collection Makefile for:	flounder
# Date created:			Oct 14, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	flounder
PORTVERSION=	0.32a
CATEGORIES=	science
MASTER_SITES=	http://www.enel.ucalgary.ca/~vigmond/flounder/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	fltk:${PORTSDIR}/x11-toolkits/fltk \
		ungif:${PORTSDIR}/graphics/libungif \
		png:${PORTSDIR}/graphics/png

USE_MESA=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib ${PTHREAD_LIBS} -lstdc++"
USE_GMAKE=	yes

.if !defined(WITHOUT_AVIFILE)
LIB_DEPENDS+=	aviplay:${PORTSDIR}/graphics/avifile
CONFIGURE_ARGS+=	--enable-avifile
.endif

.if !defined(WITHOUT_PLOT)
BUILD_DEPENDS+=	gnuplot:${PORTSDIR}/math/gnuplot
RUN_DEPENDS+=	gnuplot:${PORTSDIR}/math/gnuplot
CONFIGURE_ARGS+=	--enable-gnuplot
.endif

.if !defined(WITHOUT_GRACE)
BUILD_DEPENDS+=	xmgrace:${PORTSDIR}/math/grace
RUN_DEPENDS+=	xmgrace:${PORTSDIR}/math/grace
CONFIGURE_ARGS+=	--enable-grace
.endif

.include <bsd.port.mk>
