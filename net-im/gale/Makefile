# Created by: Peter Haight <peterh@sapros.com>
# $FreeBSD$

PORTNAME=	gale
PORTVERSION=	0.99f
PORTREVISION=	8
CATEGORIES=	net-im
MASTER_SITES=	http://download.ofb.net/${PORTNAME}/
DISTNAME=	${PORTNAME}-${PORTVERSION}ruit

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Secure instant messaging system

LIB_DEPENDS=	libgc.so:devel/boehm-gc \
		libwwwcore.so:www/libwww \
		libadns.so:dns/adns

BROKEN_aarch64=		fails to compile: conflicting types for __wcwidth
BROKEN_armv6=		fails to compile: conflicting types for __wcwidth
BROKEN_armv7=		fails to compile: conflicting types for __wcwidth

USES=		iconv libtool ncurses ssl
GNU_CONFIGURE=	yes
USE_GNOME=	glib12
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include \
		-I${LOCALBASE}/include/w3c-libwww
LIBS+=		-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} 's/-liconv/${ICONV_LIB}/' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's/\(^noinst_PROGRAMS =.*\)test-oop/\1/' \
		${WRKSRC}/liboop/Makefile.in

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so

.include <bsd.port.mk>
