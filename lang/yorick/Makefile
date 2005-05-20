# New ports collection makefile for:	Yorick
# Date created:         26 Oct 97
# Whom:                 Pedro Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	yorick
PORTVERSION=	1.6.02
CATEGORIES=	lang math
MASTER_SITES=	ftp://ftp-icf.llnl.gov/pub/Yorick/ \
		http://www.maumae.net/yorick/
EXTRACT_SUFX=	.tgz

MAINTAINER=	johans@stack.nl
COMMENT=	Interpreted language and scientific graphics

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}

USE_XLIB=	yes
MAKE_ARGS=	Y_HOME=relocatable Y_DOCDIR=/dev/null
MAN1=		yorick.1 gist.1
INFO=		yorick

PORTDOCS=	FILE_FORMATS README drat.doc graph.doc hex.doc \
		library.doc math.doc refs.pdf refs.ps refs.tex std.doc \
		yorick.pdf yorick.ps yorick.tex

do-configure:
	@(cd ${CONFIGURE_WRKSRC}; ${SETENV} ${MAKE_ENV} \
		${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ysite config)

post-build:
.if !defined(NOPORTDOCS)
	cd ${WRKSRC}/doc; make yorick.info
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/emacs/yorick.el ${WRKSRC}/relocatable
	@${RM} -rf ${WRKSRC}/relocatable/doc
	@${RM} -rf ${PREFIX}/lib/${PORTNAME}
	@${MV} ${WRKSRC}/relocatable ${PREFIX}/lib/${PORTNAME}
.for file in gist yorick
	${INSTALL_MAN} ${WRKSRC}/doc/${file}.1 ${PREFIX}/man/man1
	@${STRIP_CMD} ${PREFIX}/lib/${PORTNAME}/bin/${file}
	@${LN} -sf ${PREFIX}/lib/${PORTNAME}/bin/${file} ${PREFIX}/bin/${file}
.endfor
	@${STRIP_CMD} ${PREFIX}/lib/${PORTNAME}/lib/codger
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${DOCSDIR}
.endfor
	@${LN} -sf ${DOCSDIR} ${PREFIX}/lib/${PORTNAME}/doc
	for f in ${WRKSRC}/doc/yorick.info*; do \
	  ${INSTALL_DATA} $$f ${PREFIX}/info; \
	done
	install-info ${PREFIX}/info/yorick.info ${PREFIX}/info/dir
.endif

.include <bsd.port.mk>
