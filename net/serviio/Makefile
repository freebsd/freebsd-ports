# Created by: Mikhail Teterin <mi@aldan.algebra.com>
# $FreeBSD$

PORTNAME=	serviio
PORTVERSION=	1.8
PORTREVISION=	1
#PORTREVISION=	0
CATEGORIES=	net multimedia java www
MASTER_SITES=	http://download.serviio.org/releases/
EXTRACT_SUFX=	-linux.tar.gz

MAINTAINER=	netchild@FreeBSD.org
COMMENT=	Transcoding DLNA-server implemented in Java

RUN_DEPENDS=	ffmpeg:multimedia/ffmpeg

NO_BUILD=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.8
USES=		dos2unix
DOS2UNIX_GLOB=	derby.properties

PKGMESSAGE=	${WRKSRC}/pkg-message
SUB_FILES+=	pkg-message serviiod
USE_RC_SUBR=	serviio
SUB_LIST+=	USER=${USERS}
RESTRICTED=	License does not allow selling
EXTRACT_AFTER_ARGS=--exclude junit.jar	\
	--exclude org.restlet.ext.net.jar

USERS=	dlna
GROUPS=	dlna

do-install:
	${MKDIR} ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}/plugins
	${INSTALL_DATA} ${WRKSRC}/lib/*.jar \
		${STAGEDIR}${JAVAJARDIR}/${PORTNAME}/
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/${PORTNAME}
.for f in application-profiles profiles log4j
	${INSTALL_DATA} ${WRKSRC}/config/$f.xml \
		${STAGEDIR}${ETCDIR}/$f.xml.sample
.endfor
	${INSTALL_DATA} ${FILESDIR}/console-log4j.properties	\
		${STAGEDIR}${ETCDIR}/console-log4j.properties.sample
	${INSTALL_SCRIPT} ${WRKDIR}/serviiod ${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>
