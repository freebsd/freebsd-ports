PORTNAME=	zsync
DISTVERSION=	0.6.6
CATEGORIES=	net
MASTER_SITES=	https://zsync.moria.org.uk/download/

MAINTAINER=	chris.longros@gmail.com
COMMENT=	File transfer program
WWW=		https://zsync.moria.org.uk/

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf ssl tar:bzip2
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
		${STAGEDIR}${PREFIX}/share/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
