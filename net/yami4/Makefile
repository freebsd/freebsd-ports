PORTNAME=	yami4
PORTVERSION=	2.0.0
CATEGORIES=	net
MASTER_SITES=	http://www.inspirel.com/yami4/files/
DISTNAME=	yami4-gpl-${PORTVERSION}

MAINTAINER=	prog@msobczak.com
COMMENT=	Messaging library for distributed systems
WWW=		http://www.inspirel.com/yami4/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/gpl-3.0.txt

USES=		zip

OPTIONS_DEFINE=		YAMI4CPP YAMI4PYTHON DOCS
OPTIONS_DEFAULT=	YAMI4CPP
OPTIONS_SUB=		yes
YAMI4CPP_DESC=		Core and C++ libraries
YAMI4PYTHON_DESC=	Loadable module for Python3.9

do-build:

do-build-YAMI4CPP-on:
	${DO_MAKE_BUILD} -C ${WRKSRC}/src/core
	${DO_MAKE_BUILD} -C ${WRKSRC}/src/cpp

do-build-YAMI4PYTHON-on:
	${DO_MAKE_BUILD} -C ${WRKSRC}/src/python3 PYTHON_INCLUDE=${PREFIX}/include/python3.9 PYTHON_LIBDIR=${PREFIX}/lib

do-install:

# Note: the interaction between all options is too complex to handle with .if/.endif,
#       so the DOCS is first installed en-bloc and then selectively UNstaged
do-install-DOCS-on:
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} "core cpp python3" ${STAGEDIR}${DOCSDIR}

do-install-YAMI4CPP-on:
	cd ${WRKSRC}/include && ${COPYTREE_SHARE} "yami4-core yami4-cpp" ${STAGEDIR}${PREFIX}/include
	${RM} ${STAGEDIR}${PREFIX}/include/yami4-core/Doxyfile
	${RM} ${STAGEDIR}${PREFIX}/include/yami4-core/doxymain.h
	${RM} ${STAGEDIR}${PREFIX}/include/yami4-cpp/Doxyfile
	${RM} ${STAGEDIR}${PREFIX}/include/yami4-cpp/doxymain.h
	cd ${WRKSRC}/lib && ${INSTALL_DATA} libyamicore.a libyamicpp.a ${STAGEDIR}${PREFIX}/lib

do-install-YAMI4PYTHON-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/python3.9
	cd ${WRKSRC}/lib && ${INSTALL_DATA} yami.py ${STAGEDIR}${PREFIX}/lib/python3.9
	cd ${WRKSRC}/lib && ${INSTALL_LIB} libyami4py.so ${STAGEDIR}${PREFIX}/lib/python3.9

post-install-YAMI4CPP-off:
	${RM} -r ${STAGEDIR}${DOCSDIR}/core
	${RM} -r ${STAGEDIR}${DOCSDIR}/cpp

post-install-YAMI4PYTHON-off:
	${RM} -r ${STAGEDIR}${DOCSDIR}/python3

.include <bsd.port.mk>

.if ${PORT_OPTIONS:MYAMI4PYTHON}
USES+=		python:3.9
LIB_DEPENDS+=	libpython3.9.so:lang/python39
.endif
