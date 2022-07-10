PORTNAME=	wifibox-alpine
PORTVERSION=	20220712
CATEGORIES=	net

MAINTAINER=	pali.gabor@gmail.com
COMMENT=	Wifibox guest based on Alpine Linux

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC_scripts}/LICENSE

ONLY_FOR_ARCHS=	amd64
EXTRACT_ONLY=	${_DISTFILES:M*_GH0.tar.gz}

BUILD_DEPENDS=	patchelf>0:sysutils/patchelf \
		squashfs-tools>0:sysutils/squashfs-tools

.include "${.CURDIR}/flavors.mk"

.for flavor in ${_FLAVORS}
${flavor}_PKGNAMESUFFIX=	-${flavor}
.endfor

OPTIONS_DEFINE=			UDS_PASSTHRU
OPTIONS_SUB=			yes

OPTIONS_SINGLE=			COMPRESSION APPLICATION
OPTIONS_SINGLE_COMPRESSION=	COMP_GZIP COMP_LZO COMP_LZ4 COMP_XZ COMP_ZSTD
OPTIONS_SINGLE_APPLICATION=	APP_HOSTAPD APP_WPA_SUPPLICANT

OPTIONS_DEFAULT=		COMP_XZ APP_WPA_SUPPLICANT UDS_PASSTHRU

COMP_GZIP_DESC=		gzip
COMP_LZO_DESC=		lzo
COMP_LZ4_DESC=		lz4
COMP_XZ_DESC=		xz
COMP_ZSTD_DESC=		zstd

UDS_PASSTHRU_DESC=		Control socket pass-through
APP_HOSTAPD_DESC=		Access Point (hostapd)
APP_WPA_SUPPLICANT_DESC=	WPA Supplicant (wpa_supplicant)

UDS_PASSTHRU_RUN_DEPENDS=	socat>0:net/socat

.if ${FLAVOR:U} == default
OPTIONS_GROUP=		FIRMWARE EXTRAS
OPTIONS_GROUP_FIRMWARE=	FW_ATH10K FW_ATH11K FW_ATMEL FW_B43 FW_B43LEGACY FW_BRCM\
			FW_IPW2100 FW_IPW2200 FW_IWL3945 FW_IWL4965 FW_IWLWIFI\
			FW_MEDIATEK FW_MARVELL FW_RT61 FW_RTLWIFI FW_RTW88 FW_TI
OPTIONS_GROUP_EXTRAS=	XX_DRIVER_WL XX_DRIVER_RTW89

OPTIONS_DEFAULT+=	FW_ATH10K FW_ATH11K FW_BRCM FW_IWLWIFI FW_MEDIATEK\
			FW_MARVELL FW_RT61 FW_RTLWIFI FW_RTW88

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
FW_TI_DESC=		Texas Instruments WL1xxx 802.11b/g/n

XX_DRIVER_WL_DESC=	Broadcom 802.11 STA driver (+ firmware, exclusive)
XX_DRIVER_RTW89_DESC=	Realtek 802.11ax driver (+ firmware)
.endif

_GITHUB_SITE=	https://github.com/pgj/freebsd-wifibox-alpine/releases/download

USE_GITHUB=	nodefault
GH_ACCOUNT=	pgj
GH_PROJECT=	freebsd-wifibox-alpine:scripts
GH_TAGNAME=	f8fd8cdb1a0e545272917fe1dc1f9544cf74e383:scripts

ALPINE_VERSION=	3.16.0
ALPINE_DATE=	2022.07.09
_ALPINE_VER=	${ALPINE_VERSION:C@([0-9]+)\.([0-9]+).*@\1.\2@}

.if defined(ALPINE_DATE)
_SNAPSHOT=	${ALPINE_DATE:S/./-/g}
_ALPINE_SITE=	https://mirror.fit.cvut.cz/alpine/snapshots/${_SNAPSHOT}/v${_ALPINE_VER}
.else
_ALPINE_SITE=	https://mirror.fit.cvut.cz/alpine/v${_ALPINE_VER}
.endif

_LINUXFW_SITE=	https://git.kernel.org/pub/scm/linux/kernel/git/firmware/
_LINUXFW_TAG=	20220708
_LINUXFW=	linux-firmware-${_LINUXFW_TAG}

MASTER_SITES+=	${_ALPINE_SITE}/releases/x86_64/:rootfs \
		${_ALPINE_SITE}/main/x86_64/:main_packages \
		${_ALPINE_SITE}/community/x86_64/:community_packages \
		${_GITHUB_SITE}/packages/:custom_packages \
		${_LINUXFW_SITE}/linux-firmware.git/snapshot/:linux_firmware \
		https://sources.openwrt.org/:openwrt \
		https://lwfinger.com/b43-firmware/:b43 \
		https://thekelleys.org.uk/atmel/:atmel \
		https://github.com/openwrt/mt76/archive/:mt76

