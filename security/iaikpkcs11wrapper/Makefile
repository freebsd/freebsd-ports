# New ports collection makefile for:    iaikPkcs11Wrapper
# Date created:			19 Feb 2007
# Whom:				Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	iaikPkcs11Wrapper
PORTVERSION=	1.2.17
CATEGORIES=	security java devel
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	ale
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A PKCS\#11 Java wrapper

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.2+
JAVA_OS=	native
USE_GMAKE=	yes
ALL_TARGET=	release

PLIST_FILES=	lib/libpkcs11wrapper.so %%JAVAJARDIR%%/iaikPkcs11Wrapper.jar

PORTDOCS=	*

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
WRKSRC=		${WRKDIR}/native/platforms/linux_x64
.else
WRKSRC=		${WRKDIR}/native/platforms/linux
.endif

do-install:
	@${ECHO_MSG} -n ">> Installing JNI library in ${PREFIX}/lib..."
	@${INSTALL_PROGRAM} ${WRKSRC}/release/libpkcs11wrapper.so ${PREFIX}/lib/
	@${ECHO_MSG} " [ DONE ]"
	@${ECHO_MSG} -n ">> Installing JAR file as ${JAVAJARDIR}/iaikPkcs11Wrapper.jar..."
	@${INSTALL_DATA} ${WRKDIR}/java/lib/iaikPkcs11Wrapper.jar ${JAVAJARDIR}/
	@${ECHO_MSG} " [ DONE ]"
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKDIR}/docs && ${FIND} * | \
		${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR} > /dev/null 2>&1
	@cd ${WRKDIR}/java/docs && ${FIND} api-doc | \
		${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR} > /dev/null 2>&1
	@${ECHO_MSG} " [ DONE ]"
.endif

.include <bsd.port.post.mk>
