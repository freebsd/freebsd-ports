# New ports collection makefile for:   rblibtorrent
# Date created:        5 February 2006
# Whom:                Johan Ström <johan@stromnet.org>
#
# $FreeBSD$
#

PORTNAME=	libtorrent
PORTVERSION=	0.14.6
CATEGORIES=	net-p2p
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
PKGNAMEPREFIX=	rb
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-rasterbar-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A C++ library implementing a BitTorrent client (devel version)

LIB_DEPENDS=	boost_date_time.4:${PORTSDIR}/devel/boost-libs

CONFLICTS=	rblibtorrent-[0-9]*

USE_GNOME=	gnomehack
USE_OPENSSL=	yes
USE_AUTOTOOLS=	aclocal:110 automake:110 autoconf:262 libtool:22
ACLOCAL_ARGS=	-I m4
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--disable-debug \
		--disable-python-binding \
		--with-boost-filesystem=boost_filesystem \
		--with-boost-thread=boost_thread \
		--with-boost-regex=boost_regex \
		--with-boost-program-options=boost_program_options \
		--with-asio=shipped \
		--with-zlib=system
USE_LDCONFIG=	yes

CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

post-patch:
	@${REINPLACE_CMD} -e 's|libdir)/pkgconfig|prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile.am
	@${REINPLACE_CMD} -e 's|^AM_CFLAGS|AM_CPPFLAGS|g ; \
		 s|@BOOST_SYSTEM_LIB@||g' ${WRKSRC}/src/Makefile.am

.include <bsd.port.mk>
