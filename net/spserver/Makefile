# New ports collection makefile for:	spserver
# Date created:				18 June 2007
# Whom:					vanilla@
#
# $FreeBSD$
#

PORTNAME=	spserver
PORTVERSION=	0.8
CATEGORIES=	net
MASTER_SITES=	http://spserver.googlecode.com/files/
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	A TCP server framework library written in C++ based on libevent

LIB_DEPENDS=	event-1.3b.1:${PORTSDIR}/devel/libevent

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_LDCONFIG=	yes
USE_GMAKE=	yes
ALL_TARGET=	all ssl

post-patch:
	${SED} -i -E 's,%PREFIX%,${PREFIX},g' ${WRKSRC}/spserver/Makefile
	${SED} -i -E 's,%PREFIX%,${PREFIX},g' ${WRKSRC}/openssl/Makefile

do-install:
	@${MKDIR} ${PREFIX}/include/spserver
	@${INSTALL} ${WRKSRC}/spserver/*.hpp ${PREFIX}/include/spserver
	@${INSTALL} ${WRKSRC}/spserver/libspserver.so ${PREFIX}/lib/libspserver.so.1
	@${LN} -s ${PREFIX}/lib/libspserver.so.1 ${PREFIX}/lib/libspserver.so
	@${INSTALL} ${WRKSRC}/openssl/spopenssl.hpp ${PREFIX}/include/spserver
	@${INSTALL} ${WRKSRC}/openssl/libspopenssl.so ${PREFIX}/lib/libspopenssl.so.1
	@${LN} -s ${PREFIX}/lib/libspopenssl.so.1 ${PREFIX}/lib/libspopenssl.so

.include <bsd.port.mk>
