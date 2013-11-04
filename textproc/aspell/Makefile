# Created by: Josh Gilliam <josh@quick.net>
# $FreeBSD$

PORTNAME=	aspell
PORTVERSION=	0.60.6.1
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	aspell

MAINTAINER=	office@FreeBSD.org
COMMENT=	Spelling checker with better suggestion logic than ispell

LICENSE=	LGPL21

OPTIONS_DEFINE=	NLS DOCS ISPELL

ISPELL_DESC=	Install the ispell wrapper

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-dict-dir=${DATADIR}	\
		--enable-docdir=${DOCSDIR}	\
		--enable-curses=ncursesw \
		--enable-static

USES=		gmake iconv perl5 shebangfix
USE_LDCONFIG=	yes
SHEBANG_FILES=	scripts/aspell-import

VERINST=	${PORTVERSION:R:R}
SUB_FILES=	aspell.ver
PLIST_SUB=	VER=${VERINST}
SUB_LIST=	VERINST=${VERINST}
INFO=	aspell-dev aspell

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=		NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		NLS="@comment "
.endif

.if ${PORT_OPTIONS:MISPELL}
CONFLICTS+=            ispell* ??-ispell*
SCRIPTS=               ispell spell
PLIST_SUB+=            SCRIPTS=""
.else
PLIST_SUB+=            SCRIPTS="@comment "
.endif

# Does not link without at least -O
.if !defined(CFLAGS) || ${CFLAGS:M-O*} == ""
CFLAGS+=		-O
.endif

post-install:	${DICT_TARGET}
	@${INSTALL_DATA} ${WRKDIR}/aspell.ver ${STAGEDIR}${PREFIX}/etc
.if ${PORT_OPTIONS:MISPELL}
	@${INSTALL_SCRIPT} ${SCRIPTS:S|^|${WRKSRC}/scripts/|} ${STAGEDIR}${PREFIX}/bin
.endif
	@${ECHO_CMD} "@dirrm share/aspell" >> ${TMPPLIST}
	@${ECHO_CMD} "@dirrm lib/aspell-${VERINST}" >> ${TMPPLIST}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libaspell.so.16 \
		${STAGEDIR}${PREFIX}/lib/libpspell.so.16

.include <bsd.port.mk>
