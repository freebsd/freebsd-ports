COMMENT=	Fcitx support for GTK (common files)

PKGNAMESUFFIX=	-common

MASTERDIR=	${.CURDIR}/../fcitx5-gtk

LIB_DEPENDS=	# empty
RUN_DEPENDS=	# empty

PLIST=	${MASTERDIR}/pkg-plist.common

FLAVORS=	# empty
FLAVOR=	# empty

CMAKE_ON=	# empty
CMAKE_OFF=	ENABLE_GTK2_IM_MODULE ENABLE_GTK3_IM_MODULE \
		ENABLE_GTK4_IM_MODULE

.include "${MASTERDIR}/Makefile"
