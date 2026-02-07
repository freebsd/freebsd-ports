PORTNAME=	rendercv-fonts
DISTVERSION=	0.5.1
CATEGORIES=	x11-fonts python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	rendercv_fonts-${DISTVERSION}

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Some fonts for RenderCV
WWW=		https://github.com/rendercv/rendercv-fonts \
		https://pypi.org/project/rendercv-fonts

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python
USE_PYTHON=	autoplist pep517

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}

.include <bsd.port.mk>
