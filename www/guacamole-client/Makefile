# Created by: Richard Gallamore <ultima@FreeBSD.org>
# $FreeBSD$

PORTNAME=	guacamole-client
PORTVERSION=	0.9.13
DISTVERSIONSUFFIX=	-incubating
CATEGORIES=	www java
MASTER_SITES+=	https://sourceforge.net/projects/distfiles/files/${PORTNAME}/:repo \
		http://sourceforge.net/projects/distfiles/files/${PORTNAME}/:repo
DISTFILES=	repository-${PORTVERSION}${EXTRACT_SUFX}:repo
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
GH_PROJECT=	incubator-guacamole-client

MVN=		mvn
MVN_ARGS=	package -Duser.home=${WRKDIR}
NO_ARCH=	yes

SUB_FILES=	pkg-message

OPTIONS_DEFINE=		MK_LINK SERVER TOMCAT
OPTIONS_DEFAULT=	MK_LINK SERVER TOMCAT
OPTIONS_SUB=		yes

MK_LINK_DESC=		Make sybolic links
SERVER_DESC=		Include Guacamole Server
TOMCAT_DESC=		Use Tomcat as your servlet

TOMCAT_RUN_DEPENDS=	${LOCALBASE}/apache-tomcat-8.0/bin/bootstrap.jar:www/tomcat8
SERVER_RUN_DEPENDS=	guacd:net/guacamole-server

AUTH_EXTENSION=	duo cas header ldap noauth

.include <bsd.port.pre.mk>

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

do-install-MK_LINK-on:
		@${MKDIR} ${STAGEDIR}/root
		${RLN} ${STAGEDIR}/${ETCDIR} ${STAGEDIR}/root/.guacamole
.if ${PORT_OPTIONS:MTOMCAT}
		@${MKDIR} ${STAGEDIR}${PREFIX}/apache-tomcat-8.0/webapps
		${RLN} ${STAGEDIR}${DATADIR}/guacamole.war \
			${STAGEDIR}${PREFIX}/apache-tomcat-8.0/webapps
.endif

.include <bsd.port.post.mk>
