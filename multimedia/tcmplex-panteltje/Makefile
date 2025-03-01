PORTNAME=	tcmplex-panteltje
PORTVERSION=	0.4.7
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://panteltje.com/panteltje/dvd/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Re-write of the A/V multiplexer from the transcode distribution
WWW=		http://panteltje.com/panteltje/dvd/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN=		Unfetchable
DEPRECATED=	Abandonware, upstream is gone and no consumers in tree
EXPIRATION_DATE=2025-03-31

USES=		tar:tgz
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"
ALL_TARGET=	a.out

PORTDOCS=	CHANGES README
PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
