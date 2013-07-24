# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	fldiff
PORTVERSION=	1.1
PORTREVISION=	8
CATEGORIES=	textproc
MASTER_SITES=	http://www.easysw.com/~mike/fldiff/ \
		CRITICAL
DISTNAME=	${PORTNAME}-${PORTVERSION}-source

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Graphical diff program using FLTK

LICENSE=	GPLv2

LIB_DEPENDS=	fltk:${PORTSDIR}/x11-toolkits/fltk

GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN1=		fldiff.1
PORTDOCS=	index.html fldiff.jpg

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|@OPTIM@||' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|=Development|=Application;Development;|' \
		${WRKSRC}/fldiff.desktop

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fldiff ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/fldiff.man ${MAN1PREFIX}/man/man1/fldiff.1
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/fldiff.desktop ${PREFIX}/share/applications
	${MKDIR} ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/fldiff.png ${PREFIX}/share/pixmaps
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
