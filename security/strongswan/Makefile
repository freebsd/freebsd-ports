# Created by: Riaan Kruger <riaank@gmail.com>
# $FreeBSD$

PORTNAME=	strongswan
PORTVERSION=	5.0.1
CATEGORIES=	security
MASTER_SITES=	http://download.strongswan.org/ \
		http://download2.strongswan.org/

MAINTAINER=	strongswan@nanoteq.com
COMMENT=	Open Source IKEv2 IPsec-based VPN solution

LIB_DEPENDS=	execinfo:${PORTSDIR}/devel/libexecinfo

USE_BZIP2=	yes
USE_OPENSSL=	yes
USE_AUTOTOOLS=	libtool
USE_RC_SUBR=	strongswan.sh
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--enable-kernel-pfkey \
		--enable-kernel-pfroute  \
		--disable-kernel-netlink  \
		--disable-tools  \
		--disable-scripts  \
		--disable-gmp \
		--enable-openssl \
		--enable-eap-identity \
		--enable-eap-md5 \
		--enable-eap-tls \
		--enable-eap-mschapv2 \
		--enable-eap-peap \
		--enable-eap-ttls \
		--enable-md4 \
		--enable-blowfish \
		--enable-addrblock \
		--enable-whitelist \
		--with-group=wheel  \
		--with-lib-prefix=${PREFIX}

# Man pages with default install
MAN5=	ipsec.conf.5 ipsec.secrets.5 strongswan.conf.5
MAN8=	ipsec.8 _updown.8 _updown_espmark.8

OPTIONS_DEFINE=	CURL EAPAKA3GPP2 EAPSIMFILE IKEv1 LDAP MYSQL SQLITE
CURL_DESC=	Enable CURL to fetch CRL/OCSP
EAPAKA3GPP2_DESC=	Enable EAP AKA with 3gpp2 backend
EAPSIMFILE_DESC=	Enable EAP SIM with file backend
IKEv1_DESC=	Enable IKEv1 support (Experimental)

.include <bsd.port.options.mk>

# Extra options
.if ${PORT_OPTIONS:MCURL}
CONFIGURE_ARGS+=	--enable-curl
LIB_DEPENDS+=	curl:${PORTSDIR}/ftp/curl
PLIST_SUB+=	CURL=""
.else
PLIST_SUB+=	CURL="@comment "
.endif

.if ${PORT_OPTIONS:MEAPSIMFILE}
CONFIGURE_ARGS+=	--enable-eap-sim --enable-eap-sim-file
PLIST_SUB+=	EAPSIMFILE=""
.else
PLIST_SUB+=	EAPSIMFILE="@comment "
.endif

.if ${PORT_OPTIONS:MEAPAKA3GPP2}
CONFIGURE_ARGS+=	--enable-eap-aka --enable-eap-aka-3gpp2
LIB_DEPENDS+=	gmp:${PORTSDIR}/math/gmp
PLIST_SUB+=	EAPAKA3GPP2=""
.else
PLIST_SUB+=	EAPAKA3GPP2="@comment "
.endif

.if ${PORT_OPTIONS:MEAPSIMFILE} || ${PORT_OPTIONS:MEAPAKA3GPP2}
PLIST_SUB+=SIMAKA=""
.else
PLIST_SUB+=SIMAKA="@comment "
.endif

.if ${PORT_OPTIONS:MIKEv1}
PLIST_SUB+=	IKEv1=""
.else
CONFIGURE_ARGS+=	--disable-ikev1
PLIST_SUB+=	IKEv1="@comment "
.endif

.if ${PORT_OPTIONS:MLDAP}
USE_OPENLDAP=	yes
CONFIGURE_ARGS+=	--enable-ldap
PLIST_SUB+=	LDAP=""
.else
PLIST_SUB+=	LDAP="@comment "
.endif

.if ${PORT_OPTIONS:MMYSQL}
CONFIGURE_ARGS+=	--enable-mysql
USE_MYSQL=	yes
PLIST_SUB+=	MYSQL=""
.else
PLIST_SUB+=	MYSQL="@comment "
.endif

.if ${PORT_OPTIONS:MSQLITE}
CONFIGURE_ARGS+=	--enable-sqlite
LIB_DEPENDS+=	sqlite3:${PORTSDIR}/databases/sqlite3
PLIST_SUB+=	SQLITE=""
.else
PLIST_SUB+=	SQLITE="@comment "
.endif

.if ${PORT_OPTIONS:MMYSQL} || ${PORT_OPTIONS:MSQLITE}
CONFIGURE_ARGS+=	--enable-attr-sql --enable-sql
PLIST_SUB+=	SQL=""
.else
PLIST_SUB+=	SQL="@comment "
.endif

.include <bsd.port.pre.mk>

# Requires FreeBSD 8 and above to work
.if ${OSVERSION} < 800000
IGNORE=		requires at least FreeBSD 8.X
.endif

.include <bsd.port.post.mk>
