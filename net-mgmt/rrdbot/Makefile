PORTNAME=	rrdbot
PORTVERSION=	0.9.7.d20200312
PORTREVISION=	2
CATEGORIES=	net-mgmt

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Threaded SNMP polling daemon which stores data in RRDs
WWW=		https://github.com/REANNZ/rrdbot/

LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	librrd.so:databases/rrdtool

USES=		autoreconf
USE_GITHUB=	YES
GH_ACCOUNT=	REANNZ
GH_TAGNAME=	396ca60
USE_RC_SUBR=	rrdbot

GNU_CONFIGURE=			yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=			--datarootdir=${PREFIX}/share/rrdbot \
				--includedir=${LOCALBASE}/include \
				--libdir=${LOCALBASE}/lib

SUB_FILES=	pkg-message

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.include <bsd.port.mk>
