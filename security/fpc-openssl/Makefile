# $FreeBSD$

CATEGORIES=	security lang
PKGNAMESUFFIX=	-openssl

COMMENT=	Free Pascal unit for OpenSSL

USES=		fpc
USE_FPC=	fcl-async fcl-base fcl-net fcl-passrc fcl-res fcl-xml rtl-extra \
		rtl-objpas

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

OPTIONS_DEFINE=	OPENSSL
OPENSSL_DESC=	Install SSL and crypto library
OPTIONS_DEFAULT=	OPENSSL

OPENSSL_USES=		ssl

.include "${MASTERDIR}/Makefile"
