# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	iaikPkcs11Wrapper
PORTVERSION=	1.2.18
CATEGORIES=	security java devel
MASTER_SITES=	LOCAL/ale
DISTNAME=	${PORTNAME}_${PORTVERSION:S/./_/g}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	PKCS\#11 Java wrapper

OPTIONS_DEFINE=	DOCS EXAMPLES

USES=		dos2unix gmake zip
USE_JAVA=	yes
DOS2UNIX_GLOB=	Makefile *.c
DOS2UNIX_WRKSRC=	${WRKDIR}/src/native
JAVA_VERSION=	1.6+
JAVA_OS=	native
ALL_TARGET=	release

PLIST_FILES=	lib/libpkcs11wrapper.so ${JAVAJARDIR}/iaikPkcs11Wrapper.jar

PORTDOCS=	*
PORTEXAMPLES=	*

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
WRKSRC=		${WRKDIR}/src/native/unix/linux-x86_64
.else
WRKSRC=		${WRKDIR}/src/native/unix/linux-x86
.endif

do-install:
	@${ECHO_MSG} -n ">> Installing JNI library in ${PREFIX}/lib..."
	@${INSTALL_PROGRAM} ${WRKSRC}/release/libpkcs11wrapper.so ${STAGEDIR}${PREFIX}/lib/
	@${ECHO_MSG} " [ DONE ]"
	@${ECHO_MSG} -n ">> Installing JAR file as ${JAVAJARDIR}/iaikPkcs11Wrapper.jar..."
	@${INSTALL_DATA} ${WRKDIR}/bin/iaikPkcs11Wrapper.jar ${STAGEDIR}${JAVAJARDIR}/
	@${ECHO_MSG} " [ DONE ]"
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}..."
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKDIR}/docs && ${FIND} * | \
		${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${DOCSDIR} > /dev/null 2>&1
	@${ECHO_MSG} " [ DONE ]"
	@${ECHO_MSG} -n ">> Installing examples in ${EXAMPLESDIR}..."
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@cd ${WRKDIR}/examples && ${FIND} * | \
		${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${EXAMPLESDIR} > /dev/null 2>&1
	@${ECHO_MSG} " [ DONE ]"
.endif

.include <bsd.port.post.mk>
