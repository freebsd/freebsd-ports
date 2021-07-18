PORTNAME=	keycloak
PORTVERSION=	14.0.0
CATEGORIES=	net java
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/${PORTVERSION}/

MAINTAINER=	freebsd@rheinwolf.de
COMMENT=	Identity and access management solution

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

FLAVORS=	default mysql postgres
FLAVOR?=	${FLAVORS:[1]}
mysql_PKGNAMESUFFIX=	-mysql
postgres_PKGNAMESUFFIX=	-postgres

.if ${FLAVOR:U} == mysql
RUN_DEPENDS+=	${JAVAJARDIR}/mysql-connector-java.jar:databases/mysql-connector-java
PLIST_SUB+=	MYSQL=""
.else
PLIST_SUB+=	MYSQL="@comment "
.endif

.if ${FLAVOR:U} == postgres
RUN_DEPENDS+=	${JAVAJARDIR}/postgresql.jar:databases/postgresql-jdbc
PLIST_SUB+=	POSTGRES=""
.else
PLIST_SUB+=	POSTGRES="@comment "
.endif

USE_JAVA=	yes
JAVA_VERSION=	1.8+
JAVA_OS=	native
JAVA_VENDOR=	openjdk oracle
JAVA_RUN=	yes

USE_RC_SUBR=	keycloak

USER=		www
GROUP=		www

VAR_DIR?=	/var
LOG_DIR?=	${VAR_DIR}/log/${PORTNAME}
RUN_DIR?=	${VAR_DIR}/run/${PORTNAME}

NO_ARCH=	yes
NO_BUILD=	yes

SUB_LIST+=	GROUP=${GROUP} \
		LOG_DIR=${LOG_DIR} \
		JAVA=${JAVA} \
		PORTNAME=${PORTNAME} \
		RUN_DIR=${RUN_DIR} \
		USER=${USER}

OPTIONS_DEFINE=	DOCS EXAMPLES

CONFIG_FILES=	bin/.jbossclirc \
		bin/add-user.properties \
		bin/domain.conf \
		bin/jboss-cli-logging.properties \
		bin/jboss-cli.xml bin/product.conf \
		bin/standalone.conf \
		domain/configuration/application-roles.properties \
		domain/configuration/application-users.properties \
		domain/configuration/default-server-logging.properties \
		domain/configuration/domain.xml \
		domain/configuration/host-master.xml \
		domain/configuration/host-slave.xml \
		domain/configuration/host.xml \
		domain/configuration/logging.properties \
		domain/configuration/mgmt-groups.properties \
		domain/configuration/mgmt-users.properties \
		modules/layers.conf \
		standalone/configuration/application-roles.properties \
		standalone/configuration/application-users.properties \
		standalone/configuration/logging.properties \
		standalone/configuration/mgmt-groups.properties \
		standalone/configuration/mgmt-users.properties \
		standalone/configuration/standalone-ha.xml \
		standalone/configuration/standalone.xml

post-patch:
.for f in ${CONFIG_FILES}
	${MV} ${WRKSRC}/${f} ${WRKSRC}/${f}.sample
.endfor
	${RM} -r ${WRKSRC}/modules/system/layers/base/org/apache/activemq/artemis/journal/main/lib/linux-i686
	${RM} -r ${WRKSRC}/modules/system/layers/base/org/apache/activemq/artemis/journal/main/lib/linux-x86_64
	${RM} -r ${WRKSRC}/modules/system/layers/base/org/wildfly/openssl/main/lib

do-install:
	${MKDIR} ${STAGEDIR}${JAVASHAREDIR}/${PORTNAME}/bin
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${MKDIR} ${STAGEDIR}${LOG_DIR}/domain
	${MKDIR} ${STAGEDIR}${LOG_DIR}/standalone
	${MKDIR} ${STAGEDIR}${RUN_DIR}

	# Install files in bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/*.sh ${STAGEDIR}${JAVASHAREDIR}/${PORTNAME}/bin
.for f in .jbossclirc.sample add-user.properties.sample domain.conf.sample jboss-cli-logging.properties.sample jboss-cli.xml.sample \
	launcher.jar migrate-domain-clustered.cli migrate-domain-standalone.cli migrate-standalone-ha.cli migrate-standalone.cli \
	product.conf.sample standalone.conf.sample wildfly-elytron-tool.jar
	${INSTALL_DATA} ${WRKSRC}/bin/${f} ${STAGEDIR}${JAVASHAREDIR}/${PORTNAME}/bin
.endfor
	${INSTALL_DATA} ${WRKSRC}/jboss-modules.jar ${STAGEDIR}${JAVASHAREDIR}/${PORTNAME}
	(cd ${WRKSRC}/bin && ${COPYTREE_SHARE} client ${STAGEDIR}${JAVASHAREDIR}/${PORTNAME}/bin)

	# Install jar files, configuration and everything else
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "domain modules standalone themes welcome-content" ${STAGEDIR}${JAVASHAREDIR}/${PORTNAME})
	(cd ${WRKSRC}/docs/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})
.for d in licenses-keycloak schema
	(cd ${WRKSRC}/docs/${d} && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/${d})
.endfor

	# Create links for kc* binaries
	${LN} -sf ../share/java/${PORTNAME}/bin/kcadm.sh ${STAGEDIR}${PREFIX}/bin/kcadm
	${LN} -sf ../share/java/${PORTNAME}/bin/kcreg.sh ${STAGEDIR}${PREFIX}/bin/kcreg

	# Create links for log directories
	${LN} -sf ../../../../../..${LOG_DIR}/domain ${STAGEDIR}${JAVASHAREDIR}/${PORTNAME}/domain/log
	${LN} -sf ../../../../../..${LOG_DIR}/standalone ${STAGEDIR}${JAVASHAREDIR}/${PORTNAME}/standalone/log

.if ${FLAVOR:U} == mysql
	@${MKDIR} ${STAGEDIR}${JAVASHAREDIR}/${PORTNAME}/modules/system/layers/keycloak/com/mysql/main
	${CP} ${FILESDIR}/mysql-module.xml ${STAGEDIR}${JAVASHAREDIR}/${PORTNAME}/modules/system/layers/keycloak/com/mysql/main/module.xml
	${LN} -sf ${JAVAJARDIR}/mysql-connector-java.jar ${STAGEDIR}${JAVASHAREDIR}/${PORTNAME}/modules/system/layers/keycloak/com/mysql/main/mysql-connector-java.jar
.endif

.if ${FLAVOR:U} == postgres
	@${MKDIR} ${STAGEDIR}${JAVASHAREDIR}/${PORTNAME}/modules/system/layers/keycloak/org/postgresql/main
	${CP} ${FILESDIR}/postgresql-module.xml ${STAGEDIR}${JAVASHAREDIR}/${PORTNAME}/modules/system/layers/keycloak/org/postgresql/main/module.xml
	${LN} -sf ${JAVAJARDIR}/postgresql.jar ${STAGEDIR}${JAVASHAREDIR}/${PORTNAME}/modules/system/layers/keycloak/org/postgresql/main/postgresql.jar
.endif

.include <bsd.port.mk>
