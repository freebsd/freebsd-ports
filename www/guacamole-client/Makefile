PORTNAME=	guacamole-client
DISTVERSION=	1.6.0
CATEGORIES=	www java
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=	guacamole/${DISTVERSIONFULL}/binary
DISTFILES=	guacamole-${DISTVERSIONFULL}.war \
		guacamole-auth-ban-${DISTVERSIONFULL}${EXTRACT_SUFX} \
		guacamole-auth-duo-${DISTVERSIONFULL}${EXTRACT_SUFX} \
		guacamole-auth-header-${DISTVERSIONFULL}${EXTRACT_SUFX} \
		guacamole-auth-jdbc-${DISTVERSIONFULL}${EXTRACT_SUFX} \
		guacamole-auth-json-${DISTVERSIONFULL}${EXTRACT_SUFX} \
		guacamole-auth-ldap-${DISTVERSIONFULL}${EXTRACT_SUFX} \
		guacamole-auth-quickconnect-${DISTVERSIONFULL}${EXTRACT_SUFX} \
		guacamole-auth-sso-${DISTVERSIONFULL}${EXTRACT_SUFX} \
		guacamole-auth-restrict-${DISTVERSIONFULL}${EXTRACT_SUFX} \
		guacamole-auth-totp-${DISTVERSIONFULL}${EXTRACT_SUFX} \
		guacamole-display-statistics-${DISTVERSIONFULL}${EXTRACT_SUFX} \
		guacamole-history-recording-storage-${DISTVERSIONFULL}${EXTRACT_SUFX} \
		guacamole-vault-${DISTVERSIONFULL}${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ultima@FreeBSD.org
COMMENT=	HTML5 Clientless Remote Desktop
WWW=		https://guacamole.incubator.apache.org

LICENSE=	APACHE20

NO_ARCH=	yes
NO_BUILD=	yes

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

do-extract:

do-install:
		@${MKDIR} ${STAGEDIR}${DATADIR}
		@${MKDIR} ${STAGEDIR}${ETCDIR}
		@${MKDIR} ${STAGEDIR}/etc

		${INSTALL_DATA} ${_DISTDIR}/${DISTFILES:M*.war} \
			${STAGEDIR}${DATADIR}/guacamole.war
.for i in ${DISTFILES:N*.war}
		${INSTALL_DATA} ${_DISTDIR}/${i}${DISTVERSIONFULL}${EXTRACT_SUFX} \
			${STAGEDIR}/${DATADIR}/${i:S|-$||}${EXTRACT_SUFX}
.endfor
		${INSTALL_DATA} ${FILESDIR}/user-mapping.xml.sample ${STAGEDIR}${ETCDIR}/
		${INSTALL_DATA} ${FILESDIR}/logback.xml.sample ${STAGEDIR}${ETCDIR}/
		${INSTALL_DATA} ${FILESDIR}/guacamole.properties.sample ${STAGEDIR}${ETCDIR}/
		${RLN} ${STAGEDIR}${ETCDIR} ${STAGEDIR}/etc/guacamole

do-install-TOMCAT-on:
		@${MKDIR} ${STAGEDIR}${PREFIX}/apache-tomcat-${TOMCAT_VER}/webapps
		${RLN} ${STAGEDIR}${DATADIR}/guacamole.war \
			${STAGEDIR}${PREFIX}/apache-tomcat-${TOMCAT_VER}/webapps

.include <bsd.port.mk>
