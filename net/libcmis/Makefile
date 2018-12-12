# $FreeBSD$

PORTNAME=	libcmis
PORTVERSION=	0.5.1
PORTREVISION=	11
CATEGORIES=	net devel
MASTER_SITES=	http://dev-www.libreoffice.org/src/

MAINTAINER=	office@FreeBSD.org
COMMENT=	Client library for the CMIS interface

LICENSE=	LGPL20 MPL11 GPLv2
LICENSE_COMB=	dual

BROKEN_sparc64=	cannot link with boost

LIB_DEPENDS=	libcurl.so:ftp/curl
BUILD_DEPENDS=	cppunit-config:devel/cppunit \
		${LOCALBASE}/lib/libboost_regex.a:devel/boost-libs

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		compiler:c++11-lib gmake libtool pathfix pkgconfig
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--disable-werror --with-boost=${LOCALBASE} --without-man
PLIST_SUB=	MAJVER=${PORTVERSION:R}

post-patch:
	@${REINPLACE_CMD} -e "s|@WITH_LIBCMIS_MAN_FALSE@|#|g" \
	    ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
