# Created by: Jeremy Chadwick <koitsu@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rrdbot
PORTVERSION=	0.9.7.d20200312
CATEGORIES=	net-mgmt

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Threaded SNMP polling daemon which stores data in RRDs

LIB_DEPENDS=	librrd.so:databases/rrdtool

USES=		autoreconf

LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--libdir=${LOCALBASE}/lib --includedir=${LOCALBASE}/include \
			--datarootdir=${PREFIX}/share/rrdbot

SUB_FILES=	pkg-message
USE_RC_SUBR=	rrdbot

USE_GITHUB=	YES
GH_ACCOUNT=	REANNZ
GH_TAGNAME=	396ca60

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.include <bsd.port.mk>
