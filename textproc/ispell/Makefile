# New ports collection makefile for:    ispell
# http://fmg-www.cs.ucla.edu/fmg-members/geoff/ispell.html
# Version required:     3.1.20
# Date created:         6 November 1994
# Whom:                 jmz
#
# $FreeBSD$
#

DISTNAME=	ispell-3.1
PKGNAME=	ispell-3.1.20c
CATEGORIES=	textproc elisp
MASTER_SITES=	ftp://ftp.cs.ucla.edu/pub/ispell-3.1/ \
		ftp://ftp.kiarchive.ru/pub/unix/text/ispell/
PATCH_SITES=	ftp://ftp.kiarchive.ru/pub/unix/text/ispell/
ISPELL_FILES=	ispell-3.1.20.tar.gz
HTML_PATCH=	ispell-html-mode.patch

DISTFILES=	${ISPELL_FILES}
PATCHFILES=	${HTML_PATCH}

MAINTAINER=	jmz@FreeBSD.org

MAKE_FLAGS=	TMPDIR=${WRKDIR} -f
MAN1=		ispell.1 sq.1
MAN4=		ispell.4 english.4
MLINKS=		ispell.1 buildhash.1 ispell.1 findaffix.1 ispell.1 munchlist.1\
		ispell.1 tryaffix.1 sq.1 unsq.1
EXTRACT_ONLY=	${ISPELL_FILES}
EXTRA_DICT=	

.if (!defined(ISPELL_FR) && !defined (ISPELL_SE) && !defined(ISPELL_BR) && !defined(ISPELL_DENEU) && !defined(ISPELL_DEALT) && !defined(ISPELL_LANG))
.if (make(patch) || make(configure) || make(build) || make (install))
.BEGIN:
	@${ECHO_MSG} '*********************************************************'
	@${ECHO_MSG} '* Note that you can add build a british version by      *'
	@${ECHO_MSG} '* typing "make british" (port must be clean, type       *'
	@${ECHO_MSG} '* "make clean" to clean it).                            *'
	@${ECHO_MSG} '* Additionally, you can add further dictionaries:       *'
	@${ECHO_MSG} '*                              Use make-flag:           *'
	@${ECHO_MSG} '*  - French                    ISPELL_FR=yes            *'
	@${ECHO_MSG} '*  - Brasilian                 ISPELL_BR=yes            *'
	@${ECHO_MSG} '*  - German (old spelling)     ISPELL_DEALT=yes         *'
	@${ECHO_MSG} '*  - German (new spelling)     ISPELL_DENEU=yes         *'
	@${ECHO_MSG} '*  - Swedish                   ISPELL_SE=yes            *'
	@${ECHO_MSG} '* Example: "make ISPELL_FR=yes ISPELL_SE=yes british"   *'
	@${ECHO_MSG} '*********************************************************'
.endif
.else
.if defined(ISPELL_FR)
FRDISTFILE=	francais-IREQ-1.4.tar.gz
EXTRA_DICT+=	${FRDISTFILE}
MASTER_SITES+=	ftp://ftp.robot.ireq.ca/pub/ispell/
.endif
.if defined(ISPELL_SE)
SEDISTFILE=	iswedish-1.2.1.tar.gz
MASTER_SITES+=	http://www.sslug.dk/locale/ispell/iswedish/	
EXTRA_DICT+=	${SEDISTFILE}
EXTRACT_ONLY+=	${SEDISTFILE}
.endif
.if defined(ISPELL_BR)
BRDISTFILE=	br.ispell-2.3.tar.gz
EXTRA_DICT+=	${BRDISTFILE}
EXTRACT_ONLY+=	${BRDISTFILE}
MASTER_SITES+=	ftp://ftp.ime.usp.br/pub/ueda/br.ispell/
.endif
.if defined(ISPELL_DENEU)
DENEUDISTFILE=	igerman98-19991219.tar.gz
EXTRA_DICT+=	${DENEUDISTFILE}
EXTRACT_ONLY+=	${DENEUDISTFILE}
MASTER_SITES+=	http://members.xoom.com/maccy/ispell/dict/ \
		ftp://student.physik.uni-dortmund.de/pub/users/jacke/ispell/ 
