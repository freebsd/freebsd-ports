PORTNAME=	wifibox-alpine
PORTVERSION=	20230926
PORTREVISION=	1
CATEGORIES=	net

MAINTAINER=	pali.gabor@gmail.com
COMMENT=	Wifibox guest based on Alpine Linux
WWW=		https://github.com/pgj/freebsd-wifibox-alpine

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC_scripts}/LICENSE

ONLY_FOR_ARCHS=	amd64
EXTRACT_ONLY=	${_DISTFILES:M*_GH0.tar.gz}

BUILD_DEPENDS=	gtar>0:archivers/gtar \
		patchelf>0:sysutils/patchelf \
		squashfs-tools-ng>0:sysutils/squashfs-tools-ng

.include "${.CURDIR}/flavors.mk"

.for flavor in ${_FLAVORS}
${flavor}_PKGNAMESUFFIX=	-${flavor}
.endfor

OPTIONS_DEFINE=			UDS_PASSTHRU IPV6
OPTIONS_SUB=			yes

OPTIONS_SINGLE=			COMPRESSION APPLICATION KERNEL
OPTIONS_SINGLE_COMPRESSION=	COMP_GZIP COMP_LZ4 COMP_LZO COMP_XZ COMP_ZSTD
OPTIONS_SINGLE_APPLICATION=	APP_HOSTAPD APP_WPA_SUPPLICANT
OPTIONS_SINGLE_KERNEL=		KERN_LTS KERN_EDGE

OPTIONS_GROUP=			EXTRAS
OPTIONS_GROUP_EXTRAS=		XX_MDNS XX_FORWARDING XX_TCPDUMP

OPTIONS_DEFAULT=		COMP_XZ APP_WPA_SUPPLICANT UDS_PASSTHRU KERN_LTS IPV6

COMP_GZIP_DESC=		gzip
COMP_LZ4_DESC=		lz4
COMP_LZO_DESC=		lzo
COMP_XZ_DESC=		xz
COMP_ZSTD_DESC=		zstd

UDS_PASSTHRU_DESC=		Control socket pass-through
IPV6_DESC=			IPv6 support
APP_HOSTAPD_DESC=		Access Point (hostapd)
APP_WPA_SUPPLICANT_DESC=	WPA Supplicant (wpa_supplicant)
XX_MDNS_DESC=			mDNS Responder Daemon
XX_FORWARDING_DESC=		User-space forwarding
XX_TCPDUMP_DESC=		Packet analysis with tcpdump

KERN_LTS_DESC=			Linux LTS (6.1.x)
KERN_EDGE_DESC=			Linux edge (6.5.x)

UDS_PASSTHRU_RUN_DEPENDS=	socat>0:net/socat

.if ${FLAVOR:U} == default
OPTIONS_GROUP+=		FIRMWARE
OPTIONS_GROUP_FIRMWARE=	FW_ATH10K FW_ATH11K FW_ATMEL FW_B43 FW_B43LEGACY FW_BRCM\
			FW_IPW2100 FW_IPW2200 FW_IWL3945 FW_IWL4965 FW_IWLWIFI\
			FW_MEDIATEK FW_MARVELL FW_RT61 FW_RTLWIFI FW_RTW88 FW_RTW89\
			FW_TI
OPTIONS_GROUP_EXTRAS+=	XX_DRIVER_WL

OPTIONS_DEFAULT+=	FW_ATH10K FW_ATH11K FW_BRCM FW_IWLWIFI FW_MEDIATEK\
			FW_MARVELL FW_RT61 FW_RTLWIFI FW_RTW88 FW_RTW89

