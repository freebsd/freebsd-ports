PORTNAME=	keycloak
DISTVERSION=	26.3.2
CATEGORIES=	net java
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	freebsd@rheinwolf.de
COMMENT=	Identity and access management solution
WWW=		https://www.keycloak.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cpe java shebangfix
CPE_VENDOR=	redhat
JAVA_VERSION=	21+
JAVA_OS=	native
JAVA_VENDOR=	openjdk

USE_RC_SUBR=	keycloak

SHEBANG_FILES=	bin/kc.sh \
		bin/kcadm.sh \
		bin/kcreg.sh

VAR_DIR?=	/var
LOG_DIR?=	${VAR_DIR}/log/${PORTNAME}
RUN_DIR?=	${VAR_DIR}/run/${PORTNAME}

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES+=	pkg-message
SUB_LIST+=	GROUP=${KEYCLOAK_GROUP} \
		JAVA=${JAVA} \
		JAVA_HOME=${JAVA_HOME} \
		LOG_DIR=${LOG_DIR} \
		PORTNAME=${PORTNAME} \
		RUN_DIR=${RUN_DIR} \
		USER=${KEYCLOAK_USER} \
		GROUP=${KEYCLOAK_GROUP}

KEYCLOAK_USER=	${PORTNAME}
KEYCLOAK_GROUP=	${PORTNAME}
USERS=		${KEYCLOAK_USER}
GROUPS=		${USERS}

PLIST_SUB=	VERSION=${DISTVERSION} \
		USER=${KEYCLOAK_USER} \
		GROUP=${KEYCLOAK_GROUP}

OPTIONS_DEFINE=	DOCS EXAMPLES

CONFIG_FILES=	conf/cache-ispn.xml \
		conf/keycloak.conf \
		lib/quarkus/build-system.properties

post-patch:
.for f in ${CONFIG_FILES}
	${MV} ${WRKSRC}/${f} ${WRKSRC}/${f}.sample
.endfor
	${RM} ${WRKSRC}/bin/kc.bat
	${RM} ${WRKSRC}/bin/kcadm.bat
	${RM} ${WRKSRC}/bin/kcreg.bat

do-install:
	${MKDIR} ${STAGEDIR}${JAVASHAREDIR}/${PORTNAME}/bin \
		 ${STAGEDIR}${JAVASHAREDIR}/${PORTNAME}/data \
		 ${STAGEDIR}${LOG_DIR} \
		 ${STAGEDIR}${RUN_DIR}

	# Install files in bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/*.sh ${STAGEDIR}${JAVASHAREDIR}/${PORTNAME}/bin
	(cd ${WRKSRC}/bin && ${COPYTREE_SHARE} client ${STAGEDIR}${JAVASHAREDIR}/${PORTNAME}/bin)

	# Install jar files, configuration and everything else
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "conf lib providers themes" ${STAGEDIR}${JAVASHAREDIR}/${PORTNAME})

	# Create links for kc* binaries
	${LN} -sf ../share/java/${PORTNAME}/bin/kcadm.sh ${STAGEDIR}${PREFIX}/bin/kcadm
	${LN} -sf ../share/java/${PORTNAME}/bin/kcreg.sh ${STAGEDIR}${PREFIX}/bin/kcreg

.include <bsd.port.mk>
