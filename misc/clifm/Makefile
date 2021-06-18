# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>

PORTNAME=	clifm
PORTVERSION=	1.1
DISTVERSIONPREFIX=	v
CATEGORIES=	misc

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Non-curses, KISS file manager for the terminal

LICENSE=	GPLv2

USES=		desktop-file-utils gettext-runtime gmake localbase readline
USE_GITHUB=	yes
GH_ACCOUNT=	leo-arch
ALL_TARGET=	build
MAKE_ENV=	INSTALLPREFIX=${STAGEDIR}${PREFIX}/bin \
		DESKTOPPREFIX=${STAGEDIR}${PREFIX}/share

post-patch:
	@${REINPLACE_CMD} -e '/^CFLAGS/s,=.*-march=native,+=,' \
		${WRKSRC}/src/Makefile

.include <bsd.port.mk>
