# ex:ts=8
# New ports collection makefile for:    lprps
# Version required:     2.50
# Date created:         Sat Aug 3, 1996
# Whom:                 David O'Brien (obrien@cs.ucdavis.edu)
#
# $Id: Makefile,v 1.3 1997/10/10 06:53:28 obrien Exp $
#

DISTNAME=	lprps-2.5
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.jclark.com/pub/lprps/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=     obrien@FreeBSD.org

MANUAL_PACKAGE_BUILD=	PAPERSIZE has to be set to letter a4
MAKE_FLAGS?=	PAPERSIZE=${PAPERSIZE} -f
MAN1=		psrev.1 textps.1
MAN8=		lprps.8 psif.8 psof.8


letter::
	${MAKE} PAPERSIZE=letter

letter-install::
	${MAKE} PAPERSIZE=letter install

a4::
	${MAKE} PAPERSIZE=a4

a4-install::
	${MAKE} PAPERSIZE=a4 install


.if !defined(PAPERSIZE)
PAPERSIZE=LETTER
PAPERSIZE_UNSPECIFIED=	yes
.elif ${PAPERSIZE} == A4 || ${PAPERSIZE} == a4
PAPERSIZE=A4
.elif ${PAPERSIZE} == letter || ${PAPERSIZE} == LETTER
PAPERSIZE=LETTER
.else
PAPERSIZE_INVALID= yes
.endif	# not defined PAPERSIZE

pre-fetch:
.if defined(PAPERSIZE_UNSPECIFIED)
	@echo "Defaulting to ${PAPERSIZE} sized paper."
	@echo ""
	@echo "Set the environment variable PAPERSIZE if you want to use other sizes."
	@echo "Possible values are:  A4 or letter (default)"
.elif defined(PAPERSIZE_INVALID)
	@echo "Error: invalid value for PAPERSIZE: \"${PAPERSIZE}\"" 
	@echo "Possible values are:  A4 or letter (default)"
	@/usr/bin/false
.endif

do-install:
.for f in textps psrev
	@${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/bin
.endfor
.for f in psif lprps psof
	@${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/libexec
.endfor
.for f in psif-text psif-ps
	@${INSTALL_SCRIPT} ${WRKSRC}/${f} ${PREFIX}/libexec

.endfor
	@-test -d ${PREFIX}/share/lprps || ${MKDIR} ${PREFIX}/share/lprps
	@${INSTALL_DATA} ${WRKSRC}/banner.ps ${PREFIX}/share/lprps
	@${INSTALL_MAN} ${WRKSRC}/textps.n ${PREFIX}/man/man1/textps.1
	@${INSTALL_MAN} ${WRKSRC}/psrev.n ${PREFIX}/man/man1/psrev.1
	@${INSTALL_MAN} ${WRKSRC}/lprps.n ${PREFIX}/man/man8/lprps.8
	@${INSTALL_MAN} ${WRKSRC}/psif.n ${PREFIX}/man/man8/psif.8
	@${INSTALL_MAN} ${WRKSRC}/psof.n ${PREFIX}/man/man8/psof.8
	@${ECHO} ""
	@${ECHO} Now edit your /etc/printcap
	@${ECHO} ""

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/lprps
	@${INSTALL_DATA} ${WRKSRC}/INSTALL ${PREFIX}/share/doc/lprps
.endif

.include <bsd.port.mk>
