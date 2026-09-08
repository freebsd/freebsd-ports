PORTNAME=	javaservicewrapper
PORTVERSION=	3.7.3
PORTREVISION=	2
CATEGORIES=	sysutils java
MASTER_SITES=	https://wrapper.tanukisoftware.com/download/${PORTVERSION}/
DISTNAME=	wrapper_${PORTVERSION}_src

MAINTAINER=	michael.osipov@innomotics.com
COMMENT=	JSW enables a Java application to be run as a Unix daemon
WWW=		https://wrapper.tanukisoftware.org/

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

USES=		gmake java:ant,build

.include <bsd.port.pre.mk>

.if ${ARCH} == aarch64 || ${ARCH} == amd64 || ${ARCH:Mpowerpc64*}
MAKE_ARGS+=	-Dbits=64
.else
MAKE_ARGS+=	-Dbits=32
.endif

# In a future version support for target 8 will be removed and we need to
# check/bump.
#.if ${JAVA_PORT_VERSION} >= X
#JAVA_TARGET_VERSION=	11
#.else
JAVA_TARGET_VERSION=	8
#.endif

PLIST_SUB+=	JAVAJARDIR=${JAVAJARDIR}

post-extract:
	@${ECHO} "javac.target.version=${JAVA_TARGET_VERSION}" > ${WRKSRC}/ant.properties

post-patch:
	@${REINPLACE_CMD} -e 's|gcc|${CC} ${CFLAGS}|' \
		${WRKSRC}/src/c/Makefile-freebsd-x86-32.gmake \
		${WRKSRC}/src/c/Makefile-freebsd-x86-64.gmake
	@${CP} ${WRKSRC}/src/c/Makefile-freebsd-x86-32.gmake \
		${WRKSRC}/src/c/Makefile-freebsd-arm-32.gmake
	@${CP} ${WRKSRC}/src/c/Makefile-freebsd-x86-64.gmake \
		${WRKSRC}/src/c/Makefile-freebsd-ppcbe-64.gmake
	@${CP} ${WRKSRC}/src/c/Makefile-freebsd-x86-64.gmake \
		${WRKSRC}/src/c/Makefile-freebsd-ppcle-64.gmake
	@${CP} ${WRKSRC}/src/c/Makefile-freebsd-x86-64.gmake \
		${WRKSRC}/src/c/Makefile-freebsd-ppcbe-32.gmake

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/bin ${STAGEDIR}${PREFIX}/lib ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/wrapper ${STAGEDIR}${PREFIX}/bin
	${INSTALL_LIB} ${WRKSRC}/lib/libwrapper.so ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/lib/wrapper.jar ${STAGEDIR}${JAVAJARDIR}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/wrapper
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libwrapper.so
	${RLN} ${STAGEDIR}${PREFIX}/bin/wrapper ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.post.mk>
