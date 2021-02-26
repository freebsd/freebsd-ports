# Created by: Juraj Lutter <otis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	unifi6
PORTVERSION=	6.0.45
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
COMMENT=	UniFi Controller v6

RUN_DEPENDS=	mongodb36>0:databases/mongodb36 \
		snappyjava>0:archivers/snappy-java

USES=		cpe

CPE_VENDOR=	ubnt
CPE_PRODUCT=	unifi_controller
USE_JAVA=	yes
JAVA_VERSION=	8+
JAVA_OS=	native
JAVA_VENDOR=	openjdk bsdjava
JAVA_RUN=	yes
USE_RC_SUBR=	unifi

CONFLICTS=	unifi-devel-* unifi-lts-* unifi5-*

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
	${LN} -sf ${PREFIX}/bin/mongod ${STAGEDIR}${JAVASHAREDIR}/unifi/bin/mongod
# Create directories that will be writable by unifi
.for i in data logs run work
	${MKDIR} ${STAGEDIR}/${JAVASHAREDIR}/unifi/${i}
.endfor

post-install:
	@${FIND} -s ${STAGEDIR}${JAVASHAREDIR}/unifi -not -type d | \
		${SORT} | ${SED} -e 's#^${STAGEDIR}${PREFIX}/##' >> ${TMPPLIST}
.for dir in ${_DIR_LIST}
	@${ECHO} "@dir(unifi,wheel,) ${JAVASHAREDIR}/unifi/${dir}" >> \
		${TMPPLIST}
.endfor

.include <bsd.port.mk>
