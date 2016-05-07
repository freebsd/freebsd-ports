# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gtkada
PORTVERSION=	3.8.3.2
PORTREVISION=	2
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://downloads.dragonlace.net/src/
PKGNAMESUFFIX=	3
DISTFILES=	gtkada-for-gps-6.1.1-src.tar.gz

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Ada graphical toolkit based on Gtk3 components

LICENSE=	GPLv3

BUILD_DEPENDS=	gprbuild:devel/gprbuild

USES=		ada gmake perl5 pkgconfig
USE_PERL5=	build
USE_GNOME=	gtk30
USE_GL=		gl glu
GNU_CONFIGURE=	yes
ALL_TARGET=	tools static relocatable
NO_MTREE=	yes
WRKSRC=		${WRKDIR}/gtkada-gpl-2015-src
PORTDOCS=	gtkada_rm gtkada_ug
PORTEXAMPLES=	testgtk
RM_VERSION=	3.8.3.0
LDFLAGS=	-L${LOCALBASE}/lib

MAKE_ARGS=	PROCESSORS=${MAKE_JOBS_NUMBER}

CONFLICTS_INSTALL=	gtkada-*

CONFIGURE_ARGS+=	--with-GL=auto \
			--enable-shared \
			--enable-static

OPTIONS_DEFINE=		DOCS NLS EXAMPLES DEBUG
DOCS_BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx
DOCS_DISTFILES=		gtkada-rm-${RM_VERSION}.tar.bz2
DOCS_ALL_TARGET=	docs
NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext
EXAMPLES_ALL_TARGET=	tests

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--enable-build=Debug
.else
CONFIGURE_ARGS+=	--enable-build=Production
.endif

post-extract:
.if ${PORT_OPTIONS:MDOCS}
	${MV} ${WRKDIR}/gtkada-${RM_VERSION}/docs/* ${WRKSRC}/docs/
.endif

do-build:
#	This target is recreated because -j cannot be set, but
#	MAKE_JOBS_SAFE=yes is needed for PROCESSORS value
	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET}

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libdata
	${MV} ${STAGEDIR}${PREFIX}/lib/pkgconfig ${STAGEDIR}${PREFIX}/libdata/
	${RM} -r ${STAGEDIR}${PREFIX}/share/doc/gtkada/gtkada_ug/_sources
	${RM} ${STAGEDIR}${PREFIX}/lib/libgtkada*
	(cd ${STAGEDIR}${PREFIX}/lib && \
	  ${LN} -s gtkada/relocatable/libgtkada.so.3.8.3 libgtkada.so && \
	  ${LN} -s gtkada/relocatable/libgtkada_gl.so.3.8.3 libgtkada_gl.so)
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/gtkada/relocatable/lib*.so.3.8.3

.include <bsd.port.mk>
