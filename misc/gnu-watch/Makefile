PORTNAME=	watch
DISTVERSIONPREFIX=	v
DISTVERSION=	3.3.17
CATEGORIES=	misc
PKGNAMEPREFIX=	gnu-

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	GNU watch command

LICENSE=	GPLv2

USES=		autoreconf gettext-tools gmake libtool localbase:ldflags \
		ncurses pkgconfig tar:xz
USE_CSTD=	gnu99
USE_GITLAB=	yes
GL_ACCOUNT=	procps-ng
GL_PROJECT=	procps
GL_COMMIT=	19a508ea121c0c4ac6d0224575a036de745eaaf8
GNU_CONFIGURE=	yes

ALL_TARGET=	watch

PLIST_FILES=	bin/${PKGBASE} \
		man/man1/gnu-watch.1.gz

OPTIONS_DEFINE=		NLS UNICODE
OPTIONS_DEFAULT=	UNICODE

NLS_USES=			gettext
NLS_CONFIGURE_OFF=		--disable-nls
NLS_LDFLAGS=			-lintl
UNICODE_CONFIGURE_ENABLE=	watch8bit

post-patch:
	${REINPLACE_CMD} 's/ncursesw/${NCURSES_IMPL}/g' ${WRKSRC}/configure.ac

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/${PKGBASE}
	${INSTALL_MAN} ${WRKSRC}/watch.1 \
		${STAGEDIR}${MANPREFIX}/man/man1/${PKGBASE}.1

.include <bsd.port.mk>
