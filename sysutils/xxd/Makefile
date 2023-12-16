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

USE_GITHUB=	yes
GH_ACCOUNT=	vim
GH_PROJECT=	vim

ALL_TARGET=	${PORTNAME}
EXTRACT_AFTER_ARGS=	--include='*/src/xxd*' \
			--include='*/runtime/doc/uganda.txt' \
			--include='*/runtime/doc/xxd.1'
PORTSCOUT=	ignore:1

WRKSRC_SUBDIR=	src/xxd
WRKDOCS=	${WRKSRC}/../../runtime/doc

DISTINFO_FILE=	${VIM_PORT}/distinfo
PLIST_FILES=	bin/xxd \
		man/man1/xxd.1.gz

.include <bsd.port.pre.mk>

VIM_PORT=		${.CURDIR}/../../editors/vim
VIM_DISTVERSION!=	${BSDMAKE} -f ${VIM_PORT}/Makefile -V DISTVERSION

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xxd ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKDOCS}/xxd.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.post.mk>
