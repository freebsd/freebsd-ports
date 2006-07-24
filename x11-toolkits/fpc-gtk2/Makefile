# New ports collection makefile for:	fpc-gtk2
# Date created:		2006-06-05
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

CATEGORIES=	x11-toolkits lang
PKGNAMESUFFIX=	-gtk2

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to the GTK2 libraries

BUILD_DEPENDS=	ppc386:${PORTSDIR}/lang/fpc \
		fpcmake:${PORTSDIR}/lang/fpc-utils

USE_GNOME=	gtk20

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${PORTNAME}/packages/extra/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}
HAVE_EXAMPLES=	true

.include "${MASTERDIR}/Makefile"
