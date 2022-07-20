PORTNAME=	sbd
PORTVERSION=	1.37
CATEGORIES=	net security
MASTER_SITES=	http://tigerteam.se/dl/sbd/ \
		http://redundancy.redundancy.org/mirror/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Netcat clone with more features and crypto

ALL_TARGET=	unix

PLIST_FILES=	bin/sbd
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sbd ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
