PORTNAME=	colt
PORTVERSION=	1.2.0
PORTREVISION=	2
CATEGORIES=	science java
MASTER_SITES=	http://acs.lbl.gov/software/colt/colt-download/releases/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java package for scalable scientific and technical computing
WWW=		https://acs.lbl.gov/~hoschek/colt/

JAVA_VERSION=	8

NO_ARCH=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	${JAVAJARDIR}/colt.jar
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS COMPILE
OPTIONS_DEFAULT=COMPILE

COMPILE_DESC=	Install the pre-compiled .jar file

COMPILE_USES=	java:ant,run
COMPILE_USES_OFF=	java
COMPILE_USE=	LOCALE=en_US.ISO8859-1
COMPILE_ALL_TARGET=	build
COMPILE_VARS_OFF=	NO_BUILD=yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCOMPILE} && ${PORT_OPTIONS:MDOCS}
ALL_TARGET+=	javadoc
.endif

do-install:
.if ${PORT_OPTIONS:MDOCS}
	@${ECHO_MSG} -n ">> Installing documentation in ${STAGEDIR}${DOCSDIR}..."
	@cd ${WRKSRC}/doc && ${FIND} . -type d -exec ${MKDIR} ${STAGEDIR}${DOCSDIR}/{} \;
	@cd ${WRKSRC}/doc && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${STAGEDIR}${DOCSDIR}/{} \;
	@${ECHO_MSG} " [DONE]"
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/lib/colt.jar ${STAGEDIR}${JAVAJARDIR}

.include <bsd.port.mk>
