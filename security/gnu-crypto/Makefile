# New ports collection makefile for:	gnu-crypto
# Date created:		Fri Dec 31 00:00:25 UTC 2004
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnu-crypto
PORTVERSION=	2.0.1
PORTREVISION=	2
CATEGORIES=	security java
MASTER_SITES=   ${MASTER_SITE_GNUPG}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Java cryptographic primitives and tools

USE_BZIP2=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

CONFIGURE_ENV+= \
		CLASSPATH='' \
		JAR=${JAR} \
		JAVA=${JAVA} \
		JAVAC=${JAVAC}

USE_JAVA=       yes
JAVA_VERSION=   1.4+
USE_ANT=	yes

JAR_FILES=	\
		javax-crypto.jar \
		javax-security.jar \
		gnu-crypto.jar

INFO=		gnu-crypto
MAKEINFOFLAGS=	--no-split

.for jar in ${JAR_FILES}
PLIST_FILES+=	%%JAVAJARDIR%%/${jar}
.endfor

post-extract:
	@${RM} ${WRKSRC}/docs/*.info*

post-configure:
	@${REINPLACE_CMD} -E \
		-e 's|(\$$\(MAKEINFOFLAGS\))|\1 ${MAKEINFOFLAGS}|' \
		${BUILD_WRKSRC}/docs/${MAKEFILE}

post-build:
	@cd ${WRKSRC}/docs && ${GMAKE} all

do-install:
.for jar in ${JAR_FILES}
	@${INSTALL_DATA} ${WRKSRC}/lib/${jar} ${JAVAJARDIR}
.endfor
	@${MKDIR} ${PREFIX}/${INFO_PATH}
	@${INSTALL_DATA} ${WRKSRC}/docs/${PORTNAME}.info \
		${PREFIX}/${INFO_PATH}

post-install:
	@install-info ${PREFIX}/${INFO_PATH}/${PORTNAME}.info \
		${PREFIX}/${INFO_PATH}/dir

.include <bsd.port.mk>
