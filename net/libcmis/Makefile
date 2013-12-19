# $FreeBSD$

PORTNAME=	libcmis
PORTVERSION=	0.4.1
CATEGORIES=	net devel
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Client library for the CMIS interface

LICENSE=	LGPL20 MPL GPLv2
LICENSE_COMB=	dual

LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl
BUILD_DEPENDS=	${LOCALBASE}/lib/libcppunit.so:${PORTSDIR}/devel/cppunit \
		${LOCALBASE}/lib/libboost_regex.a:${PORTSDIR}/devel/boost-libs

GNU_CONFIGURE=	yes
USE_GNOME=	libxml2
USE_LDCONFIG=	yes
USES=		gmake pathfix pkgconfig

CONFIGURE_ARGS=	--disable-werror --with-boost=${LOCALBASE} --without-man
PLIST_SUB=	MAJVER=${PORTVERSION:R}

post-patch:
	@${REINPLACE_CMD} -e "s|@WITH_LIBCMIS_MAN_FALSE@|#|g" \
	    ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
