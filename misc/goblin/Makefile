# ex:ts=8
# Ports collection makefile for:	goblin
# Date created:			Mar 3, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	goblin
PORTVERSION=	2.6.1
CATEGORIES=	misc
MASTER_SITES=	http://www.math.uni-augsburg.de/opt/goblin.docs/
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Graph Object Library for Network Programming Problems

LIB_DEPENDS=	tk83.1:${PORTSDIR}/x11-toolkits/tk83

USE_REINPLACE=	yes
USE_GMAKE=	yes
MAKE_ENV=	LDFLAGS="${LDFLAGS}"
PLIST_SUB+=	VERSION=${PORTVERSION:R}

CFLAGS+=	-I${LOCALBASE}/include/tcl8.3 -I${LOCALBASE}/include/tk8.3 \
		-I${X11BASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib -L${X11BASE}/lib ${PTHREAD_LIBS}

post-patch:
	@${REINPLACE_CMD} -e \
		's|g++ -c .* -Iinclude|$$(CXX) -c $$(CXXFLAGS) -Iinclude|g ; \
		 s|g++ -lm|$$(CXX) -lm $$(LDFLAGS)|g ; \
		 s|8\.3|83|g ; \
		 s|/usr/include|$$(PREFIX)/include|g ; \
		 s|/usr/lib|$$(PREFIX)/lib|g ; \
		 s|/usr/bin|$$(PREFIX)/bin|g ; \
		 s|-lpthread||g' ${WRKSRC}/Makefile
	@${GREP} -lR "malloc\.h" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|malloc\.h|stdlib.h|g'

.include <bsd.port.mk>
