# New ports collection makefile for: checkpassword
# Version required:	0.81
# Date created:		05 August 1998
# Whom:			sada@FreeBSD.ORG
#
# $Id$
#

DISTNAME=	checkpassword-0.81
CATEGORIES=	security
MASTER_SITES=	ftp://koobera.math.uic.edu/www/software/

MAINTAINER=	sada@FreeBSD.ORG

ALL_TARGET=	it
INSTALL_TARGET=	setup
MAN8=		checkpassword.8
RESTRICTED=	Unsure of djb's license

DOCDIR=		${PREFIX}/share/doc/checkpassword

.SILENT:

do-configure:
	${ECHO} 'cc -s -lcrypt' > ${WRKSRC}/conf-ld
	${ECHO} ${PREFIX} >${WRKSRC}/conf-home

post-install:
	${INSTALL_MAN} ${WRKSRC}/${MAN8} ${PREFIX}/man/man8
	${MKDIR} ${DOCDIR}
.for f in BLURB CHANGES FILES INSTALL README SYSDEPS TARGETS THANKS TODO
	${INSTALL_DATA} ${WRKSRC}/$f ${DOCDIR}
.endfor

.include <bsd.port.mk>
