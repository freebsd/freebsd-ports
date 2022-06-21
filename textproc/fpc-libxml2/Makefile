# Created by: Christoper Key <cjk32@cam.ac.uk>

PORTREVISION=	4
CATEGORIES=	textproc lang
PKGNAMESUFFIX=	-libxml2

COMMENT=	Interface to xml2 library

USES=		fpc
USE_FPC=	rtl-objpas

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//:S/2//}
EXTRACTUNITDIR=	${WRKUNITDIR}

OPTIONS_DEFINE=	LIBXML2
LIBXML2_DESC=	Install xml2 library
OPTIONS_DEFAULT=	LIBXML2

LIBXML2_LIB_DEPENDS=	libxml2.so:textproc/libxml2

.include "${MASTERDIR}/Makefile"
