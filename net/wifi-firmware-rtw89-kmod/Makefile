BASEDIR=	${.CURDIR}/../wifi-firmware-kmod

FWDRV=		rtw89
FWSUBDIR=	rtw89
FWDRV_VERSION=	20230310

LICENSE=	LICENCE.rtlwifi_firmware.txt
LICENSE_NAME=	Realtek firmware license (${FWDRV})

FWSUBS=	\
	rtw8852a \
	rtw8852b \
	rtw8852c

DISTFILES_rtw8852a= \
	${FWSUBDIR}/rtw8852a_fw.bin${DISTURL_SUFFIX}
DISTFILES_rtw8852b= \
	${FWSUBDIR}/rtw8852b_fw.bin${DISTURL_SUFFIX}
DISTFILES_rtw8852c= \
	${FWSUBDIR}/rtw8852c_fw.bin${DISTURL_SUFFIX}
DISTFILES_fw= \
	${DISTFILES_rtw8852a} \
	${DISTFILES_rtw8852b} \
	${DISTFILES_rtw8852c}

DISTFILES_lic=

.include "${BASEDIR}/Makefile.inc"
