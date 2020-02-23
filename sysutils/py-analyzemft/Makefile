# Created by: Antoine Brodin <antoine@FreeBSD.org>
# $FreeBSD$

PORTNAME=	analyzemft
PORTVERSION=	2.0.19
CATEGORIES=	sysutils devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	analyzeMFT-${PORTVERSION}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Analyze the MFT from a NTFS filesystem

LICENSE=	CPL
LICENSE_NAME=	Common Public License
LICENSE_FILE=	${WRKSRC}/LICENSE.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

NO_ARCH=	yes
USES=		python:2.7
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
