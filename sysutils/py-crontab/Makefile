# Created by: Steven Kreuzer <skreuzer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	crontab
PORTVERSION=	1.9.5
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}-${PORTVERSION}

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Read and write crontab files using a direct API

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateutil>=1.5:devel/py-dateutil@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}croniter>0:sysutils/py-croniter@${FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
