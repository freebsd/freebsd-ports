CATEGORIES=	x11-toolkits lang
PKGNAMESUFFIX=	-gtk2

COMMENT=	Free Pascal interface to the GTK2 libraries

USES=		fpc
USE_FPC=	cairo fcl-base fcl-image fcl-res pasjpeg rtl-objpas x11

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

OPTIONS_DEFINE=	GTK2
GTK2_DESC=	Gimp Toolkit for X11 GUI (version 2.x)
OPTIONS_DEFAULT=	GTK2

GTK2_USES=	gnome
GTK2_USE=	GNOME=gtk20

.include "${MASTERDIR}/Makefile"
