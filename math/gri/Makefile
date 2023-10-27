PORTNAME=	gri
PORTVERSION=	2.12.23
PORTREVISION=	13
CATEGORIES=	math
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extensible plotting language for producing scientific graphs
WWW=		https://gri.sourceforge.net/

LICENSE=	GPLv2

DEPRECATED=	Last upstream release was in 2012 and gnuplot generates better results
EXPIRATION_DATE=	2023-11-26

LIB_DEPENDS=	libnetcdf.so:science/netcdf

USES=		cpe gmake localbase:ldflags readline shebangfix makeinfo tex
CPE_VENDOR=	gri_project
USE_CXXSTD=	c++14
USE_TEX=	formats:build dvipsk:build

SHEBANG_FILES=	doc/examples/FEM.pl src/gri_merge src/gri_unpage

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-FreeBSD

INFO=		gri
PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS} || ${PORT_OPTIONS:MEXAMPLES}
USES+=		magick:6,build
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/^SUBDIRS/s|doc||' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		'/gzip/s|^|#| ; \
		 /EXAMPLES_DIR/s|^|#|' ${WRKSRC}/doc/Makefile.in

post-build:
.if ${PORT_OPTIONS:MDOCS} || ${PORT_OPTIONS:MEXAMPLES}
	(cd ${WRKSRC}/doc && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})
.else
	(cd ${WRKSRC}/doc && makeinfo gri.texi)
.endif

post-install-DOCS-on:
	(cd ${WRKSRC}/doc && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})

post-install-DOCS-off:
	${INSTALL_MAN} ${WRKSRC}/doc/gri-manpage.1 \
		${STAGEDIR}${MANPREFIX}/man/man1/gri.1
	${INSTALL_MAN} ${WRKSRC}/doc/gri_merge.1-skel \
		${STAGEDIR}${MANPREFIX}/man/man1/gri_merge.1
	${INSTALL_MAN} ${WRKSRC}/doc/gri_unpage.1-skel \
		${STAGEDIR}${MANPREFIX}/man/man1/gri_unpage.1
	${INSTALL_DATA} ${WRKSRC}/doc/gri.info* ${STAGEDIR}${PREFIX}/${INFO_PATH}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/doc/examples && ${INSTALL_DATA} model* *.dat *.gri e*.ps \
		${STAGEDIR}${EXAMPLESDIR})
	(cd ${WRKSRC}/doc/examples \
		&& ${INSTALL_SCRIPT} FEM.pl ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
