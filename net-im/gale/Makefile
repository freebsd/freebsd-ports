# Created by: Peter Haight <peterh@sapros.com>
# $FreeBSD$

PORTNAME=	gale
PORTVERSION=	0.99f
PORTREVISION=	5
CATEGORIES=	net-im
MASTER_SITES=	http://download.ofb.net/${PORTNAME}/
DISTNAME=	${PORTNAME}-${PORTVERSION}ruit

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Secure instant messaging system

LIB_DEPENDS=	libgc.so:${PORTSDIR}/devel/boehm-gc \
		libwwwcore.so:${PORTSDIR}/www/libwww \
		libadns.so:${PORTSDIR}/dns/adns

USES=		iconv libtool
GNU_CONFIGURE=	yes
USE_GNOME=	glib12
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

.include <bsd.port.mk>
