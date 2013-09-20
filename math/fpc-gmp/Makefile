# Created by: Christopher Key <cjk32@cam.ac.uk>
# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	math lang
PKGNAMESUFFIX=	-gmp

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to gmp library

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS_DEFINE=	GMP
GMP_DESC=	Install gmp library
OPTIONS_DEFAULT=	GMP

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
