# Created by: Roman Neuhauser <neuhauser@sigpipe.cz>
# $FreeBSD$

PORTNAME=	mathomatic
PORTVERSION=	16.0.5
CATEGORIES=	math
MASTER_SITES=	http://www.panix.com/~gesslein/ \
		CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Highly portable, general purpose CAS (Computer Algebra System)

LICENSE=	GPLv2

USES=		gmake tar:bzip2

MAKEFILE=	makefile

PORTDOCS=	*
PLIST_FILES=	bin/mathomatic man/man1/mathomatic.1.gz \
		share/pixmaps/mathomatic.png \
		share/applications/mathomatic.desktop

MAKE_ARGS=	READLINE=1

OPTIONS_DEFINE=	DOCS

regression-test: build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} check

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mathomatic ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/icons/mathomatic.desktop \
		${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/icons/mathomatic.png ${STAGEDIR}${PREFIX}/share/pixmaps
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
