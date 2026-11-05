PORTNAME=	python-openid
PORTVERSION=	2.2.5
PORTREVISION=	3
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Python OpenID version
WWW=		http://janrain.com/openid-enabled

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN=		python 2 code (calls len() on a map object at import)
DEPRECATED=	Python 2 code; use security/py-python3-openid
EXPIRATION_DATE=	2026-11-29

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
