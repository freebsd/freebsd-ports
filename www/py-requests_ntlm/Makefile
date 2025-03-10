PORTNAME=	requests_ntlm
DISTVERSION=	1.3.0
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	HTTP NTLM authentication using the requests library
WWW=		https://github.com/requests/requests-ntlm

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ntlm-auth>=1.0.2:security/py-ntlm-auth@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.0.0:www/py-requests@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist cryptography distutils
NO_ARCH=	yes

.include <bsd.port.mk>
