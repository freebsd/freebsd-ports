# Created by: Fernan Aguero <fernan@iib.unsam.edu.ar>
# $FreeBSD$

PORTNAME=	flpsed
PORTVERSION=	0.7.2
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://www.ecademix.com/JohannesHofmann/

MAINTAINER=	bf@FreeBSD.org
COMMENT=	WYSIWYG Postscript annotator

LICENSE=	GPLv3

LIB_DEPENDS+=	libfltk.so:${PORTSDIR}/x11-toolkits/fltk

GNU_CONFIGURE=	yes
USE_GHOSTSCRIPT=yes
USES=		desktop-file-utils gmake
PLIST_DIRSTRY=	share/icons
PLIST_FILES=	bin/flpsed \
		man/man1/flpsed.1.gz \
		share/applications/flpsed.desktop \
		share/icons/flpsed.png \
		share/icons/flpsed.svg
PORTDOCS=	README

post-configure:
	@${FIND} -X ${WRKSRC} -type f -name Makefile | ${XARGS} \
	${REINPLACE_CMD} -e "s|-lpthread|${PTHREAD_LIBS}|g"

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/flpsed ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/flpsed.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/flpsed.desktop ${STAGEDIR}${PREFIX}/share/applications
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons
	${INSTALL_DATA} ${WRKSRC}/flpsed.png ${WRKSRC}/flpsed.svg ${STAGEDIR}${PREFIX}/share/icons
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
.endif

post-install:
.if !exists(${LOCALBASE}/bin/pdftops)
	@${ECHO_CMD} ""
	@${ECHO_CMD} " Consider installing graphics/xpdf, to take full advantage of "
	@${ECHO_CMD} " flpsed's ability to edit PDF files by first converting them "
	@${ECHO_CMD} " to PostScript via xpdf's pdftops(1) before editing, and then "
	@${ECHO_CMD} " transforming the edited Postscript files back to PDF via "
	@${ECHO_CMD} " Ghostscript's ps2pdf(1). "
	@${ECHO_CMD} ""
.endif

.include <bsd.port.mk>
