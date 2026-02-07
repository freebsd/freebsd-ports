PORTNAME=	cloudflare-scrape
DISTVERSION=	2.1.1
PORTREVISION=	1
CATEGORIES=	net python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python module to bypass Cloudflare's anti-bot page
WWW=		https://github.com/Anorov/cloudflare-scrape

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}PyExecJS>=0:devel/py-PyExecJS@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

USE_GITHUB=	yes
GH_ACCOUNT=	Anorov

.include <bsd.port.mk>
