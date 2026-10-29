PKGNAMESUFFIX=	-genisoimage

COMMENT=	Standalone genisoimage from cdrkit

BROKEN=		Fails to build with CMake 4

RUN_DEPENDS=	# nada

CONFLICTS=	# nada

PLIST_SUB=	CDRKIT="@comment " GENISOIMAGE=""

MASTERDIR=	${.CURDIR}/../cdrkit

.include "${MASTERDIR}/Makefile"
