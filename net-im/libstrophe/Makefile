PORTNAME=	libstrophe
DISTVERSION=	0.14.0
CATEGORIES=	net-im
MASTER_SITES=	https://github.com/strophe/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Lightweight XMPP library
WWW=		https://strophe.im/libstrophe/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE.txt

USES=		gmake libtool pkgconfig ssl tar:xz
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=	--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig
PLIST_SUB=	PORTVERSION=${PORTVERSION}

OPTIONS_DEFAULT=	EXPAT
OPTIONS_SINGLE=	XML
OPTIONS_SINGLE_XML=	EXPAT LIBXML2

EXPAT_LIB_DEPENDS=	libexpat.so:textproc/expat2

LIBXML2_USE=		GNOME=libxml2
LIBXML2_USES=		gnome
LIBXML2_CONFIGURE_WITH=	libxml2

.include <bsd.port.mk>
