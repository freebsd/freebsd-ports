# Created by: ijliao
# $FreeBSD$

PORTNAME=	gnupg
PORTVERSION=	1.2.2
CATEGORIES=	security python
MASTER_SITES=	http://www.c-s.li/ports/ \
		CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Python wrapper for GnuPG

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psutil>=0.5.1:${PORTSDIR}/sysutils/py-psutil

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install
PYDISTUTILS_AUTOPLIST=yes

NO_STAGE=	yes
.include <bsd.port.mk>
