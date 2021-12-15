# Created by: Mikhail Teterin <mi@aldan.algebra.com>

PORTNAME=	serviio
PORTVERSION=	2.2.1
PORTREVISION=	0
CATEGORIES=	net multimedia java www
MASTER_SITES=	https://download.serviio.org/releases/
EXTRACT_SUFX=	-linux.tar.gz

MAINTAINER=	netchild@FreeBSD.org
COMMENT=	Transcoding DLNA-server implemented in Java

# Converted from RESTRICTED
LICENSE=	serviio
LICENSE_NAME=	serviio
LICENSE_TEXT=	License does not allow selling
LICENSE_PERMS=	auto-accept

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
EXTRACT_AFTER_ARGS=--exclude junit.jar	\
	--exclude org.restlet.ext.net.jar

USERS=	dlna
GROUPS=	dlna

do-install:
	${MKDIR} ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}/plugins
	${INSTALL_DATA} ${WRKSRC}/lib/*.jar \
		${STAGEDIR}${JAVAJARDIR}/${PORTNAME}/
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/${PORTNAME}
.for f in application-profiles profiles log4j2
	${INSTALL_DATA} ${WRKSRC}/config/$f.xml \
		${STAGEDIR}${ETCDIR}/$f.xml.sample
.endfor
	${INSTALL_DATA} ${WRKSRC}/config/serviio.jks \
		${STAGEDIR}${ETCDIR}/serviio.jks.sample
	${INSTALL_DATA} ${FILESDIR}/console-log4j.properties	\
		${STAGEDIR}${ETCDIR}/console-log4j.properties.sample
	${INSTALL_SCRIPT} ${WRKDIR}/serviiod ${STAGEDIR}${PREFIX}/sbin

# to be used with a non-standard PREFIX for just this port
# e.g. PREFIX=/porttest
mkplist:
	${FIND} ${STAGEDIR}${PREFIX}/ -type f | ${SED} -e "s:${STAGEDIR}${PREFIX}/::g ; s:share/java/classes:%%JAVAJARDIR%%:g ; s:etc/serviio:@sample %%ETCDIR%%:g" | ${GREP} -v etc/rc.d | ${SORT} >${PLIST}.new
#	${FIND} ${STAGEDIR}${PREFIX}/ -type d | ${SED} -e "s:${STAGEDIR}${PREFIX}/:@dirrm :g ; s:etc/serviio:%%ETCDIR%%:g ; s:share/java/classes:%%JAVAJARDIR%%:g" | ${SORT} -r >>${PLIST}.new

.include <bsd.port.mk>
