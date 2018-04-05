# $FreeBSD$

CATEGORIES=	www lang
PKGNAMESUFFIX=	-libmicrohttpd

COMMENT=	Free Pascal libmicrohttpd unit

USES=		fpc
USE_FPC=	rtl-extra

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

.include "${MASTERDIR}/Makefile"
