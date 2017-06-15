# $FreeBSD$

PORTNAME=	dtc
PORTVERSION=	1.4.2
DISTVERSIONPREFIX=	ports-v
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	imp@FreeBSD.org
COMMENT=	Device Tree Compiler

LICENSE=	GPLv2

USES=		bison gmake shebangfix
USE_LDCONFIG=	yes
SHEBANG_FILES=	dtdiff

USE_GITHUB=	yes
GH_ACCOUNT=	bsdimp
GH_PROJECT=	dtc

MAKE_ARGS+=	PREFIX=${PREFIX}

.include <bsd.port.mk>
