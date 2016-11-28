# $FreeBSD$

PORTNAME=	ohmu
PORTVERSION=	1.1.0
PORTREVISION=	2
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	neel@neelc.org
COMMENT=	Tool to view space usage in your terminal

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}scandir>=1.3:sysutils/py-scandir \
		${PYTHON_PKGNAMEPREFIX}future>=0.15.2:devel/py-future

USE_GITHUB=	yes
GH_ACCOUNT=	paul-nechifor

USES=		python
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

.include <bsd.port.mk>
