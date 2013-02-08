# $FreeBSD$

PORTNAME=	salt-api
PORTVERSION=	0.7.5
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	christer.edwards@gmail.com
COMMENT=	Exposes the fundamental aspects of Salt control to external sources

LICENSE=	AL2

FETCH_ARGS=	-pRr
USE_PYTHON=	2.6-2.7
USE_PYDISTUTILS=	yes

SUB_LIST+=	PYTHON_CMD=${PYTHON_CMD}

MAN1=	salt-api.1
MAN7=	salt-api.7

BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}salt:${PORTSDIR}/sysutils/py-salt

RUN_DEPENDS:=	${BUILD_DEPENDS}

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/setup.py

.include <bsd.port.mk>
