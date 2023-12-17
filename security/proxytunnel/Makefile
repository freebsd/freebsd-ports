PORTNAME=	proxytunnel
PORTVERSION=	1.12.0
DISTVERSIONPREFIX=	v
CATEGORIES=	security

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Connects stdin and stdout to an origin server through an HTTPS proxy
WWW=		https://github.com/proxytunnel/proxytunnel/

LICENSE=	GPLv2+ BSD3CLAUSE MIT
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	asciidoc:textproc/asciidoc \
		minixmlto:textproc/minixmlto

USES=		cpe gmake pkgconfig ssl
BROKEN_SSL=	openssl openssl31
BROKEN_SSL_REASON=	Fails to build with ld: error: undefined symbol: SSL_get_peer_certificate
USE_GITHUB=	yes

PLIST_FILES=	bin/proxytunnel man/man1/proxytunnel.1.gz

post-patch:
	${REINPLACE_CMD} -e "s/xmlto/minixmlto/g" ${WRKSRC}/docs/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/${PORTNAME}.1 \
		${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
