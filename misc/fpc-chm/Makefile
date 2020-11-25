# $FreeBSD$

CATEGORIES=	misc lang
PKGNAMESUFFIX=	-chm

COMMENT=	Free Pascal unit to manipulate chm files

USES=		fpc
USE_FPC=	fcl-base fcl-xml rtl-generics

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

.include "${MASTERDIR}/Makefile"
