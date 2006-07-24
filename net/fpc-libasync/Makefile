# New ports collection makefile for:	fpc-libasync
# Date created: 			2006-06-05
# Whom: 				Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

CATEGORIES=	net lang
PKGNAMESUFFIX=	-libasync

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to async library

BUILD_DEPENDS=	ppc386:${PORTSDIR}/lang/fpc

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${PORTNAME}/packages/base/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

.include "${MASTERDIR}/Makefile"
