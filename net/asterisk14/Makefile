# New ports collection makefile for:	asterisk
# Date created:				17 October 2003
# Whom:					Maxim Sobolev <sobomax@portaone.com>
#
# $FreeBSD$
#

PORTNAME=	asterisk
PORTVERSION=	1.4.24.1
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://downloads.asterisk.org/pub/telephony/asterisk/ \
		http://downloads.asterisk.org/pub/telephony/asterisk/old-releases/

MAINTAINER=	sobomax@FreeBSD.org
COMMENT=	An Open Source PBX and telephony toolkit

BUILD_DEPENDS=	mpg123:${PORTSDIR}/audio/mpg123
LIB_DEPENDS=	speex.1:${PORTSDIR}/audio/speex \
		newt.51:${PORTSDIR}/devel/newt \
		gsm.1:${PORTSDIR}/audio/gsm \
		curl.5:${PORTSDIR}/ftp/curl
RUN_DEPENDS=	mpg123:${PORTSDIR}/audio/mpg123

ONLY_FOR_ARCHS=	i386 sparc64 amd64 powerpc

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/include/openh323" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-gsm=${LOCALBASE}
CPPFLAGS=	-I${LOCALBASE}/include -I${LOCALBASE}/include/openh323
USE_GMAKE=	yes
USE_BISON=	build
USE_RC_SUBR=	asterisk.sh
MAKE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}" \
		MKDIR="${MKDIR}" \
		PWLIBDIR=${LOCALBASE}/share/pwlib \
		OPENH323DIR=${LOCALBASE}/share/openh323 \
		OSVERSION=${OSVERSION} \
		NOISY_BUILD=YES \
		ASTCFLAGS="${CFLAGS}"
MAN8=		asterisk.8 astgenkey.8 autosupport.8 safe_asterisk.8
CONFLICTS=	asterisk*-1.2* asterisk*-1.6*

OPTIONS=	OGGVORBIS	"Enable Ogg Vorbis support" on \
		ODBC		"Enable ODBC support" on \
		POSTGRES	"Enable PostgreSQL support" on \
		RADIUS		"Enable RADIUS accounting support" on \
		SNMP		"Enable SNMP support" on \
		H323		"Enable H.323 support" on \
		FREETDS		"Enable FreeTDS support" on \
		JABBER		"Enable Jabber and Gtalk support" on \
		SQLITE          "Enable SQLITE support" on \
		CODEC_PATCH	"Apply codec negotiation patch" off \
		ILBC		"Enable iLBC codec" off \
		MISC_PATCHES	"Apply additional patches" off

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386" || ${ARCH} == "amd64"
OPTIONS+=	ZAPTEL		"Enable Zaptel support" off

# Include this since we have altered OPTIONS.
.include "$(PORTSDIR)/Mk/bsd.port.options.mk"
.endif

.if !defined(WITH_H323)
PLIST_SUB+=	WITH_H323="@comment "
CONFIGURE_ARGS+= --without-h323
.else
PLIST_SUB+=	WITH_H323=""
CONFIGURE_ARGS+= --with-h323=${LOCALBASE}
LIB_DEPENDS+=	pt_r.1:${PORTSDIR}/devel/pwlib \
		h323_r.1:${PORTSDIR}/net/openh323
.endif

.if !defined(WITH_ZAPTEL)
PLIST_SUB+=	WITH_ZAPTEL="@comment "
CONFIGURE_ARGS+= --without-zaptel
.else
PLIST_SUB+=	WITH_ZAPTEL=""
CONFIGURE_ARGS+= --with-zaptel
BUILD_DEPENDS+=	libpri>=1.2.0:${PORTSDIR}/misc/libpri \
		${LOCALBASE}/include/zaptel/zaptel.h:${PORTSDIR}/misc/zaptel
LIB_DEPENDS+=	pri.1:${PORTSDIR}/misc/libpri
RUN_DEPENDS+=	${LOCALBASE}/include/zaptel/zaptel.h:${PORTSDIR}/misc/zaptel
.endif

#
# WITH_FREETDS, WITH_PGSQL and WITH_SQLITE can also be added to MAKE_ENV
# similarly
.if !defined(WITH_ODBC)
PLIST_SUB+=	WITH_ODBC="@comment "
CONFIGURE_ARGS+= --without-odbc
.else
PLIST_SUB+=	WITH_ODBC=""
CONFIGURE_ARGS+= --with-odbc --with-ltdl
LIB_DEPENDS+=	odbc.1:${PORTSDIR}/databases/unixODBC \
		ltdl.4:${PORTSDIR}/devel/libltdl15
