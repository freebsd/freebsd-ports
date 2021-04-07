CATEGORIES=	security lang
PKGNAMESUFFIX=	-gnutls

COMMENT=	Free Pascal unit for GnuTLS

USES=		fpc
USE_FPC=	fcl-async fcl-base fcl-net fcl-passrc fcl-res fcl-xml rtl-extra \
		rtl-objpas

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

OPTIONS_DEFINE=	GNUTLS
OPTIONS_DEFAULT=	GNUTLS

GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls

.include "${MASTERDIR}/Makefile"
