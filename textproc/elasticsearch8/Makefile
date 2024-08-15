PORTNAME=	elasticsearch
PORTVERSION=	8.14.3
CATEGORIES=	textproc java devel
MASTER_SITES=	https://artifacts.elastic.co/downloads/${PORTNAME}/
PKGNAMESUFFIX=	8
DISTNAME=	${PORTNAME}-${PORTVERSION}-darwin-x86_64

MAINTAINER=	elastic@FreeBSD.org
COMMENT=	Distributed, RESTful search and analytics engine
WWW=		https://www.elastic.co/

LICENSE=	APACHE20

BUILD_DEPENDS=	jna>0:devel/jna
RUN_DEPENDS=	bash:shells/bash \
		jna>0:devel/jna

USES=		cpe shebangfix
USE_JAVA=	yes
JAVA_VERSION=	17+
USE_RC_SUBR=	${PORTNAME}

SHEBANG_FILES=	bin/elasticsearch bin/elasticsearch-certgen \
		bin/elasticsearch-certutil bin/elasticsearch-cli \
		bin/elasticsearch-create-enrollment-token \
		bin/elasticsearch-croneval bin/elasticsearch-env \
		bin/elasticsearch-env-from-file bin/elasticsearch-geoip \
		bin/elasticsearch-keystore bin/elasticsearch-node \
		bin/elasticsearch-plugin bin/elasticsearch-reconfigure-node \
		bin/elasticsearch-reset-password \
		bin/elasticsearch-saml-metadata \
		bin/elasticsearch-service-tokens \
		bin/elasticsearch-setup-passwords bin/elasticsearch-shard \
		bin/elasticsearch-sql-cli bin/elasticsearch-syskeygen \
		bin/elasticsearch-users

CONFLICTS=	elasticsearch6 elasticsearch7

NO_ARCH=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

CONFIG_FILES=	elasticsearch.yml jvm.options log4j2.properties \
		role_mapping.yml roles.yml
BINS=		elasticsearch elasticsearch-certgen elasticsearch-certutil \
		elasticsearch-cli elasticsearch-create-enrollment-token \
		elasticsearch-croneval elasticsearch-env \
		elasticsearch-env-from-file elasticsearch-geoip \
		elasticsearch-keystore elasticsearch-node elasticsearch-plugin \
		elasticsearch-reconfigure-node elasticsearch-reset-password \
		elasticsearch-saml-metadata elasticsearch-service-tokens \
		elasticsearch-setup-passwords elasticsearch-shard \
		elasticsearch-sql-cli elasticsearch-sql-cli-${PORTVERSION}.jar \
		elasticsearch-syskeygen elasticsearch-users

PORTDOCS=	LICENSE.txt NOTICE.txt README.asciidoc

SIGAR_ARCH=	${ARCH:S|i386|x86|}
SEARCHUSER?=	elasticsearch
SEARCHGROUP?=	${SEARCHUSER}
USERS=		${SEARCHUSER}
GROUPS=		${SEARCHGROUP}

PORTSCOUT=	limit:^8

SUB_FILES=	pkg-message
SUB_LIST=	ETCDIR=${ETCDIR} \
		JAVA_HOME=${JAVA_HOME} \
		BINDIR=${PREFIX}/bin

post-extract:
	${RM} -rf ${WRKSRC}/jdk.app

post-patch:
	${RM} ${WRKSRC}/lib/jna-*.jar
# ML plugin not supported on FreeBSD
	${RM} -rf ${WRKSRC}/modules/x-pack/x-pack-ml
	${RM} -rf ${WRKSRC}/jdk.app
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/bin/elasticsearch-env

do-install:
	${INSTALL} -d -m 0750 ${STAGEDIR}${PREFIX}/etc/elasticsearch
.for f in ${CONFIG_FILES}
	${INSTALL} ${WRKSRC}/config/${f} ${STAGEDIR}${ETCDIR}/${f}.sample
.endfor
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/elasticsearch/bin
.for f in ${BINS}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${f} ${STAGEDIR}${PREFIX}/lib/elasticsearch/bin
	${RLN} ${STAGEDIR}${PREFIX}/lib/elasticsearch/bin/${f} ${STAGEDIR}${PREFIX}/bin/${f}
	${ECHO_CMD} "bin/${f}" >> ${TMPPLIST}
.endfor
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/elasticsearch/lib
	(cd ${WRKSRC}/lib && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib/elasticsearch/lib/ "-name *\.jar")

	${MKDIR} ${STAGEDIR}${PREFIX}/lib/elasticsearch/modules
	(cd ${WRKSRC}/modules && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib/elasticsearch/modules/)
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/elasticsearch/plugins
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/elasticsearch
	${INSTALL} -lrs ${STAGEDIR}${ETCDIR} ${STAGEDIR}${PREFIX}/lib/elasticsearch/config
	${LN} -s ${JAVASHAREDIR}/classes/jna.jar ${STAGEDIR}${PREFIX}/lib/elasticsearch/lib/jna-0.0.0.jar
	${TOUCH} ${STAGEDIR}${ETCDIR}/users.sample ${STAGEDIR}${ETCDIR}/users_roles.sample

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

post-install:
	${ECHO} "@sample ${ETCDIR}/elasticsearch.yml.sample" >> ${TMPPLIST}
	${ECHO} "@sample ${ETCDIR}/jvm.options.sample" >> ${TMPPLIST}
	${ECHO} "@sample ${ETCDIR}/log4j2.properties.sample" >> ${TMPPLIST}
	${ECHO} "@sample ${ETCDIR}/role_mapping.yml.sample" >> ${TMPPLIST}
	${ECHO} "@sample ${ETCDIR}/roles.yml.sample" >> ${TMPPLIST}
	${FIND} -s ${STAGEDIR}${PREFIX}/lib/elasticsearch -not -type d | ${SORT} | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/##' >> ${TMPPLIST}
	${ECHO} "@dir lib/elasticsearch/plugins" >> ${TMPPLIST}
	${ECHO} "@dir libexec/elasticsearch" >> ${TMPPLIST}
	${ECHO} "@dir(${SEARCHUSER},${SEARCHGROUP},0755) ${ETCDIR}" >> ${TMPPLIST}
	${ECHO} "@owner ${SEARCHUSER}" >> ${TMPPLIST}
	${ECHO} "@group ${SEARCHGROUP}" >> ${TMPPLIST}
	${ECHO} "@mode 0640" >> ${TMPPLIST}
	${ECHO} "@sample ${ETCDIR}/users.sample" >> ${TMPPLIST}
	${ECHO} "@sample ${ETCDIR}/users_roles.sample" >> ${TMPPLIST}
	${ECHO} "@mode" >> ${TMPPLIST}
	${ECHO} "@owner" >> ${TMPPLIST}
	${ECHO} "@group" >> ${TMPPLIST}

.include <bsd.port.mk>