FW_ATH10K_DESC=		Qualcomm Atheros 802.11ac
FW_ATH11K_DESC=		Qualcomm Atheros 802.11ax
FW_ATMEL_DESC=		Atmel at76c50x 802.11b
FW_B43_DESC=		Broadcom B43xx 802.11a/b/g/n
FW_B43LEGACY_DESC=	Broadcom B43xx 802.11b (legacy)
FW_BRCM_DESC=		Broadcom 802.11n
FW_IWL3945_DESC=	Intel(R) PRO/Wireless 3945ABG 802.11a/b/g
FW_IWL4965_DESC=	Intel(R) Wireless WiFi 4965AGN 802.11a/b/g/n
FW_IWLWIFI_DESC=	Intel(R) Wireless WiFi 802.11a/b/g/n
FW_IPW2100_DESC=	Intel(R) PRO/Wireless 2100 802.11a/b
FW_IPW2200_DESC=	Intel(R) PRO/Wireless 2200 802.11b/g/n
FW_MEDIATEK_DESC=	MediaTek MT76xxx 802.11n, MT79xx 802.11ax
FW_MARVELL_DESC=	Marvell 88W8xxx (TopDog) 802.11b/g/n
FW_RT61_DESC=		Ralink RT2xxx (RT61) 802.11a/b/g
FW_RTLWIFI_DESC=	Realtek 802.11n
FW_RTW88_DESC=		Realtek 802.11ac
FW_RTW89_DESC=		Realtek 802.11ax
FW_TI_DESC=		Texas Instruments WL1xxx 802.11b/g/n

XX_DRIVER_WL_DESC=	Broadcom 802.11 STA driver (+ firmware, exclusive)
.endif

_GITHUB_SITE=	https://github.com/pgj/freebsd-wifibox-alpine/releases/download

USE_GITHUB=	nodefault
GH_ACCOUNT=	pgj
GH_PROJECT=	freebsd-wifibox-alpine:scripts
GH_TAGNAME=	2646128d92561b62fe4ea863aee9cad4b5fa8eda:scripts

ALPINE_VERSION=	3.18.3
ALPINE_DATE=	2023.09.16

_ALPINE_VER=	${ALPINE_VERSION:C@([0-9]+)\.([0-9]+).*@\1.\2@}
_ALPINE_SITE1=	https://dl-cdn.alpinelinux.org/alpine/v${_ALPINE_VER}

_ALPINE_BASE=	https://mirror.fel.cvut.cz

.if defined(ALPINE_DATE)
_SNAPSHOT=     	${ALPINE_DATE:S/./-/g}
_ALPINE_SITE2=  ${_ALPINE_BASE}/alpine/snapshots/${_SNAPSHOT}/v${_ALPINE_VER}
.else
_ALPINE_SITE2=	${_ALPINE_BASE}/alpine/v${_ALPINE_VER}
.endif

_LINUXFW_SITE=	https://git.kernel.org/pub/scm/linux/kernel/git/firmware/
_LINUXFW_TAG=	20230919
_LINUXFW=	linux-firmware-${_LINUXFW_TAG}

MASTER_SITES+=	${_ALPINE_SITE1}/releases/x86_64/:rootfs \
		${_ALPINE_SITE2}/main/x86_64/:main_packages \
		${_ALPINE_SITE2}/community/x86_64/:community_packages \
		${_GITHUB_SITE}/packages/:custom_packages \
		${_LINUXFW_SITE}/linux-firmware.git/snapshot/:linux_firmware \
		https://sources.openwrt.org/:openwrt \
		https://lwfinger.com/b43-firmware/:b43 \
		https://thekelleys.org.uk/atmel/:atmel \
		https://github.com/openwrt/mt76/archive/:mt76

_MINIROOTFS=	alpine-minirootfs-${ALPINE_VERSION}-x86_64.tar.gz
_PACKAGES=	baselayout-3.4.3-r1:wifibox \
		busybox-1.36.1-r1:wifibox \
		ifupdown-ng-0.12.1-r1:wifibox \
		iptables-1.8.9-r1:wifibox \
		iw-5.19-r1 \
		libcap2-2.69-r0 \
		libcap-utils-2.69-r0 \
		libcrypto3-3.1.2-r0 \
		libmnl-1.0.5-r1 \
		libnftnl-1.2.5-r1 \
		libnl3-3.7.0-r1 \
		libssl3-3.1.2-r0 \
		musl-1.2.4-r1 \
		openrc-0.48-r0:wifibox

