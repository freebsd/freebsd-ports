# New ports collection makefile for:	fpc-openssl
# Date created: 			2007-09-11
# Whom: 				Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTREVISION=	0
CATEGORIES=	security lang
PKGNAMESUFFIX=	-openssl

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal unit for OpenSSL

BUILD_DEPENDS=	ppc386:${PORTSDIR}/lang/fpc

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/extra/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS=	OPENSSL	"Install SSL and crypto library"	on

.include "${MASTERDIR}/Makefile"
