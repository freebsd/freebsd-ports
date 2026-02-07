PORTNAME=		cryptlib
DISTVERSION=		3.4.7
CATEGORIES=		security
MASTER_SITES=		https://cryptlib-release.s3-ap-southeast-1.amazonaws.com/
DISTNAME=		${PORTNAME}${PORTVERSION:S/.//g}

MAINTAINER=		ale@FreeBSD.org
COMMENT=		Powerful security programming toolkit
WWW=			http://www.cs.auckland.ac.nz/~pgut001/cryptlib/

LICENSE=		SLEEPYCAT
LICENSE_NAME=		Sleepycat
LICENSE_FILE=		${WRKSRC}/COPYING
LICENSE_PERMS=		dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

ONLY_FOR_ARCHS=		amd64 armv6 armv7 i386 powerpc powerpc64 powerpc64le

USES=			cpe zip:infozip

OPTIONS_DEFINE=		DOCS

EXTRACT_BEFORE_ARGS=	-aq
NO_WRKSUBDIR=		yes
MAKEFILE=		makefile
ALL_TARGET=		default FreeBSD shared testlib
USE_LDCONFIG=		yes
MAKE_JOBS_UNSAFE=	yes
CFLAGS+=		-DUSE_PKCS11

PLIST_FILES=		include/cryptlib.h \
			lib/libcl.a lib/libcl.so \
			lib/libcl.so.3 lib/libcl.so.${PORTVERSION}

PORTDOCS=		README

do-install:
	${INSTALL_DATA} ${WRKSRC}/libcl.a ${WRKSRC}/libcl.so.${PORTVERSION} \
		${STAGEDIR}${PREFIX}/lib
	${LN} -sf libcl.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libcl.so.3
	${LN} -sf libcl.so.3 ${STAGEDIR}${PREFIX}/lib/libcl.so
	${INSTALL_DATA} ${WRKSRC}/cryptlib.h ${STAGEDIR}${PREFIX}/include

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

do-test:
	@cd ${BUILD_WRKSRC} && ./testlib -a

.include <bsd.port.mk>
