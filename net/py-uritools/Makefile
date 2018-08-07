# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	uritools
PORTVERSION=	2.2.0
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	RFC 3986 compliant, Unicode-aware, scheme-agnostic replacement for urlparse

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PY_IPADDRESS}

NO_ARCH=	yes
USE_PYTHON=	autoplist concurrent distutils
USES=		python

.include <bsd.port.mk>
