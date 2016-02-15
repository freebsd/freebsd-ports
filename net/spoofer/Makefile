# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	spoofer
PORTVERSION=	0.8e
CATEGORIES=	net
MASTER_SITES=	http://spoofer.caida.org/

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	Spoofer Project testing software

PLIST_FILES=	bin/spoofer
PORTDOCS=	README

HAS_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/prober/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
