# ex:ts=8
# Ports collection makefile for:  lprps (letter)
# Date created:			  Sat Aug 3, 1996
# Whom:				  David O'Brien (obrien@cs.ucdavis.edu)
#
# $FreeBSD$
#

PORTNAME=	lprps-${PAPERSIZE}
PORTVERSION=	2.5
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.jclark.com/pub/lprps/
DISTNAME=	lprps-2.5
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PostScript printer filter package supporting a bidirectional serial channel

MAKE_FLAGS?=	PAPERSIZE=${PS} -f
MAN1=		psrev.1 textps.1
MAN8=		lprps.8 psif.8 psof.8

PAPERSIZE?=	letter
PS!=		echo ${PAPERSIZE} | awk '{print toupper($$1)}'

.if ${PAPERSIZE} != a4 && ${PAPERSIZE} != letter
.BEGIN:
	@${ECHO_MSG} "Error: invalid value for PAPERSIZE: \"${PAPERSIZE}\""
	@${ECHO_MSG} "Possible values are:  a4 or letter"
	@${FALSE}
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
	@${ECHO_MSG} ""
	@${ECHO_MSG} Now edit your /etc/printcap
	@${ECHO_MSG} ""

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/lprps
	@${INSTALL_DATA} ${WRKSRC}/INSTALL ${PREFIX}/share/doc/lprps
.endif

.include <bsd.port.mk>
