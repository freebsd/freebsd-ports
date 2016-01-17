# Created by: arved
# $FreeBSD$

PORTNAME=	matrixssl
PORTVERSION=	3.3
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:CDRAKE
DISTNAME=	Crypt-MatrixSSL3-3.3.0.1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small alternative SSL implementation

LICENSE=	GPLv2+

OPTIONS_DEFINE=	DOCS EXAMPLES

WRKSRC=		${WRKDIR}/${DISTNAME}/${PORTNAME}-${PORTVERSION:S/./-/g}-open

USES=		gmake tar:tgz
MAKE_ARGS=	CC="${CC}" DFLAGS="${CFLAGS}" STRIP="${TEST}"
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64" || ${ARCH} == "sparc64"
CFLAGS+=	-DPSTM_64BIT
.endif

post-extract:
	@cd ${WRKDIR}/${DISTNAME} \
		&& ${TAR} -xf ${PORTNAME}-${PORTVERSION:S/./-/g}-open.tgz

pre-patch:
	@cd ${WRKDIR}/${DISTNAME} \
		&& ${CAT} ${PORTNAME}-${PORTVERSION:S/./-/g}-open.patch | \
		${PATCH} -d ${WRKSRC} -p1 --quiet

post-patch:
	@${REINPLACE_CMD} -e \
		's|^LDFLAGS|#LDFLAGS|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_DATA} ${WRKSRC}/libmatrixssl.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/libmatrixssl.so ${STAGEDIR}${PREFIX}/lib
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/matrixssl
	${INSTALL_DATA} ${WRKSRC}/matrixssl/*.h ${STAGEDIR}${PREFIX}/include/matrixssl
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/matrixssl/core
	${INSTALL_DATA} ${WRKSRC}/core/*.h ${STAGEDIR}${PREFIX}/include/matrixssl/core
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/matrixssl/crypto
	${INSTALL_DATA} ${WRKSRC}/crypto/*.h ${STAGEDIR}${PREFIX}/include/matrixssl/crypto
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/apps
	${INSTALL_DATA} ${WRKSRC}/apps/Makefile ${STAGEDIR}${EXAMPLESDIR}/apps
	${INSTALL_DATA} ${WRKSRC}/apps/*.c ${STAGEDIR}${EXAMPLESDIR}/apps
	${INSTALL_DATA} ${WRKSRC}/apps/*.h ${STAGEDIR}${EXAMPLESDIR}/apps
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/sampleCerts
	${INSTALL_DATA} ${WRKSRC}/sampleCerts/*.h ${STAGEDIR}${EXAMPLESDIR}/sampleCerts
	${INSTALL_DATA} ${WRKSRC}/sampleCerts/*.pem ${STAGEDIR}${EXAMPLESDIR}/sampleCerts
.endif

.include <bsd.port.post.mk>
