# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libmapi
PORTVERSION=	0.9
PORTREVISION=	5
CATEGORIES=	mail
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=openchange/openchange/openchange-${PORTVERSION}%20${CODENAME}/
DISTNAME=	openchange-${PORTVERSION}-${CODENAME}

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Open Source implementation of Microsoft Exchange protocols

BUILD_DEPENDS=	${HOSTCONFIG}:${PORTSDIR}/net/samba4-devel \
		pidl:${PORTSDIR}/devel/p5-Parse-Pidl
LIB_DEPENDS=	ical:${PORTSDIR}/devel/libical \
		tdb:${PORTSDIR}/databases/tdb \
		tevent:${PORTSDIR}/devel/tevent \
		talloc:${PORTSDIR}/devel/talloc
RUN_DEPENDS=	${HOSTCONFIG}:${PORTSDIR}/net/samba4-devel

HOSTCONFIG=	${LOCALBASE}/libdata/pkgconfig/samba-hostconfig.pc

CODENAME=	COCHRANE
USE_GMAKE=	yes
USE_SQLITE=	3
USE_PKGCONFIG=	build
USE_PYTHON=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-samba=${LOCALBASE}

OPTIONS_DEFINE=	BOOST DOXYGEN
OPTIONS_DEFAULT=	BOOST
BOOST_DESC=	Enable libmapi++ (needs boost)

.include <bsd.port.options.mk>

CONFIGURE_ARGS+=	--disable-swig-perl
CONFIGURE_ARGS+=	--disable-pymapi

.if ${PORT_OPTIONS:MBOOST} || exists(${LOCALBASE}/lib/libboost_thread.so)
LIB_DEPENDS+=	boost_thread:${PORTSDIR}/devel/boost-libs
PLIST_SUB+=	BOOST=""
.else
PLIST_SUB+=	BOOST="@comment "
.endif

.if ${PORT_OPTIONS:MDOXYGEN} || exists(${LOCALBASE}/bin/doxygen)
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen
PLIST_SUB+=	DOXYGEN=""
.else
PLIST_SUB+=	DOXYGEN="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile

post-install:
.for i in libmapi libmapiadmin libmapiproxy libmapiserver libmapistore libocpf
	@${LN} -fs ${PREFIX}/lib/${i}.so.0.9 ${PREFIX}/lib/${i}.so.0
.endfor

.include <bsd.port.mk>
