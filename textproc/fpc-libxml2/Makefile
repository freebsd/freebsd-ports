# Created by: Christoper Key <cjk32@cam.ac.uk>
# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	textproc lang
PKGNAMESUFFIX=	-libxml2

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Interface to xml2 library

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//:S/2//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS_DEFINE=	LIBXML2
LIBXML2_DESC=	Install xml2 library
OPTIONS_DEFAULT=	LIBXML2

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
