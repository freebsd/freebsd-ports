# $FreeBSD$

PORTNAME=	cloudflare-scrape
PORTVERSION=	1.8.1
CATEGORIES=	net python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tcberner@FreeBSD.org
COMMENT=	Python module to bypass Cloudflare's anti-bot page

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}PyExecJS>=0:devel/py-PyExecJS

USES=		python
USE_PYTHON=     distutils autoplist

USE_GITHUB=     yes
GH_ACCOUNT=	Anorov

.include <bsd.port.mk>
