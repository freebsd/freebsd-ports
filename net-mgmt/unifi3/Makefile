# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	unifi3
PORTVERSION=	3.2.10
PORTREVISION=	2
CATEGORIES=	net-mgmt java
MASTER_SITES=	http://dl.ubnt.com/unifi/${PORTVERSION}/
DISTNAME=	UniFi.unix
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	feld@FreeBSD.org
COMMENT=	UniFi Wireless Controller

RUN_DEPENDS=	mongodb>0:databases/mongodb

SUB_LIST+=	USERS=${USERS} GROUPS=${GROUPS} JAVASHAREDIR=${JAVASHAREDIR}

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

USERS=	unifi
GROUPS=	unifi

WRKSRC=	${WRKDIR}/UniFi

RESTRICTED=	Redistribution of bundled firmware images is not permitted
CONFLICTS=	unifi2-[0-9]* unifi4-[0-9]* tomcat-native-[0-9]*

post-extract:
	${MKDIR} ${WRKSRC}/webapps/ROOT
	@${TAR} xf ${WRKSRC}/webapps/ROOT.war -C ${WRKSRC}/webapps/ROOT

do-install:
	${MKDIR} ${STAGEDIR}${JAVASHAREDIR}/unifi
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${JAVASHAREDIR}/unifi/)
	${LN} -sf ${PREFIX}/bin/mongod ${STAGEDIR}${JAVASHAREDIR}/unifi/bin/mongod

# Create directories that will be writable by unifi
.for i in data logs run work
	${MKDIR} ${STAGEDIR}/${JAVASHAREDIR}/unifi/${i}
.endfor

.include <bsd.port.mk>
