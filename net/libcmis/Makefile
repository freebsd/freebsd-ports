PORTNAME=	libcmis
PORTVERSION=	0.6.2
PORTREVISION=	6
CATEGORIES=	net devel
MASTER_SITES=	https://github.com/tdf/libcmis/releases/download/v${PORTVERSION}/ \
		https://dev-www.libreoffice.org/src/

MAINTAINER=	office@FreeBSD.org
COMMENT=	Client library for the CMIS interface
WWW=		https://github.com/tdf/libcmis

LICENSE=	LGPL20 MPL11 GPLv2
LICENSE_COMB=	dual

BUILD_DEPENDS=	cppunit-config:devel/cppunit \
		${LOCALBASE}/lib/libboost_regex.a:devel/boost-libs
LIB_DEPENDS=	libboost_program_options.so:devel/boost-libs \
		libcurl.so:ftp/curl

USES=		compiler:c++11-lib gmake gnome libtool localbase pathfix \
		pkgconfig tar:xz
USE_GNOME=	libxml2

CONFIGURE_ARGS=	--disable-werror --with-boost=${LOCALBASE} --without-man
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

PLIST_SUB=	MAJVER=${PORTVERSION:R} SHLIBVER=${PORTVERSION:R:E}

post-patch:
	@${REINPLACE_CMD} -e "s|@WITH_LIBCMIS_MAN_FALSE@|#|g" \
	    ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
