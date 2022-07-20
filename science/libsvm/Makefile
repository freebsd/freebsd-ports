PORTNAME=	libsvm
PORTVERSION=	3.23
CATEGORIES=	science math
MASTER_SITES=	http://www.csie.ntu.edu.tw/~cjlin/libsvm/ \
		http://www.csie.ntu.edu.tw/~cjlin/libsvm/oldfiles/

MAINTAINER?=	iblis@hs.ntnu.edu.tw
COMMENT=	Library for Support Vector Machines

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USES=		zip

USE_LDCONFIG=	yes
ALL_TARGET=	all lib

OPTIONS_DEFINE=	DOCS

.if defined(PKGNAMESUFFIX) && ${PKGNAMESUFFIX} == "-python"
CATEGORIES+=	python

USES+=		python

MAKE_ARGS=	PYTHON_INCLUDEDIR=${PYTHON_INCLUDEDIR}

PORTDOCS=	README.python

NO_BUILD=	yes
NO_ARCH=	yes
.else
PORTDOCS=	README FAQ.html README.tools

TOOLS=		tools/checkdata.py tools/easy.py tools/grid.py tools/subset.py

SUB_FILES=	pkg-message
SUB_LIST=	DATADIR=${DATADIR}

OPTIONS_DEFINE+=	OPTIMIZED_CFLAGS
OPTIONS_DEFAULT+=	OPTIMIZED_CFLAGS

OPTIMIZED_CFLAGS_CFLAGS=		-Wall -Wconversion -O3
.endif

post-patch:
.if defined(PKGNAMESUFFIX) && ${PKGNAMESUFFIX} == "-python"
	@${CP} ${WRKSRC}/python/README ${WRKSRC}/README.python
.else
	@${CP} ${WRKSRC}/tools/README ${WRKSRC}/README.tools
.endif

do-install:
.if defined(PKGNAMESUFFIX) && ${PKGNAMESUFFIX} == "-python"
	@${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}
	${INSTALL_DATA} ${WRKSRC}/python/svm.py ${STAGEDIR}${PYTHON_SITELIBDIR}
	${INSTALL_DATA} ${WRKSRC}/python/svmutil.py ${STAGEDIR}${PYTHON_SITELIBDIR}
.else
	${INSTALL_PROGRAM} ${WRKSRC}/svm-train ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/svm-predict ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/svm-scale ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/svm.h ${STAGEDIR}${PREFIX}/include/
	${INSTALL_LIB} ${WRKSRC}/libsvm.so.2 ${STAGEDIR}${PREFIX}/lib/
	${LN} -sf libsvm.so.2 ${STAGEDIR}${PREFIX}/lib/libsvm.so
	@${MKDIR} ${STAGEDIR}${DATADIR}
	for f in ${TOOLS}; do \
		${INSTALL_DATA} ${WRKSRC}/$$f ${STAGEDIR}${DATADIR}; \
	done
.endif

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
