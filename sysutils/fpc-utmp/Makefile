# New ports collection makefile for:	fpc-utmp
# Date created:		2006-06-05
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

CATEGORIES=	sysutils lang
PKGNAMESUFFIX=	-utmp

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal unit to gather information from the utmp file

BUILD_DEPENDS=	ppc386:${PORTSDIR}/lang/fpc \
		fpcmake:${PORTSDIR}/lang/fpc-utils

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${PORTNAME}/packages/extra/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}
HAVE_EXAMPLES=	true

.include "${MASTERDIR}/Makefile"
