# New ports collection makefile for:	aspell
# Date created:				7 December 1998
# Whom:					Josh Gilliam <josh@quick.net>
#
# $FreeBSD$
#

PORTNAME?=	aspell
PORTVERSION=	0.50.5
PORTREVISION=	1
CATEGORIES+=	textproc
MASTER_SITES=	http://aspell.net/	\
		${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	aspell
DISTFILES=	aspell-0.50.5.tar.gz	# needed for slave ports / options
EXTRACT_ONLY=	aspell-0.50.5.tar.gz

MAINTAINER?=	thierry@pompo.net
COMMENT?=	Spelling checker with better suggestion logic than ispell

.if !exists(/usr/bin/bzip2)
BUILD_DEPENDS+=	bzip2:${PORTSDIR}/archivers/bzip2
.endif

USE_LIBTOOL_VER=13
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--enable-dict-dir=${DATADIR} \
		--enable-doc-dir=${DOCSDIR}
USE_GMAKE=	yes

MAKE_ARGS=	NOPORTDOCS=${NOPORTDOCS}
INSTALLS_SHLIB=	yes

# Does not link without at least -O
.if !defined(CFLAGS) || ${CFLAGS:M-O*} == ""
CFLAGS+=	-O
.endif

WRKSRC=		${WRKDIR}/aspell-${PORTVERSION}	# needed for slave ports / options
DOCSDIR=	${PREFIX}/share/doc/aspell
DATADIR=	${PREFIX}/share/aspell
DESCR=		${.CURDIR}/pkg-descr

CONF_DICT_ENV=	ASPELL="${PREFIX}/bin/aspell"	\
		WORD_LIST_COMPRESS="${PREFIX}/bin/word-list-compress"
AVAIL_DICT=	af bg br ca cs cy da de el en eo es fo fr hr id it ga gl is mi ms \
		nl no pl pt ro ru sk sl sv uk
SPECDICTS=	af bg cs cy da el en fo fr ga gl hr id is it mi ms pl sk sl sv uk
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
DICTVER_GA=	0.50-4
DICTVER_GL=	0.50-0
DICTVER_HR=	0.50-0
DICTVER_ID=	0.50-0
DICTVER_IS=	0.51-0
DICTVER_IT=	0.52-0
DICTVER_MI=	0.50-0
DICTVER_MS=	0.50-0
DICTVER_PL=	0.51-0
DICTVER_SK=	0.51-1
DICTVER_SL=	0.50-0
DICTVER_SV=	0.51-0
DICTVER_UK=	0.51-0
DICT_SUFFIX=	.tar.bz2

.include <bsd.port.pre.mk>

.if defined(LANG)
.for i in ${AVAIL_DICT}
.if ${LANG:M${i}*} != ""
DEF_DICT=	${i}
.endif
.endfor
.endif
DEF_DICT?=	en

pre-everything::
.if (!defined(ASPELL_AF) \
  && !defined(ASPELL_BG) \
  && !defined(ASPELL_BR) \
  && !defined(ASPELL_CA) \
  && !defined(ASPELL_CS) \
  && !defined(ASPELL_CY) \
  && !defined(ASPELL_DA) \
  && !defined(ASPELL_DE) \
  && !defined(ASPELL_EL) \
  && !defined(ASPELL_EN) \
  && !defined(ASPELL_EO) \
  && !defined(ASPELL_ES) \
  && !defined(ASPELL_FO) \
  && !defined(ASPELL_FR) \
  && !defined(ASPELL_GA) \
  && !defined(ASPELL_GL) \
  && !defined(ASPELL_HR) \
  && !defined(ASPELL_ID) \
  && !defined(ASPELL_IS) \
  && !defined(ASPELL_IT) \
  && !defined(ASPELL_MI) \
  && !defined(ASPELL_MS) \
  && !defined(ASPELL_NL) \
  && !defined(ASPELL_NO) \
  && !defined(ASPELL_PL) \
  && !defined(ASPELL_PT) \
  && !defined(ASPELL_RO) \
  && !defined(ASPELL_RU) \
  && !defined(ASPELL_SK) \
  && !defined(ASPELL_SL) \
  && !defined(ASPELL_SV) \
  && !defined(ASPELL_UK))
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
	@${ECHO_MSG} '*  - Irish (Gaelic)               ASPELL_GA=yes         *'
	@${ECHO_MSG} '*  - Italian                      ASPELL_IT=yes         *'
	@${ECHO_MSG} '*  - Maori                        ASPELL_MI=yes         *'
	@${ECHO_MSG} '*  - Malay                        ASPELL_MS=yes         *'
	@${ECHO_MSG} '*  - Norwegian                    ASPELL_NO=yes         *'
	@${ECHO_MSG} '*  - Polish                       ASPELL_PL=yes         *'
	@${ECHO_MSG} '*  - Portuguese                   ASPELL_PT=yes         *'
	@${ECHO_MSG} '*  - Romanian                     ASPELL_RO=yes         *'
	@${ECHO_MSG} '*  - Russian                      ASPELL_RU=yes         *'
	@${ECHO_MSG} '*  - Slovak                       ASPELL_SK=yes         *'
	@${ECHO_MSG} '*  - Slovenian                    ASPELL_SL=yes         *'
	@${ECHO_MSG} '*  - Spanish                      ASPELL_ES=yes         *'
	@${ECHO_MSG} '*  - Swedish                      ASPELL_SV=yes         *'
	@${ECHO_MSG} '*  - Ukrainian                    ASPELL_UK=yes         *'
	@${ECHO_MSG} '*  - Welsh                        ASPELL_CY=yes         *'
	@${ECHO_MSG} '*                                                       *'
	@${ECHO_MSG} '* Example: "make ASPELL_FR=yes ASPELL_EN=yes install"   *'
	@${ECHO_MSG} '*********************************************************'
.else
. for LG in ${AVAIL_DICT}
.  if defined(ASPELL_${LG:U})
DICTS+=		${LG}
.  endif
. endfor
.endif
.if !defined(DICTS)
. for LG in ${AVAIL_DICT}
.  if (${DEF_DICT} == ${LG})
DICTS=	${LG}
.  endif
. endfor
.endif
.for DICO in ${DICTS}
MASTER_SITES+=	ftp://ftp.gnu.org/gnu/aspell/dict/${DICO}/:dict${DICO}
. if (${SPECDICTS:M${DICO}*} != "")
DISTFILES+=	aspell-${DICO}-${DICTVER_${DICO:U}}${DICT_SUFFIX}:dict${DICO}
. else
DISTFILES+=	aspell-${DICO}-${DICTVERSION}${DICT_SUFFIX}:dict${DICO}
. endif
.endfor

post-extract:
.for DICO in ${DICTS}
. if (${SPECDICTS:M${DICO}*} != "")
	@cd ${WRKDIR} && \
	 ${TAR} -xjf ${DISTDIR}/aspell-${DICO}-${DICTVER_${DICO:U}}${DICT_SUFFIX}
. else
	@cd ${WRKDIR} && \
	 ${TAR} -xjf ${DISTDIR}/aspell-${DICO}-${DICTVERSION}${DICT_SUFFIX}
. endif
.endfor

post-install:
.for DICO in ${DICTS}
	@${ECHO_MSG} "===>   Installing for ${DICO} dictionaries"
. if (${SPECDICTS:M${DICO}*} != "")
	@cd ${WRKDIR}/aspell-${DICO}-${DICTVER_${DICO:U}} &&	\
	 ${CONF_DICT_ENV} ./${CONFIGURE_SCRIPT} &&		\
	 ${GMAKE} install
. else
	@cd ${WRKDIR}/aspell-${DICO}-${DICTVERSION} &&		\
	 ${CONF_DICT_ENV} ./${CONFIGURE_SCRIPT} &&		\
	 ${GMAKE} install
. endif
	@${CAT} ${MASTERDIR}/pkg-plist.${DICO} >> ${TMPPLIST}
.endfor
	@${ECHO_CMD} "@dirrm share/aspell" >> ${TMPPLIST}

.include <bsd.port.post.mk>
