PORTNAME=	omada5
PORTVERSION=	5.15.24.19
CATEGORIES=	net-mgmt java
DISTNAME=	Omada_SDN_Controller_v${PORTVERSION}_linux_x64_20250724152611
MASTER_SITES=	https://static.tp-link.com/upload/software/2025/202508/20250802/
EXTRACT_ONLY=	Omada_SDN_Controller_v${PORTVERSION}_linux_x64_20250724152611.tar.gz

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Omada SDN Controller v5
WWW=		https://www.omadanetworks.com/us/business-networking/omada-controller-cloud-software/omada-software-controller/

PATCH_DEPENDS=	xxd>0:sysutils/xxd \
		unzip>0:archivers/unzip
RUN_DEPENDS=	mongodb70${MONGODB_PKGNAMESUFFIX}>0:databases/mongodb70

USES=		cpe java:extract,run
JAVA_VERSION=	8+
USE_RC_SUBR=	omada

CPE_VENDOR=	tp-link
CPE_PRODUCT=	omada_software_controller
CPE_TARGET_SW=	linux

EXTRACT_AFTER_ARGS+=	--exclude Omada_SDN_Controller_v${PORTVERSION}_linux_x64/bin \
	--exclude Omada_SDN_Controller_v${PORTVERSION}_linux_x64/*.sh

NO_BUILD=	yes

SUB_LIST+=	GROUPS=${GROUPS} \
		JAVA=${JAVA} \
		JAVA_HOME=${JAVA_HOME} \
		JAVASHAREDIR=${JAVASHAREDIR} \
		USERS=${USERS}

WRKSRC=	${WRKDIR}/Omada_SDN_Controller_v${PORTVERSION}_linux_x64

USERS=		omada
GROUPS=		omada

post-extract:
	@${MKDIR} ${WRKSRC}/bin

# post-patch below for dynamically patching out the Linux-check from the jar file
ISLINUXOS_CLASSDIR=	com/tplink/smb/omada/common/util
ISLINUXOS_CLASS=	com/tplink/smb/omada/common/util/S.class
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
