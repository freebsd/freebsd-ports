# New ports collection Makefile for: libsvm
# Date created:         Oct 28 2001
# Whom:                 Chia-Hsing Yu <me@davidyu.org>
#
# $FreeBSD$
#

PORTNAME=	libsvm
PORTVERSION=	2.84
PORTEPOCH=	1
CATEGORIES=	science math
MASTER_SITES=	http://www.csie.ntu.edu.tw/~cjlin/libsvm/ \
		http://www.csie.ntu.edu.tw/~cjlin/libsvm/oldfiles/

MAINTAINER=	rafan@FreeBSD.org
COMMENT=	A library for Support Vector Machines

USE_ZIP=	yes

.if defined(PKGNAMESUFFIX) && ${PKGNAMESUFFIX} == "-python"
CATEGORIES+=	python

USE_PYTHON=	yes

MAKE_ARGS=	PYTHON_INCLUDEDIR=${PYTHON_INCLUDEDIR}

PYEXAMPLES=	python/cross_validation.py \
		python/svm_test.py \
		python/test_cross_validation.py

TXT_DOCS=	README.python

BUILD_WRKSRC=	${WRKSRC}/python

.else

TXT_DOCS=	COPYRIGHT README FAQ.html README.tools
.if !defined(NOPORTDOCS)
PORTDOCS=	${TXT_DOCS}
.endif
TOOLS=		tools/grid.py tools/easy.py tools/subset.py

SUB_FILES=	pkg-message
SUB_LIST=	DATADIR=${DATADIR}

.endif

.include <bsd.port.pre.mk>

post-patch:

post-extract:
.if defined(PKGNAMESUFFIX) && ${PKGNAMESUFFIX} == "-python"
	@${CP} ${WRKSRC}/python/README ${WRKSRC}/README.python
.else
	@${CP} ${WRKSRC}/tools/README ${WRKSRC}/README.tools
.endif

.if defined(PKGNAMESUFFIX) && ${PKGNAMESUFFIX} == "-python"
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/python/svm.py ${PYTHON_SITELIBDIR}/
	${INSTALL_PROGRAM} ${WRKSRC}/python/svmc.so ${PYTHON_SITELIBDIR}/
	${MKDIR} ${EXAMPLESDIR}
	for f in ${PYEXAMPLES}; do \
	  ${INSTALL_DATA} ${WRKSRC}/$$f ${EXAMPLESDIR}; \
	done

.else

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/svm-train ${TARGETDIR}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/svm-predict ${TARGETDIR}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/svm-scale ${TARGETDIR}/bin/
	${MKDIR} ${DATADIR}
	for f in ${TOOLS}; do \
	  ${INSTALL_DATA} ${WRKSRC}/$$f ${DATADIR}; \
	done

.endif

post-install:
.if !defined(NOPORTDOCS)
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
