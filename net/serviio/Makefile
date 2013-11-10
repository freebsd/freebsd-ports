# Created by: Mikhail Teterin <mi@aldan.algebra.com>
# $FreeBSD$

PORTNAME=	serviio
PORTVERSION=	1.3.1
PORTREVISION=	4
CATEGORIES=	net multimedia java www
MASTER_SITES=	http://download.serviio.org/releases/
EXTRACT_SUFX=	-linux.tar.gz

MAINTAINER=	netchild@FreeBSD.org
COMMENT=	Transcoding DLNA-server implemented in Java

RUN_DEPENDS=	ffmpeg:${PORTSDIR}/multimedia/ffmpeg

NO_BUILD=	yes
USE_JAVA=	yes
USE_DOS2UNIX=	derby.properties

PKGMESSAGE=	${WRKSRC}/pkg-message
SUB_FILES+=	pkg-message serviiod serviio-console
USE_RC_SUBR=	serviio
SUB_LIST+=	USER=${USERS}
RESTRICTED=	License does not allow selling
EXTRACT_AFTER_ARGS=--exclude junit.jar	\
	--exclude org.restlet.ext.net.jar

USERS=	dlna
GROUPS=	dlna

NO_STAGE=	yes
do-install:
	${MKDIR} ${JAVAJARDIR}/${PORTNAME}/plugins
	${INSTALL_DATA} ${WRKSRC}/lib/*.jar ${JAVAJARDIR}/${PORTNAME}/
	${MKDIR} ${PREFIX}/etc/${PORTNAME}
.for f in application-profiles profiles log4j
	${INSTALL_DATA} ${WRKSRC}/config/$f.xml ${ETCDIR}/$f.dist.xml
	${TEST} -e ${ETCDIR}/$f.xml || \
		${INSTALL_DATA} ${WRKSRC}/config/$f.xml ${ETCDIR}/
.endfor
	${INSTALL_DATA} ${FILESDIR}/console-log4j.properties	\
		${ETCDIR}/console-log4j.dist.properties
	${TEST} -e ${ETCDIR}/console-log4.dist.properties || \
		${INSTALL_DATA} ${FILESDIR}/console-log4j.properties ${ETCDIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/serviiod ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKDIR}/serviio-console ${PREFIX}/bin

post-install:
	# =========================================================
	@${FMT} ${PKGMESSAGE}
	# =========================================================

.include <bsd.port.mk>