_MINIROOTFS=	alpine-minirootfs-${ALPINE_VERSION}-x86_64.tar.gz
_PACKAGES=	baselayout-3.2.0-r19:wifibox \
		busybox-1.35.0-r0:wifibox \
		ifupdown-ng-0.12.1-r0:wifibox \
		iptables-1.8.8-r0:wifibox \
		iw-5.16-r0:community \
		libcrypto1.1-1.1.1o-r0 \
		libmnl-1.0.5-r0 \
		libnftnl-1.2.1-r0 \
		libnl3-3.5.0-r0 \
		libssl1.1-1.1.1o-r0 \
		linux-lts-5.15.53-r0:wifibox \
		musl-1.2.3-r0 \
		openrc-0.44.10-r0:wifibox

.if !defined(_GUEST_MEM)
_GUEST_MEM=	64M
.endif

_BOOT_SERVICES=		networking urandom bootmisc modules hostname hwclock sysctl syslog
_DEFAULT_SERVICES=	acpid crond iptables udhcpd
_SYSINIT_SERVICES=	devfs dmesg hwdrivers mdev

_ATMEL_FIRMWARE=	atmel-firmware-1.3
_B43LEGACY_FIRMWARE=	wl_apsta-3.130.20.0
_B43_FIRMWARE=		broadcom-wl-6.30.163.46
_IPW2100_FIRMWARE=	ipw/ipw2100-1.3 \
			ipw/ipw2100-1.3-i
_IPW2200_FIRMWARE=	iwi/ipw2200-bss \
			iwi/ipw2200-ibss
_MT76_FIRMWARE=		b6e865e2cc7080c91ec34a9dd3648d25f7ce04c6

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

.if ${PORT_OPTIONS:MUDS_PASSTHRU} || make(makesum)
_PACKAGES+=		socat-1.7.4.3-r0:wifibox \
			uds_passthru-0.1.0-r0:wifibox
.endif

.if ${PORT_OPTIONS:MAPP_WPA_SUPPLICANT}
_VIRTFS_MOUNTS=		app_config:/etc/wpa_supplicant
_BOOT_SERVICES+=	wpa_supplicant
_ETC_SRCS=		etc/wpa_supplicant
.endif

.if ${PORT_OPTIONS:MAPP_WPA_SUPPLICANT} || make(makesum)
_PACKAGES+=		pcsc-lite-libs-1.9.6-r0 \
			wpa_supplicant-2.10-r0:wifibox
.endif

.if ${PORT_OPTIONS:MAPP_HOSTAPD}
_VIRTFS_MOUNTS=		app_config:/etc/hostapd
_BOOT_SERVICES+=	hostapd
_ETC_SRCS=		etc/hostapd
.endif

.if ${PORT_OPTIONS:MAPP_HOSTAPD} || make(makesum)
_PACKAGES+=		hostapd-2.10-r1:wifibox
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
LFW_TI_FILES=		ti-connectivity

.for fw_opt in ${PORT_OPTIONS:MFW_*}
.if defined(L${fw_opt}_FILES)
LINUX_FIRMWARE+=	${L${fw_opt}_FILES}
.endif
.endfor

.if ${FLAVOR:U} == iwlwifi
_GUEST_MEM=	45M
.endif

.if ${PORT_OPTIONS:MFW_RTW88} || make(makesum)
_PACKAGES+=	rtl8821ce-20220601-r0:wifibox
.endif

.if ${PORT_OPTIONS:MXX_DRIVER_WL} || make(makesum)
_PACKAGES+=	broadcom-wl-6.30.223.271-r4:wifibox
.endif

.if ${PORT_OPTIONS:MXX_DRIVER_RTW89} || make(makesum)
_PACKAGES+=	rtw89-20220630-r0:wifibox
.endif

.if !empty(LINUX_FIRMWARE)
_LINUXFWFILE=	${_LINUXFW}.tar.gz
_LINUXFWDIR=	${WRKDIR}/${_LINUXFW}
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

.if ${PORT_OPTIONS:MFW_ATMEL}
DISTFILES+=	${_ATMEL_FIRMWARE}.tar.gz:atmel
.endif

.if ${PORT_OPTIONS:MFW_B43LEGACY}
DISTFILES+=	${_B43LEGACY_FIRMWARE}.o:openwrt
.endif

.if ${PORT_OPTIONS:MFW_B43}
DISTFILES+=	${_B43_FIRMWARE}.tar.bz2:b43
EXTRACT_ONLY+=	${_B43_FIRMWARE}.tar.bz2
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

.if ${PORT_OPTIONS:MFW_MEDIATEK}
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
	${PRINTF} "cpus=1\nmemory=${_GUEST_MEM}\n" \
		> ${STAGEDIR}${PREFIX}/share/wifibox/bhyve.conf

WRKSRC=		${WRKSRC_scripts}
MAKE_ARGS+=	VERSION=${PORTVERSION} \
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

.include <bsd.port.mk>
