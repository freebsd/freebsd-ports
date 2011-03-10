# New ports collection makefile for:	openmq
# Date created:		2009-12-05
# Whom:			Radim Kolar <hsn@sanatana.iol.cz>
#
# $FreeBSD$
#

PORTNAME=	openmq
PORTVERSION=	4.5.b.29
PORTEPOCH=	1
CATEGORIES=	net java
MASTER_SITES=	http://download.java.net/mq/open-mq/4.5/b29/ \
	 	http://download.java.net/maven/2/javax/javaee-api/6.0/:2 \
		http://download.java.net/maven/2/com/sun/grizzly/grizzly-nio-framework/1.9.18a/:3 \
		http://download.java.net/maven/2/com/sun/woodstock/dependlibs/jhall/2.0/:4
DISTFILES=	${SRCDIST} ${BOOTJARS}
EXTRACT_ONLY=	${SRCDIST}

MAINTAINER=	hsn@sendmail.cz
COMMENT=	Open Message Queue - Java Message Service Broker ${CLIENT_COMMENT}

LICENSE=	GPLv2 CDDL
LICENSE_COMB=	dual

SRCDIST=	openmq4_5-source.zip
BOOTJARS=	javaee-api-6.0.jar:2 \
		grizzly-nio-framework-1.9.18a.jar:3 \
		jhall-2.0.jar:4

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6
JAVA_VENDOR=	openjdk

WRKSRC=		${WRKDIR}/mq
PLIST=		${WRKDIR}/pkg-plist

USE_ANT=	yes
.ifndef IMQ_CLIENT
USE_RC_SUBR=	imq
.else
SUB_FILES=	pkg-message
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
		@cd ${WRKSRC}/dist/mq/etc && ${FIND} . -depth 1 -type f -exec \
			${ECHO_CMD} "etc/mq/{}" \; >> ${PLIST}
		@${ECHO_CMD} "@dirrmtry etc/mq" >> ${PLIST}
.ifndef NOPORTDOCS
		@cd ${WRKSRC}/dist/mq/javadoc && ${FIND} . -type f -exec \
			${ECHO_CMD} "%%DOCSDIR%%/{} " \; >> ${PLIST}
		@cd ${WRKSRC}/dist/mq/javadoc && ${FIND} -d . -mindepth 1 -type d -exec \
			${ECHO_CMD} "@dirrm %%DOCSDIR%%/{}" \; >> ${PLIST}
		@cd ${WRKSRC}/dist/mq/examples && ${FIND} . -type f -exec \
			${ECHO_CMD} "%%EXAMPLESDIR%%/{}" \; >> ${PLIST}
		@cd ${WRKSRC}/dist/mq/examples && ${FIND} -d . -mindepth 1 -type d -exec \
			${ECHO_CMD} "@dirrm %%EXAMPLESDIR%%/{}" \; >> ${PLIST}
		@${ECHO_CMD} "@dirrm %%EXAMPLESDIR%%" >> ${PLIST}
		@${ECHO_CMD} "@dirrm %%DOCSDIR%%" >> ${PLIST}
.endif
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
		@${MKDIR} ${PREFIX}/imq
		@${MKDIR} ${PREFIX}/etc/mq
		@cd ${WRKSRC}/dist/mq && ${FIND} bin lib | \
			${CPIO} --quiet -pdmu -R ${BINOWN}:${BINGRP} ${PREFIX}/imq
		@cd ${WRKSRC}/dist/mq/etc && ${FIND} . -depth 1 -type f | \
			${CPIO} --quiet -pdmu -R ${BINOWN}:${BINGRP} ${PREFIX}/etc/mq
		@${CHMOD} 640 ${PREFIX}/etc/mq/*.sample
.if !defined(NOPORTDOCS)
		@${MKDIR} ${DOCSDIR}
		@cd ${WRKSRC}/dist/mq/javadoc && ${FIND} . | \
			${CPIO} --quiet -pdmu -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
		@${MKDIR} ${EXAMPLESDIR}
		@cd ${WRKSRC}/dist/mq/examples && ${FIND} . | \
			${CPIO} --quiet -pdmu -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
.endif
.else
		@${INSTALL_DATA} ${WRKSRC}/dist/mq/lib/imq.jar ${JAVAJARDIR}
		@${INSTALL_DATA} ${WRKSRC}/dist/mq/lib/jms.jar ${JAVAJARDIR}
		@${INSTALL_DATA} ${WRKSRC}/dist/mq/lib/fscontext.jar ${JAVAJARDIR}
		@${INSTALL_DATA} ${WRKSRC}/dist/mq/lib/jaxm-api.jar ${JAVAJARDIR}
		@${INSTALL_DATA} ${WRKSRC}/dist/mq/lib/imqxm.jar ${JAVAJARDIR}
.endif

post-install:
.ifdef IMQ_CLIENT
		@${CAT} ${PKGMESSAGE}
.else
		@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif

.include <bsd.port.mk>
