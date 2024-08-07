PORTNAME=	aspell
PORTVERSION=	0.60.8.1
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	textproc
MASTER_SITES=	GNU/aspell

PATCH_SITES=	https://github.com/GNUAspell/${PORTNAME}/commit/
PATCHFILES+=	ee6cbb12ff36a1e6618d7388a78dd4e0a2b44041.patch:-p1

MAINTAINER=	office@FreeBSD.org
COMMENT=	Spelling checker with better suggestion logic than ispell
WWW=		http://aspell.net/

LICENSE=	LGPL21

USES=		cpe gmake iconv libtool ncurses perl5 shebangfix
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--enable-dict-dir=${DATADIR}	\
		--enable-docdir=${DOCSDIR}	\
		--enable-curses="${NCURSESLIBS}" \
		--enable-static
USE_LDCONFIG=	yes
SHEBANG_FILES=	scripts/aspell-import
CPE_VENDOR=	gnu

INSTALL_TARGET=	install-strip
VERINST=	${PORTVERSION:R:R}
SUB_FILES=	aspell.ver
PLIST_SUB=	VER=${VERINST}
SUB_LIST=	VERINST=${VERINST}
INFO=		aspell aspell-dev

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

post-install:
	${INSTALL_DATA} ${WRKDIR}/aspell.ver ${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
