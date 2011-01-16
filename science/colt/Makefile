# Ports collection makefile for:        colt
# Date created:                 April 19, 2008
# Whom:                         Wen heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	colt
PORTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	science java
MASTER_SITES=	http://acs.lbl.gov/software/colt/colt-download/releases/

MAINTAINER=	wenheping@gmail.com
COMMENT=	Java package for scalable scientific and technical computing

USE_JAVA=	yes
JAVA_VERSION=	1.4+
WRKSRC=		${WRKDIR}/${PORTNAME}

.if !defined(WITHOUT_COMPILE)
USE_ANT=	yes
ALL_TARGET=	build
.if !defined(NOPORTDOCS)
ALL_TARGET+=	javadoc
.endif
.else
NO_BUILD=	yes
.endif

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

PLIST_FILES=	%%JAVAJARDIR%%/colt.jar

.include <bsd.port.pre.mk>

pre-fetch:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You may use the following build options:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "    WITHOUT_COMPILE=yes    Install the pre-compiled .jar file"
	@${ECHO_MSG} ""

do-install:
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}..."
	@cd ${WRKSRC}/doc && ${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/{} \;
	@cd ${WRKSRC}/doc && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
	@${ECHO_MSG} " [DONE]"
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/lib/colt.jar ${JAVAJARDIR}

.include <bsd.port.post.mk>
