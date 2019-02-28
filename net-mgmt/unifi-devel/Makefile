# Created by: Alban MAIRE <a.maire@s2mi.fr>
# $FreeBSD$

PORTNAME=	unifi
PORTVERSION=	5.10.19
PORTREVISION=	0
CATEGORIES=	net-mgmt java
MASTER_SITES=	http://dl.ubnt.com/unifi/${PORTVERSION}-${UNIFI_BUILD}/
PKGNAMESUFFIX=	-devel
DISTNAME=	unifi_sysvinit_all
EXTRACT_SUFX=	.deb
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	bryce@bryce.net
COMMENT=	UniFi Controller development release

LICENSE=	EULA
LICENSE_NAME=	End User License Agreement
LICENSE_TEXT=	${RESTRICTED}
LICENSE_PERMS=	no-dist-mirror no-dist-sell no-pkg-mirror no-pkg-sell no-auto-accept

RESTRICTED=	License restrictions, see https://www.ubnt.com/eula/

RUN_DEPENDS=	mongodb36>0:databases/mongodb36 \
		snappyjava>0:archivers/snappy-java

USES=		cpe
CPE_VENDOR=	ubnt
CPE_PRODUCT=	unifi_controller
USE_JAVA=	yes
JAVA_VERSION=	1.8
JAVA_OS=	native
JAVA_VENDOR=	openjdk bsdjava
JAVA_RUN=	yes
USE_RC_SUBR=	unifi

EXTRACT_CMD=	${AR}
EXTRACT_BEFORE_ARGS=	-p
EXTRACT_AFTER_ARGS=	data.tar.xz | ${TAR} -xf -

NO_BUILD=	yes
NO_ARCH=	yes
NO_WRKSUBDIR=	yes

USERS=		unifi
GROUPS=		unifi

SUB_LIST=	USERS=${USERS} GROUPS=${GROUPS} JAVASHAREDIR=${JAVASHAREDIR} \
		JAVA=${JAVA}

CONFLICTS=	unifi5-*

UNIFI_BUILD=	113b57454f
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
