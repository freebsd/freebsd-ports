# New ports collection makefile for:	ispell
# Date created:				6 November 1994
# Whom:					jmz
#
# $FreeBSD$
#

PORTNAME?=	ispell
PORTVERSION?=	3.2.06
PORTREVISION?=	15
CATEGORIES+=	textproc
MASTER_SITES=	http://fmg-www.cs.ucla.edu/geoff/tars/ \
		http://distfiles.opendarwin.org/
DISTNAME=	ispell-3.2.06		# needed for slave ports / options
DISTFILES=	ispell-3.2.06.tar.gz    # needed for slave ports / options

MAINTAINER?=	jmz@FreeBSD.org
COMMENT=	An interactive spelling checker for multiple languages
ISPELL_FILES= 	ispell-3.2.06.tar.gz

MAN1=		ispell.1
MAN4=		ispell.4 english.4
MLINKS=		ispell.1 buildhash.1 \
		ispell.1 findaffix.1 \
		ispell.1 munchlist.1 \
		ispell.1 tryaffix.1 \
		ispell.1 spell.1

EXTRACT_ONLY=	${ISPELL_FILES}
EXTRA_DICT=
MAKE_FLAGS=	TMPDIR=${WRKDIR} -f
ALL_TARGET=

BUILDHASH=	${WRKSRC}/buildhash
UNSQ?=		${WRKDIR}/${DENEUDISTFILE:S=.tar.bz2$==}/bin/unsq.pl
MUNCHLIST=	${WRKSRC}/munchlist
DATADIR=	${PREFIX}/share/ispell
ISPELL=		${WRKSRC}/ispell

.if (!defined(ISPELL_IT) && !defined(ISPELL_FR) && !defined(ISPELL_SE) && !defined(ISPELL_BR) && !defined(ISPELL_DENEU) && !defined(ISPELL_DEALT) && !defined(ISPELL_BRITISH) && !defined(ISPELL_NO) && !defined(ISPELL_NL) && !defined(ISPELL_DA) && !defined(ISPELL_AF) && !defined(ISPELL_FI) && !defined(ISPELL_PL)) && !defined(ISPELL_BG)
pre-everything::
	@${ECHO_MSG} '*********************************************************'
	@${ECHO_MSG} '* You can add further dictionaries:                     *'
	@${ECHO_MSG} '*                              Use make-flag:           *'
#	@${ECHO_MSG} '*  - Afrikaans                 ISPELL_AF=yes            *'
	@${ECHO_MSG} '*  - British                   ISPELL_BRITISH=yes       *'
	@${ECHO_MSG} '*    (replaces the American dictionary, specify also    *'
	@${ECHO_MSG} '*     ISPELL_INCLAMERICAN=yes to have both)             *'
	@${ECHO_MSG} '*  - Brazilian Portuguese      ISPELL_BR=yes            *'
	@${ECHO_MSG} '*  - Bulgarian                 ISPELL_BG=yes            *'
	@${ECHO_MSG} '*  - Dutch                     ISPELL_NL=yes            *'
	@${ECHO_MSG} '*  - Danish                    ISPELL_DA=yes            *'
	@${ECHO_MSG} '*  - Finnish                   ISPELL_FI=yes            *'
	@${ECHO_MSG} '*    (or ISPELL_FI=[small|large] (medium is default)    *'
	@${ECHO_MSG} '*  - French                    ISPELL_FR=yes            *'
	@${ECHO_MSG} '*  - German (old spelling)     ISPELL_DEALT=yes         *'
	@${ECHO_MSG} '*  - German (new spelling)     ISPELL_DENEU=yes         *'
	@${ECHO_MSG} '*  - Italian                   ISPELL_IT=yes            *'
	@${ECHO_MSG} '*  - Polish                    ISPELL_PL=yes            *'
	@${ECHO_MSG} '*  - Swedish                   ISPELL_SE=yes            *'
	@${ECHO_MSG} '*  - Norwegian                 ISPELL_NO=yes            *'
	@${ECHO_MSG} '* Example: "make ISPELL_FR=yes ISPELL_SE=yes install"   *'
	@${ECHO_MSG} '*********************************************************'
