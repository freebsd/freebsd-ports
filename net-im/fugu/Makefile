# Created by: Peter Haight <peterh@sapros.com>
# $FreeBSD$

PORTNAME=	fugu
PORTVERSION=	1.2.3
PORTREVISION=	1
CATEGORIES=	net-im python
MASTER_SITES=	http://fugu.gale.org/dist/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Graphical client for the Gale instant messaging system

LICENSE=	GPLv2

RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}Pmw>0:x11-toolkits/py-Pmw

USE_OPENSSL=	yes
USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
