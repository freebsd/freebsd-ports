# New ports collection makefile for:	ispell
# Date created:				6 November 1994
# Whom:					jmz
#
# $FreeBSD$
#

PORTNAME?=	ispell
PORTVERSION?=	3.2.05
PORTREVISION?=	1
CATEGORIES+=	textproc
MASTER_SITES=	http://fmg-www.cs.ucla.edu/geoff/tars/
DISTNAME=	ispell-3.2.05		# needed for slave ports / options
DISTFILES=	ispell-3.2.05.tar.gz    # needed for slave ports / options

MAINTAINER?=	jmz@FreeBSD.org
ISPELL_FILES= 	ispell-3.2.05.tar.gz

MAN1=		ispell.1
MAN4=		ispell.4 english.4
MLINKS=		ispell.1 buildhash.1 ispell.1 findaffix.1 ispell.1 \
		munchlist.1 ispell.1 tryaffix.1

EXTRACT_ONLY=	${ISPELL_FILES}
EXTRA_DICT=
MAKE_FLAGS=	TMPDIR=${WRKDIR} -f
ALL_TARGET=

BUILDHASH=	${WRKSRC}/buildhash
UNSQ?=		${WRKDIR}/${DENEUDISTFILE:S=.tar.bz2$==}/bin/unsq.pl
MUNCHLIST=	${WRKSRC}/munchlist
DATADIR=	${PREFIX}/share/ispell

.if (!defined(ISPELL_FR) && !defined(ISPELL_SE) && !defined(ISPELL_BR) && !defined(ISPELL_DENEU) && !defined(ISPELL_DEALT) && !defined(ISPELL_BRITISH) && !defined(ISPELL_NO) && !defined(ISPELL_NL) && !defined(ISPELL_DA) && !defined(ISPELL_AF))
pre-everything:
	@${ECHO_MSG} '*********************************************************'
	@${ECHO_MSG} '* You can add further dictionaries:                     *'
	@${ECHO_MSG} '*                              Use make-flag:           *'
	@${ECHO_MSG} '*  - Afrikaans                 ISPELL_AF=yes            *'
	@${ECHO_MSG} '*  - British                   ISPELL_BRITISH=yes       *'
	@${ECHO_MSG} '*    (replaces the American dictionary)                 *'
	@${ECHO_MSG} '*  - Dutch                     ISPELL_NL=yes            *'
	@${ECHO_MSG} '*  - Danish                    ISPELL_DA=yes            *'
	@${ECHO_MSG} '*  - French                    ISPELL_FR=yes            *'
	@${ECHO_MSG} '*  - Brasilian                 ISPELL_BR=yes            *'
	@${ECHO_MSG} '*  - German (old spelling)     ISPELL_DEALT=yes         *'
	@${ECHO_MSG} '*  - German (new spelling)     ISPELL_DENEU=yes         *'
	@${ECHO_MSG} '*  - Swedish                   ISPELL_SE=yes            *'
	@${ECHO_MSG} '*  - Norwegian                 ISPELL_NO=yes            *'
	@${ECHO_MSG} '* Example: "make ISPELL_FR=yes ISPELL_SE=yes install"   *'
	@${ECHO_MSG} '*********************************************************'
.else
.if defined(ISPELL_BRITISH)
SCRIPTS_ENV+=	ISPELL_BRITISH=${ISPELL_BRITISH}
.endif
.if defined(ISPELL_FR)
FRDISTFILE=	francais-IREQ-1.4.tar.gz
MASTER_SITES+=	ftp://ftp.robot.ireq.ca/pub/ispell/
EXTRA_DICT+=	${FRDISTFILE}
.endif
.if defined(ISPELL_SE)
SEDISTFILE=	iswedish-1.2.1.tar.gz
MASTER_SITES+=	http://www.sslug.dk/locale/ispell/iswedish/
EXTRA_DICT+=	${SEDISTFILE}
EXTRACT_ONLY+=	${SEDISTFILE}
.endif
.if defined(ISPELL_BR)
BRDISTFILE=	br.ispell-2.4.tar.gz
MASTER_SITES+=	ftp://ftp.ime.usp.br/pub/ueda/br.ispell/
EXTRA_DICT+=	${BRDISTFILE}
EXTRACT_ONLY+=	${BRDISTFILE}
.endif
.if defined(ISPELL_DENEU)
.if !exists(/usr/bin/bzip2)
BUILD_DEPENDS+=	bzip2:${PORTSDIR}/archivers/bzip2
.endif
DENEUDISTFILE=	igerman98-20001109.tar.bz2
MASTER_SITES+=	http://www.suse.de/~bjacke/igerman98/dict/ \
		ftp://student.physik.uni-dortmund.de/pub/users/jacke/ispell/
