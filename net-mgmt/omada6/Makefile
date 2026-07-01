PORTNAME=	omada6
PORTVERSION=	6.2.10.17
CATEGORIES=	net-mgmt java
MASTER_SITES=	https://static.tp-link.com/upload/software/${OMADAY}/${OMADAY}${OMADAM}/${OMADAY}${OMADAM}${OMADAD}/
DISTNAME=	Omada_Network_Application_v${PORTVERSION}_linux_x64_${OMADA_REL}
EXTRACT_ONLY=	Omada_Network_Application_v${PORTVERSION}_linux_x64_${OMADA_REL}.tar.gz

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Omada SDN Controller v6
WWW=		https://www.omadanetworks.com/us/business-networking/omada-controller-cloud-software/omada-software-controller/

PATCH_DEPENDS=	xxd>0:sysutils/xxd \
		unzip>0:archivers/unzip
RUN_DEPENDS=	mongodb70${MONGODB_PKGNAMESUFFIX}>0:databases/mongodb70

USES=		cpe java:extract,run
JAVA_VERSION=	8+
USE_RC_SUBR=	omada

# Master site and distname helpers
OMADAY=	2026
OMADAM=	04
OMADAD=	29
OMADA_REL=	20260428102037

CONFLICTS_INSTALL=	omada5

CPE_VENDOR=	tp-link
CPE_PRODUCT=	omada_software_controller
CPE_TARGET_SW=	linux

EXTRACT_AFTER_ARGS+=	--exclude Omada_Network_Application_v${PORTVERSION}_linux_x64/bin \
	--exclude Omada_Network_Application_v${PORTVERSION}_linux_x64/*.sh

NO_BUILD=	yes

SUB_LIST+=	GROUPS=${GROUPS} \
		JAVA=${JAVA} \
		JAVA_HOME=${JAVA_HOME} \
		JAVASHAREDIR=${JAVASHAREDIR} \
		USERS=${USERS}

WRKSRC=	${WRKDIR}/Omada_Network_Application_v${PORTVERSION}_linux_x64

USERS=		omada
GROUPS=		omada

post-extract:
	@${MKDIR} ${WRKSRC}/bin

# post-patch below for dynamically patching out the Linux-check from the jar file
ISLINUXOS_CLASSDIR=	com/tplink/smb/omada/common/util
ISLINUXOS_CLASS=	com/tplink/smb/omada/common/util/U.class
JARFILE=	${WRKSRC}/lib/omada-common-${PORTVERSION}.jar
SCRATCH=	${WRKDIR}/scratch
post-patch:
	${MKDIR} ${SCRATCH}/${ISLINUXOS_CLASSDIR}
	(cd ${SCRATCH} && \
		${UNZIP_CMD} -p "${JARFILE}" "${ISLINUXOS_CLASS}" | \
		${LOCALBASE}/bin/xxd -p -c 0 | \
		${SED} -e s,0100056c696e7578,01000766726565627364, | \
		${LOCALBASE}/bin/xxd -r -p > "${SCRATCH}/${ISLINUXOS_CLASS}" && \
		${LOCALBASE}/bin/jar uf "${JARFILE}" -C "${SCRATCH}" "${ISLINUXOS_CLASS}")

pre-install:
	@${RM} ${WRKSRC}/properties/omada.properties.orig

do-install:
	@${MV} ${WRKSRC}/properties/omada.properties ${WRKSRC}/properties/omada.properties.sample
	@${MV} ${WRKSRC}/properties/log4j2.properties ${WRKSRC}/properties/log4j2.properties.sample
	${MKDIR} ${STAGEDIR}${JAVASHAREDIR}/omada
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${JAVASHAREDIR}/omada)
	${RLN} /usr/bin/true ${STAGEDIR}${JAVASHAREDIR}/omada/bin/topdf

.include <bsd.port.mk>
