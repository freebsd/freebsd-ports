PORTNAME=	unifi8
PORTVERSION=	8.0.7
CATEGORIES=	net-mgmt java
MASTER_SITES=	http://dl.ubnt.com/unifi/%SUBDIR%/:unifi \
		https://repo1.maven.org/maven2/%SUBDIR%/:jax
MASTER_SITE_SUBDIR=	${PORTVERSION}/:unifi \
			javax/activation/${_JAX_DISTNAME}/${_JAX_VERSION}/:jax
DISTFILES=	unifi_sysvinit_all.deb:unifi \
		${_JAX_DISTNAME}-${_JAX_VERSION}.jar:jax
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}
EXTRACT_ONLY=	unifi_sysvinit_all.deb

MAINTAINER=	otis@FreeBSD.org
COMMENT=	UniFi Controller v8
WWW=		https://help.ui.com/hc/en-us/categories/200320654-UniFi-Wireless

RUN_DEPENDS=	snappyjava>0:archivers/snappy-java

FLAVORS=	default externaldb
FLAVOR?=	${FLAVORS:[1]}

externaldb_PKGNAMESUFFIX=	-externaldb

USES=		cpe

CPE_VENDOR=	ui
CPE_PRODUCT=	unifi_controller
USE_JAVA=	yes
JAVA_VERSION=	17
JAVA_RUN=	jre
USE_RC_SUBR=	unifi

CONFLICTS_INSTALL=	unifi7

EXTRACT_CMD=	${AR}
EXTRACT_BEFORE_ARGS=	-p
EXTRACT_AFTER_ARGS=	data.tar.xz | ${TAR} -xf -

NO_ARCH=	yes
NO_BUILD=	yes

SUB_LIST+=	GROUPS=${GROUPS} \
		JAVA=${JAVA} \
		JAVA_HOME=${JAVA_HOME} \
		JAVASHAREDIR=${JAVASHAREDIR} \
		USERS=${USERS}

NO_WRKSUBDIR=	yes

USERS=		unifi
GROUPS=		unifi

OPTIONS_DEFINE=	EXTERNALDB

.if ${FLAVOR:U} == externaldb
OPTIONS_DEFAULT+=	EXTERNALDB
.endif

EXTERNALDB_DESC=	Use external MongoDB server
EXTERNALDB_VARS=	PKGMESSAGE+=${WRKSRC}/pkg-message.extdb \
			SUB_FILES+=pkg-message.extdb
EXTERNALDB_VARS_OFF=	RUN_DEPENDS+=mongodb44>0:databases/mongodb44

_DIR_LIST=	conf data logs run work
_JAX_DISTNAME=	javax.activation-api
_JAX_VERSION=	1.2.0

post-extract:
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${_JAX_DISTNAME}-${_JAX_VERSION}.jar \
		${WRKSRC}/usr/lib/unifi/lib/

post-patch:
	(cd ${WRKSRC}/usr/lib/unifi/lib && \
		${LN} -f -s ${JAVAJARDIR}/snappy-java.jar snappy-java-*.jar)
	${RM} -r ${WRKSRC}/usr/lib/unifi/lib/native

do-install:
	${MKDIR} ${STAGEDIR}${JAVASHAREDIR}/unifi
	(cd ${WRKSRC}/usr/lib/unifi && \
		${COPYTREE_SHARE} \* ${STAGEDIR}${JAVASHAREDIR}/unifi/)
# Create directories that will be writable by unifi
.for i in data logs run work
	${MKDIR} ${STAGEDIR}/${JAVASHAREDIR}/unifi/${i}
.endfor

do-install-EXTERNALDB-off:
	${LN} -sf ${PREFIX}/bin/mongod ${STAGEDIR}${JAVASHAREDIR}/unifi/bin/mongod

post-install:
	@${FIND} -s ${STAGEDIR}${JAVASHAREDIR}/unifi -not -type d | \
		${SORT} | ${SED} -e 's#^${STAGEDIR}${PREFIX}/##' >> ${TMPPLIST}
.for dir in ${_DIR_LIST}
	@${ECHO} "@dir(unifi,wheel,) ${JAVASHAREDIR}/unifi/${dir}" >> \
		${TMPPLIST}
.endfor

.include <bsd.port.mk>
