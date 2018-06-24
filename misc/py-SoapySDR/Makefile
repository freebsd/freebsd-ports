# $FreeBSD$

PORTNAME=	SoapySDR
DISTVERSIONPREFIX=	soapy-sdr-
DISTVERSION=	0.6.1-71
DISTVERSIONSUFFIX=	-g69c16e9
CATEGORIES=	misc hamradio python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Vendor and platform neutral SDR support library (python binding)

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/../LICENSE_1_0.txt

BROKEN_i386=	error: redefinition of 'swig::traits<unsigned int>', pending fix of https://github.com/pothosware/SoapySDR/issues/169

BUILD_DEPENDS=	swig3.0:devel/swig30
LIB_DEPENDS=	libSoapySDR.so:misc/soapysdr

USES=		cmake:outsource python
USE_GITHUB=	yes
GH_ACCOUNT=	pothosware
USE_PYTHON=	flavors

CMAKE_ARGS=	-DFREEBSD_PYTHON_VERSION:INTEGER=${PYTHON_VER:S/.//} \
		-DFREEBSD_PYTHON_VER2:STRING=${PYTHON_VER}
CMAKE_OFF=	ENABLE_DOCS

WRKSRC_SUBDIR=	python${PYTHON_VER:R:R:S/2//} # WARNING There are handcrafted paths in patches with '../' added to match this WRKSRC_SUBDIR for all python flavors

PLIST_FILES=	${PYTHON_SITELIBDIR}/SoapySDR.py \
		${PYTHON_SITELIBDIR}/_SoapySDR.so

.include <bsd.port.mk>
