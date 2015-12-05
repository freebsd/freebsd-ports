# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

CATEGORIES=	security lang
PKGNAMESUFFIX=	-openssl

MAINTAINER=	freebsd-fpc@FreeBSD.org
COMMENT=	Free Pascal unit for OpenSSL

USE_FPC=	rtl-extra

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

OPTIONS_DEFINE=	OPENSSL
OPENSSL_DESC=	Install SSL and crypto library
OPTIONS_DEFAULT=	OPENSSL

OPENSSL_USE=	OPENSSL=yes

.include "${MASTERDIR}/Makefile"
