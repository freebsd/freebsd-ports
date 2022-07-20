PORTNAME=	clifm
PORTVERSION=	1.6
DISTVERSIONPREFIX=	v
CATEGORIES=	misc

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Non-curses, KISS file manager for the terminal

LICENSE=	GPLv2+

RUN_DEPENDS=	gfind:misc/findutils guniq:sysutils/coreutils

USES=		desktop-file-utils gettext-runtime python:run \
		readline shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	leo-arch
GH_PROJECT=	${PORTNAME}-colors:cfmc
GH_TAGNAME=	e9ee1c4:cfmc
ALL_TARGET=	build
SHEBANG_FILES=	misc/tools/manpages_comp_gen.py

post-install:
	${INSTALL_DATA} ${WRKSRC_cfmc}/colors/*.cfm \
		${STAGEDIR}${DATADIR}/colors

post-stage:
	@${RM} ${STAGEDIR}${DATADIR}/plugins/*.orig

.include <bsd.port.mk>
