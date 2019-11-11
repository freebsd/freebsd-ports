# $FreeBSD$

PORTNAME=	openhantek
DISTVERSION=	g20190903
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Digital Software Oscilloscope (DSO) software for Hantek oscilloscopes

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfftw3.so:math/fftw3

USES=		cmake compiler:c++11-lang gl localbase qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	OpenHantek
GH_TAGNAME=	e7e0c7b
USE_QT=		core gui opengl printsupport widgets buildtools_build qmake_build
USE_GL=		gl glu

PLIST_FILES=	bin/OpenHantek

post-patch:
	@${GREP} -rl "<libusb-1.0/libusb.h>" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} 's|<libusb-1.0/libusb.h>|<libusb.h>|'

.include <bsd.port.mk>
