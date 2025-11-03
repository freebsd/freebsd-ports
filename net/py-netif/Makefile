PORTNAME=	netif
PORTVERSION=	1.0.20220211
PORTREVISION=	1
CATEGORIES=	net python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Python network configuration library for FreeBSD
WWW=		https://github.com/freenas/py-netif

LICENSE=	BSD2CLAUSE

DEPRECATED=	Upstream unmaintained
EXPIRATION_DATE=	2025-12-03

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bsd>0:devel/py-bsd@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	freenas
GH_PROJECT=	py-netif
GH_TAGNAME=	f8922e1
USE_PYTHON=	autoplist cython distutils

HAS_CONFIGURE=	yes

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/netif*.so

.include <bsd.port.mk>
