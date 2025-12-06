PORTNAME=	proxytunnel
DISTVERSIONPREFIX=	v
DISTVERSION=	1.12.3
CATEGORIES=	security

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Connects stdin and stdout to an origin server through an HTTPS proxy
WWW=		https://github.com/proxytunnel/proxytunnel/

LICENSE=	BSD3CLAUSE GPLv2+ MIT
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	asciidoc:textproc/asciidoc \
		minixmlto:textproc/minixmlto

USES=		cpe gmake pkgconfig ssl
USE_GITHUB=	yes

PLIST_FILES=	bin/proxytunnel \
		share/man/man1/proxytunnel.1.gz

post-patch:
	${REINPLACE_CMD} -e "s/xmlto/minixmlto/g" ${WRKSRC}/docs/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/${PORTNAME}.1 \
		${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
