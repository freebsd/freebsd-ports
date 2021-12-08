PORTNAME=	colorclass
PORTVERSION=	2.2.0
PORTREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

PATCH_SITES=	https://github.com/Robpol86/${PORTNAME}/commit/
PATCHFILES+=	f8bbe9fdcff1.patch:-p1 # https://github.com/Robpol86/colorclass/pull/27

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Colorful worry-free console applications

LICENSE=	MIT

NO_ARCH=	yes
USES=		python:3.6+
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
