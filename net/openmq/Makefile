# Created by: Radim Kolar <hsn@sendmail.cz>
# $FreeBSD$

PORTNAME=	openmq
PORTVERSION=	4.5.2.p.1
PORTEPOCH=	1
CATEGORIES=	net java
MASTER_SITES=	http://download.java.net/mq/open-mq/4.5.2/b03/ \
	 	http://download.java.net/maven/2/javax/javaee-api/6.0/:2 \
		http://download.java.net/maven/2/com/sun/grizzly/grizzly-nio-framework/1.9.18a/:3 \
		http://download.java.net/maven/2/com/sun/woodstock/dependlibs/jhall/2.0/:4
DISTFILES=	${SRCDIST} ${BOOTJARS}
EXTRACT_ONLY=	${SRCDIST}

MAINTAINER=	hsn@sendmail.cz
COMMENT=	Open Message Queue - Java Message Service Broker ${CLIENT_COMMENT}

LICENSE=	GPLv2 CDDL
LICENSE_COMB=	dual

SRCDIST=	mq4_5_2p1-source.zip
BOOTJARS=	javaee-api-6.0.jar:2 \
		grizzly-nio-framework-1.9.18a.jar:3 \
		jhall-2.0.jar:4

USES=		zip
USE_JAVA=	yes
JAVA_VERSION=	1.6+
JAVA_VENDOR=	openjdk

WRKSRC=		${WRKDIR}/mq
PLIST=		${WRKDIR}/pkg-plist
MAKE_ENV+=	ANT_OPTS=-Xmx1g

.ifndef IMQ_CLIENT
OPTIONS_DEFINE=	DOCS EXAMPLES
.endif

USE_ANT=	yes
.ifndef IMQ_CLIENT
USE_RC_SUBR=	imq
.else
SUB_FILES=	pkg-message
.endif

.include <bsd.port.pre.mk>
 
.if ${JAVA_PORT_VERSION:M1.8.*}
BROKEN=		Does not build with JDK 1.8
.endif

# Get the bootstrap jars in place before the build starts, because
# pointyhat doesn't allow them to be downloaded by the "bootstrap"
# target in the Ant file.
pre-build:
		@${MKDIR} ${WRKSRC}/extlib
		@${CP} ${DISTDIR}/javaee-api-6.0.jar \
			${WRKSRC}/extlib/javaee-api-6.0.jar
		@${CP} ${DISTDIR}/grizzly-nio-framework-1.9.18a.jar \
			${WRKSRC}/extlib/grizzly.jar
		@${CP} ${DISTDIR}/jhall-2.0.jar \
			${WRKSRC}/extlib/jhall.jar

post-build:
		@${RM} ${WRKSRC}/dist/mq/bin/*.exe
		@cd ${WRKSRC}/dist/mq/etc && \
			${MV} imqenv.conf imqenv.conf.sample
		@cd ${WRKSRC}/dist/mq/etc && \
			${MV} imqbrokerd.conf imqbrokerd.conf.sample
pre-install:
.ifndef IMQ_CLIENT
		@cd ${WRKSRC}/dist/mq && ${FIND} bin lib -type f -exec \
			${ECHO_CMD} "imq/{}" \; > ${PLIST}
		@cd ${WRKSRC}/dist/mq && ${FIND} -d bin lib -type d -exec \
			${ECHO_CMD} "@dirrm imq/{}" \; >> ${PLIST}
		@cd ${WRKSRC}/dist/mq && ${FIND} etc -depth 1 -type f -print | \
			${SED} -e "\-/-s--/mq/-" >> ${PLIST}
		@${ECHO_CMD} "@dirrmtry etc/mq" >> ${PLIST}

		@cd ${WRKSRC}/dist/mq && ${FIND} javadoc -type f -print | \
			${SED} -e "/^javadoc/s//%%PORTDOCS%%%%DOCSDIR%%/" >> ${PLIST}
		@cd ${WRKSRC}/dist/mq && ${FIND} -d javadoc -mindepth 1 -type d -print | \
			${SED} -e "/^javadoc/s//%%PORTDOCS%%@dirrm %%DOCSDIR%%/" >> ${PLIST}
		@${ECHO_CMD} "%%PORTDOCS%%@dirrm %%DOCSDIR%%" >> ${PLIST}

		@cd ${WRKSRC}/dist/mq && ${FIND} examples -type f -print | \
			${SED} -e "/^examples/s//%%PORTEXAMPLES%%%%EXAMPLESDIR%%/" >> ${PLIST}
		@cd ${WRKSRC}/dist/mq && ${FIND} -d examples -mindepth 1 -type d -print | \
			${SED} -e "/^examples/s//%%PORTEXAMPLES%%@dirrm %%EXAMPLESDIR%%/" >> ${PLIST}
		@${ECHO_CMD} "%%PORTEXAMPLES%%@dirrm %%EXAMPLESDIR%%" >> ${PLIST}

		@${ECHO_CMD} "@dirrmtry imq" >> ${PLIST}
.else
		@${ECHO_CMD} "%%JAVAJARDIR%%/jms.jar" > ${PLIST}
		@${ECHO_CMD} "%%JAVAJARDIR%%/imq.jar" >> ${PLIST}
		@${ECHO_CMD} "%%JAVAJARDIR%%/fscontext.jar" >> ${PLIST}
		@${ECHO_CMD} "%%JAVAJARDIR%%/jaxm-api.jar" >> ${PLIST}
		@${ECHO_CMD} "%%JAVAJARDIR%%/imqxm.jar" >> ${PLIST}
.endif

do-install:
.ifndef IMQ_CLIENT
		@${MKDIR} ${STAGEDIR}${PREFIX}/imq
		@${MKDIR} ${STAGEDIR}${PREFIX}/etc/mq
		@cd ${WRKSRC}/dist/mq && ${FIND} bin lib | \
			${CPIO} --quiet -pdmu -R ${BINOWN}:${BINGRP} ${STAGEDIR}${PREFIX}/imq
		@cd ${WRKSRC}/dist/mq/etc && ${FIND} . -depth 1 -type f | \
			${CPIO} --quiet -pdmu -R ${BINOWN}:${BINGRP} ${STAGEDIR}${PREFIX}/etc/mq
		@${CHMOD} 640 ${STAGEDIR}${PREFIX}/etc/mq/*.sample
.if ${PORT_OPTIONS:MDOCS}
		@${MKDIR} ${STAGEDIR}${DOCSDIR}
		@cd ${WRKSRC}/dist/mq/javadoc && ${FIND} . | \
			${CPIO} --quiet -pdmu -R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
		@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
		@cd ${WRKSRC}/dist/mq/examples && ${FIND} . | \
			${CPIO} --quiet -pdmu -R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${EXAMPLESDIR}
.endif
.else
		@${INSTALL_DATA} ${WRKSRC}/dist/mq/lib/imq.jar ${STAGEDIR}${JAVAJARDIR}
		@${INSTALL_DATA} ${WRKSRC}/dist/mq/lib/jms.jar ${STAGEDIR}${JAVAJARDIR}
		@${INSTALL_DATA} ${WRKSRC}/dist/mq/lib/fscontext.jar ${STAGEDIR}${JAVAJARDIR}
		@${INSTALL_DATA} ${WRKSRC}/dist/mq/lib/jaxm-api.jar ${STAGEDIR}${JAVAJARDIR}
		@${INSTALL_DATA} ${WRKSRC}/dist/mq/lib/imqxm.jar ${STAGEDIR}${JAVAJARDIR}
.endif

.include <bsd.port.post.mk>
