# ex:ts=8
# Ports collection makefile for:	goblin
# Date created:			Mar 3, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	goblin
PORTVERSION=	2.6
CATEGORIES=	misc
MASTER_SITES=	http://www.math.uni-augsburg.de/opt/goblin.docs/
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Graph Object Library for Network Programming Problems

LIB_DEPENDS=	tk83.1:${PORTSDIR}/x11-toolkits/tk83

USE_REINPLACE=	yes
USE_GMAKE=	yes
MAKE_ENV=	LDFLAGS="${LDFLAGS}"
PLIST_SUB+=	PORTVER=${PORTVERSION}

CFLAGS+=	-I${LOCALBASE}/include/tcl8.3 -I${LOCALBASE}/include/tk8.3 \
		-I${X11BASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib -L${X11BASE}/lib ${PTHREAD_LIBS}

post-patch:
.for file in include/globals.h globals.cpp
	@${REINPLACE_CMD} -e "s/malloc.h/stdlib.h/g" ${WRKSRC}/${file}
.endfor

.include <bsd.port.mk>
