# Created by: Matthew Seaman
# $FreeBSD$

PORTNAME=	FreeBSD-Portindex
PORTVERSION=	3.2
CATEGORIES=	ports-mgmt perl5
MASTER_SITES=	http://www.infracaninophile.co.uk/portindex/
PKGNAMEPREFIX=	p5-

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Incremental FreeBSD ports INDEX file generation

LICENSE=	BSD

BUILD_DEPENDS=	p5-BerkeleyDB>0:${PORTSDIR}/databases/p5-BerkeleyDB
RUN_DEPENDS:=	${BUILD_DEPENDS}

# GraphViz not required for portindex to run or generate GraphViz
# format output: this is only needed to render the output on the same
# machine.
OPTIONS_DEFINE=	GRAPHVIZ 
GRAPHVIS_DESCR=	Add GraphViz run-time dependency

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGRAPHVIZ}
RUN_DEPENDS+=	dot:${PORTSDIR}/graphics/graphviz
.endif

USES+=		perl5
USE_XZ=		yes
USE_PERL5=	configure

CACHE_DIR?=	/var/db/portindex
CACHE_OWNER?=	root
CACHE_GROUP?=	operator
CACHE_MODE?=	0775

CFG_FILE=	portindex.cfg

SUB_FILES+=	pkg-install
SUB_LIST+=	CACHE_DIR=${CACHE_DIR} \
		CACHE_OWNER=${CACHE_OWNER} \
		CACHE_GROUP=${CACHE_GROUP} \
		CACHE_MODE=${CACHE_MODE} \
		CFG_FILE=${PREFIX}/etc/portindex.cfg

post-install: install-conf

install-conf:
	cd ${WRKSRC} ; \
	${INSTALL_DATA} ${CFG_FILE}.sample ${STAGEDIR}${PREFIX}/etc/${CFG_FILE}.sample

.include <bsd.port.mk>
