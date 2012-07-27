# New ports collection makefile for:	sivp
# Date created:		2007-09-15
# Whom:			Max Brazhnikov <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	sivp
DISTVERSION=	1.0.0.r286
PORTREVISION=	1
CATEGORIES=	math graphics multimedia
MASTER_SITES=	LOCAL/makc
PKGNAMEPREFIX=	scilab-toolbox-

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Scilab Image and Video Processing Toolbox

BUILD_DEPENDS=	${SCILAB_CMD}:${PORTSDIR}/math/scilab
LIB_DEPENDS=	opencv_legacy.2:${PORTSDIR}/graphics/opencv
RUN_DEPENDS=	${SCILAB_CMD}:${PORTSDIR}/math/scilab

USE_XZ=	yes

SCILAB_CMD=	${LOCALBASE}/bin/scilab
CONTRIBDIR?=	share/scilab/contrib
TOOLBOXDIR_REL?=	${CONTRIBDIR}/${PORTNAME}
TOOLBOXDIR=	${PREFIX}/${TOOLBOXDIR_REL}
PLIST_SUB=	TOOLBOXDIR=${TOOLBOXDIR_REL}
TOOLBOX_SUBDIRS=	demos etc images macros

OPTIONS_DEFINE=	HELP
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}
HELP_DESC=	Build help files (requires scilab with gui support)

.include <bsd.port.options.mk>

.if !${PORT_OPTIONS:MHELP}
SCILAB_ARGS=	-nogui
PLIST_SUB+=	HELP="@comment "
EXTRA_PATCHES+=	${FILESDIR}/extrapatch-etc__SIVP.start
.else
USE_DISPLAY=	yes
MAKE_ENV=	LC_ALL="C"
PLIST_SUB+=	HELP=""
TOOLBOX_SUBDIRS+=	jar
.endif

pre-everything::
	@${ECHO_CMD}
	@${ECHO_CMD} "If you want video support, OpenCV should be compiled with ffmpeg!"
	@${ECHO_CMD}

post-patch:
.if !${PORT_OPTIONS:MHELP}
	${REINPLACE_CMD} -e '/tbx_builder_help/d' ${WRKSRC}/builder.sce
.endif
	${ECHO_CMD} quit >> ${WRKSRC}/builder.sce

pre-build:
	${FIND} -d ${WRKSRC} \( -name '*.orig' -or -name '*.bak' \) -delete
.if ${PORT_OPTIONS:MHELP} && !defined(DISPLAY)
	@if [ -f ${WRKDIR}/.Xvfb.pid ]; then \
		${CAT} ${WRKDIR}/.Xvfb.pid | ${XARGS} kill || ${TRUE} ; \
		${RM} -f ${WRKDIR}/.Xvfb.pid ; \
	fi
	${LOCALBASE}/bin/Xvfb :1001 -screen 0 800x600x24 -fp ${LOCALBASE}/lib/X11/fonts/misc > /dev/null 2>&1 & ${ECHO} $$! > ${WRKDIR}/.Xvfb.pid
	@sleep 5
.endif

do-build:
	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${SCILAB_CMD} ${SCILAB_ARGS} -f builder.sce

post-build:
.if ${PORT_OPTIONS:MHELP} && !defined(DISPLAY)
	@if [ -f ${WRKDIR}/.Xvfb.pid ]; then \
		${CAT} ${WRKDIR}/.Xvfb.pid | ${XARGS} kill || ${TRUE} ; \
		${RM} -f ${WRKDIR}/.Xvfb.pid ; \
	fi
.endif

do-install:
	${MKDIR} ${TOOLBOXDIR}/sci_gateway/cpp
	${INSTALL_DATA} ${WRKSRC}/loader.sce ${TOOLBOXDIR}
	${INSTALL_DATA} ${WRKSRC}/sci_gateway/loader_gateway.sce \
		${TOOLBOXDIR}/sci_gateway
	cd ${WRKSRC}/sci_gateway/cpp && \
	${INSTALL_DATA} loader.sce ${TOOLBOXDIR}/sci_gateway/cpp && \
	${INSTALL_PROGRAM} libgw_sivp.so ${TOOLBOXDIR}/sci_gateway/cpp
.for d in ${TOOLBOX_SUBDIRS}
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${TOOLBOXDIR}
.endfor

.include <bsd.port.mk>
