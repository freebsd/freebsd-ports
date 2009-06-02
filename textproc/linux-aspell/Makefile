# New ports collection makefile for:	linux-aspell
# Date created:				14 May 2004
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	aspell
PORTVERSION=	0.50.4.1
PORTREVISION=	4
CATEGORIES=	textproc linux
MASTER_SITES=	ftp://ftp.pbone.net/mirror/ftp.ximian.com/pub/ximian-evolution/redhat-80-i386/ \
		ftp://ftp.pbone.net/mirror/ftp.ximian.com/pub/ximian-evolution/redhat-80-i386/source/ \
		ftp://ftp.is.co.za/mirror/ftp.ximian.com/ximian-evolution/redhat-80-i386/ \
		ftp://ftp.chg.ru/pub/X11/ximian/ximian-evolution/redhat-80-i386/
DISTNAME=	${PORTNAME}-${PORTVERSION}-0.ximian.5.1
DISTFILES=	${DISTNAME}.i386.rpm	# needed for slave ports / options
EXTRACT_SUFX=	.i386.rpm
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Spelling checker with better logic than ispell (linux version)

CONFLICTS=	linux-f8-aspell-[0-9]* linux-f10-aspell-[0-9]*

USE_LINUX_RPM=	yes
ONLY_FOR_ARCHS=	i386 amd64
USE_GMAKE=	yes
MD5_FILE=	${MASTERDIR}/distinfo
DIST_SUBDIR=	rpm
BRANDELF_DIRS=	usr/bin

CONF_DICT_ENV=	ASPELL="${PREFIX}/usr/bin/aspell" \
		WORD_LIST_COMPRESS="${PREFIX}/usr/bin/word-list-compress"
AVAIL_DICT=	af bg br ca cs cy da de el en eo es fo fr hr ia id it ga gd gl \
		gv is mi ms mt nb nl nn pl pt ro ru sk sl sv sw tn tr uk wa zu
SPECDICTS=	af bg cs cy da el en fo fr ga gd gl gv hr ia id is it mi ms mt \
		nb nn pl sk sl sv sw tn tr uk wa zu
DICTVERSION=	0.50-2
DICTVER_AF=	0.50-0
DICTVER_BG=	0.50-0
DICTVER_CS=	0.51-0
DICTVER_CY=	0.50-3
DICTVER_DA=	0.50.1-0
DICTVER_EL=	0.50-3
DICTVER_EN=	0.51-1
DICTVER_FO=	0.51-0
DICTVER_FR=	0.50-3
DICTVER_GA=	0.50.1-0
DICTVER_GD=	0.50-0
DICTVER_GL=	0.50-0
DICTVER_GV=	0.50-0
DICTVER_HR=	0.51-0
DICTVER_IA=	0.50-1
DICTVER_ID=	0.50.1-0
DICTVER_IS=	0.51.1-0
DICTVER_IT=	0.53-0
DICTVER_MI=	0.50-0
DICTVER_MS=	0.50-0
DICTVER_MT=	0.50-0
DICTVER_NB=	0.50.1-0
DICTVER_NN=	0.50.1-1
DICTVER_PL=	0.51-0
DICTVER_SK=	0.52-0
DICTVER_SL=	0.50-0
DICTVER_SV=	0.51-0
DICTVER_SW=	0.50-0
DICTVER_TN=	0.50-0
DICTVER_TR=	0.50-0
DICTVER_UK=	0.51-0
DICTVER_WA=	0.50-0
DICTVER_ZU=	0.50-0
DICT_SUFFIX=	.tar.bz2

