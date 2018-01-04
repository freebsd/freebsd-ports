# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	zdaemon
PORTVERSION=	4.1.0
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Daemon Process Control Library and Tools for Unix-bases Systems

LICENSE=	ZPL21
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zconfig>0:devel/py-zconfig@${FLAVOR}

NO_ARCH=	yes
USES=		python zip
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
