# Created by: Kirill Ponomarew <krion@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hidentd
PORTVERSION=	0.4
CATEGORIES=	net
MASTER_SITES=	http://core.segfault.pl/~hobbit/hidentd/dist/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple and secure ident (RFC1413) server

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes

PORTDOCS=	README
PLIST_FILES=	man/man8/hidentd.8.gz sbin/hidentd

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
