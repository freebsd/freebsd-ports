# Created by: Marcin Cieslak <saper@SYSTEM.PL>
# $FreeBSD$

PORTNAME=	jtopen
PORTVERSION=	6.2
CATEGORIES=	sysutils java
MASTER_SITES=	SF/jt400/JTOpen-full/${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION:S/./_/}

MAINTAINER=	saper@saper.info
COMMENT=	Java library to access OS/400 or i5/OS systems

LICENSE=	IBMPL10
LICENSE_NAME=	IBM Public License 1.0
LICENSE_FILE=	${FILESDIR}/IBMPL10
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		zip
NO_WRKSUBDIR=	yes
USE_JAVA=	yes

NO_BUILD=	yes

JAR_FILES=	composer.jar jt400.jar jt400Proxy.jar jt400Servlet.jar jui400.jar \
		outputwriters.jar reportwriter.jar tes.jar uitools.jar util400.jar
DOC_FILES=	changes.html license.html readme.html

OPTIONS_DEFINE=	DOCS

do-install:
.for i in ${JAR_FILES}
	${INSTALL_DATA} ${WRKSRC}/lib/${i} ${STAGEDIR}${JAVAJARDIR}
.endfor
	${MKDIR} ${STAGEDIR}/${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOC_FILES} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
