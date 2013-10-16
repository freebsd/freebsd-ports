# Created by: Craig Leres <leres@ee.lbl.gov>
# $FreeBSD$

PORTNAME=	broccoli
PORTVERSION=	2.1
CATEGORIES=	security
MASTER_SITES=	http://www.bro-ids.org/downloads/release/
DISTNAME=	bro-${PORTVERSION}

MAINTAINER=	leres@ee.lbl.gov
COMMENT=	The Bro Client Communications Library

BUILD_DEPENDS=	bison:${PORTSDIR}/devel/bison \
		swig:${PORTSDIR}/devel/swig13
LIB_DEPENDS=	GeoIP:${PORTSDIR}/net/GeoIP

EXTRACT_AFTER_ARGS= ${DISTNAME}/aux/broccoli

USES=		cmake:outsource perl5
USE_LDCONFIG=	yes
NO_MTREE=	yes
CMAKE_SOURCE_PATH=	${WRKSRC}/aux/broccoli

.if defined(BRO_PREFIX)
PREFIX=${BRO_PREFIX}
PLIST_SUB+=	CLEANUP_PREFIX=""
.else
PLIST_SUB+=	CLEANUP_PREFIX="@comment "
.endif
CMAKE_ARGS+=	-D CMAKE_INSTALL_PREFIX:PATH=${PREFIX} \
		-D PY_MOD_INSTALL_DIR:PATH=${PREFIX}

OPTIONS_DEFINE=	DEBUG PYTHON RUBY

DEBUG_DESC=	Compile in debugging mode
PYTHON_DESC=	Build python bindings for broccoli
RUBY_DESC=	Build ruby bindings for broccoli

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
CMAKE_ARGS+=		-D ENABLE_DEBUG:BOOL=true
.endif

.if ${PORT_OPTIONS:MPYTHON}
USE_PYTHON=		yes
PLIST_SUB+=		PYTHON=""
.else
CMAKE_ARGS+=		-D DISABLE_PYTHON_BINDINGS:BOOL=true
PLIST_SUB+=		PYTHON="@comment "
.endif

.if ${PORT_OPTIONS:MRUBY}
USE_RUBY=		yes
PLIST_SUB+=		RUBY=""
.else
CMAKE_ARGS+=		-D DISABLE_RUBY_BINDINGS:BOOL=true
PLIST_SUB+=		RUBY="@comment "
.endif

post-install:
	@${MKDIR} ${PREFIX}/etc
	@${INSTALL_SCRIPT} ${WRKSRC}/aux/broccoli/broccoli.conf ${PREFIX}/etc/broccoli.conf.sample
	@[ -f ${PREFIX}/etc/broccoli.conf ] || \
	    ${CP} -p ${PREFIX}/etc/broccoli.conf.sample ${PREFIX}/etc/broccoli.conf

.include <bsd.port.mk>
