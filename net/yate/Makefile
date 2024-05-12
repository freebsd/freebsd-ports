PORTNAME=		yate
DISTVERSION=		6.4.1
DISTVERSIONSUFFIX=	-g${GH_TAGNAME}
CATEGORIES=		net

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Yet Another Telephony Engine
WWW=		http://yate.ro

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	amd64 armv6 armv7 i386 powerpc powerpc64 powerpc64le

LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libgsm.so:audio/gsm \
		libspeex.so:audio/speex

USES=		autoreconf bison gmake shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	yatevoip
GH_TAGNAME=	e0a20c4
USE_GCC=	yes
USE_LDCONFIG=	yes
USE_RC_SUBR=	yate

SHEBANG_FILES=	share/scripts/banbrutes.php \
		share/scripts/leavemail.php \
		share/scripts/queue_in.php \
		share/scripts/queue_out.php \
		share/scripts/route.php share/scripts/tts.sh \
		share/scripts/voicemail.php

GNU_CONFIGURE=			yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

CONFIGURE_ARGS=	--with-zlib=/usr \
		--without-fdsize \
		--without-libqt4

MAKE_JOBS_UNSAFE=	yes

CXXFLAGS+=	-Wno-register

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}
SUB_FILES=	pkg-message

USERS=		yate
GROUPS=		yate

PLIST_SUB=	VERSION="${PORTVERSION}"

OPTIONS_DEFINE=		AMRNB DAHDI DOCS H323 ILBC MYSQL PGSQL SCTP SPANDSP \
			SQLITE
OPTIONS_DEFAULT=	SCTP
OPTIONS_SUB=	yes

AMRNB_DESC=	Adaptive Multi-Rate Narrowband support
DAHDI_DESC=	Dahdi support
H323_DESC=	H323 software channel/protocol support
ILBC_DESC=	iLBC narrowband speech codec support
SCTP_DESC=	Stream Control Transmission Protocol support

AMRNB_LIB_DEPENDS=	libamrnb.so:audio/libamrnb
AMRNB_CONFIGURE_WITH=	amrnb=${LOCALBASE}

DAHDI_BUILD_DEPENDS=	${LOCALBASE}/include/dahdi/user.h:misc/dahdi \
			libpri>=1.4.10:misc/libpri
DAHDI_LIB_DEPENDS=	libopenr2.so:misc/openr2 \
			libpri.so:misc/libpri
DAHDI_CONFIGURE_ENABLE=	dahdi

H323_LIB_DEPENDS=	libopenh323.so:net/h323plus \
			libpt.so:devel/ptlib
H323_CONFIGURE_WITH=	openh323=${LOCALBASE}

ILBC_LIB_DEPENDS=	libilbc.so:net/ilbc
ILBC_CONFIGURE_ENABLE=	ilbc

MYSQL_USES=		mysql ssl
MYSQL_CONFIGURE_WITH=	mysql

PGSQL_USES=		pgsql
PGSQL_CONFIGURE_WITH=	libpq=${LOCALBASE}

SCTP_CONFIGURE_ENABLE=	sctp

SPANDSP_LIB_DEPENDS=	libspandsp.so:comms/spandsp
SPANDSP_CONFIGURE_WITH=	spandsp

SQLITE_USES=		pkgconfig sqlite
SQLITE_CONFIGURE_WITH=	sqlite

_USES_configure+=	471:post-autoreconf

post-autoreconf:
	cd ${WRKSRC} && ./yate-config.sh

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/yate
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libyate*.so.*
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/yate/*.yate
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/yate/radio/*.yate
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/yate/sig/*.yate
.for dir in client server jabber sip
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/yate/${dir}/*.yate
.endfor

.include <bsd.port.mk>
