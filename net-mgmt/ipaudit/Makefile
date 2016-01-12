# Created by: Ying-Chieh Chen <yinjieh@csie.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	ipaudit
PORTVERSION=	0.95
CATEGORIES=	net-mgmt sysutils
MASTER_SITES=	http://ipaudit.sourceforge.net/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IP traffic summarizer

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:tgz
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

do-install:
.for f in ipaudit ipstrings total
	${INSTALL_PROGRAM} ${WRKSRC}/src/${f} ${STAGEDIR}${PREFIX}/bin
.endfor
.for f in ipaudit.1 ipstrings.1 total.1
	${INSTALL_MAN} ${WRKSRC}/man/man1/${f} ${STAGEDIR}${PREFIX}/man/man1
.endfor
	${INSTALL_DATA} ${WRKSRC}/src/ipaudit.conf.sample ${STAGEDIR}${PREFIX}/etc

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
