# Created by: Tony Shadwick <tshadwick@oss-solutions.com>
# $FreeBSD$

PORTNAME=	htop
DISTVERSION=	2.2.0
CATEGORIES=	sysutils

MAINTAINER=	gaod@hychen.org
COMMENT=	Better top(1) - interactive process viewer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf libtool localbase ncurses pkgconfig python:2.7,build shebangfix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-unicode
USE_GITHUB=	yes
GH_ACCOUNT=	hishamhm
SHEBANG_FILES=	scripts/MakeHeader.py

PLIST_FILES=	bin/htop \
		man/man1/htop.1.gz \
		share/applications/htop.desktop \
		share/pixmaps/htop.png

OPTIONS_DEFINE=		LSOF
OPTIONS_DEFAULT=	LSOF

LSOF_RUN_DEPENDS=	lsof:sysutils/lsof

.include <bsd.port.mk>
