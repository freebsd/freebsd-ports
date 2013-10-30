# $FreeBSD$

PORTNAME=	salt-api
PORTVERSION=	0.8.3
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	christer.edwards@gmail.com
COMMENT=	Exposes the fundamental aspects of Salt control to external sources

LICENSE=	AL2

FETCH_ARGS=	-pRr
USE_PYTHON=	2.6-2.7
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}salt>0:${PORTSDIR}/sysutils/py-salt
RUN_DEPENDS:=	${BUILD_DEPENDS}

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/setup.py

.include <bsd.port.mk>
