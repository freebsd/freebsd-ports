# $FreeBSD$

PORTNAME=	libcmis
PORTVERSION=	0.3.0
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
USE_GNOME=	libxml2 gnomehack
USE_GMAKE=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

CXXFLAGS+=	-std=c++98
CONFIGURE_ARGS+=	--without-man \
			--with-boost=${LOCALBASE} \
			--disable-werror

.include <bsd.port.pre.mk>

.if exists(/usr/bin/clang) && ${OSVERSION} >= 900014
CC=	/usr/bin/clang
CPP=	/usr/bin/clang-cpp
CXX=	/usr/bin/clang++
CONFIGURE_ENV+=	CXXCPP="${CPP}"
.else
BUILD_DEPENDS+=	clang-devel>=3.2.r159895:${PORTSDIR}/lang/clang-devel
USE_BINUTILS=	yes
CC=	${LOCALBASE}/bin/clang
CPP=	${CC} -E
CXX=	${LOCALBASE}/bin/clang++
CONFIGURE_ENV+=        CXXCPP="${CXX} -E"
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|@WITH_LIBCMIS_MAN_FALSE@|#|g" ${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>
