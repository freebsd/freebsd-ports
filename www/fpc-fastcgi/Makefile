# Created by: Christopher Key <cjk32@cam.ac.uk>
# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	www lang
PKGNAMESUFFIX=	-fastcgi

MAINTAINER=	freebsd-fpc@FreeBSD.org
COMMENT=	Free Pascal fastcgi unit

USE_FPC=	fpmkunit

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

.include "${MASTERDIR}/Makefile"
