# $FreeBSD$

PORTNAME=	spectra
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.1
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ library for large scale eigenvalue problems

LICENSE=	MPL20

USES=		eigen:3,run
USE_GITHUB=	yes
GH_ACCOUNT=	yixuan
NO_BUILD=	yes
NO_ARCH=	yes

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} include ${STAGEDIR}${PREFIX}

.include <bsd.port.mk>
