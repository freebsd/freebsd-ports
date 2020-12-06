# Created by: Juraj Lutter <juraj@lutter.sk>
# $FreeBSD$

PORTNAME=	unifi6
PORTVERSION=	6.0.41
CATEGORIES=	net-mgmt java
MASTER_SITES=	http://dl.ubnt.com/unifi/%SUBDIR%/:unifi \
		https://repo1.maven.org/maven2/%SUBDIR%/:jax
MASTER_SITE_SUBDIR=	${PORTVERSION}/:unifi \
			javax/activation/${JAX_DISTNAME}/${JAX_VERSION}/:jax
DISTFILES=	unifi_sysvinit_all.deb:unifi \
		${JAX_DISTNAME}-${JAX_VERSION}.jar:jax
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}
EXTRACT_ONLY=	unifi_sysvinit_all.deb

MAINTAINER=	juraj@lutter.sk
COMMENT=	UniFi Controller v6

RUN_DEPENDS=	mongodb36>0:databases/mongodb36 \
		snappyjava>0:archivers/snappy-java

USES=		cpe

SUB_LIST+=	GROUPS=${GROUPS} \
		JAVA=${JAVA} \
		JAVA_HOME=${JAVA_HOME} \
		JAVASHAREDIR=${JAVASHAREDIR} \
		USERS=${USERS}

EXTRACT_CMD=	${AR}
EXTRACT_BEFORE_ARGS=	-p
EXTRACT_AFTER_ARGS=	data.tar.xz | ${TAR} -xf -

CPE_VENDOR=	ubnt
CPE_PRODUCT=	unifi_controller
USE_JAVA=	yes
JAVA_VERSION=	1.8+
JAVA_OS=	native
JAVA_VENDOR=	openjdk bsdjava
JAVA_RUN=	yes

NO_BUILD=	yes
NO_ARCH=	yes

USE_RC_SUBR=	unifi

USERS=		unifi
GROUPS=		unifi

JAX_DISTNAME=	javax.activation-api
JAX_VERSION=	1.2.0

NO_WRKSUBDIR=	yes

CONFLICTS=	unifi-devel-*
CONFLICTS+=	unifi-lts-*
CONFLICTS+=	unifi5-*

DIR_LIST=	conf data logs run work

post-extract:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${JAX_DISTNAME}-${JAX_VERSION}.jar \
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
.for dir in ${DIR_LIST}
	@${ECHO} "@dir(unifi,wheel,) ${JAVASHAREDIR}/unifi/${dir}" >> \
		${TMPPLIST}
.endfor

.include <bsd.port.mk>
