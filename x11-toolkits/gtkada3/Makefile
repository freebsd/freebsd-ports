# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gtkada
PORTVERSION=	3.8.3.1
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://downloads.dragonlace.net/src/
PKGNAMESUFFIX=	3
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		gtkada-rm-${RM_VERSION}${EXTRACT_SUFX}

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Ada graphical toolkit based on Gtk3 components

LICENSE=	GPLv3

USES=		ada gmake perl5 pkgconfig tar:bzip2
USE_PERL5=	build
USE_GNOME=	gtk30
USE_GL=		gl glu
GNU_CONFIGURE=	yes
ALL_TARGET=	src
NO_MTREE=	yes
PORTDOCS=	gtkada_rm gtkada_ug
PORTEXAMPLES=	testgtk
RM_VERSION=	3.8.3.0

MAKE_ARGS+=	PROCESSORS=${MAKE_JOBS_NUMBER} \
		GL_SUPPORT=yes

CONFLICTS_INSTALL=	gtkada-*

CONFIGURE_ARGS+=	--with-GL=auto \
			--disable-gtkextra

OPTIONS_DEFINE=		DOCS NLS EXAMPLES DEBUG

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	sphinx-build:${PORTSDIR}/textproc/py-sphinx
.endif

.if ${PORT_OPTIONS:MNLS}
CONFIGURE_ARGS+=	--enable-nls
USES+=			gettext
.else
CONFIGURE_ARGS+=	--disable-nls
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--enable-build=Debug
.else
CONFIGURE_ARGS+=	--enable-build=Production
.endif

.if ${PORT_OPTIONS:MDOCS}
ALL_TARGET+= docs
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
ALL_TARGET+= tests
.endif

post-extract:
.if ${PORTVERSION} != ${RM_VERSION}
	${MV} ${WRKDIR}/gtkada-${RM_VERSION}/docs/* ${WRKSRC}/docs/
.endif

do-build:
#	This target is recreated because -j cannot be set, but
#	MAKE_JOBS_SAFE=yes is needed for PROCESSORS value
	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET}

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libdata
	@${MV} ${STAGEDIR}${PREFIX}/lib/pkgconfig ${STAGEDIR}${PREFIX}/libdata/
	${RM} -rf ${STAGEDIR}${PREFIX}/share/doc/gtkada/gtkada_ug/_sources

.include <bsd.port.mk>
