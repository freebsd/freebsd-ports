# New ports collection makefile for:	aspell
# Date created:				7 December 1998
# Whom:					Josh Gilliam <josh@quick.net>
#
# $FreeBSD$
#

PORTNAME?=	aspell
PORTVERSION=	0.60.2
PORTREVISION=	1
CATEGORIES+=	textproc
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	aspell
DISTFILES=	aspell-0.60.2.tar.gz	# needed for slave ports / options
EXTRACT_ONLY=	aspell-0.60.2.tar.gz

MAINTAINER?=	thierry@FreeBSD.org
COMMENT?=	Spelling checker with better suggestion logic than ispell

.if !exists(/usr/bin/bzip2)
BUILD_DEPENDS+=	bzip2:${PORTSDIR}/archivers/bzip2
.endif

USE_LIBTOOL_VER=	15
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=		--enable-dict-dir=${DATADIR}	\
			--enable-docdir=${DOCSDIR}	\
			--enable-static
PTHREAD_CFLAGS=		# Disable threading
PTHREAD_LIBS=		# libaspell may be used by unthreaded apps.
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}"	\
			LDFLAGS="-L${LOCALBASE}/lib ${LDFLAGS} ${PTHREAD_LIBS}"
USE_GMAKE=		yes
USE_ICONV=		yes
USE_GETTEXT=		yes
USE_PERL5_BUILD=	yes
INSTALLS_SHLIB=		yes

MAKE_ARGS=		NOPORTDOCS=${NOPORTDOCS}
VERINST=		${PORTVERSION:R}
PLIST_SUB=		VER=${VERINST}

.if defined(WITH_ISPELL)
CONFLICTS=		ispell* ??-ispell*
SCRIPTS=		ispell spell
PLIST_SUB+=		SCRIPTS=""
.else
PLIST_SUB+=		SCRIPTS="@comment "
.endif

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		NLS="@comment "
.else
PLIST_SUB+=		NLS=""
.endif

.if !defined(NOPORTDOCS)
MAN1=			aspell-import.1 aspell.1 pspell-config.1	\
			run-with-aspell.1 word-list-compress.1
INFO=			aspell-dev aspell
.endif

# Does not link without at least -O
.if !defined(CFLAGS) || ${CFLAGS:M-O*} == ""
CFLAGS+=		-O
.endif

WRKSRC=		${WRKDIR}/aspell-${PORTVERSION}	# needed for slave ports / options
DOCSDIR=	${PREFIX}/share/doc/aspell
DATADIR=	${PREFIX}/share/aspell
DESCR=		${.CURDIR}/pkg-descr

CONF_DICT_ENV=	ASPELL="${PREFIX}/bin/aspell"	\
		WORD_LIST_COMPRESS="${PREFIX}/bin/word-list-compress"
AVAIL_DICT=	af am az be bg bn br ca cs csb cy da de de-alt el en eo es et fa fi fo	\
		fr ga gd gl gv he hi hil hr hsb hu ia id is it la lt lv mi mk mn mr ms	\
		mt nb nds nl nn ny or pa pl pt qu ro ru rw sc sk sl sv sw ta tet tl tn	\
		tr uk uz vi wa yi zu
DICT_SUFFIX=	.tar.bz2

.include <bsd.port.pre.mk>
.include "${FILESDIR}/verdict"

.if defined(LANG)
. for i in ${AVAIL_DICT} no
.  if ${LANG:M${i}*} != ""
DEF_DICT=	${i}
.  endif
. endfor
. if defined(DEF_DICT) && ${DEF_DICT} == no
DEF_DICT=	nn
. endif
.endif
DEF_DICT?=	en

