# Created by: Tom Judge <tj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	x-pack
PORTVERSION=	5.6.3
CATEGORIES=	textproc java
MASTER_SITES=	https://artifacts.elastic.co/downloads/packs/x-pack/
PKGNAMEPREFIX=	elasticsearch5-

MAINTAINER=	tj@FreeBSD.org
COMMENT=	Elasticsearch X-Pack plugins


RUN_DEPENDS:=	elasticsearch5>=5.6.3:textproc/elasticsearch5

NO_ARCH=        yes
NO_BUILD=	yes

USES+=		zip

NON_FREEBSD_PLATFORM_DIRS=	elasticsearch/platform/darwin-x86_64 \
				elasticsearch/platform/linux-x86_64 \
				elasticsearch/platform/windows-x86_64

do-extract:
	@${MKDIR} ${WRKSRC}
	( cd ${WRKDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} -d ${PORTNAME}-${PORTVERSION} \
	      ${_DISTDIR}${DISTFILES} )
.for d in ${NON_FREEBSD_PLATFORM_DIRS}
	${RM} -r ${WRKSRC}/${d}
.endfor

do-install:
	@cd ${WRKSRC}/elasticsearch && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib/elasticsearch/plugins/x-pack

.include <bsd.port.mk>
