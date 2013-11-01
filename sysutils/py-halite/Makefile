# Created by: Christer Edwards <christer.edwards@gmail.com>
# $FreeBSD$

PORTNAME=	halite
PORTVERSION=	0.1.0
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	christer.edwards@gmail.com
COMMENT=	SaltStack Web UI

LICENSE=	AL2

FETCH_ARGS=	-pRr
USE_PYTHON=	2.6-2.7
USE_PYDISTUTILS=easy_install
PYDISTUTILS_AUTOPLIST=yes

BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}salt>=0.17.0:${PORTSDIR}/sysutils/py-salt \
		${PYTHON_PKGNAMEPREFIX}cherrypy>0:${PORTSDIR}/www/py-cherrypy

RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/setup.py

.include <bsd.port.mk>
