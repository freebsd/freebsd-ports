# ex:ts=8
# Ports collection makefile for:  lprps (letter)
# Date created:			  Sat Aug 3, 1996
# Whom:				  David O'Brien (obrien@cs.ucdavis.edu)
#
# $FreeBSD$
#

PORTNAME=	lprps
PORTVERSION=	2.5
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.jclark.com/pub/lprps/
PKGNAMESUFFIX=	-${PAPERSIZE}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PostScript printer filter package supporting a bidirectional serial channel

MAKE_FLAGS?=	PAPERSIZE=${PS} -f
PORTDOCS=	INSTALL

MAN1=		psrev.1 textps.1
MAN8=		lprps.8 psif.8 psof.8

PAPERSIZE?=	letter
PS=		${PAPERSIZE:U}

.if ${PAPERSIZE} != a4 && ${PAPERSIZE} != letter
.BEGIN:
	@${ECHO_MSG} "Error: invalid value for PAPERSIZE: \"${PAPERSIZE}\""
	@${ECHO_MSG} "Possible values are:  a4 or letter"
	@${FALSE}
.endif

do-install:
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && \
		${INSTALL_PROGRAM} textps psrev ${PREFIX}/bin && \
		${INSTALL_PROGRAM} psif lprps psof ${PREFIX}/libexec && \
		${INSTALL_SCRIPT} psif-text psif-ps ${PREFIX}/libexec && \
		${INSTALL_DATA} banner.ps ${DATADIR} && \
		${INSTALL_MAN} textps.n ${PREFIX}/man/man1/textps.1 && \
		${INSTALL_MAN} psrev.n ${PREFIX}/man/man1/psrev.1 && \
		${INSTALL_MAN} lprps.n ${PREFIX}/man/man8/lprps.8 && \
		${INSTALL_MAN} psif.n ${PREFIX}/man/man8/psif.8 && \
		${INSTALL_MAN} psof.n ${PREFIX}/man/man8/psof.8

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
	@${ECHO_MSG} ""
	@${ECHO_MSG} Now edit your /etc/printcap
	@${ECHO_MSG} ""

.include <bsd.port.mk>
