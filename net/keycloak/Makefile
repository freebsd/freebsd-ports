PORTNAME=	keycloak
DISTVERSION=	23.0.1
CATEGORIES=	net java
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/${PORTVERSION}/

MAINTAINER=	freebsd@rheinwolf.de
COMMENT=	Identity and access management solution
WWW=		https://www.keycloak.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	bash>0:shells/bash

USES=		cpe shebangfix

CPE_VENDOR=	redhat

SHEBANG_FILES=	bin/kc.sh \
		bin/kcadm.sh \
		bin/kcreg.sh

USE_JAVA=	yes
JAVA_VERSION=	17+
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
		JAVA=${JAVA} \
		LOG_DIR=${LOG_DIR} \
		PORTNAME=${PORTNAME} \
		RUN_DIR=${RUN_DIR} \
		USER=${USER}
PLIST_SUB=	VERSION=${DISTVERSION}

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
	${MKDIR} ${STAGEDIR}${JAVASHAREDIR}/${PORTNAME}/bin
	${MKDIR} ${STAGEDIR}${JAVASHAREDIR}/${PORTNAME}/data
	${MKDIR} ${STAGEDIR}${LOG_DIR}
	${MKDIR} ${STAGEDIR}${RUN_DIR}

	# Install files in bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/*.sh ${STAGEDIR}${JAVASHAREDIR}/${PORTNAME}/bin
	(cd ${WRKSRC}/bin && ${COPYTREE_SHARE} client ${STAGEDIR}${JAVASHAREDIR}/${PORTNAME}/bin)

	# Install jar files, configuration and everything else
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "conf lib providers themes" ${STAGEDIR}${JAVASHAREDIR}/${PORTNAME})

	# Create links for kc* binaries
	${LN} -sf ../share/java/${PORTNAME}/bin/kcadm.sh ${STAGEDIR}${PREFIX}/bin/kcadm
	${LN} -sf ../share/java/${PORTNAME}/bin/kcreg.sh ${STAGEDIR}${PREFIX}/bin/kcreg

.include <bsd.port.mk>
