# New ports collection makefile for:	fpc-aspell
# Date created:		2009-01-06
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTREVISION=	0
CATEGORIES=	textproc lang
PKGNAMESUFFIX=	-aspell

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Interface to aspell spelling checker

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS=	ASPELL	"Install aspell spell checker"	on

.include "${MASTERDIR}/Makefile"
