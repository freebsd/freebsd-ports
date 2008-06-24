# New ports collection makefile for:	fpc-gnome
# Date created:		2006-06-22
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTREVISION=	1
CATEGORIES=	x11-toolkits lang
PKGNAMESUFFIX=	-gnome

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal unit to create programs for GNOME 1

USE_FPC=	gtk imlib opengl x11

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/extra/gnome1/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

.include "${MASTERDIR}/Makefile"
