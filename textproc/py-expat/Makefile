# New ports collection makefile for:    py-expat
# Date created:         28 February 2001
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	expat
PORTVERSION=	${PYTHON_PORTVERSION}
CATEGORIES=	textproc python
MASTER_SITES=	ftp://www.python.org/pub/python/src/ \
		ftp://ftp.cwi.nl/pub/python/src/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${PYTHON_DISTFILE}

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${PYDISTUTILS}
LIB_DEPENDS=	expat.2:${PORTSDIR}/textproc/expat2

DIST_SUBDIR=	python
USE_PYTHON=	yes
WRKSRC=		${PYTHON_WRKSRC}/Modules

post-extract:
	@${CP} ${FILESDIR}/setup.py ${WRKSRC}

do-build:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} setup.py build)

do-install:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} setup.py install)

.include <bsd.port.mk>
