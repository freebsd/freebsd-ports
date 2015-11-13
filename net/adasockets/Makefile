# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	adasockets
PORTVERSION=	1.9.2
CATEGORIES=	net
MASTER_SITES=	http://www.rfc1149.net/download/adasockets/

MAINTAINER=	marino@FreeBSD.org
COMMENT=	IPv4 socket library for Ada (TCP, UDP, and multicast)

LICENSE=	GPLv2 GMGPL
LICENSE_COMB=	multi

USES=		ada gmake libtool
HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=--disable-doc --disable-shared

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/adasockets \
		${STAGEDIR}${PREFIX}/lib/gnat
	${MV} ${STAGEDIR}${PREFIX}/lib/libadasockets.* \
		${STAGEDIR}${PREFIX}/lib/adasockets/
	${MV} ${STAGEDIR}${PREFIX}/lib/adasockets/*.ad[bs] \
		${STAGEDIR}${PREFIX}/include/adasockets/
	${INSTALL_DATA} ${FILESDIR}/adasockets.gpr \
		${STAGEDIR}${PREFIX}/lib/gnat/

.include <bsd.port.mk>
