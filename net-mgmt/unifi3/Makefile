# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	unifi3
PORTVERSION=	3.1.10
PORTREVISION=	1
CATEGORIES=	net-mgmt java
MASTER_SITES=	http://dl.ubnt.com/unifi/${PORTVERSION}/
DISTNAME=	UniFi.unix
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	feld@FreeBSD.org
COMMENT=	UniFi Wireless Controller

RUN_DEPENDS=	mongodb>0:${PORTSDIR}/databases/mongodb

SUB_LIST+=	USERS=${USERS} GROUPS=${GROUPS} JAVASHAREDIR=${JAVASHAREDIR}

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+
JAVA_OS=	native
JAVA_VENDOR=	openjdk bsdjava
JAVA_RUN=	yes

NO_BUILD=	yes

USE_RC_SUBR=	unifi

USERS=	unifi
GROUPS=	unifi

WRKSRC=	${WRKDIR}/UniFi

RESTRICTED=	Redistribution of bundled firmware images is not permitted
CONFLICTS=	unifi2-*

post-extract:
	${MKDIR} ${WRKSRC}/webapps/ROOT
	@${TAR} xf ${WRKSRC}/webapps/ROOT.war -C ${WRKSRC}/webapps/ROOT

do-install:
	${MKDIR} ${STAGEDIR}${JAVASHAREDIR}/unifi
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${JAVASHAREDIR}/unifi/)

.include <bsd.port.mk>
