# $FreeBSD$

PORTNAME=	iio-oscilloscope
DISTVERSIONPREFIX=	v
DISTVERSION=	0.11
DISTVERSIONSUFFIX=	-master
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Oscilloscope application for interfacing with various IIO devices

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libad9361.so:misc/libad9361-iio \
		libcurl.so:ftp/curl \
		libfftw3.so:math/fftw3 \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libgtkdatabox.so:x11-toolkits/gtkdatabox \
		libiio.so:misc/libiio \
		libjansson.so:devel/jansson \
		libmatio.so:math/matio

USES=		cmake gnome localbase:ldflags pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	analogdevicesinc
USE_GNOME=	atk cairo gdkpixbuf2 gtk20 libxml2 pango
USE_LDCONFIG=	yes

LDFLAGS+=	-lm -lexecinfo

.include <bsd.port.mk>
