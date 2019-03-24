# $FreeBSD$

PORTNAME=	libcmis
PORTVERSION=	0.5.1
PORTREVISION=	11
CATEGORIES=	net devel
MASTER_SITES=	https://dev-www.libreoffice.org/src/

MAINTAINER=	office@FreeBSD.org
COMMENT=	Client library for the CMIS interface

LICENSE=	LGPL20 MPL11 GPLv2
LICENSE_COMB=	dual

BROKEN_sparc64=	cannot link with boost

BUILD_DEPENDS=	cppunit-config:devel/cppunit \
		${LOCALBASE}/lib/libboost_regex.a:devel/boost-libs
LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		compiler:c++11-lib gmake libtool pathfix pkgconfig
USE_GNOME=	libxml2

CONFIGURE_ARGS=	--disable-werror --with-boost=${LOCALBASE} --without-man
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

PLIST_SUB=	MAJVER=${PORTVERSION:R}

post-patch:
	@${REINPLACE_CMD} -e "s|@WITH_LIBCMIS_MAN_FALSE@|#|g" \
	    ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
