PORTNAME=	strongswan
DISTVERSION=	6.0.1
CATEGORIES=	security net-vpn
MASTER_SITES=	https://download.strongswan.org/ \
		https://download2.strongswan.org/

MAINTAINER=	strongswan@nanoteq.com
COMMENT=	Open Source IKEv2 IPsec-based VPN solution
WWW=		https://www.strongswan.org

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe libtool:keepla pkgconfig ssl tar:bzip2
USE_LDCONFIG=	${PREFIX}/lib/ipsec
USE_RC_SUBR=	strongswan

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc \
		--disable-gmp \
		--disable-kernel-netlink \
		--disable-scripts \
		--enable-addrblock \
		--enable-blowfish \
		--enable-cmd \
		--enable-eap-identity \
		--enable-eap-md5 \
		--enable-eap-mschapv2 \
		--enable-eap-peap \
		--enable-eap-tls \
		--enable-eap-ttls \
		--enable-kernel-pfkey \
		--enable-kernel-pfroute \
		--enable-md4 \
		--enable-openssl \
		--enable-whitelist \
		--with-group=wheel \
		--with-lib-prefix=${PREFIX}

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

OPTIONS_DEFINE=			CTR CURL DHCP EAPAKA3GPP2 EAPDYNAMIC EAPRADIUS \
				EAPSIMFILE FARP GCM IKEV1 IPSECKEY KDF \
				KERNELLIBIPSEC LDAP LOADTESTER MEDIATION ML MYSQL \
				PKCS11 PKI PYTHON SMP SQLITE STROKE SWANCTL \
				TESTVECTOR TPM TSS2 UNBOUND UNITY VICI XAUTH
OPTIONS_DEFINE_i386=	VIA
OPTIONS_DEFAULT=		BUILTIN CURL GCM IKEV1 KDF PKI SWANCTL VICI
OPTIONS_SINGLE=			PRINTF_HOOKS
OPTIONS_SINGLE_PRINTF_HOOKS=	BUILTIN LIBC VSTR
OPTIONS_SUB=			yes

# Description of options
BUILTIN_DESC=		Use builtin printf hooks
CTR_DESC=		Enable CTR cipher mode wrapper plugin
CURL_DESC=		Enable CURL to fetch CRL/OCSP
DHCP_DESC=		Enable DHCP based attribute provider plugin
EAPAKA3GPP2_DESC=	Enable EAP AKA with 3gpp2 backend
EAPDYNAMIC_DESC=	Enable EAP dynamic proxy module
EAPRADIUS_DESC=		Enable EAP Radius proxy authentication
EAPSIMFILE_DESC=	Enable EAP SIM with file backend
FARP_DESC=		Enable farp plugin
GCM_DESC=		Enable GCM AEAD wrapper crypto plugin
IKEV1_DESC=		Enable IKEv1 support
IPSECKEY_DESC=		Enable authentication with IPSECKEY resource records with DNSSEC
KDF_DESC=		Enable KDF (prf+) implementation plugin
KERNELLIBIPSEC_DESC=	Enable IPSec userland backend
LIBC_DESC=		Use libc printf hooks
LOADTESTER_DESC=	Enable load testing plugin
MEDIATION_DESC=		Enable IKEv2 Mediation Extension
ML_DESC=		Enable Module-Lattice-based crypto plugin
PKCS11_DESC=		Enable PKCS11 token support
PKI_DESC=		Enable PKI tools
PYTHON_DESC=		Python VICI protocol plugin
SMP_DESC=		Enable XML-based management protocol (DEPRECATED)
STROKE_DESC=		Enable stroke management protcol (DEPRECATED)
SWANCTL_DESC=		Install swanctl (requires VICI)
TESTVECTOR_DESC=	Enable crypto test vectors
TPM_DESC=		Enable TPM plugin
TSS2_DESC=		Enable TPM 2.0 TSS2 library
UNBOUND_DESC=		Enable DNSSEC-enabled resolver
UNITY_DESC=		Enable Cisco Unity extension plugin
VIA_DESC=		Enable VIA Padlock support
VICI_DESC=		Enable VICI management protocol
VSTR_DESC=		Use devel/vstr printf hooks
XAUTH_DESC=		Enable XAuth password verification

