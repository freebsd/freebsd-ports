# Created by: Pedro Giffuni <giffunip@asme.org>
# $FreeBSD$

PORTNAME=	yorick
PORTVERSION=	2.1.06
CATEGORIES=	lang math
MASTER_SITES=	SF
EXTRACT_SUFX=	.tgz

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Interpreted language for scientific simulations

USE_XORG=	x11
MAKE_ARGS=	Y_HOME=relocatable Y_DOCDIR=/dev/null
MAN1=		yorick.1 gist.1
INFO=		yorick

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}

PORTDOCS=	FILE_FORMATS README drat.doc graph.doc hex.doc \
		library.doc math.doc refs.pdf refs.tex std.doc \
		yorick.pdf yorick.tex

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

do-configure:
	@(cd ${CONFIGURE_WRKSRC}; ${SETENV} ${MAKE_ENV} \
		${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ysite config)

post-build:
	${MAKE} -C ${WRKSRC}/doc yorick.info

post-install:
	${INSTALL_DATA} ${WRKSRC}/emacs/yorick.el ${WRKSRC}/relocatable
	@${RM} -rf ${WRKSRC}/relocatable/doc
	@${RM} -rf ${PREFIX}/lib/${PORTNAME}
	@${MV} ${WRKSRC}/relocatable ${PREFIX}/lib/${PORTNAME}
.for f in gist yorick
	${INSTALL_MAN} ${WRKSRC}/doc/${f}.1 ${MANPREFIX}/man/man1
	@${STRIP_CMD} ${PREFIX}/lib/${PORTNAME}/bin/${f}
	@${LN} -sf ${PREFIX}/lib/${PORTNAME}/bin/${f} ${PREFIX}/bin/${f}
.endfor
	@${STRIP_CMD} ${PREFIX}/lib/${PORTNAME}/lib/codger
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${DOCSDIR}
	@${LN} -sf ${DOCSDIR} ${PREFIX}/lib/${PORTNAME}/doc
.endif
	${INSTALL_DATA} ${WRKSRC}/doc/yorick.info* ${PREFIX}/${INFO_PATH}

# Hidden by default: this requires an X terminal to run all checks
.ifdef MAINTAINER_MODE
regression-test: build
	(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} check)
.endif

.include <bsd.port.mk>
