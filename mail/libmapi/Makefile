# New ports collection makefile for:   libmapi
# Date created:			1 May 2009
# Whom:				Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libmapi
PORTVERSION=	0.9
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=openchange/openchange/openchange-${PORTVERSION}%20${CODENAME}/
DISTNAME=	openchange-${PORTVERSION}-${CODENAME}

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Open Source implementation of Microsoft Exchange protocols

BUILD_DEPENDS=	${HOSTCONFIG}:${PORTSDIR}/net/samba4-devel \
		pidl:${PORTSDIR}/devel/p5-Parse-Pidl
LIB_DEPENDS=	sqlite3.8:${PORTSDIR}/databases/sqlite3 \
		ical.44:${PORTSDIR}/devel/libical \
		tdb.1:${PORTSDIR}/databases/tdb \
		talloc.2:${PORTSDIR}/devel/talloc
RUN_DEPENDS=	${HOSTCONFIG}:${PORTSDIR}/net/samba4-devel

HOSTCONFIG=	${LOCALBASE}/libdata/pkgconfig/samba-hostconfig.pc

CODENAME=	COCHRANE
USE_GMAKE=	yes
USE_GNOME=	pkgconfig
USE_PYTHON=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-samba=${LOCALBASE}

OPTIONS=	BOOST "Enable libmapi++ (needs boost)" yes \
		DOXYGEN "Enble building documentation" no

.include <bsd.port.pre.mk>

CONFIGURE_ARGS+=	--disable-swig-perl
CONFIGURE_ARGS+=	--disable-pymapi

.if exists(${LOCALBASE}/lib/libboost_thread.so)
WITH_BOOST=yes
.endif

.if defined(WITH_BOOST)
LIB_DEPENDS+=	boost_thread.4:${PORTSDIR}/devel/boost-libs
PLIST_SUB+=	BOOST=""
.else
PLIST_SUB+=	BOOST="@comment "
.endif

.if defined(WITH_DOXYGEN) || exists(${LOCALBASE}/bin/doxygen)
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

.include <bsd.port.post.mk>
