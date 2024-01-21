PORTNAME=	mathomatic
DISTVERSION=	16.0.5
PORTREVISION=	3
CATEGORIES=	math

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Highly portable, general purpose CAS (Computer Algebra System)
WWW=		https://github.com/mfillpot/mathomatic

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake readline

USE_GITHUB=	yes
GH_ACCOUNT=	mfillpot
GH_TAGNAME=	ceb0861

MAKEFILE=	makefile
MAKE_ARGS=	READLINE=1
TEST_TARGET=	check # test fails

PLIST_FILES=	bin/mathomatic \
		share/applications/mathomatic.desktop \
		share/man/man1/mathomatic.1.gz \
		share/pixmaps/mathomatic.png
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mathomatic ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_DATA} ${WRKSRC}/icons/mathomatic.desktop \
		${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/icons/mathomatic.png ${STAGEDIR}${PREFIX}/share/pixmaps

do-install-DOCS-on:
.for d in m4 tests
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/${d}
	${INSTALL_DATA} ${WRKSRC}/${d}/* ${STAGEDIR}${DOCSDIR}/${d}
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}/html
.for f in AUTHORS README.txt changes.txt
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
