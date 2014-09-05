# Created by: Valery Komarov <komarov@valerka.net>
# $FreeBSD$

PORTNAME=	yate
DISTVERSION=	5.4.0p1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://yate.null.ro/tarballs/yate5/
DISTNAME=	${PORTNAME}-5.4.0-1

MAINTAINER=	koue@chaosophia.net
COMMENT=	Yet Another Telephony Engine

LICENSE=	GPLv2

LIB_DEPENDS=	libasound.so:${PORTSDIR}/audio/alsa-lib \
		libspeex.so:${PORTSDIR}/audio/speex \
		libgsm.so:${PORTSDIR}/audio/gsm

ONLY_FOR_ARCHS=	i386 amd64 sparc64

USE_AUTOTOOLS=	autoconf
USES=		bison gmake
USE_LDCONFIG=	yes
WANT_GNOME=	yes

CONFIGURE_ARGS=	--without-fdsize \
		--without-libqt4 \
		--with-zlib=/usr

LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include

SUB_FILES=	pkg-message
USE_RC_SUBR=	yate
USERS=		yate
GROUPS=		yate

OPTIONS_DEFINE=	DOCS MYSQL PGSQL SCTP DAHDI ILBC AMRNB SPANDSP H323 SSL
OPTIONS_DEFAULT=SCTP

SCTP_DESC=	Stream Control Transmission Protocol support
DAHDI_DESC=	Dahdi support
ILBC_DESC=	iLBC narrowband speech codec support
AMRNB_DESC=	Adaptive Multi-Rate Narrowband support
SPANDSP_DESC=	Spandsp faxing support
H323_DESC=	H323 software channel/protocol support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
CONFIGURE_ARGS+=	--with-mysql
PLIST_SUB+=		WITH_MYSQL=""
USE_MYSQL=		yes
.else
CONFIGURE_ARGS+=	--without-mysql
PLIST_SUB+=		WITH_MYSQL="@comment "
.endif

.if ${PORT_OPTIONS:MPGSQL}
CONFIGURE_ARGS+=	--with-libpq=${LOCALBASE}
PLIST_SUB+=		WITH_PGSQL=""
USE_PGSQL=		yes
.else
CONFIGURE_ARGS+=	--without-libpq
PLIST_SUB+=		WITH_PGSQL="@comment "
.endif

.if ${PORT_OPTIONS:MSCTP}
CONFIGURE_ARGS+=	--enable-sctp
PLIST_SUB+=		WITH_SCTP=""
.else
CONFIGURE_ARGS+=	--disable-sctp
PLIST_SUB+=		WITH_SCTP="@comment "
.endif

.if ${PORT_OPTIONS:MDAHDI}
CONFIGURE_ARGS+=	--enable-dahdi
BUILD_DEPENDS+=		libpri>=1.4.10:${PORTSDIR}/misc/libpri \
			${LOCALBASE}/include/dahdi/user.h:${PORTSDIR}/misc/dahdi
LIB_DEPENDS+=		libpri.so:${PORTSDIR}/misc/libpri \
			libopenr2.so:${PORTSDIR}/misc/openr2
PLIST_SUB+=		WITH_DAHDI=""
.else
CONFIGURE_ARGS+=	--disable-dahdi
PLIST_SUB+=		WITH_DAHDI="@comment "
.endif

.if ${PORT_OPTIONS:MILBC}
LIB_DEPENDS+=	libilbc.so:${PORTSDIR}/net/ilbc
CONFIGURE_ARGS+=	--enable-ilbc
PLIST_SUB+=		WITH_ILBC=""
.else
CONFIGURE_ARGS+=	--disable-ilbc
PLIST_SUB+=		WITH_ILBC="@comment "
.endif

.if ${PORT_OPTIONS:MAMRNB}
LIB_DEPENDS+=	libamrnb.so:${PORTSDIR}/audio/libamrnb
CONFIGURE_ARGS+=	--with-amrnb=${LOCALBASE}
PLIST_SUB+=		WITH_AMRNB=""
.else
CONFIGURE_ARGS+=	--without-amrnb
PLIST_SUB+=		WITH_AMRNB="@comment "
.endif

.if ${PORT_OPTIONS:MSPANDSP}
LIB_DEPENDS+=	libspandsp.so.2.0.0:${PORTSDIR}/comms/spandsp-devel
CONFIGURE_ARGS+=	--with-spandsp
PLIST_SUB+=		WITH_SPANDSP=""
.else
CONFIGURE_ARGS+=	--without-spandsp
PLIST_SUB+=		WITH_SPANDSP="@comment "
.endif

.if ${PORT_OPTIONS:MH323}
LIB_DEPENDS+=	libopenh323.so:${PORTSDIR}/net/h323plus
CONFIGURE_ARGS+=	--with-openh323=${LOCALBASE}
PLIST_SUB+=		WITH_H323=""
.else
CONFIGURE_ARGS+=	--without-openh323
PLIST_SUB+=		WITH_H323="@comment "
.endif

.if ${PORT_OPTIONS:MSSL}
CONFIGURE_ARGS+=	--with-openssl=/usr
PLIST_SUB+=		WITH_SSL=""
.else
CONFIGURE_ARGS+=	--without-openssl
PLIST_SUB+=		WITH_SSL="@comment "
.endif

MAKE_JOBS_UNSAFE=yes

post-extract:
	@${MV} ${WRKDIR}/${PORTNAME} ${WRKSRC}

post-stage:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/yate
	@cd ${STAGEDIR}${PREFIX}/lib; \
		for FILE in *.5.4.0; do \
			${STRIP_CMD} $${FILE}; \
		done
	@cd ${STAGEDIR}${PREFIX}/lib/yate; \
		for FILE in *.yate; do \
			${STRIP_CMD} $${FILE}; \
		done
	@cd ${STAGEDIR}${PREFIX}/lib/yate/client; \
		for FILE in *.yate; do \
			${STRIP_CMD} $${FILE}; \
		done
	@cd ${STAGEDIR}${PREFIX}/lib/yate/server; \
		for FILE in *.yate; do \
			${STRIP_CMD} $${FILE}; \
		done
	@cd ${STAGEDIR}${PREFIX}/lib/yate/jabber; \
		for FILE in *.yate; do \
			${STRIP_CMD} $${FILE}; \
		done
	@cd ${STAGEDIR}${PREFIX}/lib/yate/sip; \
		for FILE in *.yate; do \
			${STRIP_CMD} $${FILE}; \
		done

.include <bsd.port.mk>
