# Created by: Matthew Seaman
# $FreeBSD$

PORTNAME=	FreeBSD-Portindex
PORTVERSION=	3.6
CATEGORIES=	ports-mgmt perl5
MASTER_SITES=	http://www.infracaninophile.co.uk/portindex/
PKGNAMEPREFIX=	p5-

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Incremental FreeBSD ports INDEX file generation

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	p5-BerkeleyDB>0:${PORTSDIR}/databases/p5-BerkeleyDB
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5 tar:xz
USE_PERL5=	configure
NO_ARCH=	yes

CACHE_DIR?=	/var/db/portindex
CACHE_OWNER?=	root
CACHE_GROUP?=	operator
CACHE_MODE?=	0775

CFG_FILE=	portindex.cfg

PLIST_SUB+=	CACHE_DIR=${CACHE_DIR} \
		CACHE_OWNER=${CACHE_OWNER} \
		CACHE_GROUP=${CACHE_GROUP} \
		CACHE_MODE=${CACHE_MODE}

# GraphViz not required for portindex to run or generate GraphViz
# format output: this is only needed to render the output on the same
# machine.
OPTIONS_DEFINE=	GRAPHVIZ
GRAPHVIZ_DESC=	Add GraphViz run-time dependency
GRAPHVIZ_RUN_DEPENDS=	dot:${PORTSDIR}/graphics/graphviz

post-install:
	${MKDIR} ${STAGEDIR}${CACHE_DIR}
	${INSTALL_DATA} ${WRKSRC}/${CFG_FILE}.sample ${STAGEDIR}${PREFIX}/etc/${CFG_FILE}.sample

.include <bsd.port.mk>
