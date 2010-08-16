# New ports collection makefile for:	fpc-dts
# Date created: 	2010-04-22
# Whom: 		Christopher Key <cjk32@cam.ac.uk>
#
# $FreeBSD$
#

PORTREVISION=	0
CATEGORIES=	multimedia lang
PKGNAMESUFFIX=	-dts

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to the dts library

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS=	LIBDCA	"Install dts library"	on

.include "${MASTERDIR}/Makefile"
