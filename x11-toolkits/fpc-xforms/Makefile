# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	1
CATEGORIES=	x11-toolkits lang
PKGNAMESUFFIX=	-xforms

MAINTAINER=	acm@FreeBSD.org
COMMENT=	X-Forms interface for Free Pascal

USE_FPC=	x11

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS_DEFINE=	XFORMS
XFORMS_DESC=	Install xforms graphical user interface toolkit
OPTIONS_DEFAULT=	XFORMS

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
