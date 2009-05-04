# New ports collection makefile for:	fpc-gtk
# Date created:		2006-06-05
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTREVISION=	0
CATEGORIES=	x11-toolkits lang
PKGNAMESUFFIX=	-gtk1

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to the GTK libraries

USE_FPC=	x11 opengl

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS=	GTK1	"Gimp Toolkit for X11 GUI (version 1.x)"	on

.include "${MASTERDIR}/Makefile"
