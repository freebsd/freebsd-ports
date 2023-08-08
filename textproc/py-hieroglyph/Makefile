PORTNAME=	hieroglyph
PORTVERSION=	2.1.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Sphinx extension which builds HTML presentations
WWW=		https://github.com/nyergler/hieroglyph

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=2.0,1:textproc/py-sphinx@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist concurrent distutils
SHEBANG_FILES=	src/hieroglyph/themes/slides2/static/scripts/md/render.py

NO_ARCH=	yes

.include <bsd.port.mk>
