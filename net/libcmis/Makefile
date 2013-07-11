# $FreeBSD$

PORTNAME=	libcmis
PORTVERSION=	0.3.1
PORTREVISION=	1
CATEGORIES=	net devel
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Client library for the CMIS interface

LICENSE=	LGPL20 MPL GPLv2
LICENSE_COMB=	dual

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl
BUILD_DEPENDS=	${LOCALBASE}/lib/libcppunit.so:${PORTSDIR}/devel/cppunit \
		${LOCALBASE}/lib/libboost_regex.a:${PORTSDIR}/devel/boost-libs

GNU_CONFIGURE=	yes
USES=		pathfix pkgconfig
USE_GNOME=	libxml2
USE_GMAKE=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

CONFIGURE_ARGS=	--disable-werror --with-boost=${LOCALBASE} --without-man

post-patch:
	@${REINPLACE_CMD} -e "s|@WITH_LIBCMIS_MAN_FALSE@|#|g" \
	    ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
