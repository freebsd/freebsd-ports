# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>

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
ALL_TARGET=	build
SHEBANG_FILES=	misc/tools/manpages_comp_gen.py

OPTIONS_DEFINE=	COLORS
OPTIONS_DEFAULT=	COLORS
OPTIONS_SUB=	yes

COLORS_DESC=	Install extra color themes
COLORS_GH_PROJECT=	clifm-colors:cfmc
COLORS_GH_TAGNAME=	v0.1.0:cfmc

post-install-COLORS-on:
	@${MKDIR} ${STAGEDIR}${DATADIR}/colors
	${INSTALL_DATA} ${WRKSRC_cfmc}/colors/*.cfm \
		${STAGEDIR}${DATADIR}/colors

post-stage:
	@${RM} ${STAGEDIR}${DATADIR}/plugins/*.orig

.include <bsd.port.mk>
