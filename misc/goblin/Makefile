# ex:ts=8
# Ports collection makefile for:	goblin
# Date created:			Mar 3, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	goblin
PORTVERSION=	2.5
CATEGORIES=	misc
MASTER_SITES=	http://www.math.uni-augsburg.de/opt/goblin.docs/
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	tcl83:${PORTSDIR}/lang/tcl83 \
		tk83:${PORTSDIR}/x11-toolkits/tk83

USE_REINPLACE=	yes

CFLAGS+=	-I${LOCALBASE}/include/tcl8.3 -I${LOCALBASE}/include/tk8.3 \
		-I${X11BASE}/include
LIBS=		-L${LOCALBASE}/lib -L${X11BASE}/lib

PLIST_SUB+=	PORTVER=${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e "s,-lpthread,${PTHREAD_LIBS},g ; \
		s,g\+\+,${CXX},g ; \
		s,%%CXXFLAGS%%,${CXXFLAGS},g ; s,%%LIBS%%,${LIBS},g ; \
		s,%%PREFIX%%,${PREFIX},g" ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e "s/malloc.h/stdlib.h/g" ${WRKSRC}/include/globals.h

.include <bsd.port.mk>