.else
.if defined(ISPELL_BRITISH)
SCRIPTS_ENV+=	ISPELL_BRITISH=${ISPELL_BRITISH}
.if defined(ISPELL_INCLAMERICAN)
SCRIPTS_ENV+=   ISPELL_INCLAMERICAN=${ISPELL_INCLAMERICAN}
.endif
.endif
.if defined(ISPELL_IT)
ITDISTFILE=	ispell-it2001.tgz
MASTER_SITES+=	http://members.xoom.virgilio.it/trasforma/ispell/:it
EXTRA_DICT+=	${ITDISTFILE}:it
.endif
.if defined(ISPELL_FR)
FRDISTFILE=	francais-IREQ-1.4.tar.gz
MASTER_SITES+=	ftp://ftp.lip6.fr/pub/ispell/francais/:fr
EXTRA_DICT+=	${FRDISTFILE}:fr
.endif
.if defined(ISPELL_SE)
SEDISTFILE=	iswedish-1.2.1.tar.gz
MASTER_SITES+=	http://www.sslug.dk/locale/ispell/iswedish/:se
EXTRA_DICT+=	${SEDISTFILE}:se
EXTRACT_ONLY+=	${SEDISTFILE}
.endif
.if defined(ISPELL_BR)
BRDISTFILE=	br.ispell-2.4.tar.gz
MASTER_SITES+=	ftp://ftp.ime.usp.br/pub/ueda/br.ispell/:br
EXTRA_DICT+=	${BRDISTFILE}:br
EXTRACT_ONLY+=	${BRDISTFILE}
.endif
.if defined(ISPELL_DENEU)
DENEUDISTFILE=	igerman98-20001109.tar.bz2
MASTER_SITES+=	http://j3e.de/ispell/igerman98/dict/:denu
EXTRA_DICT+=	${DENEUDISTFILE}:denu
.endif
.if defined(ISPELL_DEALT)
DEALTDISTFILE=	hk-deutsch.tar.gz
MASTER_SITES+=	ftp://ftp.informatik.uni-kiel.de/pub/kiel/dicts/:dealt
EXTRA_DICT+=	${DEALTDISTFILE}:dealt
.endif
.if defined(ISPELL_NO)
NODISTFILE=	ispell-norsk-2.0.tar.gz
MASTER_SITES+=	http://folk.uio.no/runekl/:no
EXTRA_DICT+=	${NODISTFILE}:no
EXTRACT_ONLY+=	${NODISTFILE}
MASKBITS?=	64
USE_GMAKE=	yes
.endif
.if defined(ISPELL_NL)
NLDISTFILE=	ispell-nl-1.0.0.tar.gz
MASTER_SITES+=	${MASTER_SITE_LOCAL:S/$/:nl/}
MASTER_SITE_SUBDIR+=	fenner/:nl
EXTRA_DICT+=	${NLDISTFILE}:nl
EXTRACT_ONLY+=	${NLDISTFILE}
.endif
.if defined(ISPELL_DA)
DADISTFILE=	ispell-da-1.4.49.tar.gz
MASTER_SITES+=	http://da.speling.org/filer/:da \
		${MASTER_SITE_LOCAL:S/$/:da/}
