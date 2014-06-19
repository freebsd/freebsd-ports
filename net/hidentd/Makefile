# Created by: Kirill Ponomarew <krion@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hidentd
PORTVERSION=	0.4
CATEGORIES=	net
MASTER_SITES=	http://core.segfault.pl/~hobbit/hidentd/dist/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple and secure ident (RFC1413) server

GNU_CONFIGURE=	yes

PORTDOCS=	README
PLIST_FILES=	man/man8/hidentd.8.gz sbin/hidentd

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in README
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
