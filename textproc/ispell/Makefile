# New ports collection makefile for:    ispell
# Version required:     3.1.20
# Date created:         6 November 1994
# Whom:                 jmz
#
# $Id: Makefile,v 1.14 1996/11/17 09:05:56 obrien Exp $
#

DISTNAME=	ispell-3.1
PKGNAME=	ispell-3.1.20
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.cs.ucla.edu/pub/ispell-3.1/
DISTFILES=	ispell-3.1.20.tar.gz

MAINTAINER=	jmz@FreeBSD.org

# French
#EXTRA_DICT=	   francais-IREQ-1.3.tar.gz
#MASTER_SITES+=    ftp://ftp.ireq-robot.hydro.qc.ca/pub/ispell/

DISTFILES+=	   ${EXTRA_DICT}

MAKE_FLAGS=	TMPDIR=${.CURDIR} -f 
MAN1=		buildhash.1 findaffix.1 ispell.1 munchlist.1 \
		sq.1 tryaffix.1 unsq.1
MAN4=		ispell.4 english.4

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

pre-install:
	@${MKDIR} ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/lib
	@${MKDIR} ${PREFIX}/man/man1
	@${MKDIR} ${PREFIX}/man/man4

.include <bsd.port.mk>
