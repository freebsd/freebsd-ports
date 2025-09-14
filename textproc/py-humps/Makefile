PORTNAME=	pyhumps
PORTVERSION=	3.9.0
CATEGORIES=	textproc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	otis@FreeBSD.org
COMMENT=	Convert strings between cases
WWW=		https://github.com/nficano/humps

LICENSE=	UNLICENSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>0:devel/py-poetry-core@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	nficano
GH_PROJECT=	humps
GH_TAGNAME=	v${PORTVERSION}

USE_PYTHON=	autoplist concurrent pep517

.include <bsd.port.mk>