EXTRA_DICT+=	${DENEUDISTFILE}
.endif
.if defined(ISPELL_DEALT)
DEALTDISTFILE=	hk-deutsch.tar.gz
EXTRA_DICT+=	${DEALTDISTFILE}
MASTER_SITES+=	ftp://ftp.informatik.uni-kiel.de/pub/kiel/dicts/
.endif
.if defined(ISPELL_NO)
NODISTFILE=	ispell-norsk-2.0.tar.gz
MASTER_SITES+=	ftp://ftp.ntnu.no/store/store/stash/ispell/
EXTRA_DICT+=	${NODISTFILE}
EXTRACT_ONLY+=	${NODISTFILE}
MASKBITS?=	64
USE_GMAKE=	yes
.endif
.if defined(ISPELL_NL)
NLDISTFILE=	ispell-nl-1.0.0.tar.gz
MASTER_SITES+=	${MASTER_SITE_LOCAL} \
		http://www.ninth-circle.org/~asmodai/
MASTER_SITE_SUBDIR=	asmodai
EXTRA_DICT+=	${NLDISTFILE}
EXTRACT_ONLY+=	${NLDISTFILE}
.endif
.if defined(ISPELL_DA)
DADISTFILE=	ispell-da-1.4.22.tar.gz
MASTER_SITES+=	http://da.speling.org/filer/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	asmodai
EXTRA_DICT+=	${DADISTFILE}
EXTRACT_ONLY+=	${DADISTFILE}
.endif
.if defined(ISPELL_AF)
AFDISTFILE=	ispell-sa-1.0.0.tar.gz
MASTER_SITES+=	${MASTER_SITE_LOCAL} \
		http://www.ninth-circle.org/~asmodai/
MASTER_SITE_SUBDIR=	asmodai
EXTRA_DICT+=	${AFDISTFILE}
EXTRACT_ONLY+=	${AFDISTFILE}
.endif

DISTFILES+=	${EXTRA_DICT}
.endif

post-extract:
.if defined(ISPELL_FR)
	@${MKDIR} ${WRKDIR}/francais-IREQ
	@${TAR} -C ${WRKDIR}/francais-IREQ -zxf ${PORTSDIR}/distfiles/${FRDISTFILE}
.endif
.if defined(ISPELL_DEALT)
	@${MKDIR} ${WRKDIR}/hk-deutsch
	@${TAR} -C ${WRKDIR}/hk-deutsch/ -zxf ${PORTSDIR}/distfiles/${DEALTDISTFILE}
.endif
.if defined(ISPELL_DENEU)
	@${TAR} -C ${WRKDIR}/ -yxf ${DISTDIR}/${DENEUDISTFILE}
.endif

post-patch:
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


post-configure:
	@${ECHO} "#define CFLAGS \"${CFLAGS}\"" >> ${WRKSRC}/local.h
.if defined(MASKBITS)
	@${ECHO} "#define MASKBITS ${MASKBITS}" >> ${WRKSRC}/local.h
.endif

post-build:
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
		sort -u > all.words && \
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
		${MAKE} ${MAKEFLAGS} BUILDHASH=${BUILDHASH} all
.endif
.if defined(ISPELL_AF)
	@cd ${WRKDIR}/${AFDISTFILE:S=.tar.gz==} && \
		${MAKE} ${MAKEFLAGS} BUILDHASH=${BUILDHASH} all
.endif

pre-install:
	@if [ ! -d ${DATADIR} ]; then ${MKDIR} ${DATADIR}; fi

post-install:
.if defined(ISPELL_BRITISH)
	${INSTALL_DATA} ${WRKSRC}/languages/british/english.xlg \
		${DATADIR}/english.dict
.else
	${INSTALL_DATA} ${WRKSRC}/languages/american/english.med+ \
		${DATADIR}/english.dict
.endif
	@-${INSTALL_DATA} ${WRKDIR}/*/*.aff ${WRKDIR}/*/*.hash ${DATADIR}
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
.else
	@${CAT} ${MASTERDIR}/pkg-plist.am >> ${TMPPLIST}
.endif
	@${ECHO} "@dirrm share/ispell" >> ${TMPPLIST}

.include <bsd.port.mk>
