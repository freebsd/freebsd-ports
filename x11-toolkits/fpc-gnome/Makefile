# New ports collection makefile for:	fpc-gnome
# Date created:		2006-06-22
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

CATEGORIES=	x11-toolkits lang
PKGNAMESUFFIX=	-gnome

MAINTAINER=	acardenas@bsd.org.pe
COMMENT=	Free Pascal unit to create programs for GNOME 1

RUN_DEPENDS=	${UNITSDIR}/gtk/Package.fpc:${PORTSDIR}/x11-toolkits/fpc-gtk

UNITSDIR=	${LOCALBASE}/lib/fpc/${PORTVERSION}/units/${BUILDNAME}
MASTERDIR=	${.CURDIR}/../../lang/fpc

.include "${MASTERDIR}/Makefile"
