PORTNAME=	xxd
DISTVERSIONPREFIX=	v
DISTVERSION=	9.0.1366
CATEGORIES=	sysutils

MAINTAINER=	gmarco@giovannelli.it
COMMENT=	Hexdump and reverse hexdump utility
WWW=		https://github.com/mew-cx/xxd

CONFLICTS_INSTALL=	vim-[0-9]* vim-gtk2 vim-gtk3 vim-motif vim-x11

ALL_TARGET=	${PORTNAME}
PORTSCOUT=	ignore:1
EXTRACT_AFTER_ARGS=	--include='*/src/xxd*'
WRKSRC_SUBDIR=	src/xxd

PLIST_FILES=	bin/xxd

USE_GITHUB=	yes
GH_ACCOUNT=	vim
GH_PROJECT=	vim

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xxd ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