_BOOT_SERVICES=		bootmisc defaults modules hostname hwclock networking sysctl \
			syslog urandom
_DEFAULT_SERVICES=	acpid crond iptables udhcpd
_SYSINIT_SERVICES=	devfs dmesg hwdrivers mdev

_ATMEL_FIRMWARE=	atmel-firmware-1.3
_B43LEGACY_FIRMWARE=	wl_apsta-3.130.20.0
_B43_FIRMWARE=		broadcom-wl-6.30.163.46
_IPW2100_FIRMWARE=	ipw/ipw2100-1.3 \
			ipw/ipw2100-1.3-i
_IPW2200_FIRMWARE=	iwi/ipw2200-bss \
			iwi/ipw2200-ibss
_MT76_FIRMWARE=		c19b62fe6b68c3244e150248f250369504d3fd74

_LINUX64_KMOD!=		(kldstat -qn linux64 && echo "found") || echo ""

.if empty(_LINUX64_KMOD)
IGNORE=	needs the linux64 kernel module to build
.endif

pre-everything::
.if !defined(FIRMWARE_FILES)
	@${ECHO_MSG} "===> NOTICE:"
	@${ECHO_MSG}
	@${ECHO_MSG} "Use the FIRMWARE_FILES make(1) variable to keep only the firmware files that"
	@${ECHO_MSG} "are used by the driver to reduce the size of the disk image."
	@${ECHO_MSG}
	@sleep 1
.endif

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MUDS_PASSTHRU}
_BOOT_SERVICES+=	uds_passthru
.endif

.if ${PORT_OPTIONS:MIPV6}
_BOOT_SERVICES+=	ip6tables radvd
.endif

.if (${PORT_OPTIONS:MUDS_PASSTHRU} && empty(PORT_OPTIONS:MXX_FORWARDING)) \
	|| make(makesum) || make(fetch-url-list-int)
_PACKAGES+=		socat-1.7.4.4-r1:wifibox
.endif

.if ${PORT_OPTIONS:MXX_FORWARDING} || make(makesum) || make(fetch-url-list-int)
_PACKAGES+=		socat-with-udp-1.7.4.4-r1:wifibox
.endif

.if ${PORT_OPTIONS:MUDS_PASSTHRU} || make(makesum) || make(fetch-url-list-int)
_PACKAGES+=		uds_passthru-0.1.1-r2:wifibox
.endif

.if ${PORT_OPTIONS:MIPV6} || make(makesum) || make(fetch-url-list-int)
_PACKAGES+=		radvd-2.19-r0:wifibox
.endif

.if ${PORT_OPTIONS:MIPV6} && ${PORT_OPTIONS:MAPP_WPA_SUPPLICANT} \
	|| make(makesum) || make(fetch-url-list-int)
_PACKAGES+=		dhcpcd-10.0.2-r0:wifibox
.endif

.if ${PORT_OPTIONS:MAPP_WPA_SUPPLICANT}
_VIRTFS_MOUNTS=		app_config:/etc/wpa_supplicant
_BOOT_SERVICES+=	wpa_supplicant
_ETC_SRCS=		etc/wpa_supplicant
.if ${PORT_OPTIONS:MIPV6}
_ETC_SRCS+=		etc/optional/ipv6/wpa_supplicant
.endif
.endif

.if ${PORT_OPTIONS:MAPP_WPA_SUPPLICANT} || make(makesum) || make(fetch-url-list-int)
_PACKAGES+=		pcsc-lite-libs-1.9.9-r3 \
			wpa_supplicant-2.10-r5:wifibox
.endif

.if ${PORT_OPTIONS:MAPP_HOSTAPD}
_VIRTFS_MOUNTS=		app_config:/etc/hostapd
_BOOT_SERVICES+=	hostapd
_ETC_SRCS=		etc/hostapd
.if ${PORT_OPTIONS:MIPV6}
_ETC_SRCS+=		etc/optional/ipv6/hostapd
.endif
.endif

