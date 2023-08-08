PORTNAME=	protego
DISTVERSION=	0.1.16
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Protego-${DISTVERSION}

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Pure-Python robots.txt parser
WWW=		https://pypi.org/project/Protego/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils concurrent autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
