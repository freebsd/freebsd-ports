# $FreeBSD$

PORTNAME=	freenas.cli
PORTVERSION=	10.2a6
PORTREVISION=	1
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	FreeNAS Command Line Interface

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}freenas.utils>0:devel/py-freenas.utils
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}columnize>0:devel/py-columnize \
		${PYTHON_PKGNAMEPREFIX}pyicu>0:devel/py-pyicu \
		${PYTHON_PKGNAMEPREFIX}natural>0:devel/py-natural \
		${PYTHON_PKGNAMEPREFIX}ply>0:devel/py-ply \
		${PYTHON_PKGNAMEPREFIX}termcolor>0:devel/py-termcolor \
		${PYTHON_PKGNAMEPREFIX}texttable>0:textproc/py-texttable \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}freenas.utils>0:devel/py-freenas.utils \
		${PYTHON_PKGNAMEPREFIX}freenas.dispatcher>0:devel/py-freenas.dispatcher

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
