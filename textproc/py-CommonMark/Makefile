# $FreeBSD$

PORTNAME=	CommonMark
PORTVERSION=	0.8.1
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	commonmark-${PORTVERSION}

MAINTAINER=	romain@FreeBSD.org
COMMENT=	Python parser for the CommonMark Markdown spec

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}future>0:devel/py-future@${PY_FLAVOR}

CONFLICTS_INSTALL=	cmark

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
