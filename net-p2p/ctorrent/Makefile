PORTNAME=	ctorrent
PORTVERSION=	3.3.2
PORTREVISION=	5
CATEGORIES=	net-p2p
MASTER_SITES=	SF/dtorrent/dtorrent/${PORTVERSION} \
		http://www.rahul.net/dholmes/ctorrent/
DISTNAME=	${PORTNAME}-dnh${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	BitTorrent Client written in C for FreeBSD and Linux
WWW=		https://www.rahul.net/dholmes/ctorrent/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=	ssl

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/ctorrent share/man/man1/ctorrent.1.gz
PORTDOCS=	README-DNH.TXT UserGuide

OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_MAN} ${FILESDIR}/ctorrent.1 \
		${STAGEDIR}${PREFIX}/share/man/man1/

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/$i ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
