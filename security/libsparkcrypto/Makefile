# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libsparkcrypto
PORTVERSION=	0.1.1
CATEGORIES=	security
MASTER_SITES=	http://senier.net/libsparkcrypto/
EXTRACT_SUFX=	.tgz

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Cryptographic library implemented in SPARK

LICENSE=	BSD

USES=		ada
USE_GMAKE=	yes
USE_DOS2UNIX=	Makefile build/libsparkcrypto.gpr
SPARKARCH:=	${ARCH:S/amd64/x86_64/:S/i386/i686/}

# The APIDOC requires AdaBrowse which in turn requires ASIS which is
# coupled with the compiler.  There is a question whether Adacore's
# GPL ASIS is even compatible with FSF GNAT, which is what gcc-aux is.
# Until this question is answered, skip API document building.

MAKE_ENV+=	SPARKARCH=${SPARKARCH} \
		SPARK_DIR=${WRKSRC}/src/spark \
		DESTDIR=${LOCALBASE} \
		MODE=release \
		RUNTIME=native \
		NO_TESTS=true \
		NO_PROOF=true \
		NO_APIDOC=true

post-patch:
	# ports passed unwanted ARCH definition to Makefile
	@${REINPLACE_CMD} -e 's|ARCH|SPARKARCH|g' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
