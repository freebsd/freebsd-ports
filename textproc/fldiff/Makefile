# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	fldiff
PORTVERSION=	1.1
PORTREVISION=	10
CATEGORIES=	textproc
MASTER_SITES=	LOCAL/ehaupt
DISTNAME=	${PORTNAME}-${PORTVERSION}-source

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Graphical diff program using FLTK

LICENSE=	GPLv2

LIB_DEPENDS=	libfltk.so:x11-toolkits/fltk \
		libfontconfig.so:x11-fonts/fontconfig \
		libpng.so:graphics/png

GNU_CONFIGURE=	yes
USES=		jpeg xorg
USE_XORG=	x11 xext xfixes xft

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PORTDOCS=	index.html fldiff.jpg

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|@OPTIM@||' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/CXX="$$CC"/d' ${WRKSRC}/configure
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
