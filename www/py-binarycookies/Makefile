PORTNAME=	binarycookies
PORTVERSION=	2.1.5
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Binary cookies (de)serializer written in Python
WWW=		https://pypi.org/project/binarycookies/

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pydantic>=0:devel/py-pydantic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typer>=0.12.3:devel/py-typer@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

post-patch:
# Do not pick up leftovers (*.orig files etc.) when making the package
	@${REINPLACE_CMD} -e '/^package_data =/,+1s,\*,&.py,' \
		${WRKSRC}/${PYSETUP}

.include <bsd.port.mk>
