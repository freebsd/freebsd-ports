# New ports collection makefile for:	xmds
# Date created:		2006-07-17
# Whom:			EelVex
#
# $FreeBSD$
#

PORTNAME=	xmds
DISTVERSION=	1.5-2
CATEGORIES=	science
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	mplekos@physics.upatras.gr
COMMENT=	XMDS is a code generator that integrates equations;

BUILD_DEPENDS=	${LOCALBASE}/include/fftw.h:${PORTSDIR}/math/fftw

MAN1=	loadxsil.1 xmds.1 xsil2graphics.1

HAS_CONFIGURE=	YES

CONFIGURE_ARGS=	--with-fftw-path=${LOCALBASE}

.include <bsd.port.mk>
