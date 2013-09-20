# Created by: Josh Gilliam <josh@quick.net>
# $FreeBSD$

PORTNAME=	aspell
PORTVERSION=	0.60.6.1
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	aspell

MAINTAINER=	office@FreeBSD.org
COMMENT=	Spelling checker with better suggestion logic than ispell

LICENSE=	LGPL21

OPTIONS_DEFINE=	NLS DOCS ISPELL

ISPELL_DESC=	Install the ispell wrapper

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=		--enable-dict-dir=${DATADIR}	\
			--enable-docdir=${DOCSDIR}	\
			--enable-curses=ncursesw \
			--enable-static

USE_GMAKE=		yes
USES=			iconv perl5
USE_PERL5=		build
USE_LDCONFIG=		yes

MAKE_ARGS=		NOPORTDOCS=${NOPORTDOCS}
VERINST=		${PORTVERSION:R:R}
SUB_FILES=		aspell.ver
PLIST_SUB=		VER=${VERINST}
SUB_LIST=		VERINST=${VERINST}

NO_STAGE=	yes
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

.if ${PORT_OPTIONS:MDOCS}
MAN1=			aspell-import.1 aspell.1 pspell-config.1		\
			run-with-aspell.1 word-list-compress.1 prezip-bin.1
INFO=			aspell-dev aspell
.endif

# Does not link without at least -O
.if !defined(CFLAGS) || ${CFLAGS:M-O*} == ""
CFLAGS+=		-O
.endif

post-install:	${DICT_TARGET}
	@${INSTALL_DATA} ${WRKDIR}/aspell.ver ${PREFIX}/etc
.if ${PORT_OPTIONS:MISPELL}
	@${INSTALL_SCRIPT} ${SCRIPTS:S|^|${WRKSRC}/scripts/|} ${PREFIX}/bin
.endif
	@${ECHO_CMD} "@dirrm share/aspell" >> ${TMPPLIST}
	@${ECHO_CMD} "@dirrm lib/aspell-${VERINST}" >> ${TMPPLIST}

.include <bsd.port.mk>
