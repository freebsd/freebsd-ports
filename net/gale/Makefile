# New ports collection makefile for:    gale
# Date created:         14 July 2000
# Whom:                 Peter Haight <peterh@sapros.com>
#
# $FreeBSD$
#

PORTNAME=	gale
PORTVERSION=	0.99f
CATEGORIES=	net
MASTER_SITES=	http://download.ofb.net/${PORTNAME}/
DISTNAME=	${PORTNAME}-${PORTVERSION}ruit

MAINTAINER=	jason-fbsd-ports-gale@shalott.net
COMMENT=	A secure instant messaging system

BUILD_DEPENDS=	${LOCALBASE}/lib/libgc.a:${PORTSDIR}/devel/boehm-gc
LIB_DEPENDS=	wwwcore.1:${PORTSDIR}/www/libwww \
		adns.1:${PORTSDIR}/dns/adns

USE_ICONV=	yes
USE_GNOME=	glib12
GNU_CONFIGURE=	yes
USE_OPENSSL=	yes
INSTALLS_SHLIB=	yes
USE_REINPLACE=	YES

CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib \
		-I${LOCALBASE}/include/w3c-libwww
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500039
CFLAGS+=	-DNEED_WCWIDTH
.endif

# cheesy hack - test-oop doesn't build, but we don't care.
pre-configure:
	${REINPLACE_CMD} -e 's/\(^noinst_PROGRAMS =.*\)test-oop/\1/' \
			${WRKSRC}/liboop/Makefile.in

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
