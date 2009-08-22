# New ports collection makefile for:	sivp
# Date created:		2007-09-15
# Whom:			Max Brazhnikov <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	sivp
DISTVERSION=	0.4.3
PORTREVISION=	2
CATEGORIES=	math graphics multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-src/${PORTVERSION}
PKGNAMEPREFIX=	scilab-toolbox-

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Scilab Image and Video Processing Toolbox

BUILD_DEPENDS=	${LOCALBASE}/bin/scilab:${PORTSDIR}/math/scilab \
		${LOCALBASE}/bin/xsltproc:${PORTSDIR}/textproc/libxslt
LIB_DEPENDS=	cv.1:${PORTSDIR}/graphics/opencv
RUN_DEPENDS=	${LOCALBASE}/bin/scilab:${PORTSDIR}/math/scilab

SCILABDIR?=	lib/scilab
CONTRIBDIR?=	${SCILABDIR}/contrib
TOOLBOXDIR?=	${CONTRIBDIR}/${PORTNAME}

USE_LDCONFIG=	${TOOLBOXDIR}
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=--prefix=${PREFIX}/${TOOLBOXDIR}
CONFIGURE_ENV+=	SCI="${LOCALBASE}/${SCILABDIR}"

PLIST_SUB=	TOOLBOXDIR=${TOOLBOXDIR}

pre-everything::
	@${ECHO_CMD}
	@${ECHO_CMD} "If you want video support, OpenCV should be compiled with ffmpeg!"
	@${ECHO_CMD}

.include <bsd.port.mk>
