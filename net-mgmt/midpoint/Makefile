# $FreeBSD$

PORTNAME=	midpoint
PORTVERSION=	4.0
CATEGORIES=	net-mgmt java
MASTER_SITES=	http://evolveum.com/downloads/${PORTNAME}/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-dist

MAINTAINER=	freebsd@rheinwolf.de
COMMENT=	Identity management and identity governance system

LICENSE=	APACHE20 CDDL MIT LGPL3 AMS AREV BITSTREAM
LICENSE_COMB=	multi
LICENSE_NAME_AMS=	AMSFonts Copyright version 2.2
LICENSE_NAME_AREV=	Arev Fonts Copyright
LICENSE_NAME_BITSTREAM=	Bitstream Vera Fonts Copyright
LICENSE_FILE=	${WRKSRC}/NOTICE
LICENSE_PERMS_AMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_PERMS_AREV=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_PERMS_BITSTREAM=dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USE_RC_SUBR=	midpoint

USE_JAVA=	yes
JAVA_VERSION=	1.8+
JAVA_OS=	native
JAVA_VENDOR=	openjdk oracle
JAVA_RUN=	yes

SUB_LIST+=	PORTNAME=${PORTNAME} USERS=${USERS} GROUPS=${GROUPS} JAVA=${JAVA}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

NO_BUILD=	yes
NO_ARCH=	yes

USERS=		midpoint
GROUPS=		midpoint

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	${RM} "${WRKSRC}/doc/samples/mvnw"*
	${RM} -r "${WRKSRC}/doc/samples/maven"

do-install:
	${MKDIR} ${STAGEDIR}${JAVASHAREDIR}/${PORTNAME}
	${MKDIR} ${STAGEDIR}${JAVASHAREDIR}/icf-connectors
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${MKDIR} ${STAGEDIR}/var/db/${PORTNAME}
	${MKDIR} ${STAGEDIR}/var/log/${PORTNAME}
	${MKDIR} ${STAGEDIR}/var/run/${PORTNAME}
	${CP} ${WRKSRC}/lib/midpoint.war ${STAGEDIR}${JAVASHAREDIR}/${PORTNAME}
	${LN} -sf /var/log/${PORTNAME} ${STAGEDIR}/var/db/${PORTNAME}/log
	${LN} -sf ${JAVAJARDIR} ${STAGEDIR}/var/db/${PORTNAME}/lib
	${LN} -sf ${JAVASHAREDIR}/icf-connectors ${STAGEDIR}/var/db/${PORTNAME}/icf-connectors
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "INSTALL NEWS NOTICE README RELEASE-NOTES" ${STAGEDIR}${DOCSDIR})
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} "config schema" ${STAGEDIR}${DOCSDIR})
	(cd ${WRKSRC}/doc/samples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
