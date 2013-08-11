# Created by: stb
# $FreeBSD$

PORTNAME=	netatalk
PORTVERSION=	2.2.5
PORTEPOCH=	1
CATEGORIES=	net print
MASTER_SITES=	SF

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	File server for Mac OS X

LIB_DEPENDS=	gcrypt:${PORTSDIR}/security/libgcrypt

USE_AUTOTOOLS=	libtool
USE_BDB=	46+
USE_BZIP2=	yes
USES=		iconv
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_PERL5=	yes
WANT_GNOME=	yes
USE_RC_SUBR=	netatalk

CONFIGURE_ARGS+=	--with-tcp-wrappers \
			--with-pkgconfdir=${PREFIX}/etc \
			--with-libiconv=${LOCALBASE} \
			--with-libgcrypt-dir=${LOCALBASE} \
			--with-uams-path=${PREFIX}/libexec/netatalk-uams \
			--with-bdb=${LOCALBASE}

OPTIONS_DEFINE=	APPLETALK SRVLOC PAM TIMELORD KRB5 ZEROCONF LDAP SENDFILE
OPTIONS_DEFAULT=	APPLETALK
APPLETALK_DESC=	AppleTalk protocol support
SRVLOC_DESC=	Service Location Protocol support
TIMELORD_DESC=	Timelord network time service
KRB5_DESC=	Kerberos V UAM
ZEROCONF_DESC=	Zeroconf (Bonjour) support
SENDFILE_DESC=	sendfile support

FILES=		AppleVolumes.default AppleVolumes.system afpd.conf netatalk.conf
LINKS=		unbin unhex unsingle hqx2bin single2bin macbinary \
		binheader nadheader
MAN1=		ad.1 afpldaptest.1 afppasswd.1 apple_dump.1 asip-status.pl.1 \
		dbd.1 hqx2bin.1 macbinary.1 macusers.1 megatron.1 \
		netatalk-config.1 single2bin.1 unbin.1 unhex.1 uniconv.1 \
		unsingle.1
MAN5=		AppleVolumes.5 AppleVolumes.default.5 \
		AppleVolumes.system.5 afp_ldap.conf.5 afp_signature.conf.5 \
		afp_voluuid.conf.5 afpd.conf.5 netatalk.conf.5
MAN8=		afpd.8 cnid_dbd.8 cnid_metad.8 timelord.8

CONFLICTS=	bigloo-2.* cap-6.0.* tct-1.* netatalk-1* yudit-[0-9]*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MKRB5}
CONFIGURE_ARGS+=	--enable-krbV-uam
PLIST_SUB+=		NETATALKKRB5=""
.else
PLIST_SUB+=		NETATALKKRB5="@comment "
.endif

.if ${PORT_OPTIONS:MAPPLETALK}
CONFIGURE_ARGS+=	--enable-ddp
PLIST_SUB+=		APPLETALK=""
MAN1+=			aecho.1 getzones.1 nbp.1 nbplkup.1 nbprgstr.1 \
			nbpunrgstr.1 pap.1 papstatus.1 psorder.1
MAN3+=			atalk_aton.3 nbp_name.3
MAN4+=			atalk.4
MAN5+=			atalkd.conf.5 papd.conf.5
MAN8+=			atalkd.8 papd.8 papstatus.8 psf.8
FILES+=			atalkd.conf papd.conf
.else
PLIST_SUB+=		APPLETALK="@comment "
.endif

.if ${PORT_OPTIONS:MPAM}
CONFIGURE_ARGS+=	--with-pam
PLIST_SUB+=		NETATALKPAM=""
.else
CONFIGURE_ARGS+=	--without-pam
PLIST_SUB+=		NETATALKPAM="@comment "
.endif

.if ${PORT_OPTIONS:MSRVLOC}
CONFIGURE_ARGS+=	--enable-srvloc=${LOCALBASE}
LIB_DEPENDS+=		slp.1:${PORTSDIR}/net/openslp
SUB_LIST+=		SRVLOC="slpd"
.else
SUB_LIST+=		SRVLOC=""
.endif

.if ${PORT_OPTIONS:MTIMELORD}
CONFIGURE_ARGS+=	--enable-timelord
PLIST_SUB+=		TIMELORD=""
.else
PLIST_SUB+=		TIMELORD="@comment "
.endif

.if ${PORT_OPTIONS:MZEROCONF}
CONFIGURE_ARGS+=	--enable-zeroconf=${LOCALBASE}
CFLAGS+=		-I${LOCALBASE}/include -L${LOCALBASE}/lib
LIB_DEPENDS+=		avahi-client.3:${PORTSDIR}/net/avahi-app
USE_GNOME+=		pkgconfig
SUB_LIST+=		ZEROCONF="avahi_daemon"
.else
CONFIGURE_ARGS+=	--disable-zerconf
SUB_LIST+=		ZEROCONF=""
.endif

.if ${PORT_OPTIONS:MLDAP}
CONFIGURE_ARGS+=	--with-ldap
CFLAGS+=		-I${LOCALBASE}/include -L${LOCALBASE}/lib
USE_OPENLDAP=		yes
.else
CONFIGURE_ARGS+=	--without-ldap
.endif

.if ${PORT_OPTIONS:MSENDFILE}
CONFIGURE_ARGS+=	--enable-sendfile
.else
CONFIGURE_ARGS+=	--disable-sendfile
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

.include <bsd.port.mk>
