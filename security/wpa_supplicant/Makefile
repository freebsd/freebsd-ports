# $FreeBSD$

PORTNAME=	wpa_supplicant
PORTVERSION=	2.9
PORTREVISION=	5
CATEGORIES=	security net
MASTER_SITES=	https://w1.fi/releases/

PATCH_SITES=	https://w1.fi/security/2018-1/:2018_1

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Supplicant (client) for WPA/802.1x protocols

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/README

USES=		cpe gmake pkgconfig:build readline ssl
BUILD_WRKSRC=	${WRKSRC}/wpa_supplicant
INSTALL_WRKSRC=	${WRKSRC}/src
CFLAGS+=	${CPPFLAGS} # USES=readline only augments CPPFLAGS and LDFLAGS
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB} -lutil
MAKE_ENV=	V=1

SUB_FILES=	pkg-message
PORTDOCS=	README ChangeLog

CFG=		${BUILD_WRKSRC}/.config

.if !exists(/etc/rc.d/wpa_supplicant)
USE_RC_SUBR=	wpa_supplicant
.endif

OPTIONS_MULTI=		DRV EAP
OPTIONS_MULTI_DRV=	BSD WIRED NDIS TEST NONE #ROBOSWITCH
OPTIONS_MULTI_EAP=	TLS PEAP TTLS MD5 MSCHAPV2 GTC LEAP OTP PSK FAST \
			SIM PWD PAX AKA AKA_PRIME SAKE GPSK TNC IKEV2 EKE
OPTIONS_DEFINE=		WPS WPS_ER WPS_NOREG WPS_NFC WPS_UPNP PKCS12 SMARTCARD \
			HT_OVERRIDES VHT_OVERRIDES TLSV12 IEEE80211W \
			IEEE80211R DEBUG_FILE DEBUG_SYSLOG PRIVSEP \
			DELAYED_MIC IEEE80211N IEEE80211AC INTERWORKING \
			IEEE8021X_EAPOL \
			HS20 NO_ROAMING P2P TDLS DBUS DOCS
OPTIONS_DEFAULT=	BSD WIRED NDIS \
			TLS PEAP TTLS MD5 MSCHAPV2 GTC LEAP OTP PSK \
			WPS PKCS12 SMARTCARD IEEE80211R DEBUG_SYSLOG \
			INTERWORKING HS20 DBUS IEEE80211R IEEE80211W \
			IEEE8021X_EAPOL WPS_ER WPS_NFC WPS_UPNP NDIS \
			FAST PWD PAX SAKE GPSK TNC IKEV2 EKE

WPS_DESC=		Wi-Fi Protected Setup
WPS_ER_DESC=		Enable WPS External Registrar
WPS_NOREG_DESC=		Disable open network credentials when registrar
WPS_NFC_DESC=		Near Field Communication (NFC) configuration
WPS_UPNP_DESC=		Universal Plug and Play support
PKCS12_DESC=		PKCS\#12 (PFS) support
SMARTCARD_DESC=		Private key on smartcard support
HT_OVERRIDES_DESC=	Disable HT/HT40, mask MCS rates, etc
VHT_OVERRIDES_DESC=	Disable VHT, mask MCS rates, etc
TLSV12_DESC=		Build with TLS v1.2 instead of TLS v1.0
IEEE80211AC_DESC=	Very High Throughput, AP mode (IEEE 802.11ac)
IEEE80211N_DESC=	High Throughput, AP mode (IEEE 802.11n)
IEEE80211R_DESC=	Fast BSS Transition (IEEE 802.11r-2008)
IEEE80211W_DESC=	Management Frame Protection (IEEE 802.11w)
IEEE8021X_EAPOL_DESC=	EAP over LAN support
DEBUG_FILE_DESC=	Support for writing debug log to a file
DEBUG_SYSLOG_DESC=	Send debug messages to syslog instead of stdout
PRIVSEP_DESC=		Privilege separation
DELAYED_MIC_DESC=	Mitigate TKIP attack, random delay on MIC errors
INTERWORKING_DESC=	Improve ext. network interworking (IEEE 802.11u)
HS20_DESC=		Hotspot 2.0
NO_ROAMING_DESC=	Disable roaming
P2P_DESC=		Peer-to-Peer support
TDLS_DESC=		Tunneled Direct Link Setup

