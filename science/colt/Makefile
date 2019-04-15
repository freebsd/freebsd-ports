# Created by: Wen heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	colt
PORTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	science java
MASTER_SITES=	http://acs.lbl.gov/software/colt/colt-download/releases/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java package for scalable scientific and technical computing

USE_JAVA=	yes
JAVA_VERSION=	1.6+
WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=	DOCS COMPILE
OPTIONS_DEFAULT=COMPILE
COMPILE_DESC=	Install the pre-compiled .jar file

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCOMPILE}
USE_ANT=	yes
USE_LOCALE=	en_US.ISO8859-1
ALL_TARGET=	build
.if ${PORT_OPTIONS:MDOCS}
ALL_TARGET+=	javadoc
.endif
.else
NO_BUILD=	yes
.endif

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	*
.endif

PLIST_FILES=	%%JAVAJARDIR%%/colt.jar

.include <bsd.port.pre.mk>

do-install:
.if ${PORT_OPTIONS:MDOCS}
	@${ECHO_MSG} -n ">> Installing documentation in ${STAGEDIR}${DOCSDIR}..."
	@cd ${WRKSRC}/doc && ${FIND} . -type d -exec ${MKDIR} ${STAGEDIR}${DOCSDIR}/{} \;
	@cd ${WRKSRC}/doc && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${STAGEDIR}${DOCSDIR}/{} \;
	@${ECHO_MSG} " [DONE]"
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/lib/colt.jar ${STAGEDIR}${JAVAJARDIR}

.include <bsd.port.post.mk>
