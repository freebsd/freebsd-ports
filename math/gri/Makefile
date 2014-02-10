# Created by: M. L. Dodson, <bdodson@scms.utmb.edu>
# $FreeBSD$

PORTNAME=	gri
PORTVERSION=	2.12.23
CATEGORIES=	math
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extensible plotting language for producing scientific graphs

LIB_DEPENDS=	netcdf:${PORTSDIR}/science/netcdf

USES=		readline
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-FreeBSD

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		gri.1 gri_merge.1 gri_unpage.1
INFO=		gri
PORTDOCS=	*
PORTEXAMPLES=	*
PLIST_FILES=	bin/gri bin/gri_merge bin/gri_unpage \
		share/emacs/site-lisp/gri-mode.el \
		%%DATADIR%%/gri.cmd \
		%%DATADIR%%/logo.dat \
		%%DATADIR%%/rgb.txt \
		%%DATADIR%%/startup.msg
PLIST_DIRS=	%%DATADIR%%

NO_STAGE=	yes

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
	(cd ${WRKSRC}/doc && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})
.else
	(cd ${WRKSRC}/doc && makeinfo gri.texi)
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	(cd ${WRKSRC}/doc && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})
.else
	(cd ${WRKSRC}/doc \
		&& ${INSTALL_MAN} gri-manpage.1 ${MANPREFIX}/man/man1/gri.1 \
		&& ${INSTALL_MAN} gri_merge.1-skel ${MANPREFIX}/man/man1/gri_merge.1 \
		&& ${INSTALL_MAN} gri_unpage.1-skel ${MANPREFIX}/man/man1/gri_unpage.1)
	(cd ${WRKSRC}/doc \
		&& ${INSTALL_DATA} gri.info* ${PREFIX}/${INFO_PATH})
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC}/doc/examples \
		&& ${INSTALL_DATA} model* *.dat *.gri e*.ps ${EXAMPLESDIR})
	(cd ${WRKSRC}/doc/examples \
		&& ${INSTALL_SCRIPT} FEM.pl ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
