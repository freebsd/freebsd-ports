# ex:ts=8
# Ports collection makefile for:	goblin
# Date created:			Mar 3, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	goblin
PORTVERSION=	2.6.b5
CATEGORIES=	misc
MASTER_SITES=	http://www.math.uni-augsburg.de/opt/goblin.docs/
DISTNAME=	${PORTNAME}.${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Graph Object Library for Network Programming Problems

LIB_DEPENDS=	tcl83:${PORTSDIR}/lang/tcl83 \
		tk83:${PORTSDIR}/x11-toolkits/tk83

USE_REINPLACE=	yes

CFLAGS+=	-I${LOCALBASE}/include/tcl8.3 -I${LOCALBASE}/include/tk8.3 \
		-I${X11BASE}/include
LIBS=		-L${LOCALBASE}/lib -L${X11BASE}/lib
USE_GMAKE=	yes
PLIST_SUB+=	PORTVER=${PORTVERSION:R}

post-patch:
	@${REINPLACE_CMD} -e "s,-lpthread,${PTHREAD_LIBS},g ; \
		s,g\+\+,${CXX},g ; \
		s,%%CXXFLAGS%%,${CXXFLAGS},g ; s,%%LIBS%%,${LIBS},g ; \
		s,%%PREFIX%%,${PREFIX},g" ${WRKSRC}/Makefile
.for file in include/globals.h globals.cpp
	@${REINPLACE_CMD} -e "s/malloc.h/stdlib.h/g" ${WRKSRC}/${file}
.endfor

.include <bsd.port.mk>
