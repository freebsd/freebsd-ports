# $FreeBSD$

PORTNAME=	SoapyRTLSDR
DISTVERSIONPREFIX=	soapy-rtlsdr-
DISTVERSION=	0.3.0
PORTREVISION=	1
CATEGORIES=	misc hamradio

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Soapy SDR module for RTLSDR

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libSoapySDR.so:misc/soapysdr \
		librtlsdr.so:comms/rtl-sdr

USES=		cmake compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	pothosware

PLIST_FILES=	lib/SoapySDR/modules0.7/librtlsdrSupport.so

.include <bsd.port.mk>