MASTER_SITE_SUBDIR+=	fenner/:da
EXTRA_DICT+=	${DADISTFILE}:da
EXTRACT_ONLY+=	${DADISTFILE}
.endif
#.if defined(ISPELL_AF)
#AFDISTFILE=	ispell-sa-1.0.0.tar.gz
#MASTER_SITES+=	#${MASTER_SITE_LOCAL:S/$/:af/}
#EXTRA_DICT+=	${AFDISTFILE}:af
#EXTRACT_ONLY+=	${AFDISTFILE}
#.endif
.if defined(ISPELL_FI)
FIDICTFILE=	finnish.dict.bz2
MASTER_SITES+=	http://ispell-fi.sourceforge.net/:fi
.if ${ISPELL_FI:L} != yes
FIAFFIXFILE=	finnish.${ISPELL_FI:L}.aff.bz2
.else
FIAFFIXFILE=	finnish.medium.aff.bz2
.endif
EXTRA_DICT+=	${FIDICTFILE}:fi ${FIAFFIXFILE}:fi
.endif
.if defined(ISPELL_PL)
PLDISTFILE=	ispell-pl-20021127.tar.gz
MASTER_SITES+=	${MASTER_SITE_SOURCEFORGE:S/$/:pl/}
MASTER_SITE_SUBDIR+=	ispell-pl/:pl
MASKBITS?=	64
EXTRA_DICT+=	${PLDISTFILE}:pl
EXTRACT_ONLY+=	${PLDISTFILE}
BUILDHASH=	${WRKDIR}/${PLDISTFILE:S=.tar.gz==}/zbuduj.slownik.sh
.endif
.if defined(ISPELL_BG)
MASTER_SITES+=	${MASTER_SITE_SOURCEFORGE:S/$/:bg/}
MASTER_SITE_SUBDIR+=	bgoffice/:bg
BGDISTFILE=	ispell-bg-2.1.tar.gz
MASKBITS?=	64
EXTRA_DICT+=	${BGDISTFILE}:bg
EXTRACT_ONLY+=	${BGDISTFILE}
.endif
.endif

DISTFILES+=	${EXTRA_DICT}

post-extract:
.if defined(ISPELL_IT)
	@${TAR} -C ${WRKDIR} -zxf ${DISTDIR}/${ITDISTFILE}
.endif
.if defined(ISPELL_FR)
	@${MKDIR} ${WRKDIR}/francais-IREQ
	@${TAR} -C ${WRKDIR}/francais-IREQ -zxf ${DISTDIR}/${FRDISTFILE}
.endif
.if defined(ISPELL_DEALT)
	@${MKDIR} ${WRKDIR}/hk-deutsch
	@${TAR} -C ${WRKDIR}/hk-deutsch/ -zxf ${DISTDIR}/${DEALTDISTFILE}
.endif
.if defined(ISPELL_DENEU)
	@${TAR} -C ${WRKDIR}/ -yxf ${DISTDIR}/${DENEUDISTFILE}
.endif
.if defined(ISPELL_FI)
	${MKDIR} ${WRKDIR}/finnish
