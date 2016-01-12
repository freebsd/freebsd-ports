# Created by: Gabor Kovesdan
# $FreeBSD$

PORTNAME=	symbion-sslproxy
PORTVERSION=	1.0.5
CATEGORIES=	security
MASTER_SITES=	SF/sslproxy/sslproxy/${PORTVERSION}
DISTNAME=	sslproxy-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SSL proxy for securing insecure connections

LICENSE=	GPLv2+

USES=		gmake tar:tgz
USE_OPENSSL=	yes

SUB_FILES=	pkg-message

PORTDOCS=	README
PLIST_FILES=	sbin/ssl_proxy

post-patch:
	@${REINPLACE_CMD} -e \
		's|^CC =|CC ?=| ; \
		 s|^LD =.*|LD = $$(CC)| ; \
		 s|^CFLAGS =|#CFLAGS =| ; \
		 s|^LDFLAGS =|#LDFLAGS =|' ${WRKSRC}/Makefile.global

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} ssl_proxy ${STAGEDIR}${PREFIX}/sbin)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} README ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
