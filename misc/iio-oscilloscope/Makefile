PORTNAME=	iio-oscilloscope
DISTVERSIONPREFIX=	v
DISTVERSION=	0.14
DISTVERSIONSUFFIX=	-master
PORTREVISION=	4
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Oscilloscope application for interfacing with various IIO devices
WWW=		https://wiki.analog.com/resources/tools-software/linux-software/iio_oscilloscope

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN=		uses depracated GTK functions, see https://github.com/analogdevicesinc/iio-oscilloscope/issues/441

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
USE_GNOME=	atk cairo gdkpixbuf2 gtk20 libxml2 pango
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	analogdevicesinc

LDFLAGS+=	-lm -lexecinfo

.include <bsd.port.mk>
