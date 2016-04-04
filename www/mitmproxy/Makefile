# Created by: Hung-Yi Chen <gaod@hychen.org>
# $FreeBSD$

PORTNAME=	mitmproxy
PORTVERSION=	0.15
CATEGORIES=	www python
MASTER_SITES=	http://mitmproxy.org/download/

MAINTAINER=	gaod@hychen.org
COMMENT=	SSL-capable man-in-the-middle proxy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyasn1>0:devel/py-pyasn1 \
		${PYTHON_PKGNAMEPREFIX}Flask>0:www/py-flask \
		${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}netlib>0:net/py-netlib \
		${PYTHON_PKGNAMEPREFIX}openssl>0:security/py-openssl \
		${PYTHON_PKGNAMEPREFIX}pillow>=2.3.0:graphics/py-pillow \
		${PYTHON_PKGNAMEPREFIX}urwid>0:devel/py-urwid

USES=		python
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
