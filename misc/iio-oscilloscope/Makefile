PORTNAME=	iio-oscilloscope
DISTVERSIONPREFIX=	v
DISTVERSION=	0.18
PORTREVISION=	1
DISTVERSIONSUFFIX=	-main
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Oscilloscope application for interfacing with various IIO devices
WWW=		https://wiki.analog.com/resources/tools-software/linux-software/iio_oscilloscope

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

USES=		cmake compiler:c11 gnome localbase:ldflags pkgconfig
USE_GNOME=	atk cairo gdkpixbuf gtk30 libxml2 pango
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	analogdevicesinc

CFLAGS+=	`pkg-config --cflags gtkdatabox` # workaround for https://github.com/analogdevicesinc/iio-oscilloscope/issues/499
LDFLAGS+=	-lm -lexecinfo

.include <bsd.port.mk>
