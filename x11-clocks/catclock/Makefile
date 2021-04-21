PORTNAME=	catclock
PORTVERSION=	g20200328
CATEGORIES=	x11-clocks

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Kit-cat xclock

LICENSE=	MIT

USES=		localbase:ldflags motif xorg
USE_GITHUB=	yes
GH_ACCOUNT=	BarkyTheDog
GH_TAGNAME=	9de77d05e04bc463bdbd8cfe1f9247042369e3f9
USE_XORG=	x11 xext xt

CFLAGS+=	-I${LOCALBASE}/include/X11
LIBS+=		-lX11 ${MOTIFLIB} -lXt -lXext -lm

PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz
PORTDOCS=	README.md readme_original
PORTEXAMPLES=	xclock.ad

OPTIONS_DEFINE=	DOCS EXAMPLES

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${LIBS} -o ${PORTNAME} *.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xclock.man ${STAGEDIR}${PREFIX}/share/man/man1/${PORTNAME}.1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S|^|${WRKSRC}/|} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
