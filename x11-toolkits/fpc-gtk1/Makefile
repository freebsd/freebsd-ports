# New ports collection makefile for:	fpc-gtk
# Date created:		2006-06-05
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

CATEGORIES=	x11-toolkits lang
PKGNAMESUFFIX=	-gtk

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to the GTK libraries

BUILD_DEPENDS=	ppc386:${PORTSDIR}/lang/fpc \
		fpcmake:${PORTSDIR}/lang/fpc-utils \
		${UNITSDIR}/gtk2/Package.fpc:${PORTSDIR}/x11-toolkits/fpc-gtk2 \
		${UNITSDIR}/x11/Package.fpc:${PORTSDIR}/x11/fpc-x11 \
		${UNITSDIR}/opengl/Package.fpc:${PORTSDIR}/graphics/fpc-opengl

USE_GNOME=	gtk12

UNITSDIR=	${LOCALBASE}/lib/fpc/${PORTVERSION}/units/${BUILDNAME}
MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${PORTNAME}/packages/extra/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}
HAVE_EXAMPLES=	true
OPT=-CX -Fu${WRKDIR}/${WRKUNITDIR}/*

.include "${MASTERDIR}/Makefile"
