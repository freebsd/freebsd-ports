PORTNAME=	xxd
DISTVERSIONPREFIX=	v
DISTVERSION=	${VIM_DISTVERSION}
CATEGORIES=	sysutils

MAINTAINER=	gmarco@giovannelli.it
COMMENT=	Hexdump and reverse hexdump utility from vim distribution
WWW=		https://www.vim.org/

LICENSE=	VIM
LICENSE_NAME=	VIM License
LICENSE_FILE=	${WRKSRC}/../../runtime/doc/uganda.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

CONFLICTS_INSTALL=	vim vim-gtk2 vim-gtk3 vim-motif vim-x11

DISTINFO_FILE=	${VIM_PORT}/distinfo
ALL_TARGET=	${PORTNAME}
PORTSCOUT=	ignore:1
EXTRACT_AFTER_ARGS=	--include='*/src/xxd*' --include='*/runtime/doc/uganda.txt'
WRKSRC_SUBDIR=	src/xxd

PLIST_FILES=	bin/xxd

USE_GITHUB=	yes
GH_ACCOUNT=	vim
GH_PROJECT=	vim

.include <bsd.port.pre.mk>

VIM_PORT=		${.CURDIR}/../../editors/vim
VIM_DISTVERSION!=	${BSDMAKE} -f ${VIM_PORT}/Makefile -V DISTVERSION

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xxd ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.post.mk>
