PORTNAME=	xdiskusage
PORTVERSION=	1.54
CATEGORIES=	x11-fm
MASTER_SITES=	http://xdiskusage.sourceforge.net/ \
		http://www.gnu-darwin.org/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Show where disk space is taken up

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/README

LIB_DEPENDS=	libfltk.so:x11-toolkits/fltk \
		libfontconfig.so:x11-fonts/fontconfig

USES=		gmake tar:tgz xorg

USE_XORG=	x11 xcursor xext xfixes xft xinerama xrender

CXXFLAGS+=	`fltk-config --cxxflags`
LDFLAGS+=	`fltk-config --ldflags`

PLIST_FILES=	bin/xdiskusage man/man1/xdiskusage.1.gz

post-patch:
	@${REINPLACE_CMD} -e '/^configure:/d; /autoconf/d' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e '/@CXXFLAGS@/s|$$| ${CXXFLAGS}|' \
		${WRKSRC}/makeinclude.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xdiskusage ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xdiskusage.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