.for file in ${FIDICTFILE} ${FIAFFIXFILE}
	${BZIP2_CMD} -dc ${DISTDIR}/${file} \
		> ${WRKDIR}/finnish/${file:S/.bz2$//}
.endfor
.endif

post-patch:
.if defined(ISPELL_IT)
	@cd ${WRKDIR} && ${PATCH} < ${FILESDIR}/IT.patch 2>/dev/null
	@${REINPLACE_CMD} -e "s|%%BH%%|${BUILDHASH}|g;s|%%MH%%|${MUNCHLIST}|g" \
		${WRKDIR}/ispell-it/Makefile
.endif
.if defined(ISPELL_FR)
	@cd ${WRKDIR} && ${PATCH} < ${FILESDIR}/FR.patch 2>/dev/null
.endif
.if defined(ISPELL_BR)
	@cd ${WRKDIR}/${BRDISTFILE:S/.tar.gz$//} && ${PATCH} < ${FILESDIR}/BR.patch 2>/dev/null
.endif
.if defined(ISPELL_DENEU)
	@cd ${WRKDIR}/${DENEUDISTFILE:S=.tar.bz2$==} && ${PATCH} < ${FILESDIR}/DENEU.patch 2>/dev/null
.endif
.if defined(ISPELL_SE)
	@cd ${WRKDIR} && ${PATCH} < ${FILESDIR}/SE.patch 2>/dev/null
.endif
.if defined(ISPELL_NO)
	@cd ${WRKDIR}/norsk && ${PATCH} < ${FILESDIR}/NO.patch 2>/dev/null
	@${MKDIR} ${WRKDIR}/bin && ${CP} ${FILESDIR}/unsq.pl ${WRKDIR}/bin && ${CHMOD} +x ${WRKDIR}/bin/unsq.pl
.endif
.if defined(ISPELL_NL)
	@cd ${WRKDIR} && ${PATCH} < ${FILESDIR}/NL.patch 2>/dev/null
.endif
.if defined(ISPELL_DA)
	@cd ${WRKDIR} && ${PATCH} < ${FILESDIR}/DA.patch 2>/dev/null
.endif
.if defined(ISPELL_AF)
	@cd ${WRKDIR} && ${PATCH} < ${FILESDIR}/AF.patch 2>/dev/null
.endif
.if defined(ISPELL_PL)
	@${REINPLACE_CMD} -e 's/bash/sh/'  -e 's:^buildhash:${WRKSRC}/buildhash:' ${BUILDHASH}
.endif

post-configure:
	@${ECHO_CMD} "#define CFLAGS \"${CFLAGS}\"" >> ${WRKSRC}/local.h
	@${ECHO_CMD} "#define CC \"${CC}\"" >> ${WRKSRC}/local.h
.if defined(MASKBITS)
	@${ECHO_CMD} "#define MASKBITS ${MASKBITS}" >> ${WRKSRC}/local.h
.endif

post-build:
.if defined(ISPELL_IT)
	@cd ${WRKDIR}/ispell-it && ${MAKE} all
.endif
.if defined(ISPELL_DENEU)
	@cd ${WRKDIR}/${DENEUDISTFILE:S=.tar.bz2==} && \
		${MAKE} ${MAKEFLAGS} UNSQ=${UNSQ} BUILDHASH=${BUILDHASH} \
			german.hash && \
		${MV} german.hash ndeutsch.hash && ${MV} german.aff ndeutsch.aff
.endif
.if defined(ISPELL_DEALT)
	@cd ${WRKDIR}/${DEALTDISTFILE:S=.tar.gz==} && \
		${CAT} worte.txt verben.txt \
		adjektive.txt klein.txt geographie.txt vornamen.txt \
		abkuerz.txt imperat.txt latein.txt informatik.txt \
		infoabk.txt elektronik.txt orgabk.txt marken.txt \
		alphabeta.txt roemisch.txt zusammen.txt | \
		${SORT} -u > all.words && \
		${BUILDHASH} all.words deutsch.aff deutsch.hash
.endif
.if defined(ISPELL_BR)
	@cd ${WRKDIR}/${BRDISTFILE:S=.tar.gz==} && \
		${MAKE} ${MAKEFLAGS} BUILDHASH=${BUILDHASH} all
.endif
.if defined(ISPELL_SE)
	@cd ${WRKDIR}/${SEDISTFILE:S=.tar.gz==} && \
		${MAKE} ${MAKEFLAGS} BUILDHASH=${BUILDHASH}
.endif
.if defined(ISPELL_FR)
	@cd ${WRKDIR}/francais-IREQ && \
		${MAKE} ${MAKEFLAGS} BUILDHASH=${BUILDHASH}
.endif
.if defined(ISPELL_NO)
	@cd ${WRKDIR}/norsk && \
		${GMAKE} ${MAKEFLAGS} UNSQ=${UNSQ} BUILDHASH=${BUILDHASH} \
			MUNCHLIST=${MUNCHLIST}
.endif
.if defined(ISPELL_NL)
	@cd ${WRKDIR}/${NLDISTFILE:S=.tar.gz==} && \
		${MAKE} ${MAKEFLAGS} BUILDHASH=${BUILDHASH} all
.endif
.if defined(ISPELL_DA)
	@cd ${WRKDIR}/${DADISTFILE:S=.tar.gz==} && \
		${MAKE} ${MAKEFLAGS} BUILDHASH=${BUILDHASH} ISPELL=${ISPELL} all
.endif
.if defined(ISPELL_AF)
	@cd ${WRKDIR}/${AFDISTFILE:S=.tar.gz==} && \
		${MAKE} ${MAKEFLAGS} BUILDHASH=${BUILDHASH} all
.endif
.if defined(ISPELL_FI)
	@cd ${WRKDIR}/finnish && \
		${BUILDHASH} ${FIDICTFILE:S/.bz2//} ${FIAFFIXFILE:S/.bz2//} \
		finnish.hash && ${MV} ${FIAFFIXFILE:S/.bz2//} finnish.aff
.endif
.if defined(ISPELL_PL)
	@cd ${WRKDIR}/${PLDISTFILE:S=.tar.gz==} && \
		${CAT} A B C imiona-A imiona-B fachowe/* > polish.dic && \
		${BUILDHASH} polish.dic polish.aff polish.hash
.endif
.if defined(ISPELL_BG)
	@cd ${WRKDIR}/${BGDISTFILE:S=.tar.gz==} && \
		${BUILDHASH} data/bulgarian.dict data/bulgarian.aff data/bulgarian.hash && \
		${CP} data/bulgarian.aff bulgarian.aff && \
		${CP} data/bulgarian.hash bulgarian.hash
.endif

pre-su-install:
	@if [ ! -d ${DATADIR} ]; then ${MKDIR} ${DATADIR}; fi

post-install:
	@${RM} -f ${PREFIX}/bin/spell
	@${LN} ${PREFIX}/bin/ispell ${PREFIX}/bin/spell
.if defined(ISPELL_BRITISH)
	${INSTALL_DATA} ${WRKSRC}/languages/british/english.xlg \
		${DATADIR}/english.dict
.else
	${INSTALL_DATA} ${WRKSRC}/languages/american/english.med+ \
		${DATADIR}/english.dict
.endif
	@-${INSTALL_DATA} ${WRKDIR}/*/*.aff ${WRKDIR}/*/*.hash ${DATADIR}
.if defined(ISPELL_IT)
	@${CAT} ${MASTERDIR}/pkg-plist.it >> ${TMPPLIST}
.endif
.if defined(ISPELL_FR)
	@${CAT} ${MASTERDIR}/pkg-plist.fr >> ${TMPPLIST}
.endif
.if defined(ISPELL_DEALT)
	@${CAT} ${MASTERDIR}/pkg-plist.dealt >> ${TMPPLIST}
.endif
.if defined(ISPELL_DENEU)
	@${CAT} ${MASTERDIR}/pkg-plist.deneu >> ${TMPPLIST}
.endif
.if defined(ISPELL_BR)
	@${CAT} ${MASTERDIR}/pkg-plist.br >> ${TMPPLIST}
.endif
.if defined(ISPELL_SE)
	@${CAT} ${MASTERDIR}/pkg-plist.se >> ${TMPPLIST}
.endif
.if defined(ISPELL_NO)
	@${CAT} ${MASTERDIR}/pkg-plist.no >> ${TMPPLIST}
.endif
.if defined(ISPELL_NL)
	@${CAT} ${MASTERDIR}/pkg-plist.nl >> ${TMPPLIST}
.endif
.if defined(ISPELL_DA)
	@${CAT} ${MASTERDIR}/pkg-plist.da >> ${TMPPLIST}
.endif
.if defined(ISPELL_AF)
	@${CAT} ${MASTERDIR}/pkg-plist.af >> ${TMPPLIST}
.endif
.if defined(ISPELL_BRITISH)
	@${CAT} ${MASTERDIR}/pkg-plist.british >> ${TMPPLIST}
.if defined(ISPELL_INCLAMERICAN)
	@${CAT} ${MASTERDIR}/pkg-plist.am >> ${TMPPLIST}
.endif
.else
	@${CAT} ${MASTERDIR}/pkg-plist.am >> ${TMPPLIST}
.endif
.if defined(ISPELL_FI)
	@${CAT} ${MASTERDIR}/pkg-plist.fi >> ${TMPPLIST}
.endif
.if defined(ISPELL_PL)
	@${CAT} ${MASTERDIR}/pkg-plist.pl >> ${TMPPLIST}
.endif
	@${ECHO_CMD} "@dirrm share/ispell" >> ${TMPPLIST}

.include <bsd.port.mk>