.if ${PORT_OPTIONS:MAPP_HOSTAPD} || make(makesum) || make(fetch-url-list-int)
_PACKAGES+=		hostapd-2.10-r3:wifibox
.endif

.if ${PORT_OPTIONS:MXX_MDNS}
_DEFAULT_SERVICES+=	mdnsresponderposix
_ETC_SRCS+=		etc/optional/mdns
.endif

.if ${PORT_OPTIONS:MXX_MDNS} || make(makesum) || make(fetch-url-list-int)
_PACKAGES+=		mbedtls-2.28.4-r0 \
			mDNSResponder-1790.80.10-r1:wifibox
.endif

.if ${PORT_OPTIONS:MXX_FORWARDING}
_BOOT_SERVICES+=	forwarding
_ETC_SRCS+=		etc/optional/forwarding
.endif

.if ${PORT_OPTIONS:MXX_FORWARDING} || make(makesum) || make(fetch-url-list-int)
_PACKAGES+=		forwarding-0.1.0-r2:wifibox
.endif

.if ${PORT_OPTIONS:MXX_TCPDUMP} || make(makesum) || make(fetch-url-list-int)
_PACKAGES+=		libpcap-1.10.4-r1 \
			tcpdump-4.99.4-r1
.endif

.if ${PORT_OPTIONS:MKERN_LTS} || make(makesum) || make(fetch-url-list-int)
_PACKAGES+=		linux-lts-6.1.54-r0:wifibox
.endif

.if ${PORT_OPTIONS:MKERN_EDGE} || make(makesum) || make(fetch-url-list-int)
_PACKAGES+=		linux-edge-6.5.4-r0:wifibox
.endif

.if ${PORT_OPTIONS:MXX_MDNS} || ${PORT_OPTIONS:MXX_FORWARDING}
PKGMESSAGE=		pkg-message.iptables
.endif

.for flavor in ${_FLAVORS}
.if ${FLAVOR:U} == ${flavor}
PORT_OPTIONS+=		FW_${flavor:tu}
.endif
.endfor

DIST_SUBDIR=	wifibox-alpine
DISTFILES+=	${_MINIROOTFS}:rootfs

LFW_ATH10K_FILES=	ath10k
LFW_ATH11K_FILES=	ath11k
LFW_BRCM_FILES=		brcm
LFW_IWL3945_FILES=	iwlwifi-3945-*.ucode
LFW_IWL4965_FILES=	iwlwifi-4965-*.ucode
LFW_IWLWIFI_FILES=	iwlwifi-*
LFW_MEDIATEK_FILES=	mediatek
LFW_MARVELL_FILES=	mwl*
LFW_RT61_FILES=		rt*.bin
LFW_RTLWIFI_FILES=	rtlwifi
LFW_RTW88_FILES=	rtw88
LFW_RTW89_FILES=	rtw89
LFW_TI_FILES=		ti-connectivity

.for fw_opt in ${PORT_OPTIONS:MFW_*}
.if defined(L${fw_opt}_FILES)
LINUX_FIRMWARE+=	${L${fw_opt}_FILES}
.endif
.endfor

.if ${PORT_OPTIONS:MFW_RTW88} && ${PORT_OPTIONS:MKERN_LTS} \
	|| make(makesum) || make(fetch-url-list-int)
_PACKAGES+=	rtl8821ce-20230915-r1:wifibox \
		rtw88-20230913-r1:wifibox
.endif

.if ${PORT_OPTIONS:MFW_RTW88} && ${PORT_OPTIONS:MKERN_EDGE} \
	|| make(makesum) || make(fetch-url-list-int)
_PACKAGES+=	rtl8821ce-edge-20230915-r1:wifibox \
		rtw88-edge-20230913-r1:wifibox
.endif

