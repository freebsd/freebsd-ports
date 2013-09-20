# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	math lang
PKGNAMESUFFIX=	-fftw

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to the FFTW3 library

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS_DEFINE=	FFTW3
FFTW3_DESC=	Install FFTW3 library
OPTIONS_DEFAULT=	FFTW3

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
