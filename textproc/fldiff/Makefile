# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	fldiff
PORTVERSION=	1.1
PORTREVISION=	8
CATEGORIES=	textproc
MASTER_SITES=	CRITICAL
DISTNAME=	${PORTNAME}-${PORTVERSION}-source

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Graphical diff program using FLTK

LICENSE=	GPLv2

LIB_DEPENDS=	libfltk.so:${PORTSDIR}/x11-toolkits/fltk

GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PORTDOCS=	index.html fldiff.jpg

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|@OPTIM@||' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|=Development|=Application;Development;|' \
		${WRKSRC}/fldiff.desktop

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fldiff ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/fldiff.man ${STAGEDIR}${MAN1PREFIX}/man/man1/fldiff.1
	${INSTALL_DATA} ${WRKSRC}/fldiff.desktop ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/fldiff.png ${STAGEDIR}${PREFIX}/share/pixmaps
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
