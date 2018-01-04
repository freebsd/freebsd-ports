# $FreeBSD$

PORTNAME=	freenas.cli
PORTVERSION=	10.2a6
PORTREVISION=	1
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	FreeNAS Command Line Interface

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}freenas.utils>0:devel/py-freenas.utils@${FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}columnize>0:devel/py-columnize@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyicu>0:devel/py-pyicu@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}natural>0:devel/py-natural@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ply>0:devel/py-ply@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}termcolor>0:devel/py-termcolor@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}texttable>0:textproc/py-texttable@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}freenas.utils>0:devel/py-freenas.utils@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}freenas.dispatcher>0:devel/py-freenas.dispatcher@${FLAVOR}

USES=		python:2.7
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
