PORTNAME=	fake-useragent
PORTVERSION=	1.4.0
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Up to date simple useragent faker with real world database
WWW=		https://pypi.org/project/fake-useragent/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}importlib-metadata>=4.0:devel/py-importlib-metadata@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}importlib-resources>=5.0:devel/py-importlib-resources@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
