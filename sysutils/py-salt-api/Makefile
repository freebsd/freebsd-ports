# $FreeBSD$

PORTNAME=	salt-api
PORTVERSION=	0.8.4
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	christer.edwards@gmail.com
COMMENT=	Exposes the fundamental aspects of Salt control to external sources

LICENSE=	APACHE20

USES=		python:2
USE_PYTHON=	distutils autoplist

BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}salt>0:${PORTSDIR}/sysutils/py-salt
RUN_DEPENDS:=	${BUILD_DEPENDS}

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/setup.py

.include <bsd.port.mk>
