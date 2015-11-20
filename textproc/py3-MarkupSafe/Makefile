# Created by: Muhammad Moinur Rahman <bofh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	MarkupSafe
PORTVERSION=	0.23
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Implements XML/HTML/XHTML Markup safe string for Python

LICENSE=	BSD3CLAUSE

USES=		python:3
USE_PYTHON=	autoplist concurrent distutils
INSTALL_TARGET=	install-strip

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/markupsafe/_speedups.so

.include <bsd.port.mk>
