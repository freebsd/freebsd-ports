# New ports collection Makefile for: libsvm
# Date created:         Oct 28 2001
# Whom:                 Chia-Hsing Yu <me@davidyu.org>
#
# $FreeBSD$
#

PORTNAME=	libsvm
PORTVERSION=	2.8
PORTREVISION=	0
PORTEPOCH=	1
CATEGORIES=	science math
MASTER_SITES=	http://www.csie.ntu.edu.tw/~cjlin/libsvm/ \
		http://www.csie.ntu.edu.tw/~cjlin/libsvm/oldfiles/

MAINTAINER=	rafan@infor.org
COMMENT=	A library for Support Vector Machines

USE_ZIP=	yes
USE_REINPLACE=	yes

.if defined(WITH_PYTHON)
CATEGORIES+=	python
USE_PYTHON=	yes
PLIST_SUB+=	LIBSVM_PYTHON=""
PYEXAMPLES=	python/cross_validation.py \
		python/svm_test.py \
		python/test_cross_validation.py
.else
PLIST_SUB+=	LIBSVM_PYTHON="@comment "
.endif

TXT_DOCS=	COPYRIGHT README FAQ.html README.python
.if !defined(NOPORTDOCS)
PORTDOCS=	${TXT_DOCS}
.endif
TOOLS=		tools/grid.py tools/easy.py

MSG_FILE=	${PKGDIR}/pkg-message
PKGMESSAGE=	${WRKSRC}/pkg-message

.include <bsd.port.pre.mk>

pre-everything::
.if defined(WITH_PYTHON)
	@${ECHO_MSG} "Build with Python interface."
.else
	@${ECHO_MSG} "You can enable Python interface by defining WITH_PYTHON."
.endif

post-patch:
.if defined(WITH_PYTHON)
	@${REINPLACE_CMD} -e "s,%%PYTHON_INCLUDEDIR%%,${PYTHON_INCLUDEDIR}," ${WRKSRC}/python/Makefile
.endif
	@${SED} 's|%%DATADIR%%|${DATADIR}|g' ${MSG_FILE} > ${PKGMESSAGE}

post-build:
.if defined(WITH_PYTHON)
	cd ${WRKSRC}/python; ${MAKE}
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/svm-train ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/svm-predict ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/svm-scale ${PREFIX}/bin/
.if defined(WITH_PYTHON)
	${INSTALL_SCRIPT} ${WRKSRC}/python/svm.py ${PYTHON_SITELIBDIR}/
	${INSTALL_PROGRAM} ${WRKSRC}/python/svmc.so ${PYTHON_SITELIBDIR}/
	${MKDIR} ${EXAMPLESDIR}
	for f in ${PYEXAMPLES}; do \
	  ${INSTALL_DATA} ${WRKSRC}/$$f ${EXAMPLESDIR}; \
	done
.endif
	${MKDIR} ${DATADIR}
	for f in ${TOOLS}; do \
	  ${INSTALL_DATA} ${WRKSRC}/$$f ${DATADIR}; \
	done
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${CP} ${WRKSRC}/python/README ${WRKSRC}/README.python
	for f in ${TXT_DOCS}; do \
	  ${INSTALL_DATA} ${WRKSRC}/$$f ${DOCSDIR}; \
	done
.endif
	@${ECHO} ""
	@${CAT} ${PKGMESSAGE}
	@${ECHO} ""

.include <bsd.port.post.mk>
