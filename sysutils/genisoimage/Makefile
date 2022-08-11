PKGNAMESUFFIX=	-genisoimage

COMMENT=	Standalone genisoimage from cdrkit

BROKEN_aarch64=	Fails to link: missing sbrk
BROKEN_riscv64=	Fails to link: missing sbrk

RUN_DEPENDS=	# nada

CONFLICTS=	# nada

PLIST_SUB=	CDRKIT="@comment " GENISOIMAGE=""

MASTERDIR=	${.CURDIR}/../cdrkit

.include "${MASTERDIR}/Makefile"
