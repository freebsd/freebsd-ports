# Created by: Nikolai Lifanov
# $FreeBSD$

PKGNAMESUFFIX=	-genisoimage

COMMENT=	Standalone genisoimage from cdrkit

BROKEN_aarch64=	Fails to link: missing sbrk
BROKEN_riscv64=	Fails to link: missing sbrk

RUN_DEPENDS=	# nada

CONFLICTS=	# nada

PLIST_SUB=	CDRKIT="@comment " GENISOIMAGE=""

SLAVE_PORT=	cdrkit

MASTERDIR=	${.CURDIR}/../cdrkit

.include "${MASTERDIR}/Makefile"
