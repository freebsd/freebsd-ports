PORTNAME=	ogmtools
PORTVERSION=	1.5
PORTREVISION=	17
CATEGORIES=	multimedia audio
MASTER_SITES=	http://www.bunkus.org/videotools/ogmtools/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Tools to extract from/get info about/create OGG media streams
WWW=		https://www.bunkus.org/videotools/ogmtools/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libogg.so:audio/libogg \
		libvorbis.so:audio/libvorbis

USES=		autoreconf localbase:ldflags tar:bzip2
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DVDREAD
OPTIONS_DEFAULT=DVDREAD
OPTIONS_SUB=	yes
DVDREAD_DESC=	DVD title chapter extraction via libdvdread

DVDREAD_LIB_DEPENDS=	libdvdread.so:multimedia/libdvdread
DVDREAD_CONFIGURE_WITH=	dvdread

.include <bsd.port.mk>
