# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	evernote
PORTVERSION=	1.25.1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Evernote SDK for Python

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}oauth2>0:net/py-oauth2@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}thrift>0:devel/py-thrift@${FLAVOR}

USES=		python:-2.7
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
