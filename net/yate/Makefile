# Created by: Valery Komarov <komarov@valerka.net>
# $FreeBSD$

PORTNAME=	yate
DISTVERSION=	5.5.0p1
CATEGORIES=	net
MASTER_SITES=	http://yate.null.ro/tarballs/yate5/
DISTNAME=	${PORTNAME}-5.5.0-1

MAINTAINER=	koue@chaosophia.net
COMMENT=	Yet Another Telephony Engine

LICENSE=	GPLv2

LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libspeex.so:audio/speex \
		libgsm.so:audio/gsm

ONLY_FOR_ARCHS=	i386 amd64 sparc64 armv6

USES=		autoreconf bison gmake shebangfix
SHEBANG_FILES=	share/scripts/banbrutes.php \
		share/scripts/leavemail.php \
		share/scripts/queue_in.php \
		share/scripts/queue_out.php \
		share/scripts/route.php \
		share/scripts/voicemail.php
USE_LDCONFIG=	yes
WANT_GNOME=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--without-fdsize \
		--without-libqt4 \
		--with-zlib=/usr

LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include

SUB_FILES=	pkg-message
USE_RC_SUBR=	yate
USERS=		yate
GROUPS=		yate

OPTIONS_DEFINE=	AMRNB DOCS DAHDI H323 ILBC MYSQL PGSQL SCTP SPANDSP SQLITE SSL
OPTIONS_DEFAULT=SCTP

AMRNB_DESC=	Adaptive Multi-Rate Narrowband support
DAHDI_DESC=	Dahdi support
H323_DESC=	H323 software channel/protocol support
ILBC_DESC=	iLBC narrowband speech codec support
SCTP_DESC=	Stream Control Transmission Protocol support
SPANDSP_DESC=	Spandsp faxing support

OPTIONS_SUB=	yes

AMRNB_CONFIGURE_WITH=	amrnb=${LOCALBASE}
AMRNB_LIB_DEPENDS=	libamrnb.so:audio/libamrnb

DAHDI_CONFIGURE_ENABLE=	dahdi
DAHDI_BUILD_DEPENDS=	libpri>=1.4.10:misc/libpri \
			${LOCALBASE}/include/dahdi/user.h:misc/dahdi
DAHDI_LIB_DEPENDS=	libpri.so:misc/libpri \
			libopenr2.so:misc/openr2

H323_CONFIGURE_WITH=	openh323=${LOCALBASE}
H323_LIB_DEPENDS=	libopenh323.so:net/h323plus

ILBC_CONFIGURE_ENABLE=	ilbc
ILBC_LIB_DEPENDS=	libilbc.so:net/ilbc

MYSQL_CONFIGURE_WITH=	mysql
MYSQL_USE=		mysql=yes

SSL_CONFIGURE_WITH=	openssl=${OPENSSLBASE}
SSL_USES=		ssl

PGSQL_CONFIGURE_WITH=	libpq=${LOCALBASE}
PGSQL_USES=		pgsql

SCTP_CONFIGURE_ENABLE=	sctp

SPANDSP_CONFIGURE_WITH=	spandsp
SPANDSP_LIB_DEPENDS=	libspandsp.so:comms/spandsp

SQLITE_CONFIGURE_WITH=	sqlite
SQLITE_USES=		pkgconfig sqlite

post-extract:
	@${MV} ${WRKDIR}/${PORTNAME} ${WRKSRC}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/yate
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libyate*.so.5.5.0
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/yate/*.yate
.for dir in client server jabber sip
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/yate/${dir}/*.yate
.endfor

.include <bsd.port.mk>
