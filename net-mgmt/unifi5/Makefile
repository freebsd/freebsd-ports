# Created by: Alban MAIRE <a.maire@s2mi.fr>
# $FreeBSD$

PORTNAME=	unifi5
PORTVERSION=	5.4.15
PORTREVISION=	0
CATEGORIES=	net-mgmt java
MASTER_SITES=	https://www.ubnt.com/downloads/unifi/${PORTVERSION}/ \
		LOCAL/feld/${PORTNAME}-${PORTVERSION}/
DISTNAME=	UniFi.unix
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	feld@FreeBSD.org
COMMENT=	UniFi Controller v5

RUN_DEPENDS=	mongodb>0:databases/mongodb \
		snappyjava>0:archivers/snappy-java

BUILD=		0
BUNDLEDFW=	3.7.51.6230
#UNIFI_TAG=	6cbeae59e7

SUB_LIST+=	USERS=${USERS} GROUPS=${GROUPS} JAVASHAREDIR=${JAVASHAREDIR} \
		JAVA=${JAVA}
PLIST_SUB+=	BUILDVERSION="${PORTVERSION}.${BUILD}" BUNDLEDFW="${BUNDLEDFW}"

USES=		cpe zip
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

WRKSRC=		${WRKDIR}/UniFi

RESTRICTED=	Redistribution of bundled firmware images is not permitted
CONFLICTS=	unifi2-* unifi3-* unifi4-*

post-patch:
	${RM} ${WRKSRC}/lib/snappy-java-1.0.5.jar
	(cd ${WRKSRC}/lib && ${LN} -s ${JAVAJARDIR}/snappy-java.jar snappy-java-1.0.5.jar)

do-install:
	${MKDIR} ${STAGEDIR}${JAVASHAREDIR}/unifi
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${JAVASHAREDIR}/unifi/)
	${LN} -sf ${PREFIX}/bin/mongod ${STAGEDIR}${JAVASHAREDIR}/unifi/bin/mongod
# Create directories that will be writable by unifi
.for i in data logs run work
	${MKDIR} ${STAGEDIR}/${JAVASHAREDIR}/unifi/${i}
.endfor

.include <bsd.port.mk>
