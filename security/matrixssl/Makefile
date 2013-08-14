# New ports collection Makefile for:	matrixssl
# Date created:				2006-03-17
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	matrixssl
PORTVERSION=	3.3
CATEGORIES=	security
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:CDRAKE
DISTNAME=	Crypt-MatrixSSL3-3.3.0.1
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small alternative SSL implementation

LICENSE=	GPLv2 # (or later)

OPTIONS_DEFINE=	DOCS EXAMPLES

WRKSRC=		${WRKDIR}/${DISTNAME}/${PORTNAME}-${PORTVERSION:S/./-/g}-open

USE_GMAKE=	yes
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
	${INSTALL_DATA} ${WRKSRC}/libmatrixssl.* ${PREFIX}/lib
	@${MKDIR} ${PREFIX}/include/matrixssl
	${INSTALL_DATA} ${WRKSRC}/matrixssl/*.h ${PREFIX}/include/matrixssl
	@${MKDIR} ${PREFIX}/include/matrixssl/core
	${INSTALL_DATA} ${WRKSRC}/core/*.h ${PREFIX}/include/matrixssl/core
	@${MKDIR} ${PREFIX}/include/matrixssl/crypto
	${INSTALL_DATA} ${WRKSRC}/crypto/*.h ${PREFIX}/include/matrixssl/crypto
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}/apps
	${INSTALL_DATA} ${WRKSRC}/apps/Makefile ${EXAMPLESDIR}/apps
	${INSTALL_DATA} ${WRKSRC}/apps/*.c ${EXAMPLESDIR}/apps
	${INSTALL_DATA} ${WRKSRC}/apps/*.h ${EXAMPLESDIR}/apps
	@${MKDIR} ${EXAMPLESDIR}/sampleCerts
	${INSTALL_DATA} ${WRKSRC}/sampleCerts/*.h ${EXAMPLESDIR}/sampleCerts
	${INSTALL_DATA} ${WRKSRC}/sampleCerts/*.pem ${EXAMPLESDIR}/sampleCerts
.endif

.include <bsd.port.post.mk>
