PORTNAME=	humanzip
PORTVERSION=	0.5
PORTREVISION= 	1
CATEGORIES=	textproc archivers
MASTER_SITES=	SAVANNAH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Compresses text to human readable output
WWW=		https://savannah.nongnu.org/projects/humanzip/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

PORTDOCS=	CHANGELOG README TODO
PLIST_FILES=	bin/humanunzip bin/humanzip \
		share/man/man1/humanunzip.1.gz share/man/man1/humanzip.1.gz

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		's|g++|$${CXX}| ; \
		 s|-O2|$${CFLAGS}|' ${WRKSRC}/${MAKEFILE}

do-install:
.for i in humanzip humanunzip
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} ${i} ${STAGEDIR}${PREFIX}/bin)
.endfor
	(cd ${WRKSRC} && ${INSTALL_MAN} humanzip.1 \
		${STAGEDIR}${PREFIX}/share/man/man1)
	${LN} -sf humanzip.1 ${STAGEDIR}${PREFIX}/share/man/man1/humanunzip.1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${STAGEDIR}${DOCSDIR})
.endfor

.include <bsd.port.mk>
