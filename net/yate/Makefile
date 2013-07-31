# Created by: Valery Komarov <komarov@valerka.net>
# $FreeBSD$

PORTNAME=	yate
PORTVERSION=	4.3.0.p1	# XXX: please use DISTVERSION next time
CATEGORIES=	net
MASTER_SITES=	http://yate.null.ro/tarballs/yate4/
DISTNAME=	${PORTNAME}-4.3.0-1

MAINTAINER=	komarov@valerka.net
COMMENT=	Yet Another Telephony Engine

LIB_DEPENDS=	libgsm.so:${PORTSDIR}/audio/gsm \
		libspeex.so:${PORTSDIR}/audio/speex

ONLY_FOR_ARCHS=	i386 amd64 sparc64

USE_AUTOTOOLS=	autoconf
USES=		bison gmake
USE_LDCONFIG=	yes
WANT_GNOME=	yes

CONFIGURE_ARGS=	--without-fdsize \
		--without-libqt4 \
		--with-zlib=/usr

LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include

MAKE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}" \
		PWLIBDIR=${LOCALBASE}/share/pwlib \
		OPENH323DIR=${LOCALBASE}/share/openh323 \
		OSVERSION=${OSVERSION}

MAN8=		yate-config.8 yate.8

SUB_FILES=	pkg-message
USE_RC_SUBR=	yate
USERS=		yate
GROUPS=		yate

OPTIONS_DEFINE=	MYSQL PGSQL SCTP AMR_NB ILBC SPANDSP DAHDI H323 SSL ALSA DOCS
OPTIONS_DEFAULT=	SCTP

SCTP_DESC=	Stream Control Transmission Protocol support
ILBC_DESC=	iLBC narrowband speech codec support
SPANDSP_DESC=	Spandsp faxing support
DAHDI_DESC=	Dahdi driver
H323_DESC=	H323 software channel/protocol support

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MMYSQL}
CONFIGURE_ARGS+=	--with-mysql
MAKE_ENV+=	WITH_MYSQL=1
PLIST_SUB+=	WITH_MYSQL=""
USE_MYSQL=	yes
.else
CONFIGURE_ARGS+=	--without-mysql
PLIST_SUB+=	WITH_MYSQL="@comment "
.endif

.if ${PORT_OPTIONS:MPGSQL}
CONFIGURE_ARGS+=	--with-libpq=${LOCALBASE}
MAKE_ENV+=	WITH_PGSQL=1
PLIST_SUB+=	WITH_PGSQL=""
USE_PGSQL=	yes
.else
CONFIGURE_ARGS+=	--without-libpq
PLIST_SUB+=	WITH_PGSQL="@comment "
.endif

.if ${PORT_OPTIONS:MSCTP}
CONFIGURE_ARGS+=	--enable-sctp
MAKE_ENV+=	WITH_SCTP=1
PLIST_SUB+=	WITH_SCTP=""
.else
PLIST_SUB+=	WITH_SCTP="@comment "
.endif

.if ${PORT_OPTIONS:MAMR_NB}
LIB_DEPENDS=	libopencore-amrnb.so:${PORTSDIR}/audio/opencore-amr
CONFIGURE_ARGS+=	--with-amrnb=${LOCALBASE}
PLIST_SUB+=	WITH_AMR_NB=""
.else
CONFIGURE_ARGS+=	--without-amrnb
PLIST_SUB+=	WITH_AMR_NB="@comment "
.endif

.if ${PORT_OPTIONS:MILBC}
LIB_DEPENDS+=	libilbc.so:${PORTSDIR}/net/ilbc
CONFIGURE_ARGS+=	--enable-ilbc
PLIST_SUB+=	WITH_ILBC=""
.else
CONFIGURE_ARGS+=	--disable-ilbc
PLIST_SUB+=	WITH_ILBC="@comment "
.endif

.if ${PORT_OPTIONS:MSPANDSP}
CONFIGURE_ARGS+=	--with-spandsp=${LOCALBASE}/include
LIB_DEPENDS+=	libspandsp.so:${PORTSDIR}/comms/spandsp-devel
MAKE_ENV+=	WITH_SPANDSP=1
PLIST_SUB+=	WITH_SPANDSP=""
.else
CONFIGURE_ARGS+=	--without-spandsp
PLIST_SUB+=	WITH_SPANDSP="@comment "
.endif

.if ${PORT_OPTIONS:MDAHDI}
CONFIGURE_ARGS+=	--enable-dahdi --enable-wpcard --enable-tdmcard
BUILD_DEPENDS+=	${LOCALBASE}/include/dahdi/user.h:${PORTSDIR}/misc/dahdi
MAKE_ENV+=	WITH_DAHDI=1
PLIST_SUB+=	WITH_DAHDI=""
.else
CONFIGURE_ARGS+=	--disable-dahdi
PLIST_SUB+=	WITH_DAHDI="@comment "
.endif

.if ${PORT_OPTIONS:MH323}
CONFIGURE_ARGS+=	--with-pwlib=${LOCALBASE} \
			--with-openh323=${LOCALBASE}
LIB_DEPENDS+=	libpt_r.so:${PORTSDIR}/devel/pwlib \
		libh323_r.so:${PORTSDIR}/net/openh323
MAKE_ENV+=	WITH_H323=1
PLIST_SUB+=	WITH_H323=""
.else
CONFIGURE_ARGS+=	--without-openh323
PLIST_SUB+=	WITH_H323="@comment "
.endif

.if ${PORT_OPTIONS:MSSL}
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
CONFIGURE_ARGS+=	--with-openssl=${OPENSSLBASE}
MAKE_ENV+=	WITH_SSL=1
PLIST_SUB+=	WITH_SSL=""
.else
CONFIGURE_ARGS+=	--without-openssl
PLIST_SUB+=	WITH_SSL="@comment "
.endif

.if ${PORT_OPTIONS:MALSA}
LIB_DEPENDS+=	libasound.so:${PORTSDIR}/audio/alsa-lib
MAKE_ENV+=	WITH_ALSA=1
PLIST_SUB+=	WITH_ALSA=""
.else
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-noalsa
PLIST_SUB+=	WITH_ALSA="@comment "
.endif

.if ! ${PORT_OPTIONS:MDOCS}
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-noportdocs
.endif

post-extract:
	@${MV} ${WRKDIR}/${PORTNAME} ${WRKSRC}

post-install:
	@cd ${PREFIX}/etc/${PORTNAME}; \
	    for cfg in *.sample; do \
		test -f $${cfg%%.sample} || ${CP} -p $${cfg} $${cfg%%.sample}; \
	    done
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.post.mk>
