# Created by: Gabor Kovesdan

PORTNAME=	symbion-sslproxy
PORTVERSION=	1.0.5
CATEGORIES=	security
MASTER_SITES=	SF/sslproxy/sslproxy/${PORTVERSION}
DISTNAME=	sslproxy-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SSL proxy for securing insecure connections

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Abandonware, last release in 2009 and inactive upstream
EXPIRATION_DATE=2022-03-31

USES=		gmake ssl tar:tgz
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

SUB_FILES=	pkg-message

PORTDOCS=	README
PLIST_FILES=	sbin/ssl_proxy

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		's|^CC =|CC ?=| ; \
		 s|^LD =.*|LD = $$(CC)| ; \
		 s|^CFLAGS =|#CFLAGS =| ; \
		 s|^LDFLAGS =|#LDFLAGS =|' ${WRKSRC}/Makefile.global

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ssl_proxy ${STAGEDIR}${PREFIX}/sbin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
