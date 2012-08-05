# New ports collection makefile for:	yate
# Date created:				2011-04-05
# Whom:					Valery Komarov <komarov@valerka.net>
#
# $FreeBSD$

PORTNAME=	yate
PORTVERSION=	4.0.0.p1
CATEGORIES=	net
MASTER_SITES=	http://yate.null.ro/tarballs/yate4/
DISTNAME=	yate-4.0.0-1

MAINTAINER=	komarov@valerka.net
COMMENT=	Yet Another Telephony Engine

LIB_DEPENDS=	gsm.1:${PORTSDIR}/audio/gsm \
		speex.1:${PORTSDIR}/audio/speex

ONLY_FOR_ARCHS=	i386 amd64 sparc64

USE_AUTOTOOLS=	autoconf
USE_GMAKE=	yes
USE_BISON=	build
USE_LDCONFIG=	yes
WANT_GNOME=	yes
GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/yate

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

OPTIONS=	MYSQL "MySQL Database support" off \
		PGSQL "PostgreSQL Database support" off \
		SCTP "Stream Control Transmission Protocol" on \
		AMR_NB "AMR Narrow Band encoder (opencore)" off \
		ILBC "Enable iLBC codec" off \
		SPANDSP "Enable Spandsp faxing support" off \
		DAHDI "Dahdi driver" off \
		H323 "H323 software channel/protocol support" off \
		SSL "Enable SSL support" off \
		ALSA "Enable ALSA channel support" off

SUB_FILES=	pkg-message
USE_RC_SUBR=	yate

USERS=	yate
GROUPS=	yate

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_MYSQL)
CONFIGURE_ARGS+=	--with-mysql
MAKE_ENV+=	WITH_MYSQL=1
PLIST_SUB+=	WITH_MYSQL=""
USE_MYSQL=	yes
.else
CONFIGURE_ARGS+=	--without-mysql
PLIST_SUB+=	WITH_MYSQL="@comment "
.endif

.if !defined(WITHOUT_PGSQL)
CONFIGURE_ARGS+=	--with-libpq=${LOCALBASE}
MAKE_ENV+=	WITH_PGSQL=1
PLIST_SUB+=	WITH_PGSQL=""
USE_PGSQL=	yes
.else
CONFIGURE_ARGS+=	--without-libpq
PLIST_SUB+=	WITH_PGSQL="@comment "
.endif

.if !defined(WITHOUT_SCTP)
CONFIGURE_ARGS+=	--enable-sctp
MAKE_ENV+=	WITH_SCTP=1
PLIST_SUB+=	WITH_SCTP=""
.else
PLIST_SUB+=	WITH_SCTP="@comment "
.endif

.if !defined(WITHOUT_AMR_NB)
LIB_DEPENDS+=	opencore-amrnb.0:${PORTSDIR}/audio/opencore-amr
CONFIGURE_ARGS+=	--with-amrnb=${LOCALBASE}
PLIST_SUB+=	WITH_AMR_NB=""
.else
CONFIGURE_ARGS+=	--without-amrnb
PLIST_SUB+=	WITH_AMR_NB="@comment "
.endif

.if !defined(WITHOUT_ILBC)
LIB_DEPENDS+=	ilbc.0:${PORTSDIR}/net/ilbc
CONFIGURE_ARGS+=	--enable-ilbc
PLIST_SUB+=	WITH_ILBC=""
.else
CONFIGURE_ARGS+=	--disable-ilbc
PLIST_SUB+=	WITH_ILBC="@comment "
.endif

.if !defined(WITHOUT_SPANDSP)
CONFIGURE_ARGS+=	--with-spandsp=${LOCALBASE}/include
LIB_DEPENDS+=	spandsp.2:${PORTSDIR}/comms/spandsp-devel
MAKE_ENV+=	WITH_SPANDSP=1
PLIST_SUB+=	WITH_SPANDSP=""
.else
CONFIGURE_ARGS+=	--without-spandsp
PLIST_SUB+=	WITH_SPANDSP="@comment "
.endif

.if !defined(WITHOUT_DAHDI)
CONFIGURE_ARGS+=	--enable-dahdi --enable-wpcard --enable-tdmcard
BUILD_DEPENDS+=	${LOCALBASE}/include/dahdi/user.h:${PORTSDIR}/misc/dahdi
MAKE_ENV+=	WITH_DAHDI=1
PLIST_SUB+=	WITH_DAHDI=""
.else
CONFIGURE_ARGS+=	--disable-dahdi
PLIST_SUB+=	WITH_DAHDI="@comment "
.endif

.if !defined(WITHOUT_H323)
CONFIGURE_ARGS+=	--with-pwlib=${LOCALBASE} \
			--with-openh323=${LOCALBASE}
LIB_DEPENDS+=	pt_r.1:${PORTSDIR}/devel/pwlib \
		h323_r.1:${PORTSDIR}/net/openh323
MAKE_ENV+=	WITH_H323=1
PLIST_SUB+=	WITH_H323=""
.else
CONFIGURE_ARGS+=	--without-openh323
PLIST_SUB+=	WITH_H323="@comment "
.endif

.if !defined(WITHOUT_SSL)
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
CONFIGURE_ARGS+=	--with-openssl=${OPENSSLBASE}
MAKE_ENV+=	WITH_SSL=1
PLIST_SUB+=	WITH_SSL=""
.else
CONFIGURE_ARGS+=	--without-openssl
PLIST_SUB+=	WITH_SSL="@comment "
.endif

.if defined(WITH_ALSA)
LIB_DEPENDS+=	asound.2:${PORTSDIR}/audio/alsa-lib
MAKE_ENV+=	WITH_ALSA=1
PLIST_SUB+=	WITH_ALSA=""
.else
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-noalsa
PLIST_SUB+=	WITH_ALSA="@comment "
.endif

.if defined(NOPORTDOCS)
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-noportdocs
.endif

post-install:
	@cd ${PREFIX}/etc/${PORTNAME}; \
	    for cfg in *.sample; do \
		test -f $${cfg%%.sample} || ${CP} -p $${cfg} $${cfg%%.sample}; \
	    done
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
