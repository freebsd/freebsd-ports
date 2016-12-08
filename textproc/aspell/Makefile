# Created by: Josh Gilliam <josh@quick.net>
# $FreeBSD$

PORTNAME=	aspell
PORTVERSION=	0.60.6.1
PORTREVISION=	6
CATEGORIES=	textproc
MASTER_SITES=	GNU/aspell

MAINTAINER=	office@FreeBSD.org
COMMENT=	Spelling checker with better suggestion logic than ispell

LICENSE=	LGPL21

OPTIONS_DEFINE=	NLS DOCS
OPTIONS_SUB=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-dict-dir=${DATADIR}	\
		--enable-docdir=${DOCSDIR}	\
		--enable-curses=ncursesw \
		--enable-static

USES=		cpe gmake iconv libtool ncurses perl5 shebangfix
USE_LDCONFIG=	yes
SHEBANG_FILES=	scripts/aspell-import
CPE_VENDOR=	gnu

INSTALL_TARGET=	install-strip
VERINST=	${PORTVERSION:R:R}
SUB_FILES=	aspell.ver
PLIST_SUB=	VER=${VERINST}
SUB_LIST=	VERINST=${VERINST}
INFO=	aspell-dev aspell

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.options.mk>

# Does not link without at least -O
.if !defined(CFLAGS) || ${CFLAGS:M-O*} == ""
CFLAGS+=		-O
.endif

post-install:
	@${INSTALL_DATA} ${WRKDIR}/aspell.ver ${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
