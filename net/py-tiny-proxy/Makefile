PORTNAME=	tiny-proxy
DISTVERSION=	0.2.1
CATEGORIES=	net www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Proxy server with SOCKS4(a), SOCKS5(h), HTTP tunnel support
WWW=		https://pypi.org/project/tiny-proxy/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}anyio>=3.6.1:devel/py-anyio@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
