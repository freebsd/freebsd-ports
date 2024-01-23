PORTNAME=	sbd
PORTVERSION=	1.37
CATEGORIES=	net security
MASTER_SITES=	http://tigerteam.se/dl/sbd/ \
		http://redundancy.redundancy.org/mirror/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Netcat clone with more features and crypto
WWW=		http://tigerteam.se/dl/sbd/

BROKEN=		Unfetchable
DEPRECATED=     Abandonware and unfetchable, consider using ncat in security/nmap
EXPIRATION_DATE=2024-02-29

ALL_TARGET=	unix

PLIST_FILES=	bin/sbd
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sbd ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
