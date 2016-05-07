# $FreeBSD$

PORTNAME=	hourglass
PORTVERSION=	1.0.1
DISTVERSIONSUFFIX=	b
CATEGORIES=	sysutils parallel
MASTER_SITES=	http://www.cs.utah.edu/~regehr/hourglass/

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	Real-time application to learn how CPU scheduling works

RUN_DEPENDS=	jgraph:graphics/jgraph

ONLY_FOR_ARCHS=	i386 amd64
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/busy bin/hourglass
PORTDOCS=	CALIBRATION

OPTIONS_DEFINE=	DOCS

THREAD_LIBS=	-pthread

post-patch:
	@${REINPLACE_CMD} -e 's,%LOCALBASE%,${LOCALBASE},g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's,%THREAD_LIBS%,${THREAD_LIBS},g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's,%THREAD_CFLAGS%,${THREAD_CFLAGS},g' \
		${WRKSRC}/configure

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
