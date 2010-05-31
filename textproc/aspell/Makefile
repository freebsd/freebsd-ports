# New ports collection makefile for:	aspell
# Date created:				7 December 1998
# Whom:					Josh Gilliam <josh@quick.net>
#
# $FreeBSD$
#

PORTNAME=	aspell
PORTVERSION=	0.60.6
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	aspell
.if defined(WITHOUT_DICTEN)
PKGNAMESUFFIX=	-without-dicten
.endif
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Spelling checker with better suggestion logic than ispell

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=		--enable-dict-dir=${DATADIR}	\
			--enable-docdir=${DOCSDIR}	\
			--enable-static
PTHREAD_CFLAGS=		# Disable threading
PTHREAD_LIBS=		# libaspell may be used by unthreaded apps.
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}"	\
			LDFLAGS="-L${LOCALBASE}/lib ${LDFLAGS} ${PTHREAD_LIBS}"
USE_GMAKE=		yes
USE_ICONV=		yes
USE_PERL5_BUILD=	yes
USE_LDCONFIG=		yes

SLAVEDIRS=		textproc/aspell-without-dicten

MAKE_ARGS=		NOPORTDOCS=${NOPORTDOCS}
VERINST=		${PORTVERSION:R}
SUB_FILES=		aspell.ver
PLIST_SUB=		VER=${VERINST}
SUB_LIST=		VERINST=${VERINST}

.if defined(WITHOUT_DICTEN)
CONFLICTS=		aspell-0.*
DICT_TARGET=
.else
VERDICT_EN=		6-en-6.0-0
DICT_SUFFIX=		.tar.bz2
MASTER_SITES+=		${MASTER_SITE_GNU:S|$|:dicten|}
MASTER_SITE_SUBDIR+=	aspell/dict/en/:dicten
DISTFILES+=		aspell${VERDICT_EN}${DICT_SUFFIX}:dicten
CONFLICTS=		aspell-without-dicten-0.*
DICT_TARGET=		inst-dicten
CONF_DICT_ENV=		ASPELL="${PREFIX}/bin/aspell"	\
			WORD_LIST_COMPRESS="${PREFIX}/bin/word-list-compress"
.endif

.if defined(WITH_ISPELL)
CONFLICTS+=		ispell* ??-ispell*
SCRIPTS=		ispell spell
PLIST_SUB+=		SCRIPTS=""
.else
PLIST_SUB+=		SCRIPTS="@comment "
.endif

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		NLS="@comment "
.else
USE_GETTEXT=		yes
PLIST_SUB+=		NLS=""
.endif

.if !defined(NOPORTDOCS)
MAN1=			aspell-import.1 aspell.1 pspell-config.1		\
			run-with-aspell.1 word-list-compress.1 prezip-bin.1
INFO=			aspell-dev aspell
.endif

# Does not link without at least -O
.if !defined(CFLAGS) || ${CFLAGS:M-O*} == ""
CFLAGS+=		-O
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 602107
CONFIGURE_ARGS+=	--disable-wide-curses
.else
CONFIGURE_ARGS+=	--enable-curses=ncursesw
.endif

pre-everything::
	@${ECHO_MSG} ""
.if !defined(WITH_ISPELL)
	@${ECHO_MSG} "Define WITH_ISPELL to install Ispell's wrapper."
	@${ECHO_MSG} ""
.endif
.if !defined(WITHOUT_DICTEN)
	@${ECHO_MSG} "Define WITHOUT_DICTEN to not install english dictionary."
	@${ECHO_MSG} ""
.endif

post-extract:
.if !defined(WITHOUT_DICTEN)
	cd ${WRKDIR} && \
	${TAR} -xjf ${DISTDIR}/aspell${VERDICT_EN}${DICT_SUFFIX}
.endif

pre-configure:
	@cd ${WRKSRC} && ${ACLOCAL}

post-install:	${DICT_TARGET}
	${INSTALL_DATA} ${WRKDIR}/aspell.ver ${PREFIX}/etc
.if defined(WITH_ISPELL)
	${INSTALL_SCRIPT} ${SCRIPTS:S|^|${WRKSRC}/scripts/|} ${PREFIX}/bin
.endif
	@${ECHO_CMD} "@dirrm share/aspell" >> ${TMPPLIST}
	@${ECHO_CMD} "@dirrm lib/aspell-${VERINST}" >> ${TMPPLIST}

inst-dicten:
# Install en-aspell by default
.if !exists(${LOCALBASE}/lib/aspell-${VERINST}/en.dat) && !defined(WITHOUT_DICTEN)
	@${ECHO_MSG} "===>   Installing for en dictionaries"
	cd ${WRKDIR}/aspell${VERDICT_EN} &&		\
	 ${CONF_DICT_ENV} ./${CONFIGURE_SCRIPT} &&	\
	 ${GMAKE} ${INSTALL_TARGET}
	${SED} -e "s|%%VER%%|${VERINST}|" ${MASTERDIR}/pkg-plist.en	\
		>> ${TMPPLIST}
.endif

.include <bsd.port.post.mk>
