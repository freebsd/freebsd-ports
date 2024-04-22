PORTNAME=	multicat
PORTVERSION=	2.3
PORTREVISION=	2
CATEGORIES=	net multimedia
MASTER_SITES=	https://get.videolan.org/multicat/${PORTVERSION}/

MAINTAINER=	m.muenz@gmail.com
COMMENT=	Simple and efficient multicast and transport stream manipulation
WWW=		https://www.videolan.org/projects/multicat.html

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/bitstream/mpeg/ts.h:multimedia/bitstream

USES=		localbase tar:bzip2
ALL_TARGET=	multicat ingests aggregartp reordertp

PLIST_FILES=	bin/aggregartp \
		bin/ingests \
		bin/multicat \
		bin/reordertp \
		share/man/man1/aggregartp.1.gz \
		share/man/man1/ingests.1.gz \
		share/man/man1/multicat.1.gz \
		share/man/man1/reordertp.1.gz
PORTDOCS=	AUTHORS Changelog NEWS README
BINARIES=	${ALL_TARGET}

OPTIONS_DEFINE=	DOCS

do-install:
.for file in ${BINARIES}
	${INSTALL_PROGRAM} ${WRKSRC}/${file} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${file}.1 ${STAGEDIR}${PREFIX}/share/man/man1
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
