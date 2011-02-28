# New ports collection makefile for:	fpc-matroska
# Date created: 	2010-04-22
# Whom: 		Christopher Key <cjk32@cam.ac.uk>
#
# $FreeBSD$
#

PORTREVISION=	2
CATEGORIES=	multimedia lang
PKGNAMESUFFIX=	-matroska

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to matroska library

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS=	LIBMATROSKA	"Install matroska library"	on

.include "${MASTERDIR}/Makefile"
