# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

CATEGORIES=	x11-toolkits lang
PKGNAMESUFFIX=	-xforms

MAINTAINER=	freebsd-fpc@FreeBSD.org
COMMENT=	X-Forms interface for Free Pascal

USE_FPC=	x11

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

OPTIONS_DEFINE=	EXAMPLES XFORMS
XFORMS_DESC=	Install xforms graphical user interface toolkit
OPTIONS_DEFAULT=	XFORMS

XFORMS_LIB_DEPENDS=	libforms.so:x11-toolkits/xforms

.include "${MASTERDIR}/Makefile"
