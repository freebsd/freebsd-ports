# New ports collection makefile for:	asterisk
# Date created:				17 October 2003
# Whom:					Maxim Sobolev <sobomax@portaone.com>
#
# $FreeBSD$
#

PORTNAME=	asterisk
PORTVERSION=	1.4.2
CATEGORIES=	net
MASTER_SITES=	http://ftp.digium.com/pub/asterisk/ \
		http://ftp.digium.com/pub/asterisk/old-releases/

MAINTAINER=	sobomax@FreeBSD.org
COMMENT=	An Open Source PBX and telephony toolkit

BUILD_DEPENDS=	mpg123:${PORTSDIR}/audio/mpg123
LIB_DEPENDS=	speex.1:${PORTSDIR}/audio/speex \
		newt.51:${PORTSDIR}/devel/newt \
		curl.4:${PORTSDIR}/ftp/curl
RUN_DEPENDS=	mpg123:${PORTSDIR}/audio/mpg123

ONLY_FOR_ARCHS=	i386 sparc64 amd64

GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --mandir=/usr/local/man
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_GMAKE=	yes
USE_BISON=	yes
USE_RC_SUBR=	asterisk.sh
MAKE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}" \
		MKDIR="${MKDIR}" \
		PWLIBDIR=${LOCALBASE}/share/pwlib \
		OPENH323DIR=${LOCALBASE}/share/openh323 \
		OSVERSION=${OSVERSION} \
		CXX="${CXX}"
MAN8=		asterisk.8 astgenkey.8 autosupport.8 safe_asterisk.8

OPTIONS=	OGGVORBIS	"Enable Ogg Vorbis support" on \
		ODBC		"Enable ODBC support" on \
		POSTGRES	"Enable PostgreSQL support" on \
		RADIUS		"Enable RADIUS accounting support" on \
		SNMP		"Enable SNMP support" on

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
OPTIONS+=	H323		"Enable H.323 support" on \
		ZAPTEL		"Enable Zaptel support" on
.endif

.if defined(WITHOUT_H323)
PLIST_SUB+=	WITH_H323="@comment "
CONFIGURE_ARGS+= --without-h323
.else
PLIST_SUB+=	WITH_H323=""
CONFIGURE_ARGS+= --with-h323
LIB_DEPENDS+=	pt_r.1:${PORTSDIR}/devel/pwlib \
		h323_r.1:${PORTSDIR}/net/openh323
.endif

.if defined(WITHOUT_ZAPTEL)
PLIST_SUB+=	WITH_ZAPTEL="@comment "
CONFIGURE_ARGS+= --without-zaptel
.else
PLIST_SUB+=	WITH_ZAPTEL=""
CONFIGURE_ARGS+= --with-zaptel
BUILD_DEPENDS+=	libpri>=1.2.0:${PORTSDIR}/misc/libpri \
		${LOCALBASE}/include/zaptel.h:${PORTSDIR}/misc/zaptel
LIB_DEPENDS+=	pri.1:${PORTSDIR}/misc/libpri
RUN_DEPENDS+=	${LOCALBASE}/include/zaptel.h:${PORTSDIR}/misc/zaptel
.endif

#
# WITH_FREETDS, WITH_PGSQL and WITH_SQLITE can also be added to MAKE_ENV
# similarly
.if defined(WITHOUT_ODBC)
PLIST_SUB+=	WITH_ODBC="@comment "
CONFIGURE_ARGS+= --without-odbc
.else
PLIST_SUB+=	WITH_ODBC=""
CONFIGURE_ARGS+= --with-odbc
LIB_DEPENDS+=	odbc.1:${PORTSDIR}/databases/unixODBC
.endif

.if defined(WITHOUT_POSTGRES)
PLIST_SUB+=	WITH_POSTGRES="@comment "
CONFIGURE_ARGS+= --without-postgres
.else
PLIST_SUB+=	WITH_POSTGRES=""
USE_PGSQL=	yes
CONFIGURE_ARGS+= --with-postgres
.endif

.if defined(WITHOUT_OGGVORBIS)
PLIST_SUB+=	WITH_OGGVORBIS="@comment "
CONFIGURE_ARGS+= --without-ogg
.else
PLIST_SUB+=	WITH_OGGVORBIS=""
CONFIGURE_ARGS+= --with-ogg
LIB_DEPENDS+=	vorbis.3:${PORTSDIR}/audio/libvorbis
.endif

.if defined(WITHOUT_RADIUS)
PLIST_SUB+=	WITH_RADIUS="@comment "
CONFIGURE_ARGS+= --without-radius
.else
PLIST_SUB+=	WITH_RADIUS=""
CONFIGURE_ARGS+= --with-radius
LIB_DEPENDS+=	radiusclient-ng.2:${PORTSDIR}/net/radiusclient
.endif

.if defined(WITHOUT_SNMP)
PLIST_SUB+=	WITH_SNMP="@comment "
CONFIGURE_ARGS+= --without-netsnmp
.else
PLIST_SUB+=	WITH_SNMP=""
CONFIGURE_ARGS+= --with-netsnmp
LIB_DEPENDS+=	netsnmp.10:${PORTSDIR}/net-mgmt/net-snmp
.endif

post-patch:
	${REINPLACE_CMD} -e 's|/var/lib|${PREFIX}/share|g' ${WRKSRC}/configs/musiconhold.conf.sample

.include <bsd.port.post.mk>
