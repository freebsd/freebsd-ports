# Created by: nicolai@catpipe.net
# $FreeBSD$

PORTNAME=	snmp++
PORTVERSION=	3.2.25
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.agentpp.com/
DISTNAME=	${PORTNAME}v${PORTVERSION}

MAINTAINER=	nicolai@catpipe.net
COMMENT=	SNMP C++ library with V3 support

MAKEFILE=	Makefile.FreeBSD
WRKSRC=		${WRKDIR}/${PORTNAME}/src

USES=		gmake
USE_LDCONFIG=	yes
MAKE_ARGS=	CC="${CXX}"

post-extract:
	${CP} ${FILESDIR}/Makefile.FreeBSD ${WRKSRC}

post-install:
	${LN} -sf ${PREFIX}/lib/libsnmp++.so.2.0.0 ${STAGEDIR}${PREFIX}/lib/libsnmp++.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libsnmp++.so.2.0.0

.include <bsd.port.mk>
