# $FreeBSD$

PKGNAMESUFFIX=	-bananapi

COMMENT=	Cross-build U-Boot loader for Banana Pi

LICENSE=	GPLv2

# Local overrides
MASTERDIR=	${.CURDIR}/../u-boot-cubieboard
DESCR=		${.CURDIR}/pkg-descr
MODEL=		bananapi
CONF_TARGET=	Bananapi_defconfig

.include "${MASTERDIR}/Makefile"
