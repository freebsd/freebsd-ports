# $FreeBSD$

PORTNAME=	pssh
PORTVERSION=	2.3.1
CATEGORIES=	security net sysutils
MASTER_SITES=	CHEESESHOP

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	Parallel versions of the openssh tools

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	rsync:net/rsync

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist distutils concurrent optsuffix

.include <bsd.port.mk>
