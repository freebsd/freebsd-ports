# Created by: EelVex
# $FreeBSD$

PORTNAME=	xmds
PORTVERSION=	1.6
CATEGORIES=	science
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}.5
DISTNAME=	xmds-1.6.5

MAINTAINER=	mplekos@physics.upatras.gr
COMMENT=	XMDS is a code generator that integrates equations;

MAN1=	loadxsil.1 xmds.1 xsil2graphics.1

OPTIONS_DEFINE=	FFTW3
FFTW3_DESC=	Use fftw3 instead of fftw2

GNU_CONFIGURE=	yes

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFFTW3}
BUILD_DEPENDS=	${LOCALBASE}/include/fftw3.h:${PORTSDIR}/math/fftw3
CONFIGURE_ARGS=	--enable-fftw3 --with-fftw3-path=${LOCALBASE}
.else
BUILD_DEPENDS=	${LOCALBASE}/include/fftw.h:${PORTSDIR}/math/fftw
CONFIGURE_ARGS=	--with-fftw-path=${LOCALBASE}
.endif

.include <bsd.port.mk>
