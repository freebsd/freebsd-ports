# Created by: Kris Moore <kmoore@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pbi-manager
PORTVERSION=	1456333648
CATEGORIES=	sysutils

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	PBI management utilities

LICENSE=	BSD3CLAUSE

DEPRECATED=	Abandoned upstream
EXPIRATION_DATE=	2019-12-15

RUN_DEPENDS=	${LOCALBASE}/share/pcbsd/scripts/functions.sh:sysutils/pcbsd-libsh

WRKSRC_SUBDIR=	src-sh/pbi-manager
USES=		pkgconfig
NO_BUILD=	yes
NO_ARCH=	yes
MAKE_ARGS=	PREFIX=${STAGEDIR}${PREFIX}

USE_GITHUB=	yes
GH_ACCOUNT=	pcbsd
GH_PROJECT=	pcbsd
GH_TAGNAME=	b77814

.include <bsd.port.mk>
