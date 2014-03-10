# Created by: Chia-Hsing Yu <me@davidyu.org>
# $FreeBSD$

PORTNAME=	libsvm
PORTVERSION=	3.10
PORTEPOCH=	1
CATEGORIES=	science math
MASTER_SITES=	http://www.csie.ntu.edu.tw/~cjlin/libsvm/ \
		http://www.csie.ntu.edu.tw/~cjlin/libsvm/oldfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION:C/0$//}

MAINTAINER=	rafan@FreeBSD.org
COMMENT=	A library for Support Vector Machines

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS DOCS
OPTIONS_DEFAULT=	OPTIMIZED_CFLAGS

USES=		zip

USE_LDCONFIG=	yes
ALL_TARGET=	all lib

.if defined(PKGNAMESUFFIX) && ${PKGNAMESUFFIX} == "-python"
CATEGORIES+=	python

USE_PYTHON=	yes

MAKE_ARGS=	PYTHON_INCLUDEDIR=${PYTHON_INCLUDEDIR}

TXT_DOCS=	README.python

NO_BUILD=	yes

.else
TXT_DOCS=	COPYRIGHT README FAQ.html README.tools

TOOLS=		tools/checkdata.py tools/easy.py tools/grid.py tools/subset.py

SUB_FILES=	pkg-message
SUB_LIST=	DATADIR=${DATADIR}

.endif

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	${TXT_DOCS}
.endif

.if ${PORT_OPTIONS:MOCFLAGS}
# same as LIBSVM itself
CFLAGS=		-Wall -Wconversion -O3
.endif

post-patch:
.if defined(PKGNAMESUFFIX) && ${PKGNAMESUFFIX} == "-python"
	@${CP} ${WRKSRC}/python/README ${WRKSRC}/README.python
.else
	@${CP} ${WRKSRC}/tools/README ${WRKSRC}/README.tools
.endif

.if defined(PKGNAMESUFFIX) && ${PKGNAMESUFFIX} == "-python"
do-install:
	${INSTALL_DATA} ${WRKSRC}/python/svm.py ${PYTHON_SITELIBDIR}/
	${INSTALL_DATA} ${WRKSRC}/python/svmutil.py ${PYTHON_SITELIBDIR}/
.else

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/svm-train ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/svm-predict ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/svm-scale ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/svm.h ${PREFIX}/include/
	${INSTALL_LIB} ${WRKSRC}/libsvm.so.2 ${PREFIX}/lib/
	${LN} -sf libsvm.so.2 ${PREFIX}/lib/libsvm.so
	${MKDIR} ${DATADIR}
	for f in ${TOOLS}; do \
	  ${INSTALL_DATA} ${WRKSRC}/$$f ${DATADIR}; \
	done

.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	for f in ${TXT_DOCS}; do \
	  ${INSTALL_DATA} ${WRKSRC}/$$f ${DOCSDIR}; \
	done
.endif
.if defined(PKGNAMESUFFIX) && ${PKGNAMESUFFIX} != "-python"
	@${ECHO_MSG} ""
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG} ""
.endif

.include <bsd.port.post.mk>
