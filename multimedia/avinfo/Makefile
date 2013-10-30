# Created by: ijliao
# $FreeBSD$

PORTNAME=	avinfo
PORTVERSION=	1.0.a15
CATEGORIES=	multimedia
MASTER_SITES=	http://shounen.ru/soft/avinfo/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION}unix

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A utility for displaying AVI header information

USES=		bison gmake

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz

PORTDOCS=	*


.include <bsd.port.options.mk>

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
