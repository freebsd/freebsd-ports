# Created by: Maxim Sobolev <sobomax@portaone.com>
# $FreeBSD$

PORTNAME=	asterisk
PORTVERSION=	1.4.42
PORTREVISION=	4
CATEGORIES=	net
MASTER_SITES=	http://downloads.asterisk.org/pub/telephony/asterisk/ \
		http://downloads.asterisk.org/pub/telephony/asterisk/old-releases/
PKGNAMESUFFIX=	14

MAINTAINER=	bamby@sippysoft.com
COMMENT=	An Open Source PBX and telephony toolkit

BROKEN=		Fails to configure or build

BUILD_DEPENDS=	mpg123:${PORTSDIR}/audio/mpg123
LIB_DEPENDS=	speex.1:${PORTSDIR}/audio/speex \
		newt.52:${PORTSDIR}/devel/newt \
		gsm.1:${PORTSDIR}/audio/gsm \
		curl:${PORTSDIR}/ftp/curl
RUN_DEPENDS=	mpg123:${PORTSDIR}/audio/mpg123

ONLY_FOR_ARCHS=	i386 sparc64 amd64 powerpc

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/openh323
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-gsm=${LOCALBASE}
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/openh323
USE_GCC=	any
USE_GMAKE=	yes
USES=		bison
USE_RC_SUBR=	asterisk
MAKE_ENV=	MKDIR="${MKDIR}" \
		PWLIBDIR=${LOCALBASE}/share/pwlib \
		OPENH323DIR=${LOCALBASE}/share/openh323 \
		OSVERSION=${OSVERSION} \
		NOISY_BUILD=YES \
		ASTCFLAGS="${PTHREAD_CFLAGS} ${CFLAGS}" \
		ASTLDFLAGS="${PTHREAD_LIBS} -L${LOCALBASE}/lib"
MAN8=		asterisk.8 astgenkey.8 autosupport.8 safe_asterisk.8
CONFLICTS=	asterisk*-1.2* asterisk*-1.6* asterisk*-1.8*

OPTIONS_DEFINE=	VORBIS ODBC PGSQL RADIUS SNMP H323 FREETDS JABBER SQLITE \
		CODEC_PATCH ILBC MISC_PATCHES
OPTIONS_DEFAULT=	VORBIS ODBC PGSQL RADIUS SNMP H323 FREETFS JABBER SQLITE
MISC_PATCHES_DESC=	Apply additional patches
ILBC_DESC=	iLBC codec
DAHDI_DESC=	DAHDI support

OPTIONS_DEFINE_i386=	DAHDI
OPTIONS_DEFAULT_i386=	DAHDI
OPTIONS_DEFINE_amd64=	DAHDI
OPTIONS_DEFAULT_amd64=	DAHDI
OPTIONS_DEFINE_sparc64=	DAHDI
OPTIONS_DEFAULT_sparc64=	DAHDI

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${PREFIX} == ${LOCALBASE}
CONFIGURE_ARGS+=--localstatedir=/var
.endif

.if ! ${PORT_OPTIONS:MH323}
PLIST_SUB+=	WITH_H323="@comment "
CONFIGURE_ARGS+= --without-h323
.else
PLIST_SUB+=	WITH_H323=""
CONFIGURE_ARGS+= --with-h323=${LOCALBASE}
LIB_DEPENDS+=	pt_r.1:${PORTSDIR}/devel/pwlib \
		h323_r.1:${PORTSDIR}/net/openh323
.endif

.if ! ${PORT_OPTIONS:MDAHDI}
PLIST_SUB+=	WITH_DAHDI="@comment "
CONFIGURE_ARGS+=	--without-dahdi
.else
PLIST_SUB+=	WITH_DAHDI=""
CONFIGURE_ARGS+=	--with-dahdi
BUILD_DEPENDS+=	libpri>=1.4.10:${PORTSDIR}/misc/libpri \
		${LOCALBASE}/include/dahdi/user.h:${PORTSDIR}/misc/dahdi
LIB_DEPENDS+=	pri.1:${PORTSDIR}/misc/libpri
RUN_DEPENDS+=	${LOCALBASE}/lib/dahdi/dahdi.ko:${PORTSDIR}/misc/dahdi-kmod
.endif

