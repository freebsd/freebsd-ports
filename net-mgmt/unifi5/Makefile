# Created by: Alban MAIRE <a.maire@s2mi.fr>
# $FreeBSD$

PORTNAME=	unifi5
PORTVERSION=	5.6.26
PORTREVISION=	0
CATEGORIES=	net-mgmt java
MASTER_SITES=	http://dl.ubnt.com/unifi/${PORTVERSION}/
DISTNAME=	unifi_sysvinit_all
EXTRACT_SUFX=	.deb
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	feld@FreeBSD.org
COMMENT=	UniFi Controller v5

RUN_DEPENDS=	mongodb>0:databases/mongodb \
		snappyjava>0:archivers/snappy-java

BUILD=		0
TOMCATVER=	7.0.82

SUB_LIST+=	USERS=${USERS} GROUPS=${GROUPS} JAVASHAREDIR=${JAVASHAREDIR} \
		JAVA=${JAVA}
PLIST_SUB+=	BUILDVERSION="${PORTVERSION}.${BUILD}" BUNDLEDFW="${BUNDLEDFW}" TOMCATVER="${TOMCATVER}"

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

CONFLICTS=	unifi2-* unifi3-* unifi4-*

post-patch:
	${RM} ${WRKSRC}/usr/lib/unifi/lib/snappy-java-1.1.2.6.jar ${WRKSRC}/usr/lib/unifi/bin/*
	(cd ${WRKSRC}/usr/lib/unifi/lib && ${LN} -s ${JAVAJARDIR}/snappy-java.jar snappy-java-1.1.2.6.jar)

do-install:
	${MKDIR} ${STAGEDIR}${JAVASHAREDIR}/unifi
	(cd ${WRKSRC}/usr/lib/unifi && ${COPYTREE_SHARE} \* ${STAGEDIR}${JAVASHAREDIR}/unifi/)
	${LN} -sf ${PREFIX}/bin/mongod ${STAGEDIR}${JAVASHAREDIR}/unifi/bin/mongod
# Create directories that will be writable by unifi
.for i in data logs run work
	${MKDIR} ${STAGEDIR}/${JAVASHAREDIR}/unifi/${i}
.endfor

.include <bsd.port.mk>
