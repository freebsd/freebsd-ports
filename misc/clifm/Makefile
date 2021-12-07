# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>

PORTNAME=	clifm
PORTVERSION=	1.3
DISTVERSIONPREFIX=	v
CATEGORIES=	misc

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Non-curses, KISS file manager for the terminal

LICENSE=	GPLv2+

USES=		desktop-file-utils gettext-runtime readline
USE_GITHUB=	yes
GH_ACCOUNT=	leo-arch
ALL_TARGET=	build

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

.include <bsd.port.mk>
