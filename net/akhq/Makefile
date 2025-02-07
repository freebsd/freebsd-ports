PORTNAME=	akhq
DISTVERSION=	0.25.1
DISTVERSIONSUFFIX= -all
PORTREVISION=	1
CATEGORIES=	net java
MASTER_SITES=	https://github.com/tchiotludo/akhq/releases/download/${PORTVERSION}/
EXTRACT_SUFX=	.jar

MAINTAINER=	freebsd@hackacad.net
COMMENT=	Kafka Gui for Apache Kafka
WWW=		https://github.com/tchiotludo/akhq

LICENSE=	APACHE20

USES=		java
JAVA_VERSION=	17+
USE_RC_SUBR=	akhq

NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	akhq
SUB_LIST=	WWWOWN=${WWWOWN}

PLIST_FILES=	"@sample ${ETCDIR}/application.yml.sample" \
		${JAVASHAREDIR}/${PORTNAME}/${PORTNAME}.jar 
PLIST_SUB+=     ${SUB_LIST}

CONFIG_FILES=	application.yml

NO_EXTRACT=	yes

do-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${MKDIR} ${STAGEDIR}${JAVASHAREDIR}/${PORTNAME}
	${INSTALL_DATA} ${DISTDIR}/${DISTFILES} ${STAGEDIR}${JAVASHAREDIR}/${PORTNAME}/${PORTNAME}.jar
	${INSTALL_DATA} ${FILESDIR}/application.yml ${STAGEDIR}${ETCDIR}/application.yml.sample
	${INSTALL_DATA} ${FILESDIR}/application.yml ${STAGEDIR}${ETCDIR}/application.yml

.include <bsd.port.mk>
