# New ports collection makefile for:	fpc-zvt
# Date created:		2006-06-22
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTREVISION=	2
CATEGORIES=	x11-toolkits lang
PKGNAMESUFFIX=	-zvt

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to Zed's Virtual Terminal

BUILD_DEPENDS=	ppc386:${PORTSDIR}/lang/fpc \
		fpcmake:${PORTSDIR}/lang/fpc-utils \
		${UNITSDIR}/gtk/Package.fpc:${PORTSDIR}/x11-toolkits/fpc-gtk \
		${UNITSDIR}/imlib/Package.fpc:${PORTSDIR}/graphics/fpc-imlib \
		${UNITSDIR}/x11/Package.fpc:${PORTSDIR}/x11/fpc-x11 \
		${UNITSDIR}/opengl/Package.fpc:${PORTSDIR}/graphics/fpc-opengl

UNITSDIR=	${LOCALBASE}/lib/fpc/${PORTVERSION}/units/${BUILDNAME}
MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/extra/gnome1/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS=	ZVT	"Install library components for Zed's Virtual Terminal"	on

.include "${MASTERDIR}/Makefile"
