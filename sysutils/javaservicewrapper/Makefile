# Created by: alepulver

PORTNAME=	javaservicewrapper
PORTVERSION=	3.5.45
CATEGORIES=	sysutils java
MASTER_SITES=	https://wrapper.tanukisoftware.com/download/${PORTVERSION}/
DISTNAME=	wrapper_${PORTVERSION}_src

MAINTAINER=	michael.osipov@siemens.com
COMMENT=	JSW enables a Java application to be run as a Unix daemon

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

ONLY_FOR_ARCHS=	aarch64 amd64 armv6 armv7 i386 powerpc64 powerpc64le

USES=		gmake iconv
USE_JAVA=	yes
JAVA_VERSION=	8+

USE_ANT=	yes
USE_LDCONFIG=	${PREFIX}/lib/javaservicewrapper/lib

DATADIR=	${PREFIX}/lib/${PORTNAME}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${ARCH} == aarch64 || ${ARCH} == amd64 || ${ARCH:Mpowerpc64*}
MAKE_ARGS+=	-Dbits=64
.else
MAKE_ARGS+=	-Dbits=32
CFLAGS+=	-fPIC
.endif

.include <bsd.port.pre.mk>

.if ${JAVA_PORT_VERSION} >= 15
PLIST_SUB+=	JS_ENGINE="@comment "
.else
PLIST_SUB+=	JS_ENGINE=""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|gcc|${CC} ${CFLAGS}| ; \
			s|/usr/local|${ICONV_PREFIX}|g ; \
			s|-liconv|${ICONV_LIB}|' \
		${WRKSRC}/src/c/Makefile-freebsd-x86-32.gmake \
		${WRKSRC}/src/c/Makefile-freebsd-x86-64.gmake
	@${REINPLACE_CMD} -e 's|\(javac\.target\.version\)=.*|\1=1.8|' \
		${WRKSRC}/default.properties
	@${CP} ${WRKSRC}/src/c/Makefile-freebsd-x86-32.gmake \
		${WRKSRC}/src/c/Makefile-freebsd-arm-32.gmake
	@${CP} ${WRKSRC}/src/c/Makefile-freebsd-x86-64.gmake \
		${WRKSRC}/src/c/Makefile-freebsd-armhf-64.gmake
	@${CP} ${WRKSRC}/src/c/Makefile-freebsd-x86-64.gmake \
		${WRKSRC}/src/c/Makefile-freebsd-ppcbe-64.gmake
	@${CP} ${WRKSRC}/src/c/Makefile-freebsd-x86-64.gmake \
		${WRKSRC}/src/c/Makefile-freebsd-ppcle-64.gmake

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${CP} -rp bin conf lib test ${STAGEDIR}${DATADIR}
	${STRIP_CMD} ${STAGEDIR}${DATADIR}/bin/wrapper
	${LN} -sf ${DATADIR}/bin/wrapper ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
