# Created by: Tony Shadwick <tshadwick@oss-solutions.com>
# $FreeBSD$

PORTNAME=	htop
PORTVERSION=	2.0.0
PORTREVISION=	2
CATEGORIES=	sysutils

MAINTAINER=	gaod@hychen.org
COMMENT=	Better top(1) - interactive process viewer

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lexecinfo

CONFIGURE_ARGS=	--enable-unicode
USES=		autoreconf execinfo libtool ncurses python:2,build shebangfix
SHEBANG_LANG=	python2
SHEBANG_FILES=	scripts/MakeHeader.py
USE_GITHUB=	yes
GH_ACCOUNT=	hishamhm

.include <bsd.port.mk>
