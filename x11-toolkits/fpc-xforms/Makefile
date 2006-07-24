# New ports collection makefile for:	fpc-forms
# Date created:		2006-06-05
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

CATEGORIES=	x11-toolkits lang
PKGNAMESUFFIX=	-forms

MAINTAINER=	acm@FreeBSD.org
COMMENT=	X-Forms interface for Free Pascal

BUILD_DEPENDS=	ppc386:${PORTSDIR}/lang/fpc \
		fpcmake:${PORTSDIR}/lang/fpc-utils \
		${UNITSDIR}/x11/Package.fpc:${PORTSDIR}/x11/fpc-x11
LIB_DEPENDS=	forms.1:${PORTSDIR}/x11-toolkits/xforms

UNITSDIR=	${LOCALBASE}/lib/fpc/${PORTVERSION}/units/${BUILDNAME}
MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${PORTNAME}/packages/extra/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}
HAVE_EXAMPLES=	true

.include "${MASTERDIR}/Makefile"
