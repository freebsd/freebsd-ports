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

BUILD_DEPENDS=	ppc386:${PORTSDIR}/lang/fpc \
		fpcmake:${PORTSDIR}/lang/fpc-utils \
		${UNITSDIR}/x11/Package.fpc:${PORTSDIR}/x11/fpc-x11

UNITSDIR=	${LOCALBASE}/lib/fpc/${PORTVERSION}/units/${BUILDNAME}
MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/extra/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS=	GTK2	"Gimp Toolkit for X11 GUI (version 2.x)"	on

.include "${MASTERDIR}/Makefile"
