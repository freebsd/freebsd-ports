# $FreeBSD$

PORTNAME=	hieroglyph
PORTVERSION=	2.1.0
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Sphinx extension which builds HTML presentations

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PY_SPHINX}

USES=		python:3.5+ shebangfix
USE_PYTHON=	autoplist concurrent distutils
SHEBANG_FILES=	src/hieroglyph/themes/slides2/static/scripts/md/render.py

NO_ARCH=	yes

.include <bsd.port.mk>
