# New ports collection makefile for:	ipaudit
# Date created:		15 July 2003
# Whom:			Ying-Chieh Chen <yinjieh@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	ipaudit
PORTVERSION=	0.95
CATEGORIES=	net-mgmt sysutils
MASTER_SITES=	http://ipaudit.sourceforge.net/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	yinjieh@csie.nctu.edu.tw
COMMENT=	IP traffic summarizer

MAN1=		ipaudit.1 ipstrings.1 total.1

BIN=		ipaudit ipstrings total

MSG_FILE=	${PKGDIR}/pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

do-install:
.for b in ${BIN}
	cd ${WRKSRC}/src && ${INSTALL_PROGRAM} $b ${PREFIX}/bin
.endfor
.for m in ${MAN1}
	cd ${WRKSRC}/man/man1 && ${INSTALL_MAN} $m ${PREFIX}/man/man1
.endfor
	cd ${WRKSRC}/src && ${INSTALL_DATA} ipaudit.conf.sample ${PREFIX}/etc

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
	@${SED} 's|%%PREFIX%%|${PREFIX}|g' ${MSG_FILE} > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
