# New ports collection makefile for:    Distutils
# Date created:         23 March 2000
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	distutils
PORTVERSION=	1.0.2
CATEGORIES=	misc python
MASTER_SITES=	http://www.python.org/sigs/distutils-sig/download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Distutils-${PORTVERSION}

MAINTAINER=	tg@FreeBSD.org

USE_PYTHON=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} > 211
IGNORE=		"Use the version distributed with ${PYTHON_VERSION}"
.endif

do-build:
	@(cd ${WRKSRC}; ${PYTHON_CMD} setup.py build)

do-install:
	@(cd ${WRKSRC}; ${PYTHON_CMD} setup.py install)

.include <bsd.port.post.mk>
