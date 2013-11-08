# $FreeBSD$

PORTNAME=	hourglass
PORTVERSION=	1.0.1
CATEGORIES=	sysutils parallel
MASTER_SITES=	http://www.cs.utah.edu/~regehr/hourglass/
DISTNAME=	${PORTNAME}-${PORTVERSION}b

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	Real-time application to learn how CPU scheduling works

RUN_DEPENDS=	jgraph:${PORTSDIR}/graphics/jgraph

ONLY_FOR_ARCHS=	i386 amd64
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/busy bin/hourglass
PORTDOCS=	CALIBRATION

.include <bsd.port.options.mk>

THREAD_LIBS=	-pthread

post-patch:
	@${REINPLACE_CMD} -e 's,%LOCALBASE%,${LOCALBASE},g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's,%THREAD_LIBS%,${THREAD_LIBS},g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's,%THREAD_CFLAGS%,${THREAD_CFLAGS},g' \
		${WRKSRC}/configure

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
. for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
. endfor
.endif

.include <bsd.port.mk>
