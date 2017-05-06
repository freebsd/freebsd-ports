# Created by: Hammurabi Mendes <hmendes@brturbo.com>
# $FreeBSD$

PORTNAME=	proxytunnel
PORTVERSION=	1.9.1
CATEGORIES=	security

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Connects stdin and stdout to an origin server through an HTTPS proxy

LICENSE=	GPLv2+ BSD3CLAUSE MIT
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	asciidoc:textproc/asciidoc \
		minixmlto:textproc/minixmlto

USES=		pkgconfig gmake ssl
USE_GITHUB=	yes

PLIST_FILES=	bin/proxytunnel man/man1/proxytunnel.1.gz

post-patch:
	${REINPLACE_CMD} -e "s/xmlto/minixmlto/g" ${WRKSRC}/docs/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/${PORTNAME}.1 \
		${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
