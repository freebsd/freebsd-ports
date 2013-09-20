# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	math lang
PKGNAMESUFFIX=	-numlib

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal unit to numerical methods

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
