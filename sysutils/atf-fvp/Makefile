WWW=		https://github.com/ARM-software/arm-trusted-firmware
MASTERDIR=	${.CURDIR}/../atf-master

PLAT=		fvp
BL31=		bl1.bin
FIP=		fip.bin
ATF_TARGET=	bl1 dtbs fip BL33=${LOCALBASE}/share/edk2-fvp/FVP_AARCH64_EFI.fd

BUILD_DEPENDS+=	${LOCALBASE}/share/edk2-fvp/FVP_AARCH64_EFI.fd:sysutils/edk2@fvp

.include "${MASTERDIR}/Makefile"