# Extra options
BUILTIN_CONFIGURE_ON=		--with-printf-hooks=builtin
CTR_CONFIGURE_ON=		--enable-ctr
CURL_LIB_DEPENDS=		libcurl.so:ftp/curl
CURL_CONFIGURE_ON=		--enable-curl
DHCP_CONFIGURE_ON=		--enable-dhcp
EAPAKA3GPP2_LIB_DEPENDS=	libgmp.so:math/gmp
EAPAKA3GPP2_CONFIGURE_ON=	--enable-eap-aka \
				--enable-eap-aka-3gpp2
EAPDYNAMIC_CONFIGURE_ON=	--enable-eap-dynamic
EAPRADIUS_CONFIGURE_ON=		--enable-eap-radius
EAPSIMFILE_CONFIGURE_ON=	--enable-eap-sim \
				--enable-eap-sim-file
FARP_CONFIGURE_ON=		--enable-farp
GCM_CONFIGURE_ON=		--enable-gcm
IKEV1_CONFIGURE_OFF=		--disable-ikev1
IPSECKEY_CONFIGURE_ON=		--enable-ipseckey
KDF_CONFIGURE_ON=		--enable-kdf
KERNELLIBIPSEC_CONFIGURE_ON=	--enable-kernel-libipsec
LDAP_USES=			ldap
LDAP_CONFIGURE_ON=		--enable-ldap
LIBC_CONFIGURE_ON=		--with-printf-hooks=glibc
LOADTESTER_CONFIGURE_ON=	--enable-load-tester
MEDIATION_CONFIGURE_ON=		--enable-mediation
ML_CONFIGURE_ON=		--enable-ml
MYSQL_LIB_DEPENDS=		libunwind.so:devel/libunwind
MYSQL_USES=			mysql
MYSQL_CONFIGURE_ON=		--enable-mysql
PKCS11_CONFIGURE_ON=		--enable-pkcs11
PKI_CONFIGURE_OFF=		--disable-pki
PYTHON_IMPLIES=			VICI
PYTHON_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}vici>0:security/py-vici@${PY_FLAVOR}
PYTHON_USES=			python
SMP_LIB_DEPENDS=		libxml2.so:textproc/libxml2
SMP_CONFIGURE_ON=		--enable-smp
SQLITE_LIB_DEPENDS=		libsqlite3.so:databases/sqlite3
SQLITE_CONFIGURE_ON=		--enable-sqlite
STROKE_CONFIGURE_ON=		--enable-stroke
SWANCTL_IMPLIES=		VICI
SWANCTL_CONFIGURE_ON=		--enable-swanctl
TESTVECTOR_CONFIGURE_ON=	--enable-test-vectors
TPM_CONFIGURE_ON=		--enable-tpm
TSS2_LIB_DEPENDS=		libtss2-sys.so:security/tpm2-tss
TSS2_CONFIGURE_ON=		--enable-tss-tss2
UNBOUND_LIB_DEPENDS=		libldns.so:dns/ldns \
				libunbound.so:dns/unbound
UNBOUND_CONFIGURE_ON=		--enable-unbound
UNITY_CONFIGURE_ON=		--enable-unity
VIA_CONFIGURE_ON=		--enable-padlock
VICI_CONFIGURE_ON=		--enable-vici
VICI_SUB_LIST=			INTERFACE="vici"
VICI_SUB_LIST_OFF=		INTERFACE="stroke"
VSTR_LIB_DEPENDS=		libvstr.so:devel/vstr
VSTR_CONFIGURE_ON=		--with-printf-hooks=vstr
XAUTH_CONFIGURE_ON=		--enable-xauth-eap \
				--enable-xauth-generic \
				--enable-xauth-pam

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEAPSIMFILE} || ${PORT_OPTIONS:MEAPAKA3GPP2}
PLIST_SUB+=	SIMAKA=""
.else
PLIST_SUB+=	SIMAKA="@comment "
.endif

.if ${PORT_OPTIONS:MMYSQL} || ${PORT_OPTIONS:MSQLITE}
CONFIGURE_ARGS+=	--enable-attr-sql \
			--enable-sql
PLIST_SUB+=		SQL=""
.else
PLIST_SUB+=		SQL="@comment "
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
