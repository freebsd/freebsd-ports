# New ports collection makefile for:    ispell
# http://fmg-www.cs.ucla.edu/fmg-members/geoff/ispell.html
# Version required:     3.1.20
# Date created:         6 November 1994
# Whom:                 jmz
#
# $Id: Makefile,v 1.23 1997/12/16 20:17:36 ache Exp $
#

DISTNAME=	ispell-3.1
PKGNAME=	ispell-3.1.20
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.cs.ucla.edu/pub/ispell-3.1/
DISTFILES=	ispell-3.1.20.tar.gz

PATCH_SITES=    ftp://ftp.kiarchive.ru/pub/unix/text/ispell/
PATCHFILES=     ispell-html-mode.patch

MAINTAINER=	jmz@FreeBSD.org

MAKE_FLAGS=	TMPDIR=${.CURDIR} -f 
MAN1=		buildhash.1 findaffix.1 ispell.1 munchlist.1 \
		sq.1 tryaffix.1 unsq.1
MAN4=		ispell.4 english.4

pre-fetch pre-build pre-install:
.if !defined(ISPELL_FR)
	@echo '*********************************************************' 
	@echo '* Note that you can build a french or british version   *' 
	@echo '* by typing "make french" or "make british"             *'
	@echo '*********************************************************' 
.else
EXTRA_DICT=	francais-IREQ-1.4.tar.gz
MASTER_SITES+=	ftp://ftp.robot.ireq.ca/pub/ispell/
DISTFILES+=	${EXTRA_DICT}
.endif	

pre-extract:
.if !defined(LANG) 
	@echo '******************************************************' 
	@echo '* Note that you can build a british version by       *' 
	@echo '* typing "make british" following a "make clean"     *' 
	@echo '******************************************************' 
.endif	


pre-configure:
.if defined(EXTRA_DICT)
	@echo ${EXTRA_DICT} > ${WRKDIR}/extra_dict
.else
	@echo -n
.endif

post-configure:
	@echo "#define CFLAGS \"${CFLAGS}\"" >> ${WRKSRC}/local.h

british:
	@echo "Okay, making a british version of ispell...."
	@${MAKE} ${.MAKEFLAGS} LANG=british all 

french:
	@echo "Okay, making a french/english version of ispell...."
	@${MAKE} ${.MAKEFLAGS} ISPELL_FR=yes

pre-install:
	@${MKDIR} ${PREFIX}/share/emacs/site-lisp

.include <bsd.port.mk>
