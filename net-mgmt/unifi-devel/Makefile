# Created by: Alban MAIRE <a.maire@s2mi.fr>
# $FreeBSD$

PORTNAME=	unifi
PORTVERSION=	5.7.15
PORTREVISION=	1
CATEGORIES=	net-mgmt java
MASTER_SITES=	http://dl.ubnt.com/unifi/${PORTVERSION}-${UNIFI_BUILD}/
PKGNAMESUFFIX=	-devel
DISTNAME=	unifi_sysvinit_all
EXTRACT_SUFX=	.deb
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	bryce@bryce.net
COMMENT=	UniFi Controller development release

RUN_DEPENDS=	mongodb>0:databases/mongodb \
		snappyjava>0:archivers/snappy-java

SUB_LIST+=	USERS=${USERS} GROUPS=${GROUPS} JAVASHAREDIR=${JAVASHAREDIR} \
		JAVA=${JAVA}

EXTRACT_CMD=	/usr/bin/ar
EXTRACT_BEFORE_ARGS=	-p
EXTRACT_AFTER_ARGS=	data.tar.xz | ${TAR} -xf -

UNIFI_BUILD=	e9b882be05

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

CONFLICTS=	unifi2-* unifi3-* unifi4-* unifi5-*

DIR_LIST=	conf data logs run work

post-patch:
	(cd ${WRKSRC}/usr/lib/unifi/lib && ${LN} -f -s ${JAVAJARDIR}/snappy-java.jar snappy-java-*.jar)
	${RM} -r ${WRKSRC}/usr/lib/unifi/lib/native

do-install:
	${MKDIR} ${STAGEDIR}${JAVASHAREDIR}/unifi
	(cd ${WRKSRC}/usr/lib/unifi && ${COPYTREE_SHARE} \* ${STAGEDIR}${JAVASHAREDIR}/unifi/)
	${LN} -sf ${PREFIX}/bin/mongod ${STAGEDIR}${JAVASHAREDIR}/unifi/bin/mongod
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
