# Created by: Dominic Fandrey <kamikaze@bsdforen.de>
# $FreeBSD$

PORTNAME=	automounter
PORTVERSION=	1.5.1
CATEGORIES=	sysutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Provides scripts to dynamically configure amd

LICENSE=	BSD2CLAUSE

WRKSRC_SUBDIR=	src
NO_BUILD=	yes
PKGMESSAGE=	${WRKSRC}/../NOTES

USE_GITHUB=	yes
GH_ACCOUNT=	lonkamikaze

do-install:
		@(cd ${WRKSRC}; ./install.sh -destdir=${STAGEDIR} \
			-prefix=${PREFIX})

.include <bsd.port.mk>