.endif

.if !defined(WITH_FREETDS)
PLIST_SUB+=	WITH_FREETDS="@comment "
CONFIGURE_ARGS+= --without-tds
.else
PLIST_SUB+=	WITH_FREETDS=""
CONFIGURE_ARGS+= --with-tds=${LOCALBASE}
LIB_DEPENDS+=	tds.5:${PORTSDIR}/databases/freetds
.endif

.if !defined(WITH_POSTGRES)
PLIST_SUB+=	WITH_POSTGRES="@comment "
CONFIGURE_ARGS+= --without-postgres
.else
PLIST_SUB+=	WITH_POSTGRES=""
USE_PGSQL=	yes
CONFIGURE_ARGS+= --with-postgres
.endif

.if !defined(WITH_OGGVORBIS)
PLIST_SUB+=	WITH_OGGVORBIS="@comment "
CONFIGURE_ARGS+= --without-ogg
.else
PLIST_SUB+=	WITH_OGGVORBIS=""
CONFIGURE_ARGS+= --with-ogg
LIB_DEPENDS+=	vorbis.4:${PORTSDIR}/audio/libvorbis
.endif

.if !defined(WITH_RADIUS)
PLIST_SUB+=	WITH_RADIUS="@comment "
CONFIGURE_ARGS+= --without-radius
.else
PLIST_SUB+=	WITH_RADIUS=""
CONFIGURE_ARGS+= --with-radius
LIB_DEPENDS+=	radiusclient-ng.2:${PORTSDIR}/net/radiusclient
.endif

.if !defined(WITH_SNMP)
PLIST_SUB+=	WITH_SNMP="@comment "
CONFIGURE_ARGS+= --without-netsnmp
.else
PLIST_SUB+=	WITH_SNMP=""
CONFIGURE_ARGS+= --with-netsnmp
LIB_DEPENDS+=	netsnmp.16:${PORTSDIR}/net-mgmt/net-snmp
.endif

.if !defined(WITH_JABBER)
PLIST_SUB+=	WITH_JABBER="@comment "
CONFIGURE_ARGS+= --without-iksemel
.else
PLIST_SUB+=	WITH_JABBER=""
CONFIGURE_ARGS+= --with-iksemel
LIB_DEPENDS+=	iksemel.4:${PORTSDIR}/textproc/iksemel
.endif

.if !defined(WITH_SQLITE)
PLIST_SUB+=	WITH_SQLITE="@comment "
CONFIGURE_ARGS+=	--without-sqlite
.else
PLIST_SUB+=	WITH_SQLITE=""
CONFIGURE_ARGS+= --with-sqlite
LIB_DEPENDS+=	sqlite:${PORTSDIR}/databases/sqlite2
.endif

.if !defined(WITH_ILBC)
PLIST_SUB+=	WITH_ILBC="@comment "
.else
PLIST_SUB+=	WITH_ILBC=""
EXTRA_PATCHES+=	${PATCHDIR}/ilbc_enable.diff
.endif

.if defined(WITH_CODEC_PATCH)
PATCHFILES=	asterisk-1.4.24-codec-negotiation-20090326.diff.gz
PATCH_SITES=	http://b2bua.org/chrome/site/
EXTRA_PATCHES+=	${PATCHDIR}/codecnego-patch-Makefile
.else
EXTRA_PATCHES+=	${PATCHDIR}/nocodecnego-patch-Makefile
.endif

.if defined(WITH_MISC_PATCHES)
EXTRA_PATCHES+=	${PATCHDIR}/dtmf_debug.diff
EXTRA_PATCHES+=	${PATCHDIR}/feature_disconnect.diff
EXTRA_PATCHES+=	${PATCHDIR}/sip_force_callid.diff
EXTRA_PATCHES+=	${PATCHDIR}/sip_set_auth.diff
.if defined(WITH_CODEC_PATCH)
EXTRA_PATCHES+=	${PATCHDIR}/rtp_force_dtmf-codecnego.diff
.else
EXTRA_PATCHES+=	${PATCHDIR}/rtp_force_dtmf-nocodecnego.diff
.endif
.endif

post-extract:
	${MKDIR} ${WRKSRC}/codecs/ilbc
	${FIND} ${WRKSRC} -name '*.d' -delete

post-patch:
	${REINPLACE_CMD} -e 's|/var/lib|${PREFIX}/share|g' ${WRKSRC}/configs/musiconhold.conf.sample

.include <bsd.port.post.mk>
