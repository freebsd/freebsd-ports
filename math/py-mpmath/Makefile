# New ports collection makefile for:	py-mpmath
# Date created:		2008-10-16
# Whom:			Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	mpmath
PORTVERSION=	0.10
PORTREVISION=	2
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wenheping@gmail.com
COMMENT=	Python Library for Arbitrary-precision Floating-point Arithmetic

BUILD_DEPENDS=	${LOCALBASE}/bin/sphinx-build:${PORTSDIR}/textproc/py-sphinx \
		${PYTHON_SITELIBDIR}/gmpy.so:${PORTSDIR}/math/py-gmpy

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

post-install:
	@cd ${WRKSRC}/doc && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} build.py
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}..."
	@cd ${WRKSRC}/doc && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} build.py
	@cd ${WRKSRC}/doc/build && ${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/{} \;
	@cd ${WRKSRC}/doc/build && ${FIND} . -type f -exec \
		${INSTALL_DATA} {} ${DOCSDIR}/{} \;
	@${ECHO_MSG} " [DONE]"
.endif
.include <bsd.port.mk>