pre-everything::
.if defined(ASPELL_NO)
ASPELL_NN=	yes
.endif
.if defined(WITH_ALL_DICTS)
. for LG in ${AVAIL_DICT}
ASPELL_${LG:U}=	yes
. endfor
.endif
.for LG in ${AVAIL_DICT}
. if defined(ASPELL_${LG:U})
DICTS+=		${LG}
. endif
.endfor
.if !defined(DICTS)
	@${ECHO_MSG} '*********************************************************'
	@${ECHO_MSG} '* You can add further dictionaries:                     *'
	@${ECHO_MSG} '*                                 Use make-flag:        *'
	@${ECHO_MSG} '*  - Afrikaans                    ASPELL_AF=yes         *'
	@${ECHO_MSG} '*  - Amharic                      ASPELL_AM=yes         *'
	@${ECHO_MSG} '*  - Azerbaijani                  ASPELL_AZ=yes         *'
	@${ECHO_MSG} '*  - Belarusian                   ASPELL_BE=yes         *'
	@${ECHO_MSG} '*  - Bengali                      ASPELL_BN=yes         *'
	@${ECHO_MSG} '*  - Bulgarian                    ASPELL_BG=yes         *'
	@${ECHO_MSG} '*  - Breton                       ASPELL_BR=yes         *'
	@${ECHO_MSG} '*  - Catalan / Valencian          ASPELL_CA=yes         *'
	@${ECHO_MSG} '*  - Croatian                     ASPELL_HR=yes         *'
	@${ECHO_MSG} '*  - Czech                        ASPELL_CS=yes         *'
	@${ECHO_MSG} '*  - Danish                       ASPELL_DA=yes         *'
	@${ECHO_MSG} '*  - Dutch                        ASPELL_NL=yes         *'
	@${ECHO_MSG} '*  - English                      ASPELL_EN=yes         *'
	@${ECHO_MSG} '*  - Esperanto                    ASPELL_EO=yes         *'
	@${ECHO_MSG} '*  - Estonian                     ASPELL_ET=yes         *'
	@${ECHO_MSG} '*  - Faroese                      ASPELL_FO=yes         *'
	@${ECHO_MSG} '*  - Finnish                      ASPELL_FI=yes         *'
	@${ECHO_MSG} '*  - French                       ASPELL_FR=yes         *'
	@${ECHO_MSG} '*  - Galician                     ASPELL_GL=yes         *'
	@${ECHO_MSG} '*  - German                       ASPELL_DE=yes         *'
	@${ECHO_MSG} '*  - German (orig spelling rules) ASPELL_DE-ALT=yes     *'
	@${ECHO_MSG} '*  - Greek                        ASPELL_EL=yes         *'
	@${ECHO_MSG} '*  - Hebrew                       ASPELL_HE=yes         *'
	@${ECHO_MSG} '*  - Hiligaynon                   ASPELL_HIL=yes        *'
	@${ECHO_MSG} '*  - Hindi                        ASPELL_HI=yes         *'
	@${ECHO_MSG} '*  - Hungarian                    ASPELL_HU=yes         *'
	@${ECHO_MSG} '*  - Icelandic                    ASPELL_IS=yes         *'
	@${ECHO_MSG} '*  - Indonesian                   ASPELL_ID=yes         *'
	@${ECHO_MSG} '*  - Interlingua                  ASPELL_IA=yes         *'
	@${ECHO_MSG} '*  - Irish (Gaelic)               ASPELL_GA=yes         *'
	@${ECHO_MSG} '*  - Italian                      ASPELL_IT=yes         *'
	@${ECHO_MSG} '*  - Kashubian                    ASPELL_CSB=yes        *'
	@${ECHO_MSG} '*  - Kinyarwanda                  ASPELL_RW=yes         *'
	@${ECHO_MSG} '*  - Latin                        ASPELL_LA=yes         *'
	@${ECHO_MSG} '*  - Latvian                      ASPELL_LV=yes         *'
	@${ECHO_MSG} '*  - Lithuanian                   ASPELL_LT=yes         *'
	@${ECHO_MSG} '*  - Low Saxon                    ASPELL_NDS=yes        *'
	@${ECHO_MSG} '*  - Macedonian                   ASPELL_MK=yes         *'
	@${ECHO_MSG} '*  - Maori                        ASPELL_MI=yes         *'
	@${ECHO_MSG} '*  - Malay                        ASPELL_MS=yes         *'
	@${ECHO_MSG} '*  - Maltese                      ASPELL_MT=yes         *'
	@${ECHO_MSG} '*  - Manx Gaelic                  ASPELL_GV=yes         *'
	@${ECHO_MSG} '*  - Marathi                      ASPELL_MR=yes         *'
	@${ECHO_MSG} '*  - Mongolian                    ASPELL_MN=yes         *'
	@${ECHO_MSG} '*  - Norwegian Bokmal             ASPELL_NB=yes         *'
	@${ECHO_MSG} '*  - Norwegian Nynorsk            ASPELL_NN=yes         *'
	@${ECHO_MSG} '*  - Nyanja (Chichewa)            ASPELL_NY=yes         *'
	@${ECHO_MSG} '*  - Oriya                        ASPELL_OR=yes         *'
	@${ECHO_MSG} '*  - Persian (Farsi)              ASPELL_FA=yes         *'
	@${ECHO_MSG} '*  - Polish                       ASPELL_PL=yes         *'
	@${ECHO_MSG} '*  - Portuguese                   ASPELL_PT=yes         *'
	@${ECHO_MSG} '*  - Punjabi                      ASPELL_PU=yes         *'
	@${ECHO_MSG} '*  - Quechua                      ASPELL_QU=yes         *'
	@${ECHO_MSG} '*  - Romanian                     ASPELL_RO=yes         *'
	@${ECHO_MSG} '*  - Russian                      ASPELL_RU=yes         *'
	@${ECHO_MSG} '*  - Sardinian                    ASPELL_SC=yes         *'
	@${ECHO_MSG} '*  - Scottish Gaelic              ASPELL_GD=yes         *'
	@${ECHO_MSG} '*  - Slovak                       ASPELL_SK=yes         *'
	@${ECHO_MSG} '*  - Slovenian                    ASPELL_SL=yes         *'
	@${ECHO_MSG} '*  - Swahili                      ASPELL_SW=yes         *'
	@${ECHO_MSG} '*  - Spanish                      ASPELL_ES=yes         *'
	@${ECHO_MSG} '*  - Swedish                      ASPELL_SV=yes         *'
	@${ECHO_MSG} '*  - Tagalog                      ASPELL_TL=yes         *'
	@${ECHO_MSG} '*  - Tamil                        ASPELL_TA=yes         *'
	@${ECHO_MSG} '*  - Tetum                        ASPELL_TET=yes        *'
	@${ECHO_MSG} '*  - Tswana                       ASPELL_TN=yes         *'
	@${ECHO_MSG} '*  - Turkish                      ASPELL_TR=yes         *'
	@${ECHO_MSG} '*  - Ukrainian                    ASPELL_UK=yes         *'
	@${ECHO_MSG} '*  - Upper Sorbian                ASPELL_HSB=yes        *'
	@${ECHO_MSG} '*  - Uzbek                        ASPELL_UZ=yes         *'
	@${ECHO_MSG} '*  - Vietnamese                   ASPELL_VI=yes         *'
	@${ECHO_MSG} '*  - Walloon                      ASPELL_WA=yes         *'
	@${ECHO_MSG} '*  - Welsh                        ASPELL_CY=yes         *'
	@${ECHO_MSG} '*  - Yiddish                      ASPELL_YI=yes         *'
	@${ECHO_MSG} '*  - Zulu                         ASPELL_ZU=yes         *'
	@${ECHO_MSG} '*                                                       *'
	@${ECHO_MSG} '* Example: "make ASPELL_FR=yes ASPELL_EN=yes install"   *'
	@${ECHO_MSG} '*********************************************************'
