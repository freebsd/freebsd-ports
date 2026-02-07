PORTNAME=	prtunnel
PORTVERSION=	0.2.7
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://joshbeam.com/files/

MAINTAINER=	vd@FreeBSD.org
COMMENT=	Tunnel for TCP connections using an HTTP or SOCKS5 proxy
WWW=		https://www.joshbeam.com/software/prtunnel/

ALL_TARGET=	${PORTNAME}

PORTDOCS=	ChangeLog README
PLIST_FILES=	bin/prtunnel share/man/man1/prtunnel.1.gz

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -E '/^(CC|CFLAGS|PREFIX)/d' \
		${WRKSRC}/Makefile

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
