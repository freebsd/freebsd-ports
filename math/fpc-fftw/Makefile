# New ports collection makefile for:	fpc-fftw
# Date created:		2006-09-05
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTREVISION=	1
CATEGORIES=	math lang
PKGNAMESUFFIX=	-fftw

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to the FFTW3 library

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS=	FFTW3	"Install FFTW3 library"	on

.include "${MASTERDIR}/Makefile"
