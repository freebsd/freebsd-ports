PORTNAME=	xxd
DISTVERSIONPREFIX=	${VIM_DISTVERSIONPREFIX}
DISTVERSION=	${VIM_DISTVERSION}
CATEGORIES=	sysutils

MAINTAINER=	gmarco@giovannelli.it
COMMENT=	Hexdump and reverse hexdump utility from vim distribution
WWW=		${VIM_WWW}

CONFLICTS_INSTALL=	vim-[0-9]* vim-console vim-gtk2 vim-gtk3 vim-motif vim-x11

DISTINFO_FILE=	${VIM_PORT}/distinfo
ALL_TARGET=	${PORTNAME}
PORTSCOUT=	ignore:1
EXTRACT_AFTER_ARGS=	--include='*/src/xxd*'
WRKSRC_SUBDIR=	src/xxd

PLIST_FILES=	bin/xxd

USE_GITHUB=	yes
GH_ACCOUNT=	vim
GH_PROJECT=	vim

.include <bsd.port.pre.mk>

VIM_PORT=		${.CURDIR}/../../editors/vim
VIM_DISTVERSIONPREFIX!=	${BSDMAKE} -f ${VIM_PORT}/Makefile -V DISTVERSIONPREFIX
VIM_DISTVERSION!=	${BSDMAKE} -f ${VIM_PORT}/Makefile -V DISTVERSION
VIM_WWW!=		${BSDMAKE} -f ${VIM_PORT}/Makefile -V WWW

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xxd ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.post.mk>
