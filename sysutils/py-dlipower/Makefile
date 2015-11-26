# Created by: M. Warner Losh <imp@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dlipower
PORTVERSION=	0.7.117
PORTEPOCH=	1
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	imp@FreeBSD.org
COMMENT=	CLI interface to Digital Logger's (DLI) Power Strips

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4.0:${PORTSDIR}/www/py-beautifulsoup \
		${PYTHON_PKGNAMEPREFIX}requests>=2.0:${PORTSDIR}/www/py-requests \
		${PYTHON_PKGNAMEPREFIX}six>=1.9:${PORTSDIR}/devel/py-six

USES=		python
USE_PYTHON=	autoplist concurrent distutils
NO_ARCH=	yes

.include <bsd.port.mk>
