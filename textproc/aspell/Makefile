# New ports collection makefile for:	aspell
# Date created:				7 December 1998
# Whom:					Josh Gilliam <josh@quick.net>
#
# $FreeBSD$
#

PORTNAME?=	aspell
PORTVERSION=	0.50.2
CATEGORIES+=	textproc
MASTER_SITES=	http://savannah.gnu.org/download/${PORTNAME}/rel/	\
		${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	aspell
DISTFILES=	aspell-0.50.2.tar.gz	# needed for slave ports / options
EXTRACT_ONLY=	aspell-0.50.2.tar.gz

MAINTAINER?=	thierry@pompo.net

.if !exists(/usr/bin/bzip2)
BUILD_DEPENDS+=	bzip2:${PORTSDIR}/archivers/bzip2
.endif

USE_LIBTOOL=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--enable-dict-dir=${DATADIR} \
		--enable-doc-dir=${DOCSDIR}
USE_GMAKE=	yes
USE_REINPLACE=	yes

MAKE_ARGS=	NOPORTDOCS=${NOPORTDOCS}
INSTALLS_SHLIB=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}
WRKSRC=		${WRKDIR}/aspell-${PORTVERSION}	# needed for slave ports / options
DOCSDIR=	${PREFIX}/share/doc/aspell
DATADIR=	${PREFIX}/share/aspell
COMMENT=	${.CURDIR}/pkg-comment
DESCR=		${.CURDIR}/pkg-descr

CONF_DICT_ENV=	ASPELL="${PREFIX}/bin/aspell"	\
		WORD_LIST_COMPRESS="${PREFIX}/bin/word-list-compress"
DICT_DIR=	-${DICTVERSION}-${DICTREVISION}
DICT_SUFFIX=	${DICT_DIR}.tar.bz2
AVAIL_DICT=	br ca cs da de en eo es fo fr it nl no pl pt ro ru sk sv
DICTVERSION=	0.50
DICTREVISION=	2

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
.if (!defined(ASPELL_BR) && !defined(ASPELL_CA) && !defined(ASPELL_CS) && !defined(ASPELL_DA) && !defined(ASPELL_DE) && !defined(ASPELL_EN) && !defined(ASPELL_EO) && !defined(ASPELL_ES) && !defined(ASPELL_FO) && !defined(ASPELL_FR) && !defined(ASPELL_IT) && !defined(ASPELL_NL) && !defined(ASPELL_NO) && !defined(ASPELL_PL) && !defined(ASPELL_PT) && !defined(ASPELL_RO) && !defined(ASPELL_RU) && !defined(ASPELL_SK) && !defined(ASPELL_SV))
	@${ECHO_MSG} '*********************************************************'
	@${ECHO_MSG} '* You can add further dictionaries:                     *'
	@${ECHO_MSG} '*                                 Use make-flag:        *'
	@${ECHO_MSG} '*  - Breton                       ASPELL_BR=yes         *'
	@${ECHO_MSG} '*  - Catalan                      ASPELL_CA=yes         *'
	@${ECHO_MSG} '*  - Czech                        ASPELL_CS=yes         *'
	@${ECHO_MSG} '*  - Danish                       ASPELL_DA=yes         *'
	@${ECHO_MSG} '*  - German                       ASPELL_DE=yes         *'
	@${ECHO_MSG} '*  - English                      ASPELL_EN=yes         *'
	@${ECHO_MSG} '*  - Esperanto                    ASPELL_EO=yes         *'
	@${ECHO_MSG} '*  - Spanish                      ASPELL_ES=yes         *'
	@${ECHO_MSG} '*  - Faroese                      ASPELL_FO=yes         *'
	@${ECHO_MSG} '*  - French                       ASPELL_FR=yes         *'
	@${ECHO_MSG} '*  - Italian                      ASPELL_IT=yes         *'
	@${ECHO_MSG} '*  - Dutch                        ASPELL_NL=yes         *'
	@${ECHO_MSG} '*  - Norwegian                    ASPELL_NO=yes         *'
	@${ECHO_MSG} '*  - Polish                       ASPELL_PL=yes         *'
	@${ECHO_MSG} '*  - Portuguese                   ASPELL_PT=yes         *'
	@${ECHO_MSG} '*  - Romanian                     ASPELL_RO=yes         *'
	@${ECHO_MSG} '*  - Russian                      ASPELL_RU=yes         *'
	@${ECHO_MSG} '*  - Slovak                       ASPELL_SK=yes         *'
	@${ECHO_MSG} '*  - Swedish                      ASPELL_SV=yes         *'
	@${ECHO_MSG} '*                                                       *'
	@${ECHO_MSG} '* Example: "make ASPELL_FR=yes ASPELL_EN=yes install"   *'
	@${ECHO_MSG} '*********************************************************'
.else
.if defined(ASPELL_BR)
DICTS+=		br
.endif
.if defined(ASPELL_CA)
DICTS+=		ca
.endif
.if defined(ASPELL_CS)
DICTS+=		cs
.endif
.if defined(ASPELL_DA)
DICTS+=		da
.endif
.if defined(ASPELL_DE)
DICTS+=		de
.endif
.if defined(ASPELL_EN)
DICTS+=		en
.endif
.if defined(ASPELL_EO)
DICTS+=		eo
.endif
.if defined(ASPELL_ES)
DICTS+=		es
.endif
.if defined(ASPELL_FO)
DICTS+=		fo
.endif
.if defined(ASPELL_FR)
DICTS+=		fr
.endif
.if defined(ASPELL_IT)
DICTS+=		it
.endif
.if defined(ASPELL_NL)
DICTS+=		nl
.endif
.if defined(ASPELL_NO)
DICTS+=		no
.endif
.if defined(ASPELL_PL)
DICTS+=		pl
.endif
.if defined(ASPELL_PT)
DICTS+=		pt
.endif
.if defined(ASPELL_RO)
DICTS+=		ro
.endif
.if defined(ASPELL_RU)
DICTS+=		ru
.endif
.if defined(ASPELL_SK)
DICTS+=		sk
.endif
.if defined(ASPELL_SV)
DICTS+=		sv
.endif
.endif
.if !defined(DICTS)
.for LG in ${AVAIL_DICT}
.if (${DEF_DICT} == ${LG})
DICTS=	${LG}
.endif
.endfor
.endif
.for DICO in ${DICTS}
DISTFILES+=	aspell-${DICO}${DICT_SUFFIX}
.endfor

post-extract:
.for DICO in ${DICTS}
	@cd ${WRKDIR} && \
	 ${TAR} -xjf ${DISTDIR}/aspell-${DICO}${DICT_SUFFIX}
.endfor

post-install:
.for DICO in ${DICTS}
	@${ECHO_MSG} "===>   Installing for ${DICO} dictionaries"
	@cd ${WRKDIR}/aspell-${DICO}${DICT_DIR} && \
	 ${CONF_DICT_ENV} ./${CONFIGURE_SCRIPT} && \
	 ${GMAKE} install
	@${CAT} ${MASTERDIR}/pkg-plist.${DICO} >> ${TMPPLIST}
.endfor
	@${ECHO_CMD} "@dirrm share/aspell" >> ${TMPPLIST}

.include <bsd.port.post.mk>
