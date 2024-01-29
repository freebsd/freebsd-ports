PORTNAME=	libdca
PORTVERSION=	0.0.7
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	https://get.videolan.org/${PORTNAME}/${DISTVERSION}/ \
		https://download.videolan.org/pub/videolan/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Free DTS Coherent Acoustics decoder
WWW=		https://www.videolan.org/developers/libdca.html

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf libtool pathfix pkgconfig tar:bzip2
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
