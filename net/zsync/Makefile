PORTNAME=	zsync
PORTVERSION=	0.6.2
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://zsync.moria.org.uk/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	File transfer program

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf tar:bzip2
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/zsync \
		bin/zsyncmake \
		share/man/man1/zsync.1.gz \
		share/man/man1/zsyncmake.1.gz
PORTDOCS=	INSTALL NEWS README

_MANPAGE=	zsync.1 zsyncmake.1
_BINS=		zsync zsyncmake

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${_BINS:S,^,${WRKSRC}/,} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${_MANPAGE:S,^,${WRKSRC}/doc/,} \
		${STAGEDIR}${MANPREFIX}/share/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
