# Created by: antoine@FreeBSD.org
# $FreeBSD$

PORTNAME=	rekall
PORTVERSION=	1.5.0
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Memory forensics analysis framework

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}rekall-core>=1.5.0.p:security/py-rekall-core \
		${PYTHON_PKGNAMEPREFIX}rekall_gui>=1.5.0.p:security/py-rekall_gui \
		${PYTHON_PKGNAMEPREFIX}ipython>=0:devel/ipython

NO_ARCH=	yes
USES=		python:2.7 zip
USE_PYTHON=	distutils autoplist

post-extract:
	@${CHMOD} -R a+rX ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} 's,ipython==4.0.0,ipython,' ${WRKSRC}/setup.py

.include <bsd.port.mk>
