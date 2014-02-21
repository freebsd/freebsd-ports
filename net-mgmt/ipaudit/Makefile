# Created by: Ying-Chieh Chen <yinjieh@csie.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	ipaudit
PORTVERSION=	0.95
CATEGORIES=	net-mgmt sysutils
MASTER_SITES=	http://ipaudit.sourceforge.net/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IP traffic summarizer

MANPAGE=	ipaudit.1 ipstrings.1 total.1

BIN=		ipaudit ipstrings total

MSG_FILE=	${PKGDIR}/pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

OPTIONS_DEFINE=	DOCS

do-install:
.for f in ${BIN}
	${INSTALL_PROGRAM} ${WRKSRC}/src/${f} ${STAGEDIR}${PREFIX}/bin
.endfor
.for f in ${MANPAGE}
	${INSTALL_MAN} ${WRKSRC}/man/man1/${f} ${STAGEDIR}${PREFIX}/man/man1
.endfor
	${INSTALL_DATA} ${WRKSRC}/src/ipaudit.conf.sample ${STAGEDIR}${PREFIX}/etc
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	@${SED} 's|%%PREFIX%%|${PREFIX}|g' ${MSG_FILE} > ${PKGMESSAGE}

.include <bsd.port.mk>
