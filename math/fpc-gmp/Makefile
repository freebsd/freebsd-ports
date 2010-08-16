# New ports collection makefile for:	fpc-gmp
# Date created:		2010-04-22
# Whom: 		Christopher Key <cjk32@cam.ac.uk>
#
# $FreeBSD$
#

PORTREVISION=	0
CATEGORIES=	math lang
PKGNAMESUFFIX=	-gmp

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to gmp library

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS=	GMP	"Install gmp library"	on

.include "${MASTERDIR}/Makefile"
