# New ports collection makefile for:   rblibtorrent
# Date created:        5 February 2006
# Whom:                Johan Ström <johan@stromnet.org>
#
# $FreeBSD$
#

PORTNAME=	libtorrent
PORTVERSION=	0.14.2
CATEGORIES=	net-p2p
MASTER_SITES=	SF
PKGNAMEPREFIX=	rb
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-rasterbar-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A C++ library implementing a BitTorrent client (devel version)

LIB_DEPENDS=	boost_date_time.4:${PORTSDIR}/devel/boost

CONFLICTS=	rblibtorrent-[0-9]*

USE_GNOME=	gnomehack
USE_OPENSSL=	yes
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--disable-debug \
		--disable-python-binding \
		--with-boost-filesystem=boost_filesystem \
		--with-boost-thread=boost_thread \
		--with-boost-regex=boost_regex \
		--with-boost-program-options=boost_program_options
USE_LDCONFIG=	yes

CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

post-patch:
	@${REINPLACE_CMD} -e '/if \[/s|==|=|g' ${WRKSRC}/configure

.include <bsd.port.mk>
