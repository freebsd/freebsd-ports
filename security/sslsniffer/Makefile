# Created by: Jim Geovedi <jim@corebsd.or.id>
# $FreeBSD$

PORTNAME=	sslsniffer
PORTVERSION=	1.21
CATEGORIES=	security net
MASTER_SITES=	http://crypto.stanford.edu/~eujin/sslsniffer/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SSLv3/TLS and SSLv2 sniffer

LICENSE=	GPLv2+

USES=		ssl
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}
WRKSRC=		${WRKDIR}/${PORTNAME}

PORTDOCS=	README
PLIST_FILES=	bin/sslsniffer

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sslsniffer ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
