BASEDIR=	${.CURDIR}/../wifi-firmware-kmod
FWDRV=mt7601u
FWSUBDIR=	mediatek
FWDRV_VERSION=	20241017

NOT_FOR_ARCHS=

LICENSE_FILE=	LICENCE.ralink_a_mediatek_company_firmware
LICENSE_NAME=   Ralink, A MediaTek Company license (${FWDRV})

WHENCE_REGEX=mt7601u
FWSUBS= #No flavors

DISTFILES_${FWDRV}=\
	${FWSUBDIR}/mt7601u.bin${DISTURL_SUFFIX}
DISTFILES_${FWDRV}_lic=

.include "${BASEDIR}/Makefile.inc"
