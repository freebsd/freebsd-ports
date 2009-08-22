# New ports collection makefile for:	xmds
# Date created:		2006-07-17
# Whom:			EelVex
#
# $FreeBSD$
#

PORTNAME=	xmds
PORTVERSION=	1.6
CATEGORIES=	science
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}.5
DISTNAME=	xmds-1.6.5

MAINTAINER=	mplekos@physics.upatras.gr
COMMENT=	XMDS is a code generator that integrates equations;

MAN1=	loadxsil.1 xmds.1 xsil2graphics.1

OPTIONS=	FFTW3 "Use fftw3 instead of fftw2" Off
HAS_CONFIGURE=	YES
USE_AUTOTOOLS=	automake:16

.include <bsd.port.pre.mk>

.if defined(WITH_FFTW3)
BUILD_DEPENDS=	${LOCALBASE}/include/fftw3.h:${PORTSDIR}/math/fftw3
CONFIGURE_ARGS=	--enable-fftw3 --with-fftw3-path=${LOCALBASE}
.else
BUILD_DEPENDS=	${LOCALBASE}/include/fftw.h:${PORTSDIR}/math/fftw
CONFIGURE_ARGS=	--with-fftw-path=${LOCALBASE}
.endif

.include <bsd.port.post.mk>
