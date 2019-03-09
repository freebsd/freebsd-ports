# Created by: Alban MAIRE <a.maire@s2mi.fr>
# $FreeBSD$

PORTNAME=	unifi
PORTVERSION=	5.6.40
PORTREVISION=	2
CATEGORIES=	net-mgmt java
MASTER_SITES=	http://dl.ubnt.com/unifi/${PORTVERSION}/
PKGNAMESUFFIX=	-lts
DISTNAME=	unifi_sysvinit_all
EXTRACT_SUFX=	.deb
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	feld@FreeBSD.org
COMMENT=	UniFi Controller v5

RUN_DEPENDS=	mongodb36>0:databases/mongodb36 \
		snappyjava>0:archivers/snappy-java

SUB_FILES=	mongod
SUB_LIST+=	USERS=${USERS} GROUPS=${GROUPS} JAVASHAREDIR=${JAVASHAREDIR} \
		JAVA=${JAVA}

EXTRACT_CMD=	/usr/bin/ar
EXTRACT_BEFORE_ARGS=	-p
EXTRACT_AFTER_ARGS=	data.tar.xz | ${TAR} -xf -

USES=		cpe
CPE_VENDOR=	ubnt
CPE_PRODUCT=	unifi_controller
USE_JAVA=	yes
JAVA_VERSION=	1.8
JAVA_OS=	native
JAVA_VENDOR=	openjdk bsdjava
JAVA_RUN=	yes

NO_BUILD=	yes
NO_ARCH=	yes

USE_RC_SUBR=	unifi

USERS=		unifi
GROUPS=		unifi

NO_WRKSUBDIR=	yes

CONFLICTS=	unifi5-* unifi-devel-*

DIR_LIST=	conf data logs run work

post-patch:
	(cd ${WRKSRC}/usr/lib/unifi/lib && ${LN} -f -s ${JAVAJARDIR}/snappy-java.jar snappy-java-*.jar)
	${RM} -r ${WRKSRC}/usr/lib/unifi/lib/native

do-install:
	${MKDIR} ${STAGEDIR}${JAVASHAREDIR}/unifi
	(cd ${WRKSRC}/usr/lib/unifi && ${COPYTREE_SHARE} \* ${STAGEDIR}${JAVASHAREDIR}/unifi/)
	${INSTALL_SCRIPT} ${WRKDIR}/mongod ${STAGEDIR}${JAVASHAREDIR}/unifi/bin/mongod
# Create directories that will be writable by unifi
.for i in data logs run work
	${MKDIR} ${STAGEDIR}/${JAVASHAREDIR}/unifi/${i}
.endfor

post-install:
	@${FIND} -s ${STAGEDIR}${JAVASHAREDIR}/unifi -not -type d | ${SORT} | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/##' >> ${TMPPLIST}
.for dir in ${DIR_LIST}
	@${ECHO} "@dir(unifi,wheel,) ${JAVASHAREDIR}/unifi/${dir}" >> ${TMPPLIST}
.endfor

.include <bsd.port.mk>