. for LG in ${AVAIL_DICT}
.  if (${DEF_DICT} == ${LG})
DICTS=	${LG}
.  endif
. endfor
.endif

.for DICO in ${DICTS}
MASTER_SITES+=	ftp://ftp.gnu.org/gnu/aspell/dict/${DICO:S/-alt//}/:dict${DICO:S/-//}		\
		http://gnu.mirror.mcgill.ca/aspell/dict/${DICO:S/-alt//}/:dict${DICO:S/-//}	\
		http://mirrors.usc.edu/pub/gnu/aspell/dict/${DICO:S/-alt//}/:dict${DICO:S/-//}	\
		ftp://ftp.sunsite.org.uk/package/gnu/aspell/dict/${DICO:S/-alt//}/:dict${DICO:S/-//}
DISTFILES+=	aspell${VERDICT_${DICO:U}}${DICT_SUFFIX}:dict${DICO:S/-//}
.endfor

post-extract:
.for DICO in ${DICTS}
	@cd ${WRKDIR} && \
	 ${TAR} -xjf ${DISTDIR}/aspell${VERDICT_${DICO:U}}${DICT_SUFFIX}
.endfor

pre-configure:
	@cd ${WRKSRC} && ${ACLOCAL}

post-install:
.for DICO in ${DICTS}
	@${ECHO_MSG} "===>   Installing for ${DICO} dictionaries"
	@cd ${WRKDIR}/aspell${VERDICT_${DICO:U}} &&	\
	 ${CONF_DICT_ENV} ./${CONFIGURE_SCRIPT} &&		\
	 ${GMAKE} install
	@${SED} -e "s|%%VER%%|${VERINST}|" ${MASTERDIR}/pkg-plist.${DICO}	\
		>> ${TMPPLIST}
.endfor
	@${ECHO_CMD} "@dirrm share/aspell" >> ${TMPPLIST}
	@${ECHO_CMD} "@dirrm lib/aspell-${VERINST}" >> ${TMPPLIST}
.if defined(WITH_ISPELL)
	${INSTALL_SCRIPT} ${SCRIPTS:S|^|${WRKSRC}/scripts/|} ${PREFIX}/bin
.endif

.include <bsd.port.post.mk>