.include <bsd.port.pre.mk>

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
DICO_WRKDIR=	${WRKDIR}_DICO

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
	@${ECHO_MSG} '*  - Bulgarian                    ASPELL_BG=yes         *'
	@${ECHO_MSG} '*  - Breton                       ASPELL_BR=yes         *'
	@${ECHO_MSG} '*  - Catalan                      ASPELL_CA=yes         *'
	@${ECHO_MSG} '*  - Croatian                     ASPELL_HR=yes         *'
	@${ECHO_MSG} '*  - Czech                        ASPELL_CS=yes         *'
	@${ECHO_MSG} '*  - Danish                       ASPELL_DA=yes         *'
	@${ECHO_MSG} '*  - Dutch                        ASPELL_NL=yes         *'
	@${ECHO_MSG} '*  - English                      ASPELL_EN=yes         *'
	@${ECHO_MSG} '*  - Esperanto                    ASPELL_EO=yes         *'
	@${ECHO_MSG} '*  - Faroese                      ASPELL_FO=yes         *'
	@${ECHO_MSG} '*  - French                       ASPELL_FR=yes         *'
	@${ECHO_MSG} '*  - Galician                     ASPELL_GL=yes         *'
	@${ECHO_MSG} '*  - German                       ASPELL_DE=yes         *'
	@${ECHO_MSG} '*  - Greek                        ASPELL_EL=yes         *'
	@${ECHO_MSG} '*  - Icelandic                    ASPELL_IS=yes         *'
	@${ECHO_MSG} '*  - Indonesian                   ASPELL_ID=yes         *'
	@${ECHO_MSG} '*  - Interlingua                  ASPELL_IA=yes         *'
	@${ECHO_MSG} '*  - Irish (Gaelic)               ASPELL_GA=yes         *'
	@${ECHO_MSG} '*  - Italian                      ASPELL_IT=yes         *'
	@${ECHO_MSG} '*  - Maori                        ASPELL_MI=yes         *'
	@${ECHO_MSG} '*  - Malay                        ASPELL_MS=yes         *'
	@${ECHO_MSG} '*  - Maltese                      ASPELL_MT=yes         *'
	@${ECHO_MSG} '*  - Manx Gaelic                  ASPELL_GV=yes         *'
	@${ECHO_MSG} '*  - Norwegian Bokmal             ASPELL_NB=yes         *'
	@${ECHO_MSG} '*  - Norwegian Nynorsk            ASPELL_NN=yes         *'
	@${ECHO_MSG} '*  - Polish                       ASPELL_PL=yes         *'
	@${ECHO_MSG} '*  - Portuguese                   ASPELL_PT=yes         *'
	@${ECHO_MSG} '*  - Romanian                     ASPELL_RO=yes         *'
	@${ECHO_MSG} '*  - Russian                      ASPELL_RU=yes         *'
	@${ECHO_MSG} '*  - Scottish Gaelic              ASPELL_GD=yes         *'
	@${ECHO_MSG} '*  - Slovak                       ASPELL_SK=yes         *'
	@${ECHO_MSG} '*  - Slovenian                    ASPELL_SL=yes         *'
	@${ECHO_MSG} '*  - Swahili                      ASPELL_SW=yes         *'
	@${ECHO_MSG} '*  - Spanish                      ASPELL_ES=yes         *'
	@${ECHO_MSG} '*  - Swedish                      ASPELL_SV=yes         *'
	@${ECHO_MSG} '*  - Tswana                       ASPELL_TN=yes         *'
	@${ECHO_MSG} '*  - Turkish                      ASPELL_TR=yes         *'
	@${ECHO_MSG} '*  - Ukrainian                    ASPELL_UK=yes         *'
	@${ECHO_MSG} '*  - Walloon                      ASPELL_WA=yes         *'
	@${ECHO_MSG} '*  - Welsh                        ASPELL_CY=yes         *'
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
MASTER_SITES+=	ftp://ftp.gnu.org/gnu/aspell/dict/${DICO}/:dict${DICO} \
		http://gnu.mirror.mcgill.ca/aspell/dict/${DICO}/:dict${DICO} \
		http://mirrors.usc.edu/pub/gnu/aspell/dict/${DICO}/:dict${DICO} \
		ftp://ftp.sunsite.org.uk/package/gnu/aspell/dict/${DICO}/:dict${DICO}
. if (${SPECDICTS:M${DICO}*} != "")
DISTFILES+=	aspell-${DICO}-${DICTVER_${DICO:U}}${DICT_SUFFIX}:dict${DICO}
. else
DISTFILES+=	aspell-${DICO}-${DICTVERSION}${DICT_SUFFIX}:dict${DICO}
. endif
.endfor

post-extract:
.for DICO in ${DICTS}
. if (${SPECDICTS:M${DICO}*} != "")
	@${MKDIR} -p ${DICO_WRKDIR} && cd ${DICO_WRKDIR} && \
	 ${TAR} -xjf ${DISTDIR}/${DIST_SUBDIR}/aspell-${DICO}-${DICTVER_${DICO:U}}${DICT_SUFFIX}
. else
	@${MKDIR} -p ${DICO_WRKDIR} && cd ${DICO_WRKDIR} && \
	 ${TAR} -xjf ${DISTDIR}/${DIST_SUBDIR}/aspell-${DICO}-${DICTVERSION}${DICT_SUFFIX}
. endif
.endfor

post-patch:
.for DICO in ${DICTS}
. if (${SPECDICTS:M${DICO}*} != "")
	@${REINPLACE_CMD} -e 's|$${dictdir}|${PREFIX}$${dictdir}|g ; \
		s|$${datadir}|${PREFIX}$${datadir}|g' \
			${DICO_WRKDIR}/aspell-${DICO}-${DICTVER_${DICO:U}}/Makefile.pre
. else
	@${REINPLACE_CMD} -e 's|$${dictdir}|${PREFIX}$${dictdir}|g ; \
		s|$${datadir}|${PREFIX}$${datadir}|g' \
			${DICO_WRKDIR}/aspell-${DICO}-${DICTVERSION}/Makefile.pre
. endif
.endfor

post-install:
.for DICO in ${DICTS}
	@${ECHO_MSG} "===>   Installing for ${DICO} dictionaries"
. if (${SPECDICTS:M${DICO}*} != "")
	@cd ${DICO_WRKDIR}/aspell-${DICO}-${DICTVER_${DICO:U}} &&	\
	 ${CONF_DICT_ENV} ./${CONFIGURE_SCRIPT} &&		\
	 ${GMAKE} install
. else
	@cd ${DICO_WRKDIR}/aspell-${DICO}-${DICTVERSION} &&		\
	 ${CONF_DICT_ENV} ./${CONFIGURE_SCRIPT}  &&		\
	 ${GMAKE} install
. endif
	@${CAT} ${MASTERDIR}/pkg-plist.${DICO} >> ${TMPPLIST}
.endfor
	@${CAT} ${MASTERDIR}/pkg-plist.dirrm >> ${TMPPLIST}

post-clean:
	@${RM} -rf ${DICO_WRKDIR} || ${TRUE}

.include <bsd.port.post.mk>
