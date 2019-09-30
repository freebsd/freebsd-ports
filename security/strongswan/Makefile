# Created by: Riaan Kruger <riaank@gmail.com>
# $FreeBSD$

PORTNAME=	strongswan
PORTVERSION=	5.8.1
CATEGORIES=	security net-vpn
MASTER_SITES=	http://download.strongswan.org/ \
		http://download2.strongswan.org/

MAINTAINER=	strongswan@nanoteq.com
COMMENT=	Open Source IKEv2 IPsec-based VPN solution

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe libtool:keepla pkgconfig tar:bzip2 ssl
USE_RC_SUBR=	strongswan
USE_LDCONFIG=	${PREFIX}/lib/ipsec

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=	--enable-kernel-pfkey \
		--enable-kernel-pfroute  \
		--disable-kernel-netlink  \
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
		--enable-cmd \
		--with-group=wheel  \
		--with-lib-prefix=${PREFIX}

OPTIONS_DEFINE=	CURL EAPAKA3GPP2 EAPDYNAMIC EAPRADIUS EAPSIMFILE GCM IKEV1 \
		IPSECKEY KERNELLIBIPSEC LOADTESTER LDAP MEDIATION MYSQL PKI \
		PKCS11 SCEP SMP SQLITE SWANCTL TESTVECTOR TPM UNBOUND UNITY \
		VICI XAUTH
OPTIONS_DEFINE_i386=	VIA
OPTIONS_DEFAULT=	BUILTIN CURL IKEV1 PKI SWANCTL VICI
OPTIONS_SINGLE=	PRINTF_HOOKS
OPTIONS_SINGLE_PRINTF_HOOKS=	BUILTIN LIBC VSTR
OPTIONS_SUB=	yes

# Description of options
BUILTIN_DESC=	Use builtin printf hooks
CURL_DESC=	Enable CURL to fetch CRL/OCSP
EAPAKA3GPP2_DESC=	Enable EAP AKA with 3gpp2 backend
EAPDYNAMIC_DESC=	Enable EAP dynamic proxy module
EAPRADIUS_DESC=		Enable EAP Radius proxy authentication
EAPSIMFILE_DESC=	Enable EAP SIM with file backend
GCM_DESC=		Enable GCM AEAD wrapper crypto plugin
IKEV1_DESC=	Enable IKEv1 support
IPSECKEY_DESC=	Enable authentication with IPSECKEY resource records with DNSSEC
KERNELLIBIPSEC_DESC=	Enable IPSec userland backend
LIBC_DESC=	Use libc printf hooks
LOADTESTER_DESC=	Enable load testing plugin
MEDIATION_DESC=		Enable IKEv2 Mediation Extension
PKCS11_DESC=	Enable PKCS11 token support
PKI_DESC=	Enable PKI tools
SCEP_DESC=	Enable Simple Certificate Enrollment Protocol
SMP_DESC=	Enable XML-based management protocol (DEPRECATED)
SWANCTL_DESC=	Install swanctl (requires VICI)
TESTVECTOR_DESC=	Enable crypto test vectors
TPM_DESC=	Enable TPM plugin
UNBOUND_DESC=	Enable DNSSEC-enabled resolver
UNITY_DESC=	Enable Cisco Unity extension plugin
VIA_DESC=	Enable VIA Padlock support
VICI_DESC=	Enable VICI management protocol
VSTR_DESC=	Use devel/vstr printf hooks
XAUTH_DESC=	Enable XAuth password verification

# Extra options
BUILTIN_CONFIGURE_ON=	--with-printf-hooks=builtin
CURL_CONFIGURE_ON=	--enable-curl
CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
EAPAKA3GPP2_CONFIGURE_ON=	--enable-eap-aka --enable-eap-aka-3gpp2
EAPAKA3GPP2_LIB_DEPENDS=libgmp.so:math/gmp
EAPDYNAMIC_CONFIGURE_ON=--enable-eap-dynamic
EAPRADIUS_CONFIGURE_ON=	--enable-eap-radius
EAPSIMFILE_CONFIGURE_ON=--enable-eap-sim --enable-eap-sim-file
GCM_CONFIGURE_ON=	--enable-gcm
IKEV1_CONFIGURE_OFF=	--disable-ikev1
IPSECKEY_CONFIGURE_ON=	--enable-ipseckey
KERNELLIBIPSEC_CONFIGURE_ON=	--enable-kernel-libipsec
LDAP_CONFIGURE_ON=	--enable-ldap
LDAP_USE=		OPENLDAP=yes
LIBC_CONFIGURE_ON=	--with-printf-hooks=glibc
LOADTESTER_CONFIGURE_ON=--enable-load-tester
MEDIATION_CONFIGURE_ON=	--enable-mediation
MYSQL_CONFIGURE_ON=	--enable-mysql
MYSQL_USES=		mysql
PKCS11_CONFIGURE_ON=	--enable-pkcs11
PKI_CONFIGURE_OFF=	--disable-pki
SCEP_CONFIGURE_OFF=	--disable-scepclient
SMP_CONFIGURE_ON=	--enable-smp
SMP_LIB_DEPENDS=	libxml2.so:textproc/libxml2
SQLITE_CONFIGURE_ON=	--enable-sqlite
SQLITE_LIB_DEPENDS=	libsqlite3.so:databases/sqlite3
SWANCTL_CONFIGURE_ON=	--enable-swanctl
SWANCTL_IMPLIES=	VICI
TESTVECTOR_CONFIGURE_ON=--enable-test-vectors
TPM_CONFIGURE_ON=	--enable-tpm
UNBOUND_CONFIGURE_ON=	--enable-unbound
UNBOUND_LIB_DEPENDS=	libunbound.so:dns/unbound \
			libldns.so:dns/ldns
UNITY_CONFIGURE_ON=	--enable-unity
VIA_CONFIGURE_ON=	--enable-padlock
VICI_CONFIGURE_ON=	--enable-vici
VSTR_CONFIGURE_ON=	--with-printf-hooks=vstr
VSTR_LIB_DEPENDS=	libvstr.so:devel/vstr
XAUTH_CONFIGURE_ON=	--enable-xauth-eap \
			--enable-xauth-generic \
			--enable-xauth-pam

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEAPSIMFILE} || ${PORT_OPTIONS:MEAPAKA3GPP2}
PLIST_SUB+=	SIMAKA=""
.else
PLIST_SUB+=	SIMAKA="@comment "
.endif

.if ${PORT_OPTIONS:MMYSQL} || ${PORT_OPTIONS:MSQLITE}
CONFIGURE_ARGS+=	--enable-attr-sql --enable-sql
PLIST_SUB+=	SQL=""
.else
PLIST_SUB+=	SQL="@comment "
.endif

.if ${PORT_OPTIONS:MIKEV1} || ${PORT_OPTIONS:MXAUTH}
PLIST_SUB+=	XAUTHGEN=""
.else
PLIST_SUB+=	XAUTHGEN="@comment "
.endif

# Hack to disable VIA in plist of unsupported architectures
.if ! ${OPTIONS_DEFINE:MVIA}
PLIST_SUB+=	VIA="@comment "
.else
.endif

post-install:
.if ${PORT_OPTIONS:MVICI}
	${INSTALL_DATA} ${WRKSRC}/src/libcharon/plugins/vici/libvici.h \
		${STAGEDIR}${PREFIX}/include
.endif

.include <bsd.port.mk>
