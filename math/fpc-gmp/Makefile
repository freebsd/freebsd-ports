CATEGORIES=	math lang
PKGNAMESUFFIX=	-gmp

COMMENT=	Free Pascal interface to gmp library

USES=		fpc

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

OPTIONS_DEFINE=	GMP
GMP_DESC=	Install gmp library
OPTIONS_DEFAULT=	GMP

GMP_LIB_DEPENDS=	libgmp.so:math/gmp

.include "${MASTERDIR}/Makefile"
