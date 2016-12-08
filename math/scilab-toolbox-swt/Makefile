# $FreeBSD$

PORTNAME=	swt
PORTVERSION=	0.1.20
PORTREVISION=	3
CATEGORIES=	math
MASTER_SITES=	http://atoms.scilab.org/toolboxes/swt/${PORTVERSION}/files/
PKGNAMEPREFIX=	scilab-toolbox-
DISTFILES=	${DISTNAME}-3-src${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Scilab 1-D and 2-D Wavelet Toolbox

BUILD_DEPENDS=	${SCILAB_CMD}:math/scilab
RUN_DEPENDS:=	${BUILD_DEPENDS}

SCILAB_CMD=	${LOCALBASE}/bin/scilab-adv-cli
SCILAB_ARGS=	-noatomsautoload -nb -nouserstartup
MAKE_ENV=	LC_ALL="C" SCI_JAVA_ENABLE_HEADLESS=1 SCI_DISABLE_TK=1

CONTRIBDIR?=	share/scilab/contrib
TOOLBOXDIR_REL?=	${CONTRIBDIR}/${PORTNAME}
TOOLBOXDIR=	${PREFIX}/${TOOLBOXDIR_REL}
PLIST_SUB=	TOOLBOXDIR=${TOOLBOXDIR_REL}
TOOLBOX_SUBDIRS=	demos etc macros

OPTIONS_DEFINE=	HELP SIVP
OPTIONS_DEFAULT=	HELP
OPTIONS_SUB=	yes

HELP_DESC=	Build help files (requires scilab with gui support)
SIVP_DESC=	Enable Image and Video support
SIVP_RUN_DEPENDS=	${LOCALBASE}/${CONTRIBDIR}/sivp/loader.sce:math/scilab-toolbox-sivp

WRKSRC=		${WRKDIR}/swt

.include <bsd.port.options.mk>

.if !${PORT_OPTIONS:MHELP}
SCILAB_ARGS+=	-nwni
EXTRA_PATCHES+=	${FILESDIR}/extrapatch-etc__swt.start
.else
TOOLBOX_SUBDIRS+=	jar
.endif

post-patch:
.if !${PORT_OPTIONS:MHELP}
	${REINPLACE_CMD} -e '/tbx_builder_help/d' ${WRKSRC}/builder.sce
.endif
	${REINPLACE_CMD} -e '/#include <malloc.h>/d' \
		${WRKSRC}/sci_gateway/c/kiss_fft.h
	${ECHO_CMD} quit >> ${WRKSRC}/builder.sce

pre-build:
	${FIND} -d ${WRKSRC} \( -name '*.orig' -or -name '*.bak' \) -delete

do-build:
	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${SCILAB_CMD} ${SCILAB_ARGS} -f builder.sce

do-install:
	${MKDIR} ${STAGEDIR}${TOOLBOXDIR}/sci_gateway/c
	${INSTALL_DATA} ${WRKSRC}/loader.sce ${STAGEDIR}${TOOLBOXDIR}
	${INSTALL_DATA} ${WRKSRC}/sci_gateway/loader_gateway.sce \
		${STAGEDIR}${TOOLBOXDIR}/sci_gateway
	cd ${WRKSRC}/sci_gateway/c && \
	${INSTALL_DATA} loader.sce ${STAGEDIR}${TOOLBOXDIR}/sci_gateway/c && \
	${INSTALL_PROGRAM} libswt_c.so ${STAGEDIR}${TOOLBOXDIR}/sci_gateway/c
.for d in ${TOOLBOX_SUBDIRS}
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${STAGEDIR}${TOOLBOXDIR}
.endfor

.include <bsd.port.mk>
