# New ports collection makefile for:	fpc-gtk2
# Date created:		2006-06-05
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTREVISION=	0
CATEGORIES=	x11-toolkits lang
PKGNAMESUFFIX=	-gtk2

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to the GTK2 libraries

USE_FPC=	x11

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS=	GTK2	"Gimp Toolkit for X11 GUI (version 2.x)"	on

.include "${MASTERDIR}/Makefile"