FETCH_BEFORE_ARGS+=	-b		# HTTP Workaround at Xoom
.endif
.if defined(ISPELL_DEALT)
DEALTDISTFILE=	hk-deutsch.tar.gz
EXTRA_DICT+=	${DEALTDISTFILE}
MASTER_SITES+=	ftp://ftp.informatik.uni-kiel.de/pub/kiel/dicts/
.endif
DISTFILES+=	${EXTRA_DICT}
.endif
ALL_TARGET=	WRKDIR=${WRKDIR} SEDISTFILE=${SEDISTFILE} BRDISTFILE=${BRDISTFILE} all

british:
	@${ECHO_MSG} "Okay, making a british version of ispell...."
	@${MAKE} ${.MAKEFLAGS} ISPELL_LANG=british all
	@${TOUCH} ${WRKDIR}/.british-build

post-extract:
.if defined(ISPELL_FR)
	@${MKDIR} -p ${WRKDIR}/francais-IREQ
	@${TAR} -C ${WRKDIR}/francais-IREQ -zxf ${PORTSDIR}/distfiles/${FRDISTFILE}
.endif
.if defined(ISPELL_DEALT)
	-@${MKDIR} ${WRKDIR}/hk-deutsch
	@${TAR} -C ${WRKDIR}/hk-deutsch/ -zxf ${PORTSDIR}/distfiles/${DEALTDISTFILE}
.endif
	@${TOUCH} ${WRKSRC}/dummy
	@${CP} ${FILESDIR}/Makefile ${WRKDIR}/Makefile

post-patch:
.if defined(ISPELL_FR)
	@cd ${WRKDIR} && ${PATCH} < ${FILESDIR}/FR.patch 2>/dev/null
.endif
.if defined(ISPELL_BR)
	@cd ${WRKDIR} && ${PATCH} < ${FILESDIR}/BR.patch 2>/dev/null
	@cd ${WRKDIR} && ${PATCH} < ${FILESDIR}/BR2.patch 2>/dev/null
.endif
.if defined(ISPELL_DENEU)
	@cd ${WRKDIR} && ${PATCH} < ${FILESDIR}/DENEU.patch 2>/dev/null
.endif
.if defined(ISPELL_SE)
	@cd ${WRKDIR} && ${PATCH} < ${FILESDIR}/SE.patch 2>/dev/null
.endif

post-configure:
	@${ECHO} "#define CFLAGS \"${CFLAGS}\"" >> ${WRKSRC}/local.h

do-build:
	@(cd ${WRKDIR}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} WRKSRC=${WRKSRC} ${ALL_TARGET})

do-install:
	@(cd ${WRKDIR}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} WRKSRC=${WRKSRC} ${INSTALL_TARGET})

post-install:
	@[ -e ${WRKDIR}/.british-build ] && \
		cat ${.CURDIR}/pkg/PLIST.BRITISH >> ${TMPPLIST} || \
		cat ${.CURDIR}/pkg/PLIST.AM >> ${TMPPLIST}
.if defined(ISPELL_FR)
	@cat ${.CURDIR}/pkg/PLIST.FR >> ${TMPPLIST}
.endif
.if defined(ISPELL_DEALT)
	@cat ${.CURDIR}/pkg/PLIST.DEALT >> ${TMPPLIST}
.endif
.if defined(ISPELL_DENEU)
	@cat ${.CURDIR}/pkg/PLIST.DENEU >> ${TMPPLIST}
.endif
.if defined(ISPELL_BR)
	@cat ${.CURDIR}/pkg/PLIST.BR >> ${TMPPLIST}
.endif
.if defined(ISPELL_SE)
	@cat ${.CURDIR}/pkg/PLIST.SE >> ${TMPPLIST}
.endif
	@echo "@dirrm share/ispell" >> ${TMPPLIST}
	
.include <bsd.port.mk>