.if ${PORT_OPTIONS:MFW_RTW89} && ${PORT_OPTIONS:MKERN_LTS} \
	|| make(makesum) || make(fetch-url-list-int)
_PACKAGES+=	rtw89-20230913-r1:wifibox
.endif

.if ${PORT_OPTIONS:MFW_RTW89} && ${PORT_OPTIONS:MKERN_EDGE} \
	|| make(makesum) || make(fetch-url-list-int)
_PACKAGES+=	rtw89-edge-20230913-r1:wifibox
.endif

.if ${PORT_OPTIONS:MXX_DRIVER_WL} && ${PORT_OPTIONS:MKERN_LTS} \
	|| make(makesum) || make(fetch-url-list-int)
_PACKAGES+=	broadcom-wl-6.30.223.271-r13:wifibox
.endif

.if ${PORT_OPTIONS:MXX_DRIVER_WL} && ${PORT_OPTIONS:MKERN_EDGE} \
	|| make(makesum) || make(fetch-url-list-int)
_PACKAGES+=	broadcom-wl-edge-6.30.223.271-r13:wifibox
.endif

.if !empty(LINUX_FIRMWARE)
_LINUXFWFILE=	${_LINUXFW}.tar.gz
_LINUXFWDIR=	${WRKDIR}/${_LINUXFW}
.endif

.if !empty(LINUX_FIRMWARE) || make(makesum)
DISTFILES+=	${_LINUXFWFILE}:linux_firmware
.endif

.for package in ${_PACKAGES}
.if ${package:M*\:wifibox}
DISTFILES+=	${package:C@^([^:]*):wifibox$@\1@}.apk:custom_packages
.elif ${package:M*\:community}
DISTFILES+=	${package:C@^([^:]*):community$@\1@}.apk:community_packages
.else
DISTFILES+=	${package:C@^([^:]*):wifibox$@\1@}.apk:main_packages
.endif
_APK_FILES+=	${_DISTDIR}/${package:C@^([^:]*):.*$@\1@}.apk
.endfor

_GUESTDIR=	${WRKSRC}/guest
_ETCDIR=	${_GUESTDIR}/etc
_FIRMWAREDIR=	${_GUESTDIR}/lib/firmware

.if ${PORT_OPTIONS:MFW_ATMEL} || make(makesum)
DISTFILES+=	${_ATMEL_FIRMWARE}.tar.gz:atmel
.endif

.if ${PORT_OPTIONS:MFW_B43LEGACY} || make(makesum)
DISTFILES+=	${_B43LEGACY_FIRMWARE}.o:openwrt
.endif

.if ${PORT_OPTIONS:MFW_B43}
EXTRACT_ONLY+=	${_B43_FIRMWARE}.tar.bz2
.endif

.if ${PORT_OPTIONS:MFW_B43} || make(makesum)
DISTFILES+=	${_B43_FIRMWARE}.tar.bz2:b43
.endif

.if ${PORT_OPTIONS:MFW_B43*}
BUILD_DEPENDS+=		b43-fwcutter>0:sysutils/b43-fwcutter
FW_B43_TARGETDIR=	${_FIRMWAREDIR}/b43
FW_B43_FIRMWARE=	${WRKDIR}/${_B43_FIRMWARE}.wl_apsta.o
FW_B43LEGACY_TARGETDIR=	${_FIRMWAREDIR}/b43legacy
FW_B43LEGACY_FIRMWARE=	${_DISTDIR}/${_B43LEGACY_FIRMWARE}.o
.endif

.if ${PORT_OPTIONS:MFW_IPW2*} && !exists(${SRC_BASE}/sys/Makefile)
IGNORE= requires kernel source files in SRC_BASE=${SRC_BASE}
.endif

.if ${PORT_OPTIONS:MFW_MEDIATEK} || make(makesum)
DISTFILES+=	${_MT76_FIRMWARE}.zip:mt76
.endif

pre-build:
.if ${PORT_OPTIONS:MAPP_WPA_SUPPLICANT}
	${MKDIR} ${_ETCDIR}/wpa_supplicant
