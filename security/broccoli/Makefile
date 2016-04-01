# Created by: Craig Leres <leres@ee.lbl.gov>
# $FreeBSD$

PORTNAME=	broccoli
PORTVERSION=	1.97
PORTEPOCH=	1
CATEGORIES=	security
MASTER_SITES=	http://www.bro.org/downloads/release/
DISTNAME=	bro-2.4.1

MAINTAINER=	leres@ee.lbl.gov
COMMENT=	Bro Client Communications Library

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${LOCALBASE}/bin/bison:devel/bison \
		${LOCALBASE}/bin/swig:devel/swig13
LIB_DEPENDS=	libGeoIP.so:net/GeoIP

EXTRACT_AFTER_ARGS=	${DISTNAME}/aux/broccoli

USES=		cmake:outsource
USE_LDCONFIG=	yes
CMAKE_SOURCE_PATH=	${WRKSRC}/aux/broccoli

.if defined(BRO_PREFIX)
PREFIX=		${BRO_PREFIX}
PLIST_SUB+=	CLEANUP_PREFIX=""
NO_MTREE=	yes
.else
PLIST_SUB+=	CLEANUP_PREFIX="@comment "
.endif
CMAKE_ARGS+=	-D CMAKE_INSTALL_PREFIX:PATH=${PREFIX} \
		-D BRO_ETC_INSTALL_DIR:PATH=${PREFIX}/etc

OPTIONS_DEFINE=	DEBUG PYTHON RUBY
OPTIONS_SUB=

OPTIONS_DEFAULT=	PYTHON

DEBUG_DESC=	Compile in debugging mode
PYTHON_DESC=	Build python bindings for broccoli
RUBY_DESC=	Build ruby bindings for broccoli

DEBUG_CMAKE_ON=	-D ENABLE_DEBUG:BOOL=true
PYTHON_USES=	python
PYTHON_CMAKE_ON=	-D PY_MOD_INSTALL_DIR:PATH=${PYTHON_SITELIBDIR}
PYTHON_CMAKE_OFF=	-D DISABLE_PYTHON_BINDINGS:BOOL=true
RUBY_USE=	ruby=yes
RUBY_CMAKE_ON=	-D RB_INSTALL_DIR:PATH=${RUBY_SITELIBDIR} \
		-D RB_ARCH_INSTALL_DIR:PATH=${RUBY_SITEARCHLIBDIR}
RUBY_CMAKE_OFF=		-D DISABLE_RUBY_BINDINGS:BOOL=true

post-install::
	@${MV} ${STAGEDIR}${PREFIX}/etc/broccoli.conf ${STAGEDIR}${PREFIX}/etc/broccoli.conf.example
.if defined(BRO_PREFIX) && empty(${PORT_OPTIONS:MPYTHON})
	# Move lib/pythonX.X tree into BRO_PREFIX
	${MV} ${STAGEDIR}${PYTHON_LIBDIR} ${STAGEDIR}${PREFIX}/lib
.endif
.if defined(BRO_PREFIX)
	${FIND} ${STAGEDIR} -type d | ${XARGS} ${CHMOD} g-w
.endif

.include <bsd.port.mk>
