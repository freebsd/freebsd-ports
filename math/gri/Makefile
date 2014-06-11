# Created by: M. L. Dodson, <bdodson@scms.utmb.edu>
# $FreeBSD$

PORTNAME=	gri
PORTVERSION=	2.12.23
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extensible plotting language for producing scientific graphs

LIB_DEPENDS=	libnetcdf.so:${PORTSDIR}/science/netcdf

USES=		gmake readline shebangfix
SHEBANG_FILES=	src/gri_merge src/gri_unpage
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-FreeBSD

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

INFO=		gri
PORTDOCS=	*
PORTEXAMPLES=	*
PLIST_FILES=	bin/gri bin/gri_merge bin/gri_unpage \
		man/man1/gri.1.gz man/man1/gri_merge.1.gz \
		man/man1/gri_unpage.1.gz \
		share/emacs/site-lisp/gri-mode.el \
		%%DATADIR%%/gri.cmd \
		%%DATADIR%%/logo.dat \
		%%DATADIR%%/rgb.txt \
		%%DATADIR%%/startup.msg
PLIST_DIRS=	%%DATADIR%%

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS} || ${PORT_OPTIONS:MEXAMPLES}
BUILD_DEPENDS+=	convert:${PORTSDIR}/graphics/ImageMagick \
		dvips:${PORTSDIR}/print/dvipsk-tetex
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

post-install:
.if ${PORT_OPTIONS:MDOCS}
	(cd ${WRKSRC}/doc && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})
.else
	${INSTALL_MAN} ${WRKSRC}/doc/gri-manpage.1 \
		${STAGEDIR}${MANPREFIX}/man/man1/gri.1 
	${INSTALL_MAN} ${WRKSRC}/doc/gri_merge.1-skel \
		${STAGEDIR}${MANPREFIX}/man/man1/gri_merge.1
	${INSTALL_MAN} ${WRKSRC}/doc/gri_unpage.1-skel \
		${STAGEDIR}${MANPREFIX}/man/man1/gri_unpage.1
	${INSTALL_DATA} ${WRKSRC}/doc/gri.info* ${STAGEDIR}${PREFIX}/${INFO_PATH}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/doc/examples && ${INSTALL_DATA} model* *.dat *.gri e*.ps \
		${STAGEDIR}${EXAMPLESDIR})
	(cd ${WRKSRC}/doc/examples \
		&& ${INSTALL_SCRIPT} FEM.pl ${STAGEDIR}${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