.endif
.if ${PORT_OPTIONS:MAPP_HOSTAPD}
	${MKDIR} ${_ETCDIR}/hostapd
.endif
	${MKDIR} ${_FIRMWAREDIR}
.for fw in ${PORT_OPTIONS:MFW_B43*}
.if ${fw}
	(_TARGETDIR=${${fw}_TARGETDIR}; \
	${MKDIR} $$_TARGETDIR; \
	${LOCALBASE}/bin/b43-fwcutter -w $$_TARGETDIR ${${fw}_FIRMWARE}; \
	${FIND} $$_TARGETDIR -mindepth 2 -type f -exec ${MV} {} $$_TARGETDIR \; ; \
	${FIND} $$_TARGETDIR -type d -delete)
.endif
.endfor
.if ${PORT_OPTIONS:MFW_ATMEL}
	${TAR} -xf ${_DISTDIR}/${_ATMEL_FIRMWARE}.tar.gz \
		-C ${_FIRMWAREDIR} --strip-components 2 \
		*/images/atmel_*.bin
.endif
.for fw in ${PORT_OPTIONS:MFW_IPW2*}
.for fw_file in ${${fw:C@FW@@}_FIRMWARE}
	uudecode -p ${SRC_BASE}/sys/contrib/dev/${fw_file}.fw.uu \
		> ${_FIRMWAREDIR}/${fw_file:C@^[^/]*/(.*)@\1@}.fw
.endfor
.endfor
.for fw_files in ${LINUX_FIRMWARE}
	${TAR} -xf ${_DISTDIR}/${_LINUXFWFILE} \
		-C ${_FIRMWAREDIR} --strip-components 1 \
		*/${fw_files}
.endfor
.if ${PORT_OPTIONS:MFW_MEDIATEK}
	${TAR} -xf ${_DISTDIR}/${_MT76_FIRMWARE}.zip \
		-C ${_FIRMWAREDIR} --strip-components 2 \
		*/firmware/mt76??_e?.bin
.endif

post-install:
.if empty(PORT_OPTIONS:MUDS_PASSTHRU)
	${RM} ${STAGEDIR}${PREFIX}/etc/wifibox/appliance/uds_passthru.conf.sample
.endif
.if ${PORT_OPTIONS:MAPP_HOSTAPD} && ${PORT_OPTIONS:MUDS_PASSTHRU}
	${MKDIR} ${STAGEDIR}/var/run/hostapd
.endif

WRKSRC=		${WRKSRC_scripts}
MAKE_ARGS+=	VERSION=${PORTVERSION} \
		MANDIR="${STAGEDIR}${PREFIX}/share/man" \
		MINIROOTFS=${_DISTDIR}/${_MINIROOTFS} \
		PACKAGES="${_APK_FILES}" \
		BOOT_SERVICES="${_BOOT_SERVICES}" \
		DEFAULT_SERVICES="${_DEFAULT_SERVICES}" \
		SYSINIT_SERVICES="${_SYSINIT_SERVICES}" \
		ETC_SRCS="${_ETC_SRCS}" \
		EXTRA_VIRTFS_MOUNTS="${_VIRTFS_MOUNTS}" \
		SQUASHFS_COMP=${PORT_OPTIONS:MCOMP_*:S/COMP_//:tl}

.if defined(FIRMWARE_FILES)
MAKE_ARGS+=	FIRMWARE_FILES=${FIRMWARE_FILES}
.endif

.if make(check-alpine-packages)
_APK_FETCH!=	${MAKE} fetch-urlall-list | ${GREP} apk | ${GREP} -v distcache
.endif

check-alpine-packages:
.for apk in ${_APK_FETCH}
	@${ECHO} -n "${apk:C@^.*/([0-9A-za-z\._-]*)@\1@} (${apk})..."
	@${FETCH_CMD} -s ${apk} > /dev/null
	@${ECHO} "OK"
.endfor

.include <bsd.port.mk>
