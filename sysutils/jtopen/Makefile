# New ports collection makefile for:	jtopen
# Date created:		2008-06-13
# Whom:			Marcin Cieslak <saper@SYSTEM.PL>
#
# $FreeBSD$
#

PORTNAME=	jtopen
PORTVERSION=	6.2
CATEGORIES=	sysutils java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	jt400
DISTNAME=	${PORTNAME}_${PORTVERSION:S/./_/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	JTOpen is a Java library to access OS/400 or i5/OS system

USE_ZIP=	yes
NO_WRKSUBDIR=	yes
USE_JAVA=	1.4+

NO_BUILD=	yes

JAR_FILES=	composer.jar jt400.jar jt400Proxy.jar jt400Servlet.jar jui400.jar \
		outputwriters.jar reportwriter.jar tes.jar uitools.jar util400.jar
DOC_FILES=	changes.html license.html readme.html

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
