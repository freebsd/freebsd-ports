# Created by: Peter Haight <peterh@sapros.com>
# $FreeBSD$

PORTNAME=	fugu
PORTVERSION=	1.2.3
PORTREVISION=	1
CATEGORIES=	net-im python
MASTER_SITES=	http://fugu.gale.org/dist/

MAINTAINER=	5u623l20@gmail.com
COMMENT=	A graphical client for the Gale instant messaging system

LICENSE=	GPLv2

RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/Pmw:${PORTSDIR}/x11-toolkits/py-Pmw

USE_OPENSSL=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
