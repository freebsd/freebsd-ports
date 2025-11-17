PORTNAME=	wifi-firmware-${FWDRV}-kmod
PORTVERSION=	${FWDRV_VERSION}
PORTREVISION?=	2
CATEGORIES=	net
MASTER_SITES=	https://git.kernel.org/pub/scm/linux/kernel/git/firmware/linux-firmware.git/plain/ \
		https://fra.source.kernel.org/pub/scm/linux/kernel/git/firmware/linux-firmware.git/plain/ \
		https://sea.source.kernel.org/pub/scm/linux/kernel/git/firmware/linux-firmware.git/plain/ \
		https://sg2.source.kernel.org/pub/scm/linux/kernel/git/firmware/linux-firmware.git/plain/ \
		https://sto.source.kernel.org/pub/scm/linux/kernel/git/firmware/linux-firmware.git/plain/ \
		https://tor.source.kernel.org/pub/scm/linux/kernel/git/firmware/linux-firmware.git/plain/

MAINTAINER=	bz@FreeBSD.org
COMMENT=	Firmware modules for the ${FWDRV} (${FLAVOR}) WiFi NIC driver
WWW?=		https://git.kernel.org/pub/scm/linux/kernel/git/firmware/linux-firmware.git/tree/${FWSUBDIR}

FWDRV_VERSION?=	0
FWDRV?=		base

LICENSE_NAME?=	firmware license (${FWDRV})
LICENSE_PERMS?=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

EXTRACT_SUFX=
DISTURL_SUFFIX?=	?h=${PORTVERSION}

# Sanity checks
.if !defined(FWDRV) || !defined(FWSUBDIR) || !defined(FWSUBS) || \
	!defined(FWDRV_VERSION) || \
	!defined(LICENSE_NAME) || !defined(LICENSE_FILE) || \
	!defined(DISTFILES_${FWDRV}) || !defined(DISTFILES_${FWDRV}_lic) || \
	!defined(BASEDIR) || !defined(WHENCE_REGEX)
IGNORE=	is a metaport or misconfigured child port; there is nothing to build
.endif

FILESDIR=	${BASEDIR}/files

LICENSE_COMB=	multi
LICENSE=	primary whence

# Port primary license.
LICENSE_FILE_primary=	${WRKSRC}/${LICENSE_FILE}
LICENSE_NAME_primary=	${LICENSE_NAME}
LICENSE_PERMS_primary=	${LICENSE_PERMS}

# Add WHENCE file next to license where it makes sense despite not being a license.
LICENSE_NAME_whence=	Origin and licensing information for linux-firmware files
LICENSE_FILE_whence=	${WRKSRC}/WHENCE
LICENSE_PERMS_whence=	${LICENSE_PERMS}
#PLIST_FILES+=	${_LICENSE_DIR}/WHENCE

# Add extra license files.
.if "${DISTFILES_${FLAVOR}_lic}"
.for _n in ${DISTFILES_${FLAVOR}_lic:range}
LICENSE+=			extra${_n}
LICENSE_FILE_extra${_n}=	${WRKSRC}/lic/${DISTFILES_${FLAVOR}_lic:[${_n}]:C@(^[^?]*)${DISTURL_SUFFIX:Q}@\1@:S,/,_,g}
LICENSE_NAME_extra${_n}=	${LICENSE_NAME} (extra fw license)
LICENSE_PERMS_extra${_n}=	${LICENSE_PERMS}
.endfor
.endif

PLIST=		${WRKDIR}/PLIST

# Split things into the full package (driver name) and more specific flavors.
FLAVORS=	${FWDRV} \
		${FWSUBS}

# Generate the conflicts list.
.for f in ${FWSUBS}
${FWDRV}_CONFLICTS_INSTALL+=	${PORTNAME}-${f}
${f}_PKGNAMESUFFIX=		-${f}
${f}_CONFLICTS_INSTALL=		${PORTNAME}
.endfor

DISTFILES=	${DISTFILES_${FLAVOR}:O:u} \
		${DISTFILES_${FLAVOR}_lic} \
		${LICENSE_FILE}${DISTURL_SUFFIX} \
		WHENCE${DISTURL_SUFFIX}

DIST_SUBDIR=	linux-firmware/${FWDRV}fw
EXTRACT_ONLY=

.if !defined(NOT_FOR_ARCHS)
ONLY_FOR_ARCHS?=	aarch64 amd64 i386
ONLY_FOR_ARCHS_REASON=	LinuxKPI driver only available for these architectures
.endif

USES=		uidfix

.include <bsd.port.pre.mk>

# src.git main 479905a1ed26c54ef29cdff65cf25f7feade654b (stable/14 2ca7b03d6275)
# allows direct loading of firmware files.
# We write a PLIST file so we can then simply use COPYTREE_SHARE with adjusted
# permissions to copy the files over.
.if (${OSVERSION} < 1402000) || (${OSVERSION} >= 1500000 && ${OSVERSION} < 1500014)
# For 13.5, which is the last supported release before plain firmware loading is
# implemented, we did ship firmware in src/ still so there is no need to build.
# Also mtw (mt7601u) was never in a version earlier than this.
# XXX remove comment after April 2026 when 13.5 goes out of support as well.
IGNORE=		Not supported for this osversion.
.endif

BOOT_LOADERCONFD=	/boot/loader.conf.d
BOOTFWDIR?=	/boot/firmware
_SHAREMODE=	0444
NO_BUILD=	yes

