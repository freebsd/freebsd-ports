# Created by: Peter Haight <peterh@sapros.com>
# $FreeBSD$

PORTNAME=	gale
PORTVERSION=	0.99f
PORTREVISION=	2
CATEGORIES=	net-im
MASTER_SITES=	http://download.ofb.net/${PORTNAME}/
DISTNAME=	${PORTNAME}-${PORTVERSION}ruit

MAINTAINER=	jason-fbsd-ports-gale@shalott.net
COMMENT=	Secure instant messaging system

LIB_DEPENDS=	gc.1:${PORTSDIR}/devel/boehm-gc \
		wwwcore.1:${PORTSDIR}/www/libwww \
		adns.1:${PORTSDIR}/dns/adns

USES=		iconv
USE_GNOME=	glib12
USE_AUTOTOOLS=	libtool
LIBTOOLFILES=	configure liboop/configure
USE_OPENSSL=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes

CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib \
		-I${LOCALBASE}/include/w3c-libwww
LDFLAGS+=	-L${LOCALBASE}/lib

# cheesy hack - test-oop doesn't build, but we don't care.
pre-configure:
	${REINPLACE_CMD} -e 's/\(^noinst_PROGRAMS =.*\)test-oop/\1/' \
			${WRKSRC}/liboop/Makefile.in

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
