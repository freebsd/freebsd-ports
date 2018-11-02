# Created by: imp
# $FreeBSD$

PORTNAME=	nvme-cli
PORTVERSION=	1.6
CATEGORIES=	sysutils

MAINTAINER=	imp@FreeBSD.org
COMMENT=	Port of Linux nvme cli utility

LICENSE=	GPLv2

# only tested on amd64, all other archs are no-go until we're sure amd64 works.
# And there's plenty in amd64 that compiles, but won't run (eg using /sys/, etc)
ONLY_FOR_ARCHS=	amd64
BROKEN_FreeBSD_11=	Uses newer API than in 11.x

USES=		gmake

USE_GITHUB=	yes
GH_ACCOUNT=	bsdimp
GH_PROJECT=	nvme-cli
GH_TAGNAME=	9221b5f

.include <bsd.port.mk>
