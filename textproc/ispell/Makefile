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
		ftp://kdstevens.com/pub/stevens/
DISTFILES=	ispell-3.1.20.tar.gz ${ISPELL_ELISP}

PATCH_SITES=    ftp://ftp.kiarchive.ru/pub/unix/text/ispell/ \
		ftp://kdstevens.com/pub/stevens/
PATCHFILES=     ispell-html-mode.patch texpatch-3.1.20c.gz

MAINTAINER=	jmz@FreeBSD.org

EXTRACT_ONLY=	ispell-3.1.20.tar.gz
ISPELL_ELISP=	ispell.el-3.2.gz

MAKE_FLAGS=	TMPDIR=${WRKDIR} -f
MAN1=		ispell.1 sq.1
MAN4=		ispell.4 english.4
MLINKS=		ispell.1 buildhash.1 ispell.1 findaffix.1 ispell.1 munchlist.1\
		ispell.1 tryaffix.1 sq.1 unsq.1

.if !defined(ISPELL_FR)
.if (make(patch) || make(configure) || make(build) || make (install))
.BEGIN:
	@${ECHO_MSG} '*********************************************************'
	@${ECHO_MSG} '* Note that you can build a french or british version   *'
	@${ECHO_MSG} '* by typing "make french" or "make british"             *'
	@${ECHO_MSG} '*********************************************************'
.endif
.else
EXTRA_DICT=	francais-IREQ-1.4.tar.gz
MASTER_SITES+=	ftp://ftp.robot.ireq.ca/pub/ispell/
DISTFILES+=	${EXTRA_DICT}
EXTRACT_ONLY+=	${EXTRA_DICT}
.endif

pre-extract:
.if !defined(LANG)
	@${ECHO_MSG} '******************************************************'
	@${ECHO_MSG} '* Note that you can build a british version by       *'
	@${ECHO_MSG} '* typing "make british" following a "make clean"     *'
	@${ECHO_MSG} '******************************************************'
.endif

post-extract:
	@${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/${ISPELL_ELISP} > ${WRKSRC}/ispell.el

pre-configure:
.if defined(EXTRA_DICT)
	@${ECHO} ${EXTRA_DICT} > ${WRKDIR}/extra_dict
.else
	@${ECHO} -n
.endif

post-configure:
	@${ECHO} "#define CFLAGS \"${CFLAGS}\"" >> ${WRKSRC}/local.h

british:
	@${ECHO_MSG} "Okay, making a british version of ispell...."
	@${MAKE} ${.MAKEFLAGS} LANG=british all

french:
	@${ECHO_MSG} "Okay, making a french/english version of ispell...."
	@${MAKE} ${.MAKEFLAGS} ISPELL_FR=yes

pre-install:
	@${MKDIR} ${PREFIX}/share/emacs/site-lisp

.include <bsd.port.mk>
