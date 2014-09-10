# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	1
CATEGORIES=	x11-toolkits lang
PKGNAMESUFFIX=	-gtk1

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to the GTK libraries

USE_FPC=	x11 opengl

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}
OPT=		-Fu${WRKDIR}/${WRKUNITDIR}/*

OPTIONS_DEFINE=	GTK1
GTK1_DESC=	Gimp Toolkit for X11 GUI (version 1.x)
OPTIONS_DEFAULT=	GTK1

GTK1_USE=	GNOME=gtk12

.include "${MASTERDIR}/Makefile"
