# Created by: ijliao

PORTNAME=	avinfo
PORTVERSION=	1.0.a15
CATEGORIES=	multimedia
MASTER_SITES=	http://shounen.ru/soft/avinfo/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION}unix

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Utility for displaying AVI header information

DEPRECATED=	Last release in 2008, please consider using multimedia/mediainfo or multimedia/ffmpeg instead
EXPIRATION_DATE=2022-06-30

USES=		bison gmake

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

# Fix build with clang11. Seems dead upstream.
CFLAGS+=	-fcommon

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/^CC=/ d; /^CFLAGS=/ d; /^PREFIX=/ d' \
		${WRKSRC}/config.mk
	@${REINPLACE_CMD} -e '/BISON.*-d/ s|$$| \&\& ${REINPLACE_CMD} -e "/int yyparse (void)/ d" ass.tab.h|' \
		${WRKSRC}/src/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/src/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${WRKSRC}/README \
		${WRKSRC}/copying ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
