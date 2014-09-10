# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	1
CATEGORIES=	x11-toolkits lang
PKGNAMESUFFIX=	-gnome1

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal unit to create programs for GNOME 1

USE_FPC=	gtk1 imlib opengl x11

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

.include "${MASTERDIR}/Makefile"
