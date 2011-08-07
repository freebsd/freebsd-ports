# Ports collection makefile for:    netatalk
# Date created:         23 Jul 1997
# Whom:                 stb
#
# $FreeBSD$
#

PORTNAME=	netatalk
PORTVERSION=	2.2.0
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	net print
MASTER_SITES=	SF/netatalk/netatalk/2.2

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	File server for Mac OS X

LIB_DEPENDS=	gcrypt:${PORTSDIR}/security/libgcrypt

USE_AUTOTOOLS=	libtool
USE_BDB=	46+
USE_BZIP2=	yes
USE_ICONV=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_PERL5=	yes
WANT_GNOME=	yes
USE_RC_SUBR=	netatalk

CONFIGURE_ARGS+=	--with-tcp-wrappers \
			--with-pkgconfdir=${PREFIX}/etc \
			--with-libiconv=${LOCALBASE} \
			--with-libgcrypt-dir=${LOCALBASE} \
			--with-uams-path=${LOCALBASE}/libexec/netatalk-uams \
			--with-bdb=${LOCALBASE}

OPTIONS=	APPLETALK	"Enable AppleTalk protocol support" on \
		SRVLOC		"Enable Service Location Protocol support" off \
		PAM		"Enable PAM support" off \
		TIMELORD	"Enable Timelord network time service" off \
		KRB5		"Enable Kerberos V UAM" off \
		ZEROCONF	"Enable Zeroconf (Bonjour) support" on

FILES=		AppleVolumes.default AppleVolumes.system afpd.conf \
		atalkd.conf papd.conf netatalk.conf
LINKS=		unbin unhex unsingle hqx2bin single2bin macbinary \
		binheader nadheader
MAN1=		ad.1 afpldaptest.1 afppasswd.1 apple_dump.1 asip-status.pl.1 \
		dbd.1 hqx2bin.1 macbinary.1 megatron.1 \
		netatalk-config.1 single2bin.1 unbin.1 unhex.1 uniconv.1 \
		unsingle.1
MAN5=		AppleVolumes.5 AppleVolumes.default.5 \
		AppleVolumes.system.5 afp_ldap.conf.5 afp_signature.conf.5 \
		afp_voluuid.conf.5 afpd.conf.5 netatalk.conf.5
MAN8=		afpd.8 cnid_dbd.8 cnid_metad.8 timelord.8

CONFLICTS=	bigloo-2.* cap-6.0.* tct-1.* netatalk-1* yudit-[0-9]*

.include <bsd.port.pre.mk>

.if defined(WITH_KRB5)
CONFIGURE_ARGS+=	--enable-krbV-uam
PLIST_SUB+=		NETATALKKRB5=""
.else
PLIST_SUB+=		NETATALKKRB5="@comment "
.endif

.if defined(WITH_APPLETALK)
CONFIGURE_ARGS+=	--enable-ddp
PLIST_SUB+=		APPLETALK=""
MAN1+=			aecho.1 getzones.1 nbp.1 nbplkup.1 nbprgstr.1 \
			nbpunrgstr.1 pap.1 papstatus.1 psorder.1
MAN3+=			atalk_aton.3 nbp_name.3
MAN4+=			atalk.4
MAN5+=			atalkd.conf.5 papd.conf.5
MAN8+=			atalkd.8 papd.8 papstatus.8 psf.8
.else
PLIST_SUB+=		APPLETALK="@comment "
.endif

.if defined(WITH_PAM)
CONFIGURE_ARGS+=	--with-pam
PLIST_SUB+=		NETATALKPAM=""
.else
CONFIGURE_ARGS+=	--without-pam
PLIST_SUB+=		NETATALKPAM="@comment "
.endif

.if defined(WITH_SRVLOC)
CONFIGURE_ARGS+=	--enable-srvloc=${LOCALBASE}
LIB_DEPENDS+=		slp.1:${PORTSDIR}/net/openslp
SUB_LIST+=		SRVLOC="slpd"
.else
SUB_LIST+=		SRVLOC=""
.endif

.if defined (WITH_TIMELORD)
CONFIGURE_ARGS+=	--enable-timelord
PLIST_SUB+=		TIMELORD=""
.else
PLIST_SUB+=		TIMELORD="@comment "
.endif

.if defined (WITH_ZEROCONF)
CONFIGURE_ARGS+=	--enable-zeroconf=${LOCALBASE}
LIB_DEPENDS+=		avahi-client.3:${PORTSDIR}/net/avahi-app
USE_GNOME+=		pkgconfig
.endif

.if ${OSVERSION} < 800031
PLIST_SUB+=	ATFUNCS="@comment "
.else
PLIST_SUB+=	ATFUNCS=""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%DB_NAME%%|${BDB_INCLUDE_DIR:T}| ; \
	    	s|%%DB_LIB%%|-l${BDB_LIB_NAME}|g ; \
		s|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/configure

post-install:
	@${RM} -f ${PREFIX}/bin/nu ${PREFIX}/bin/lp2pap.sh \
		${PREFIX}/bin/test_parse_mtab \
		${PREFIX}/bin/afpd-mtab.pl
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/macusers/macusers \
		${PREFIX}/bin/macusers
.for i in ${FILES}
	[ -f ${PREFIX}/etc/${i} ] || \
		${INSTALL_DATA} -c ${PREFIX}/etc/${i}.dist ${PREFIX}/etc/${i}
.endfor
.for i in ${LINKS}
	( cd ${PREFIX}/bin && ${LN} -sf megatron ${i} )
.endfor
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
