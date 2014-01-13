# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	port-for
PORTVERSION=	0.3
CATEGORIES=	net devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Python utility and library that helps with TCP ports management

LICENSE=	MIT

# Python3 Ready
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} '/DEFAULT_CONFIG_PATH/ s|/etc|${PREFIX}&|' ${WRKSRC}/port_for/store.py

.include <bsd.port.mk>
