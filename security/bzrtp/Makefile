# $FreeBSD$

PORTNAME=	bzrtp
PORTVERSION=	1.0.4
CATEGORIES=	security
MASTER_SITES=	SAVANNAH/linphone/bzrtp

MAINTAINER=	tijl@FreeBSD.org
COMMENT=	ZRTP support library (RFC 6189)

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libbctoolbox.so:net/bctoolbox

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-strict
INSTALL_TARGET=	install-strip
USES=		libtool pathfix pkgconfig
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

.include <bsd.port.mk>
