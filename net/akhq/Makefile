PORTNAME=	akhq
DISTVERSION=	0.25.1
DISTVERSIONSUFFIX= -all
CATEGORIES=	net java
MASTER_SITES=	https://github.com/tchiotludo/akhq/releases/download/${PORTVERSION}/
EXTRACT_SUFX=	.jar

MAINTAINER=	freebsd@hackacad.net
COMMENT=	AKHQ (previously known as KafkaHQ)
WWW=		https://github.com/tchiotludo/akhq

LICENSE=	APACHE20

USES=		java
JAVA_VERSION=	17+
USE_RC_SUBR=	akhq

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	${JAVASHAREDIR}/${PORTNAME}/${PORTNAME}.jar

CONFIG_FILES=	application.yml

NO_EXTRACT=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/akhq
	${MKDIR} ${STAGEDIR}${JAVASHAREDIR}/${PORTNAME}
	${INSTALL_DATA} ${DISTDIR}/${DISTFILES} ${STAGEDIR}${JAVASHAREDIR}/${PORTNAME}/${PORTNAME}.jar
	${INSTALL_DATA} ${FILESDIR}/application.yml ${STAGEDIR}${PREFIX}/etc/akhq/application.yml.sample
	${ECHO} "@sample ${PREFIX}/etc/akhq/application.yml.sample" >> ${TMPPLIST}

post-install:
	@if [ ! -f ${STAGEDIR}${PREFIX}/etc/akhq/application.yml ]; then \
		${CP} -p ${STAGEDIR}${PREFIX}/etc/akhq/application.yml.sample ${STAGEDIR}${PREFIX}/etc/akhq/application.yml ; \
	fi

.include <bsd.port.mk>
