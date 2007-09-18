# New ports collection makefile for:	fpc-gnome
# Date created:		2006-06-22
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTREVISION=	0
CATEGORIES=	x11-toolkits lang
PKGNAMESUFFIX=	-gnome

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal unit to create programs for GNOME 1

BUILD_DEPENDS=	ppc386:${PORTSDIR}/lang/fpc \
		fpcmake:${PORTSDIR}/lang/fpc-utils \
		${UNITSDIR}/gtk/Package.fpc:${PORTSDIR}/x11-toolkits/fpc-gtk \
		${UNITSDIR}/imlib/Package.fpc:${PORTSDIR}/graphics/fpc-imlib \
		${UNITSDIR}/opengl/Package.fpc:${PORTSDIR}/graphics/fpc-opengl \
		${UNITSDIR}/x11/Package.fpc:${PORTSDIR}/x11/fpc-x11

UNITSDIR=	${LOCALBASE}/lib/fpc/${PORTVERSION}/units/${BUILDNAME}
MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/extra/gnome1/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

.include "${MASTERDIR}/Makefile"