#
# WITH_FREETDS, WITH_PGSQL and WITH_SQLITE can also be added to MAKE_ENV
# similarly
.if ! ${PORT_OPTIONS:MODBC}
PLIST_SUB+=	WITH_ODBC="@comment "
CONFIGURE_ARGS+= --without-odbc
.else
PLIST_SUB+=	WITH_ODBC=""
CONFIGURE_ARGS+= --with-odbc --with-ltdl
USE_AUTOTOOLS+=	libltdl
LIB_DEPENDS+=	odbc.2:${PORTSDIR}/databases/unixODBC
.endif

.if ! ${PORT_OPTIONS:MFREETDS}
PLIST_SUB+=	WITH_FREETDS="@comment "
CONFIGURE_ARGS+= --without-tds
.else
PLIST_SUB+=	WITH_FREETDS=""
CONFIGURE_ARGS+= --with-tds=${LOCALBASE}
LIB_DEPENDS+=	tds.5:${PORTSDIR}/databases/freetds
.endif

.if ! ${PORT_OPTIONS:MPGSQL}
PLIST_SUB+=	WITH_POSTGRES="@comment "
CONFIGURE_ARGS+= --without-postgres
.else
PLIST_SUB+=	WITH_POSTGRES=""
USE_PGSQL=	yes
CONFIGURE_ARGS+= --with-postgres
.endif

.if ! ${PORT_OPTIONS:MVORBIS}
PLIST_SUB+=	WITH_VORBIS="@comment "
CONFIGURE_ARGS+= --without-ogg
.else
PLIST_SUB+=	WITH_VORBIS=""
CONFIGURE_ARGS+= --with-ogg
LIB_DEPENDS+=	vorbis.4:${PORTSDIR}/audio/libvorbis
.endif

.if ! ${PORT_OPTIONS:MRADIUS}
PLIST_SUB+=	WITH_RADIUS="@comment "
CONFIGURE_ARGS+= --without-radius
.else
PLIST_SUB+=	WITH_RADIUS=""
CONFIGURE_ARGS+= --with-radius
LIB_DEPENDS+=	radiusclient-ng.2:${PORTSDIR}/net/radiusclient
.endif

.if ! ${PORT_OPTIONS:MSNMP}
PLIST_SUB+=	WITH_SNMP="@comment "
CONFIGURE_ARGS+= --without-netsnmp
.else
PLIST_SUB+=	WITH_SNMP=""
CONFIGURE_ARGS+= --with-netsnmp
LIB_DEPENDS+=	netsnmp:${PORTSDIR}/net-mgmt/net-snmp
.endif

.if ! ${PORT_OPTIONS:MJABBER}
PLIST_SUB+=	WITH_JABBER="@comment "
CONFIGURE_ARGS+= --without-iksemel
.else
PLIST_SUB+=	WITH_JABBER=""
CONFIGURE_ARGS+= --with-iksemel
LIB_DEPENDS+=	iksemel.4:${PORTSDIR}/textproc/iksemel
.endif

.if ! ${PORT_OPTIONS:MSQLITE}
PLIST_SUB+=	WITH_SQLITE="@comment "
CONFIGURE_ARGS+=	--without-sqlite
.else
PLIST_SUB+=	WITH_SQLITE=""
CONFIGURE_ARGS+= --with-sqlite
LIB_DEPENDS+=	sqlite:${PORTSDIR}/databases/sqlite2
.endif

.if ! ${PORT_OPTIONS:MILBC}
PLIST_SUB+=	WITH_ILBC="@comment "
.else
PLIST_SUB+=	WITH_ILBC=""
EXTRA_PATCHES+=	${PATCHDIR}/ilbc_enable.diff
.endif

.if ${PORT_OPTIONS:MCODEC_PATCH}
PATCHFILES=	asterisk-1.4.42-codec-negotiation-20111017.diff.gz
PATCH_SITES=	${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=	fjoe/
EXTRA_PATCHES+=	${PATCHDIR}/codecnego-patch-Makefile
.else
EXTRA_PATCHES+=	${PATCHDIR}/nocodecnego-patch-Makefile
.endif

.if ${PORT_OPTIONS:MMISC_PATCHES}
EXTRA_PATCHES+=	${PATCHDIR}/dtmf_debug.diff
EXTRA_PATCHES+=	${PATCHDIR}/sip_force_callid.diff
EXTRA_PATCHES+=	${PATCHDIR}/sip_set_auth.diff
.if ${PORT_OPTIONS:MCODEC_PATCH}
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
