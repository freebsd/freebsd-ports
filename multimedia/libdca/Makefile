PORTNAME=	libdca
PORTVERSION=	0.0.7
CATEGORIES=	multimedia
MASTER_SITES=	http://download.videolan.org/pub/videolan/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Free DTS Coherent Acoustics decoder
WWW=		https://www.videolan.org/developers/libdca.html

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf libtool pathfix pkgconfig tar:bzip2
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
