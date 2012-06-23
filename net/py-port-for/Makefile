# New ports collection makefile for:	py-port-for
# Date created:		2012-06-18
# Whom:			koobs <koobs.freebsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	port-for
PORTVERSION=	0.3
CATEGORIES=	net devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs.freebsd@gmail.com
COMMENT=	Python utility and library that helps with TCP ports management

LICENSE=	MIT

# Python3 Ready
USE_PYTHON=	2.5+
USE_PYDISTUTILS=	yes

post-patch:
	@${REINPLACE_CMD} '/DEFAULT_CONFIG_PATH/ s|/etc|${PREFIX}&|' ${WRKSRC}/port_for/store.py

.include <bsd.port.mk>
