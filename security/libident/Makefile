PORTNAME=	libident
PORTVERSION=	0.32
PORTREVISION=	4
CATEGORIES=	security
MASTER_SITES=	http://www.remlab.net/files/libident/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small library to interface the ident protocol server (rfc1413)

USES=		libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
