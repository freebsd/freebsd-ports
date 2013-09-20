# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	misc lang
PKGNAMESUFFIX=	-chm

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal unit to manipulate chm files

USE_FPC=	fcl-xml

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
