# New ports collection makefile for:	ispell
# Date created:				6 November 1994
# Whom:					jmz
#
# $FreeBSD$
#

PORTNAME?=	ispell
PORTVERSION?= 	3.1.20c
CATEGORIES=	textproc elisp
MASTER_SITES=	ftp://ftp.cs.ucla.edu/pub/ispell-3.1/ \
		ftp://ftp.kiarchive.ru/pub/unix/text/ispell/

MAINTAINER=	jmz@FreeBSD.org
PATCH_SITES=	ftp://ftp.kiarchive.ru/pub/unix/text/ispell/
ISPELL_FILES=	ispell-3.1.20.tar.gz
HTML_PATCH=	ispell-html-mode.patch
DISTFILES=	${ISPELL_FILES}
PATCHFILES=	${HTML_PATCH}

MAN1=		ispell.1 sq.1
MAN4=		ispell.4 english.4
MLINKS=		ispell.1 buildhash.1 ispell.1 findaffix.1 ispell.1 \
		munchlist.1 ispell.1 tryaffix.1 sq.1 unsq.1

EXTRACT_ONLY=	${ISPELL_FILES}
EXTRA_DICT=
MAKE_FLAGS=	TMPDIR=${WRKDIR} -f
ALL_TARGET=
BUILDHASH=	${WRKSRC}/buildhash
DATADIR=	${PREFIX}/share/ispell

.if (!defined(ISPELL_FR) && !defined (ISPELL_SE) && !defined(ISPELL_BR) && !defined(ISPELL_DENEU) && !defined(ISPELL_DEALT) && !defined(ISPELL_BRITISH) && !defined(ISPELL_NO))
.if (make(extract) || make(patch) || make(configure) || make(build) || make (install))
.BEGIN:
	@${ECHO_MSG} '*********************************************************'
	@${ECHO_MSG} '* You can add further dictionaries:                     *'
	@${ECHO_MSG} '*                              Use make-flag:           *'
	@${ECHO_MSG} '*  - British                   ISPELL_BRITISH=yes       *'
	@${ECHO_MSG} '*    (replaces the American dictionary)                 *'
	@${ECHO_MSG} '*  - French                    ISPELL_FR=yes            *'
	@${ECHO_MSG} '*  - Brasilian                 ISPELL_BR=yes            *'
	@${ECHO_MSG} '*  - German (old spelling)     ISPELL_DEALT=yes         *'
	@${ECHO_MSG} '*  - German (new spelling)     ISPELL_DENEU=yes         *'
	@${ECHO_MSG} '*  - Swedish                   ISPELL_SE=yes            *'
	@${ECHO_MSG} '*  - Norwegian                 ISPELL_NO=yes            *'
	@${ECHO_MSG} '* Example: "make ISPELL_FR=yes ISPELL_SE=yes install"   *'
	@${ECHO_MSG} '*********************************************************'
.endif
.else
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
DENEUDISTFILE=	igerman98-19991219.tar.gz
MASTER_SITES+=	http://members.xoom.com/maccy/ispell/dict/ \
		ftp://student.physik.uni-dortmund.de/pub/users/jacke/ispell/
EXTRA_DICT+=	${DENEUDISTFILE}
EXTRACT_ONLY+=	${DENEUDISTFILE}
FETCH_BEFORE_ARGS+=	-b		# HTTP Workaround at Xoom
.endif
.if defined(ISPELL_DEALT)
DEALTDISTFILE=	hk-deutsch.tar.gz
EXTRA_DICT+=	${DEALTDISTFILE}
MASTER_SITES+=	ftp://ftp.informatik.uni-kiel.de/pub/kiel/dicts/
.endif
.if defined(ISPELL_NO)
NODISTFILE=    ispell-norsk-1.1a.tar.gz
MASTER_SITES+= http://www.uio.no/~runekl/
EXTRA_DICT+=   ${NODISTFILE}
MASKBITS?=     64
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
.if defined(ISPELL_NO)
	@${MKDIR} ${WRKDIR}/inorsk
	@${TAR} -C ${WRKDIR}/inorsk/ -zxf ${PORTSDIR}/distfiles/${NODISTFILE}
.endif

post-patch:
.if defined(ISPELL_FR)
	@cd ${WRKDIR} && ${PATCH} < ${FILESDIR}/FR.patch 2>/dev/null
.endif
.if defined(ISPELL_BR)
	@cd ${WRKDIR}/${BRDISTFILE:S/.tar.gz$//} && ${PATCH} < ${FILESDIR}/BR.patch 2>/dev/null
.endif
.if defined(ISPELL_DENEU)
	@cd ${WRKDIR} && ${PATCH} < ${FILESDIR}/DENEU.patch 2>/dev/null
.endif
.if defined(ISPELL_SE)
	@cd ${WRKDIR} && ${PATCH} < ${FILESDIR}/SE.patch 2>/dev/null
.endif
.if defined(ISPELL_NO)
	@cd ${WRKSRC} && ${PATCH} < ${FILESDIR}/NO.patch 2>/dev/null
.endif

post-configure:
	@${ECHO} "#define CFLAGS \"${CFLAGS}\"" >> ${WRKSRC}/local.h
.if defined(MASKBITS)
	@${ECHO} "#define MASKBITS ${MASKBITS}" >> ${WRKSRC}/local.h
.endif

post-build:
.if defined(ISPELL_DENEU)
	@cd ${WRKDIR}/${DENEUDISTFILE:S=.tar.gz==} && \
		${MAKE} ${MAKEFLAGS} BUILDHASH=${BUILDHASH} german.hash && \
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
	@cd ${WRKDIR}/inorsk && \
		${CP} norsk.7bit norsk.aff && \
		${CAT} norsk.base > norsk.sml && \
		${BUILDHASH} norsk.sml norsk.aff norsk.hash
.endif

pre-install:
	@if [ ! -d ${DATADIR} ]; then ${MKDIR} ${DATADIR}; fi

post-install:
	@-${INSTALL_DATA} ${WRKDIR}/*/*.aff ${WRKDIR}/*/*.hash ${DATADIR}
.if defined(ISPELL_FR)
	@${CAT} ${MASTERDIR}/pkg/PLIST.FR >> ${TMPPLIST}
.endif
.if defined(ISPELL_DEALT)
	@${CAT} ${MASTERDIR}/pkg/PLIST.DEALT >> ${TMPPLIST}
.endif
.if defined(ISPELL_DENEU)
	@${CAT} ${MASTERDIR}/pkg/PLIST.DENEU >> ${TMPPLIST}
.endif
.if defined(ISPELL_BR)
	@${CAT} ${MASTERDIR}/pkg/PLIST.BR >> ${TMPPLIST}
.endif
.if defined(ISPELL_SE)
	@${CAT} ${MASTERDIR}/pkg/PLIST.SE >> ${TMPPLIST}
.endif
.if defined(ISPELL_NO)
	@${CAT} ${MASTERDIR}/pkg/PLIST.NO >> ${TMPPLIST}
.endif
.if defined(ISPELL_BRITISH)
	@${CAT} ${MASTERDIR}/pkg/PLIST.BRITISH >> ${TMPPLIST}
.else
	@${CAT} ${MASTERDIR}/pkg/PLIST.AM >> ${TMPPLIST}
.endif
	@${ECHO} "@dirrm share/ispell" >> ${TMPPLIST}

.include <bsd.port.mk>
