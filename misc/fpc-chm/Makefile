# New ports collection makefile for:	fpc-chm
# Date created:		2009-01-06
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTREVISION=	0
CATEGORIES=	misc lang
PKGNAMESUFFIX=	-chm

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal unit to manipulate chm files

USE_FPC=	fcl-xml

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

.include "${MASTERDIR}/Makefile"
