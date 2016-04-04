# Created by: Ultima <ultima1252@gmail.com>
# $FreeBSD$

PORTNAME=	guacamole-client
PORTVERSION=	0.9.9
CATEGORIES=	www java
MASTER_SITES+=	https://sourceforge.net/projects/distfiles/files/${PORTNAME}/:repo \
		http://sourceforge.net/projects/distfiles/files/${PORTNAME}/:repo
DISTNAME=	${PORTVERSION}
DISTFILES=	${PORTVERSION}_GH${EXTRACT_SUFX} \
		repository-${PORTVERSION}${EXTRACT_SUFX}:repo
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ultima1252@gmail.com
COMMENT=	HTML5 Clientless Remote Desktop

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/share/java/maven33/bin/mvn:devel/maven33

USE_GITHUB=	yes
GH_ACCOUNT=	glyptodon

MVN=		mvn
MVN_ARGS=	package -Duser.home=${WRKDIR}
USE_JAVA=	yes
JAVA_VERSION=	1.8+

OPTIONS_DEFINE=		MK_LINK SERVER TOMCAT
OPTIONS_DEFAULT=	MK_LINK SERVER TOMCAT
OPTIONS_SUB=		yes
MK_LINK_DESC=		Make sybolic links
TOMCAT_RUN_DEPENDS=	${LOCALBASE}/apache-tomcat-8.0/bin/bootstrap.jar:www/tomcat8
TOMCAT_DESC=		Use Tomcat as your servlet

SERVER_RUN_DEPENDS=	guacd:net/guacamole-server
SERVER_DESC=		Include Guacamole Server

GUACAMOLE_CONF=	${PREFIX}/etc/guacamole
GUACAMOLE_DATA=	${PREFIX}/share/${PORTNAME}

.include <bsd.port.pre.mk>

do-build:
		cd ${WRKSRC} && ${MVN} ${MVN_ARGS}

do-install:
		@${MKDIR} ${STAGEDIR}${GUACAMOLE_DATA}
		@${MKDIR} ${STAGEDIR}${GUACAMOLE_CONF}

		@${CP} ${WRKSRC}/guacamole/target/guacamole-${PORTVERSION}.war \
			${STAGEDIR}${GUACAMOLE_DATA}/guacamole.war
		@${CP} ${WRKSRC}/extensions/guacamole-auth-jdbc/target/guacamole-auth-jdbc-${PORTVERSION}.tar.gz \
			${STAGEDIR}/${GUACAMOLE_DATA}/guacamole-auth-jdbc.tar.gz
		@${CP} ${WRKSRC}/extensions/guacamole-auth-ldap/target/guacamole-auth-ldap-${PORTVERSION}.tar.gz \
			 ${STAGEDIR}/${GUACAMOLE_DATA}/guacamole-auth-ldap.tar.gz
		@${CP} ${WRKSRC}/extensions/guacamole-auth-noauth/target/guacamole-auth-noauth-${PORTVERSION}.tar.gz \
			 ${STAGEDIR}/${GUACAMOLE_DATA}/guacamole-auth-noauth.tar.gz

.if ${PORT_OPTIONS:MMK_LINK}
		@${MKDIR} ${STAGEDIR}/root
		@${MKDIR} ${STAGEDIR}${PREFIX}/apache-tomcat-8.0/webapps
		@${LN} -s ${GUACAMOLE_CONF} ${STAGEDIR}/root/.guacamole
		@${LN} -s ${GUACAMOLE_DATA}/guacamole.war \
			${STAGEDIR}${PREFIX}/apache-tomcat-8.0/webapps/
.endif
		@${CP} ${FILESDIR}/user-mapping.xml.sample ${STAGEDIR}${GUACAMOLE_CONF}/
		@${CP} ${FILESDIR}/logback.xml.sample ${STAGEDIR}${GUACAMOLE_CONF}/
		@${CP} ${FILESDIR}/guacamole.properties.sample ${STAGEDIR}${GUACAMOLE_CONF}/

.include <bsd.port.post.mk>