DRV_DESC=		Driver options
BSD_DESC=		BSD net80211 interface
NDIS_DESC=		Windows NDIS interface
WIRED_DESC=		Wired ethernet interface
ROBOSWITCH_DESC=	Broadcom Roboswitch interface
TEST_DESC=		Development testing interface
NONE_DESC=		The 'no driver' interface, e.g. WPS ER only

EAP_DESC=		Extensible Authentication Protocols
TLS_DESC=		Transport Layer Security
PEAP_DESC=		Protected Extensible Authentication Protocol
TTLS_DESC=		Tunneled Transport Layer Security
MD5_DESC=		MD5 hash (deprecated, no key generation)
MSCHAPV2_DESC=		Microsoft CHAP version 2 (RFC 2759)
GTC_DESC=		Generic Token Card
LEAP_DESC=		Lightweight Extensible Authentication Protocol
OTP_DESC=		One-Time Password
PSK_DESC=		Pre-Shared key
FAST_DESC=		Flexible Authentication via Secure Tunneling
AKA_DESC=		Autentication and Key Agreement (UMTS)
AKA_PRIME_DESC=		AKA Prime variant (RFC 5448)
EKE_DESC=		Encrypted Key Exchange
SIM_DESC=		Subscriber Identity Module
IKEV2_DESC=		Internet Key Exchange version 2
PWD_DESC=		Shared password (RFC 5931)
PAX_DESC=		Password Authenticated Exchange
SAKE_DESC=		Shared-Secret Authentication & Key Establishment
GPSK_DESC=		Generalized Pre-Shared Key
TNC_DESC=		Trusted Network Connect

PRIVSEP_PLIST_FILES=	sbin/wpa_priv
DBUS_PLIST_FILES=	share/dbus-1/system-services/fi.w1.wpa_supplicant1.service \
			etc/dbus-1/system.d/dbus-wpa_supplicant.conf

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MNDIS} && ${PORT_OPTIONS:MPRIVSEP}
BROKEN=	Fails to compile with both NDIS and PRIVSEP
.endif

.if ${PORT_OPTIONS:MIEEE80211AC} && ${PORT_OPTIONS:MIEEE80211N}
BROKEN=	Fails to compile with both IEEE80211AC and IEEE80211N
.endif

.if ${PORT_OPTIONS:MSIM} || ${PORT_OPTIONS:MAKA} || ${PORT_OPTIONS:MAKA_PRIME}
LIB_DEPENDS+=	libpcsclite.so:devel/pcsc-lite
CFLAGS+=	-I${LOCALBASE}/include/PCSC
LDFLAGS+=	-L${LOCALBASE}/lib
.endif

.if ${PORT_OPTIONS:MDBUS}
LIB_DEPENDS+=	libdbus-1.so:devel/dbus
.endif

post-patch:
	@${CP} ${FILESDIR}/Packet32.[ch] ${FILESDIR}/ntddndis.h \
		${WRKSRC}/src/utils
	# Set driver(s)
.for item in BSD NDIS WIRED ROBOSWITCH TEST NONE
.  if ${PORT_OPTIONS:M${item}}
	@${ECHO_CMD} CONFIG_DRIVER_${item}=y >> ${CFG}
.  endif
.endfor
	# Set EAP protocol(s)
.for item in MD5 MSCHAPV2 TLS PEAP TTLS FAST GTC OTP PSK PWD PAX LEAP SIM \
	AKA AKA_PRIME SAKE GPSK TNC IKEV2 EKE
