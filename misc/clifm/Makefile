PORTNAME=	clifm
PORTVERSION=	1.26
DISTVERSIONPREFIX=	v
CATEGORIES=	misc

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Non-curses, KISS file manager for the terminal
WWW=		https://github.com/leo-arch/clifm/wiki

LICENSE=	GPLv2+

RUN_DEPENDS=	gfind:misc/findutils guniq:sysutils/coreutils

USES=		desktop-file-utils gettext-runtime python:run \
		readline shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	leo-arch
GH_PROJECT=	${PORTNAME}-colors:cfmc
GH_TAGNAME=	9075864:cfmc
ALL_TARGET=	build
MAKE_ENV=	LIBS_FreeBSD="-I${LOCALBASE}/include -L${LOCALBASE}/lib \
		-lreadline -lintl -lmagic" MANDIR=${PREFIX}/share/man
SHEBANG_FILES=	misc/tools/deroff.py misc/tools/manpages_comp_gen.py

post-install:
	${INSTALL_DATA} ${WRKSRC_cfmc}/colors/*.clifm \
		${STAGEDIR}${DATADIR}/colors

.include <bsd.port.mk>
