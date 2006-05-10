# ex:ts=8
# Ports collection makefile for:	goblin
# Date created:			Mar 3, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	goblin
PORTVERSION=	2.6.4
CATEGORIES=	misc
MASTER_SITES=	http://www.math.uni-augsburg.de/opt/goblin.docs/
DISTNAME=	${PORTNAME}.${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Graph Object Library for Network Programming Problems

LIB_DEPENDS=	tk83.1:${PORTSDIR}/x11-toolkits/tk83

CONFLICTS=	ImageMagick-[0-9]* display-*

USE_GMAKE=	yes
MAKE_ARGS=	CC="${CC}" CCFLAGS="${CFLAGS}" \
		CXX="${CXX}" CXXFLAGS="${CXXFLAGS}" \
		LD="${CXX}" LIBS="-lm ${LDFLAGS}" LISShared="-lm ${LDFLAGS}" \
		libtcl=83 libtk=83 prefix=${PREFIX}
ALL_TARGET=	all goblin.a glpk.a
PLIST_SUB+=	VERSION=${PORTVERSION:R}

CFLAGS+=	-I${LOCALBASE}/include/tcl8.3 -I${LOCALBASE}/include/tk8.3 \
		-I${X11BASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib -L${X11BASE}/lib ${PTHREAD_LIBS}

WISH=		${LOCALBASE}/bin/wish8.3

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502126
BROKEN=		"Does not compile on FreeBSD >= 5.x"
.endif

.if ${OSVERSION} < 500035
CXXFLAGS+=	-fhuge-objects
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread||g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|/usr/bin/wish|${WISH}|g' ${WRKSRC}/display
	@${GREP} -lR "malloc\.h" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|malloc\.h|stdlib.h|g'

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/gosh

.include <bsd.port.post.mk>
