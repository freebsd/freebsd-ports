# New ports collection makefile for:	flpsed
# Date created:				6 January 2005
# Whom:					Fernan Aguero <fernan@iib.unsam.edu.ar>
#
# $FreeBSD$
#

PORTNAME=	flpsed
PORTVERSION=	0.6.1
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://www.ecademix.com/JohannesHofmann/

MAINTAINER=	bf1783@gmail.com
COMMENT=	WYSIWYG Postscript pseudo-editor

BUILD_DEPENDS+=	${LOCALBASE}/lib/libfltk2.a:${PORTSDIR}/x11-toolkits/fltk2
RUN_DEPENDS+=	${LOCALBASE}/lib/libfltk2.a:${PORTSDIR}/x11-toolkits/fltk2

GNU_CONFIGURE=	yes
USE_GHOSTSCRIPT=yes
USE_GMAKE=	yes

PLIST_FILES=	bin/flpsed
MAN1=		flpsed.1
PORTDOCS=	README

post-configure:
	@${FIND} -X ${WRKSRC} -type f | ${XARGS} ${REINPLACE_CMD} -e \
		"s|-lpthread|${PTHREAD_LIBS}|g"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/flpsed ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/flpsed.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
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
