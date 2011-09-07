# New ports collection makefile for:	fpc-forms
# Date created:		2006-06-05
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTREVISION=	1
CATEGORIES=	x11-toolkits lang
PKGNAMESUFFIX=	-xforms

MAINTAINER=	acm@FreeBSD.org
COMMENT=	X-Forms interface for Free Pascal

USE_FPC=	x11

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS=	XFORMS	"Install xforms graphical user interface toolkit"	on

.include "${MASTERDIR}/Makefile"
