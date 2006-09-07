# New ports collection makefile for:	fpc-fftw
# Date created:		2006-09-05
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTREVISION=	0
CATEGORIES=	math lang
PKGNAMESUFFIX=	-fftw

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to the FFTW3 library

BUILD_DEPENDS=	ppc386:${PORTSDIR}/lang/fpc
LIB_DEPENDS=	fftw3.4:${PORTSDIR}/math/fftw3

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/extra/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

.include "${MASTERDIR}/Makefile"