.  if ${PORT_OPTIONS:M${item}}
	@${ECHO_CMD} CONFIG_EAP_${item:tu}=y >> ${CFG}
.  endif
.endfor
.if ${PORT_OPTIONS:MSIM} || ${PORT_OPTIONS:MAKA} || ${PORT_OPTIONS:MAKA_PRIME}
	@${ECHO_CMD} CONFIG_PCSC=y >> ${CFG}
.endif
.for simple in WPS WPS_ER WPS_NFC WPS_UPNP PKCS12 SMARTCARD HT_OVERRIDES \
	VHT_OVERRIDES TLSV12 IEEE80211AC IEEE80211N IEEE80211R IEEE80211W \
	IEEE8021X_EAPOL \
	INTERWORKING DEBUG_FILE DEBUG_SYSLOG HS20 NO_ROAMING PRIVSEP P2P TDLS
.  if ${PORT_OPTIONS:M${simple}}
	@${ECHO_CMD} CONFIG_${simple}=y >> ${CFG}
.  endif
.endfor
.for item in READLINE PEERKEY
	@${ECHO_CMD} CONFIG_${item}=y >> ${CFG}
.endfor
.if ${PORT_OPTIONS:MIEEE80211AC} || ${PORT_OPTIONS:MIEEE80211N}
	@${ECHO_CMD} CONFIG_AP=y >> ${CFG}
.endif
.if ${PORT_OPTIONS:MGPSK}
	# GPSK desired, assume highest SHA desired too
	@${ECHO_CMD} CONFIG_EAP_GPSK_SHA256=y >> ${CFG}
.endif
.if ${PORT_OPTIONS:MWPS_NOREG}
	@${ECHO_CMD} CONFIG_WPS_REG_DISABLE_OPEN=y >> ${CFG}
.endif
.if ${PORT_OPTIONS:MDELAYED_MIC}
	@${ECHO_CMD} CONFIG_DELAYED_MIC_ERROR_REPORT=y >> ${CFG}
.endif
.if ${PORT_OPTIONS:MDBUS}
	@${ECHO_CMD} CONFIG_CTRL_IFACE_DBUS_NEW=y >> ${CFG}
	@${ECHO_CMD} CONFIG_CTRL_IFACE_DBUS_INTRO=y >> ${CFG}
.endif
	@${ECHO_CMD} CONFIG_OS=unix >> ${CFG}
	@${ECHO_CMD} CONFIG_CTRL_IFACE=unix >> ${CFG}
	@${ECHO_CMD} CONFIG_BACKEND=file >> ${CFG}
	@${ECHO_CMD} CONFIG_L2_PACKET=freebsd >> ${CFG}
	@${ECHO_CMD} CONFIG_TLS=openssl >> ${CFG}

do-install:
	(cd ${BUILD_WRKSRC} && ${INSTALL_PROGRAM} wpa_supplicant wpa_cli \
		wpa_passphrase ${STAGEDIR}${PREFIX}/sbin)
	${INSTALL_DATA} ${BUILD_WRKSRC}/wpa_supplicant.conf \
		${STAGEDIR}${PREFIX}/etc/wpa_supplicant.conf.sample

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${BUILD_WRKSRC} && \
		${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

do-install-PRIVSEP-on:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/wpa_priv ${STAGEDIR}${PREFIX}/sbin

do-install-DBUS-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/dbus-1/system-services/
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/dbus-1/system.d/
	${INSTALL_DATA} ${BUILD_WRKSRC}/dbus/fi.w1.wpa_supplicant1.service \
		${STAGEDIR}${PREFIX}/share/dbus-1/system-services/
	${INSTALL_DATA} ${BUILD_WRKSRC}/dbus/dbus-wpa_supplicant.conf \
		${STAGEDIR}${PREFIX}/etc/dbus-1/system.d/

.include <bsd.port.post.mk>
