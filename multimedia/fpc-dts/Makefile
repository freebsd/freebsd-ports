# Created by: Christopher Key <cjk32@cam.ac.uk>
# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	multimedia lang
PKGNAMESUFFIX=	-dts

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to the dts library

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS_DEFINE=	LIBDCA
LIBDCA_DESC=	Install dts library
OPTIONS_DEFAULT=	LIBDCA

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
