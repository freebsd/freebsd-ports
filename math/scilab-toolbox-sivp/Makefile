# New ports collection makefile for:	sivp
# Date created:		2007-09-15
# Whom:			Max Brazhnikov <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	sivp
DISTVERSION=	0.5.2
CATEGORIES=	math graphics multimedia
MASTER_SITES=	SF/${PORTNAME}
PKGNAMEPREFIX=	scilab-toolbox-

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Scilab Image and Video Processing Toolbox

BUILD_DEPENDS=	${SCILAB_CMD}:${PORTSDIR}/math/scilab
LIB_DEPENDS=	cv.2:${PORTSDIR}/graphics/opencv
RUN_DEPENDS=	${SCILAB_CMD}:${PORTSDIR}/math/scilab

USE_ZIP=	yes

SCILAB_CMD=	${LOCALBASE}/bin/scilab
CONTRIBDIR?=	share/scilab/contrib
TOOLBOXDIR_REL?=	${CONTRIBDIR}/${PORTNAME}
TOOLBOXDIR=	${PREFIX}/${TOOLBOXDIR_REL}
PLIST_SUB=	TOOLBOXDIR=${TOOLBOXDIR_REL}

pre-everything::
	@${ECHO_CMD}
	@${ECHO_CMD} "If you want video support, OpenCV should be compiled with ffmpeg!"
	@${ECHO_CMD}

do-build:
	cd ${WRKSRC} && ${SCILAB_CMD} -nogui -f builder.sce

do-install:
	${MKDIR} ${TOOLBOXDIR}/sci_gateway/c
	${INSTALL_DATA} ${WRKSRC}/loader.sce ${TOOLBOXDIR}
	${INSTALL_DATA} ${WRKSRC}/sci_gateway/loader_gateway.sce \
		${TOOLBOXDIR}/sci_gateway
	cd ${WRKSRC}/sci_gateway/c && \
	${INSTALL_DATA} loader.sce ${TOOLBOXDIR}/sci_gateway/c && \
	${INSTALL_PROGRAM} libsivp.so ${TOOLBOXDIR}/sci_gateway/c
.for d in demos etc images jar macros
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${TOOLBOXDIR}
.endfor

.include <bsd.port.mk>
