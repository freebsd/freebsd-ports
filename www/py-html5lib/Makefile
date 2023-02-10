PORTNAME=	html5lib
PORTVERSION=	1.0.1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Python based HTML parser based on the HTML5 spec
WWW=		https://github.com/html5lib

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webencodings>0:converters/py-webencodings@${PY_FLAVOR}

NO_ARCH=	yes
USES=		cpe python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
