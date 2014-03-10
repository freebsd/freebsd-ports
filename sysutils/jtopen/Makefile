# Created by: Marcin Cieslak <saper@SYSTEM.PL>
# $FreeBSD$

PORTNAME=	jtopen
PORTVERSION=	6.2
CATEGORIES=	sysutils java
MASTER_SITES=	SF/jt400/JTOpen-full/${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION:S/./_/}

MAINTAINER=	saper@saper.info
COMMENT=	JTOpen is a Java library to access OS/400 or i5/OS system

USES=		zip
NO_WRKSUBDIR=	yes
USE_JAVA=	1.4+

NO_BUILD=	yes

JAR_FILES=	composer.jar jt400.jar jt400Proxy.jar jt400Servlet.jar jui400.jar \
		outputwriters.jar reportwriter.jar tes.jar uitools.jar util400.jar
DOC_FILES=	changes.html license.html readme.html

NO_STAGE=	yes
.include <bsd.port.pre.mk>

do-install:
.for i in ${JAR_FILES}
	${INSTALL_DATA} ${WRKSRC}/lib/${i} ${JAVAJARDIR}
.endfor

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for d in ${DOC_FILES}
	${INSTALL_MAN} ${WRKSRC}/${d} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
