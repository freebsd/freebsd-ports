# $FreeBSD$

PORTNAME=	sivp
DISTVERSION=	1.0.0.r286
PORTREVISION=	8
CATEGORIES=	math graphics multimedia
MASTER_SITES=	LOCAL/makc
PKGNAMEPREFIX=	scilab-toolbox-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Scilab Image and Video Processing Toolbox

BUILD_DEPENDS=	${SCILAB_CMD}:math/scilab
LIB_DEPENDS=	libopencv_legacy.so:graphics/opencv2
RUN_DEPENDS=	${SCILAB_CMD}:math/scilab

USES=		dos2unix pkgconfig tar:xz
DOS2UNIX_FILES=	etc/SIVP.start \
		sci_gateway/cpp/builder_gateway_cpp.sce \
		sci_gateway/cpp/sivp_init.cpp

SCILAB_CMD=	${LOCALBASE}/bin/scilab-adv-cli
SCILAB_ARGS=	-noatomsautoload -nb -nouserstartup
MAKE_ENV=	LC_ALL="C" SCI_JAVA_ENABLE_HEADLESS=1 SCI_DISABLE_TK=1

CONTRIBDIR?=	share/scilab/contrib
TOOLBOXDIR_REL?=	${CONTRIBDIR}/${PORTNAME}
TOOLBOXDIR=	${PREFIX}/${TOOLBOXDIR_REL}
PLIST_SUB=	TOOLBOXDIR=${TOOLBOXDIR_REL}
TOOLBOX_SUBDIRS=	demos etc images macros

OPTIONS_DEFINE=	HELP
OPTIONS_DEFAULT=	HELP
OPTIONS_SUB=	yes
HELP_DESC=	Build help files (requires scilab with gui support)

.include <bsd.port.options.mk>

.if !${PORT_OPTIONS:MHELP}
SCILAB_ARGS+=	-nwni
EXTRA_PATCHES+=	${FILESDIR}/extrapatch-etc__SIVP.start
.else
TOOLBOX_SUBDIRS+=	jar
.endif

pre-everything::
	@${CAT} ${PKGMESSAGE}

post-patch:
.if !${PORT_OPTIONS:MHELP}
	${REINPLACE_CMD} -e '/tbx_builder_help/d' ${WRKSRC}/builder.sce
.endif
	${ECHO_CMD} quit >> ${WRKSRC}/builder.sce

pre-build:
	${FIND} -d ${WRKSRC} \( -name '*.orig' -or -name '*.bak' \) -delete

do-build:
	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${SCILAB_CMD} ${SCILAB_ARGS} -f builder.sce

do-install:
	${MKDIR} ${STAGEDIR}${TOOLBOXDIR}/sci_gateway/cpp
	${INSTALL_DATA} ${WRKSRC}/loader.sce ${STAGEDIR}${TOOLBOXDIR}
	${INSTALL_DATA} ${WRKSRC}/sci_gateway/loader_gateway.sce \
		${STAGEDIR}${TOOLBOXDIR}/sci_gateway
	cd ${WRKSRC}/sci_gateway/cpp && \
	${INSTALL_DATA} loader.sce ${STAGEDIR}${TOOLBOXDIR}/sci_gateway/cpp && \
	${INSTALL_PROGRAM} libgw_sivp.so ${STAGEDIR}${TOOLBOXDIR}/sci_gateway/cpp
.for d in ${TOOLBOX_SUBDIRS}
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${STAGEDIR}${TOOLBOXDIR}
.endfor

.include <bsd.port.mk>
