# Created by: nicolai@catpipe.net
# $FreeBSD$

PORTNAME=	snmp++
PORTVERSION=	3.3.0
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.agentpp.com/
DISTNAME=	${PORTNAME}v${PORTVERSION}

MAINTAINER=	nicolai@petri.dk
COMMENT=	SNMP C++ library with V3 support

LICENSE=	BSD3CLAUSE

MAKEFILE=	Makefile.FreeBSD
WRKSRC=		${WRKDIR}/${PORTNAME}/src

USES=		gmake ssl:build
USE_LDCONFIG=	yes
MAKE_ARGS=	CC="${CXX}" PORTOPTS="-I${OPENSSLINC} -L${OPENSSLLIB}"

post-extract:
	${CP} ${FILESDIR}/Makefile.FreeBSD ${WRKSRC}

post-install:
	${LN} -sf ${PREFIX}/lib/libsnmp++.so.3.3.0 ${STAGEDIR}${PREFIX}/lib/libsnmp++.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libsnmp++.so.3.3.0

.include <bsd.port.mk>
