BASEDIR=	${.CURDIR}/../wifi-firmware-kmod

FWDRV=		rtw88
FWSUBDIR=	rtw88
FWDRV_VERSION=	20230310

LICENSE=	LICENCE.rtlwifi_firmware.txt
LICENSE_NAME=	Realtek firmware license (${FWDRV})

FWSUBS=	\
	rtw8723d \
	rtw8822b \
	rtw8821c \
	rtw8822c

DISTFILES_rtw8723d= \
	${FWSUBDIR}/rtw8723d_fw.bin${DISTURL_SUFFIX}
DISTFILES_rtw8822b= \
	${FWSUBDIR}/rtw8822b_fw.bin${DISTURL_SUFFIX}
DISTFILES_rtw8821c= \
	${FWSUBDIR}/rtw8821c_fw.bin${DISTURL_SUFFIX}
DISTFILES_rtw8822c= \
	${FWSUBDIR}/rtw8822c_fw.bin${DISTURL_SUFFIX} \
	${FWSUBDIR}/rtw8822c_wow_fw.bin${DISTURL_SUFFIX}
DISTFILES_fw= \
	${DISTFILES_rtw8723d} \
	${DISTFILES_rtw8822b} \
	${DISTFILES_rtw8821c} \
	${DISTFILES_rtw8822c}

DISTFILES_lic= \
	${FWSUBDIR}/README${DISTURL_SUFFIX}

.include "${BASEDIR}/Makefile.inc"
