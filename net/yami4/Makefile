PORTNAME=	yami4
PORTVERSION=	2.0.0
CATEGORIES=	net
MASTER_SITES=	https://www.inspirel.com/yami4/files/
DISTNAME=	yami4-gpl-${PORTVERSION}

MAINTAINER=	prog@msobczak.com
COMMENT=	Messaging library for distributed systems
WWW=		https://www.inspirel.com/yami4/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/gpl-3.0.txt

USES=		zip

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

do-build:
	${DO_MAKE_BUILD} -C ${WRKSRC}/src/core
	${DO_MAKE_BUILD} -C ${WRKSRC}/src/cpp

do-install:
	cd ${WRKSRC}/include && ${COPYTREE_SHARE} "yami4-core yami4-cpp" ${STAGEDIR}${PREFIX}/include
	${RM} ${STAGEDIR}${PREFIX}/include/yami4-core/Doxyfile
	${RM} ${STAGEDIR}${PREFIX}/include/yami4-core/doxymain.h
	${RM} ${STAGEDIR}${PREFIX}/include/yami4-cpp/Doxyfile
	${RM} ${STAGEDIR}${PREFIX}/include/yami4-cpp/doxymain.h
	cd ${WRKSRC}/lib && ${INSTALL_DATA} libyamicore.a libyamicpp.a ${STAGEDIR}${PREFIX}/lib

do-install-DOCS-on:
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} "core cpp" ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
