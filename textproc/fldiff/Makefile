# New ports collection makefile for:	fldiff
# Date created:				13 Sep 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	fldiff
PORTVERSION=	1.1
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	http://www.easysw.com/~mike/fldiff/ \
		CRITICAL
DISTNAME=	${PORTNAME}-${PORTVERSION}-source

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	A graphical diff program using FLTK

LIB_DEPENDS=	fltk.1:${PORTSDIR}/x11-toolkits/fltk

GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN1=		fldiff.1
PORTDOCS=	index.html fldiff.jpg

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
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
