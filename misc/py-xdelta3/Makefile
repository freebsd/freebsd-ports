# New ports collection makefile for:	py-xdelta3
# Date created:				7 Jun 2010
# Whom:					Anonymous
#
# $FreeBSD$
#

PORTREVISION=	0
PORTEPOCH=	0
CATEGORIES?=	misc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

COMMENT=	Python module for xdelta3

BUILD_DEPENDS=	swig:${PORTSDIR}/devel/swig13 \
		${NONEXISTENT}:${PORTSDIR}/misc/xdelta3:build

MASTERDIR=	${.CURDIR}/../../misc/xdelta3

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	xdelta3main

WRKDIR=		${WRKDIRPREFIX}${MASTERDIR}/work
PLIST_FILES=	%%PYTHON_SITELIBDIR%%/${PYDISTUTILS_PKGNAME}.so \
		%%PYTHON_SITELIBDIR%%/xdelta3module.so \
		%%PYTHON_SITELIBDIR%%/xdelta3.py

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xdelta3module.so ${PYTHONPREFIX_SITELIBDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/xdelta3.py ${PYTHONPREFIX_SITELIBDIR}

regression-test: build
	${PYTHON_CMD} ${WRKSRC}/xdelta3-test.py

.include "${MASTERDIR}/Makefile"
