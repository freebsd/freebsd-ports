# Created by: Richard Gallamore <ultima@FreeBSD.org>
# $FreeBSD$

PORTNAME=	guacamole-client
DISTVERSION=	1.1.0
CATEGORIES=	www java
MASTER_SITES+=	https://sourceforge.net/projects/distfiles/files/${PORTNAME}/:repo \
		http://sourceforge.net/projects/distfiles/files/${PORTNAME}/:repo
DISTFILES=	repository-${DISTVERSION}${EXTRACT_SUFX}:repo
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ultima@FreeBSD.org
COMMENT=	HTML5 Clientless Remote Desktop

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/share/java/maven33/bin/mvn:devel/maven33

USES=		tar:xz
USE_JAVA=	yes
JAVA_VERSION=	1.8+

USE_GITHUB=	yes
GH_ACCOUNT=	apache

MVN=		mvn
MVN_ARGS=	package -Duser.home=${WRKDIR}
NO_ARCH=	yes

SUB_FILES=	pkg-message

OPTIONS_DEFINE=		SERVER TOMCAT
OPTIONS_DEFAULT=	SERVER TOMCAT
OPTIONS_SUB=		yes

SERVER_DESC=		Include Guacamole Server
TOMCAT_DESC=		Use Tomcat as your servlet

TOMCAT_PLIST_SUB=	TOMCAT_VER=${TOMCAT_VER}
TOMCAT_RUN_DEPENDS=	${LOCALBASE}/apache-tomcat-${TOMCAT_VER}/bin/bootstrap.jar:www/tomcat${TOMCAT_VER:C/\.[0]?//}
TOMCAT_VARS=		TOMCAT_VER=9.0

SERVER_RUN_DEPENDS=	guacd:net/guacamole-server

AUTH_EXTENSION=	cas duo header ldap openid quickconnect totp

post-patch:
		@${REINPLACE_CMD} 's|/etc/guacamole|${ETCDIR}| ; \
			s|"/etc"|"${ETCDIR:S|/${PORTNAME}||}"|' \
			${WRKSRC}/guacamole-ext/src/main/java/org/apache/guacamole/environment/LocalEnvironment.java

do-build:
		cd ${WRKSRC} && ${MVN} ${MVN_ARGS}

do-install:
		@${MKDIR} ${STAGEDIR}${DATADIR}
		@${MKDIR} ${STAGEDIR}${ETCDIR}

		${INSTALL_DATA} ${WRKSRC}/guacamole/target/guacamole-${DISTVERSIONFULL}.war \
			${STAGEDIR}${DATADIR}/guacamole.war
.for i in ${AUTH_EXTENSION}
		${INSTALL_DATA} ${WRKSRC}/extensions/guacamole-auth-$i/target/guacamole-auth-$i-${DISTVERSIONFULL}.tar.gz \
			${STAGEDIR}/${DATADIR}/guacamole-auth-$i.tar.gz
.endfor
		${INSTALL_DATA} ${WRKSRC}/extensions/guacamole-auth-jdbc/modules/guacamole-auth-jdbc-dist/target/guacamole-auth-jdbc-${DISTVERSIONFULL}.tar.gz \
			${STAGEDIR}/${DATADIR}/guacamole-auth-jdbc.tar.gz
		${INSTALL_DATA} ${FILESDIR}/user-mapping.xml.sample ${STAGEDIR}${ETCDIR}/
		${INSTALL_DATA} ${FILESDIR}/logback.xml.sample ${STAGEDIR}${ETCDIR}/
		${INSTALL_DATA} ${FILESDIR}/guacamole.properties.sample ${STAGEDIR}${ETCDIR}/

do-install-TOMCAT-on:
		@${MKDIR} ${STAGEDIR}${PREFIX}/apache-tomcat-${TOMCAT_VER}/webapps
		${RLN} ${STAGEDIR}${DATADIR}/guacamole.war \
			${STAGEDIR}${PREFIX}/apache-tomcat-${TOMCAT_VER}/webapps

.include <bsd.port.mk>
