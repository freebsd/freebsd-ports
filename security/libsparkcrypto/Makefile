# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libsparkcrypto
PORTVERSION=	0.1.1
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	http://senier.net/libsparkcrypto/

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Cryptographic library implemented in SPARK

LICENSE=	BSD3CLAUSE

USES=		ada dos2unix gmake tar:tgz
DOS2UNIX_FILES=	Makefile build/libsparkcrypto.gpr \
		src/shared/generic/lsc-byteswap64.ads \
		src/shared/generic/lsc-types.ads
SPARKARCH:=	${ARCH:S/amd64/x86_64/:S/i386/i686/}
ALL_TARGET=	all build

MAKE_ENV+=	SPARKARCH=${SPARKARCH} \
		SPARK_DIR=${WRKSRC}/src/spark \
		MODE=release \
		RUNTIME=native \
		NO_TESTS=true \
		NO_PROOF=true

OPTIONS_DEFINE=		DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	adabrowse:${PORTSDIR}/textproc/adabrowse
.else
MAKE_ENV+=	NO_APIDOC=true
.endif

post-patch:
#	ports passed unwanted ARCH definition to Makefile
	@${REINPLACE_CMD} -e 's|ARCH|SPARKARCH|g' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