post-extract:
	@${MKDIR} ${WRKSRC}/fw
	@${MKDIR} ${WRKSRC}/lic
	# Deal with supplementary licenses files.
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${LICENSE_FILE}${DISTURL_SUFFIX} ${WRKSRC}/${LICENSE_FILE}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/WHENCE${DISTURL_SUFFIX} ${WRKSRC}/WHENCE.in
	@${SED} -e "s@%%XXX%%@${WHENCE_REGEX:Q}@g" ${FILESDIR}/WHENCE.awk.in > ${WRKSRC}/WHENCE.awk
	@${AWK} -f ${WRKSRC}/WHENCE.awk ${WRKSRC}/WHENCE.in > ${WRKSRC}/WHENCE
	# Do we need to set a tunable?
	# At the moment we consider these temporary hacks.
	# Otherwise we need a better way to express this per-port/-flavor.
.if defined(COMPAT_LINUXKPI_SKB_MEM_LIMIT) && ${COMPAT_LINUXKPI_SKB_MEM_LIMIT} > 0
	@${MKDIR} ${WRKSRC}/${BOOT_LOADERCONFD}
	@${ECHO_CMD} "compat.linuxkpi.skb.mem_limit=${COMPAT_LINUXKPI_SKB_MEM_LIMIT}" >> ${WRKSRC}/${BOOT_LOADERCONFD}/${FLAVOR}.conf
	@${ECHO_CMD} "${BOOT_LOADERCONFD}/${FLAVOR}.conf" >> ${PLIST}
.endif
.if defined(COMPAT_LINUXKPI_HWCRYPTO_HT_VHT) && (${COMPAT_LINUXKPI_HWCRYPTO_HT_VHT:M${FLAVOR}} != "")
	@${MKDIR} ${WRKSRC}/${BOOT_LOADERCONFD}
	@${ECHO_CMD} "compat.linuxkpi.80211.hw_crypto=1" >> ${WRKSRC}/${BOOT_LOADERCONFD}/${FWDRV}-${FLAVOR}.conf
	# "iwlwifi_11n_disable" one is iwlwifi specific; for all the others bz created them homogeneously.
	# Setting an unknown kenv does not hurt.
	@${ECHO_CMD} "compat.linuxkpi.${FWDRV}_11n_disable=0" >> ${WRKSRC}/${BOOT_LOADERCONFD}/${FWDRV}-${FLAVOR}.conf
	@${ECHO_CMD} "compat.linuxkpi.${FWDRV}_disable_11n=0" >> ${WRKSRC}/${BOOT_LOADERCONFD}/${FWDRV}-${FLAVOR}.conf
	@${ECHO_CMD} "compat.linuxkpi.${FWDRV}_disable_11ac=0" >> ${WRKSRC}/${BOOT_LOADERCONFD}/${FWDRV}-${FLAVOR}.conf
	@${ECHO_CMD} "${BOOT_LOADERCONFD}/${FWDRV}-${FLAVOR}.conf" >> ${PLIST}
.endif
################################################################################
.for _f in ${DISTFILES_${FLAVOR}:O:u}
	# Create firmware source directory and copy in distfile.
	@${MKDIR} ${WRKSRC}/fw/${_f:S@${STRIP_FWSUBDIR:Q}@@:H}
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${_f} ${WRKSRC}/fw/${_f:C@(^[^?]*)${DISTURL_SUFFIX:Q}@\1@:S@${STRIP_FWSUBDIR:Q}@@}
	@${ECHO_CMD} ${BOOTFWDIR}/${_f:C@(^[^?]*)${DISTURL_SUFFIX:Q}@\1@:S@${STRIP_FWSUBDIR:Q}@@} >> ${PLIST}.tmp
.endfor
	# Create PLIST for firmware files.
	(cd ${WRKSRC}/fw/ && ${FIND} . -type d -mindepth 1 | \
	    ${AWK} -vB="${BOOTFWDIR}/" '{ sub("^./", "@dir "B); print; }') >> ${PLIST}.tmp
	# Remove possibly duplicate @dir entries
	@${SORT} -u ${PLIST}.tmp >> ${PLIST}
################################################################################
	# Copy in additional licenses files.
.for _f in ${DISTFILES_${FLAVOR}_lic}
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${_f} ${WRKSRC}/lic/${_f:C@(^[^?]*)${DISTURL_SUFFIX:Q}@\1@:S,/,_,g}
.endfor

do-install:
	(cd ${WRKSRC}/fw/ && ${COPYTREE_SHARE} . ${STAGEDIR}/${BOOTFWDIR})

post-install:
.if defined(COMPAT_LINUXKPI_SKB_MEM_LIMIT) && ${COMPAT_LINUXKPI_SKB_MEM_LIMIT} > 0
	@${MKDIR} ${STAGEDIR}/${BOOT_LOADERCONFD}
	@${INSTALL_DATA} ${WRKSRC}/${BOOT_LOADERCONFD}/${FLAVOR}.conf ${STAGEDIR}/${BOOT_LOADERCONFD}/${FLAVOR}.conf
.endif
.if defined(COMPAT_LINUXKPI_HWCRYPTO_HT_VHT) && (${COMPAT_LINUXKPI_HWCRYPTO_HT_VHT:M${FLAVOR}} != "")
	@${MKDIR} ${STAGEDIR}/${BOOT_LOADERCONFD}
	@${INSTALL_DATA} ${WRKSRC}/${BOOT_LOADERCONFD}/${FWDRV}-${FLAVOR}.conf ${STAGEDIR}/${BOOT_LOADERCONFD}/${FWDRV}-${FLAVOR}.conf
.endif
	@${DO_NADA}

.include <bsd.port.post.mk>
