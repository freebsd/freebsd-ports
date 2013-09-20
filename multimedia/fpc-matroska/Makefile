# Created by: Christopher Key <cjk32@cam.ac.uk>
# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	multimedia lang
PKGNAMESUFFIX=	-matroska

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to matroska library

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS_DEFINE=	LIBMATROSKA
LIBMATROSKA_DESC=	Install matroska library
OPTIONS_DEFAULT=	LIBMATROSKA

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
