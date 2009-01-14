# New ports collection makefile for:	fpc-md5
# Date created: 			8 February 2004
# Whom: 				John Merryweather Cooper
#
# $FreeBSD$
#

PORTREVISION=	0
CATEGORIES=	security lang
PKGNAMESUFFIX=	-hash

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal unit for MD5 hash routines

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

.include "${MASTERDIR}/Makefile"
