# Created by: Yuri Victorovich
# $FreeBSD$

PORTNAME=	txtorcon
PORTVERSION=	0.19.3
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@rawbw.com
COMMENT=	Twisted-based Tor controller client

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}twisted>=15.5.0:devel/py-twisted \
		${PYTHON_PKGNAMEPREFIX}ipaddress>=1.0.16:net/py-ipaddress \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=3.6.1:devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}incremental>0:devel/py-incremental \
		${PYTHON_PKGNAMEPREFIX}Automat>0:devel/py-Automat

USES=		python:2.7 shebangfix
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes
SHEBANG_FILES=	examples/*.py

.include <bsd.port.mk>
