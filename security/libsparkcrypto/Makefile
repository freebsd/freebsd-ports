# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libsparkcrypto
PORTVERSION=	0.1.1
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://senier.net/libsparkcrypto/
EXTRACT_SUFX=	.tgz

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Cryptographic library implemented in SPARK

LICENSE=	BSD

USES=		ada gmake
USE_DOS2UNIX=	Makefile build/libsparkcrypto.gpr
SPARKARCH:=	${ARCH:S/amd64/x86_64/:S/i386/i686/}

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
