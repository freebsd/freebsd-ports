# New ports collection Makefile for: libsvm
# Date created:         Oct 28 2001
# Whom:                 Chia-Hsing Yu <me@davidyu.org>
#
# $FreeBSD$
#

PORTNAME=	libsvm
PORTVERSION=	2.36
PORTREVISION=	0
CATEGORIES=	science math
MASTER_SITES=	http://www.csie.ntu.edu.tw/~cjlin/libsvm/

MAINTAINER=	me@davidyu.org

.if defined(WITH_PYTHON)
USE_PYTHON=	yes
PLIST=		${WRKDIR}/pkg-plist
ALL_TARGET=	all py
MAKE_ARGS+=	PYTHON_INCLUDEDIR=${PYTHON_INCLUDEDIR}
.endif

.if defined(WITH_PYTHON)
pre-install:
	@cat ${PKGDIR}/pkg-plist.python ${PKGDIR}/pkg-plist > ${PLIST}
.endif

pre-everything::
.if !defined(WITH_PYTHON)
	@${ECHO_MSG} "You can install python interface by defining WITH_PYTHON=yes"
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/svm-train ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/svm-predict ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/svm-scale ${PREFIX}/bin/
.if defined(WITH_PYTHON)
	${INSTALL_SCRIPT} ${WRKSRC}/python/svm.py ${PYTHON_SITELIBDIR}/
	${INSTALL_PROGRAM} ${WRKSRC}/python/svmc.so ${PYTHON_SITELIBDIR}/
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/libsvm
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${PREFIX}/share/doc/libsvm
.endif

.include <bsd.port.mk>
