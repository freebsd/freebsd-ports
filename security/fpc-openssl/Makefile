# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	security lang
PKGNAMESUFFIX=	-openssl

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal unit for OpenSSL

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS_DEFINE=	OPENSSL
OPENSSL_DESC=	Install SSL and crypto library
OPTIONS_DEFAULT=	OPENSSL

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
