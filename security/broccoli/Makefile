# Created by: Craig Leres <leres@ee.lbl.gov>
# $FreeBSD$

PORTNAME=	broccoli
PORTVERSION=	2.2
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.bro.org/downloads/release/
DISTNAME=	bro-${PORTVERSION}

MAINTAINER=	leres@ee.lbl.gov
COMMENT=	The Bro Client Communications Library

LICENSE=	BSD

BUILD_DEPENDS=	bison:${PORTSDIR}/devel/bison \
		swig:${PORTSDIR}/devel/swig13
LIB_DEPENDS=	libGeoIP.so:${PORTSDIR}/net/GeoIP

EXTRACT_AFTER_ARGS=	${DISTNAME}/aux/broccoli

USES=		cmake:outsource
USE_LDCONFIG=	yes
CMAKE_SOURCE_PATH=	${WRKSRC}/aux/broccoli

.if defined(BRO_PREFIX)
PREFIX=		${BRO_PREFIX}
PLIST_SUB+=	CLEANUP_PREFIX=""
.if ! defined(WITH_PKGNG) && ! exists(${BRO_PREFIX})
NEED_ROOT=	yes
.endif
NO_MTREE=	yes
.else
PLIST_SUB+=	CLEANUP_PREFIX="@comment "
.endif
CMAKE_ARGS+=	-D CMAKE_INSTALL_PREFIX:PATH=${PREFIX} \
		-D BRO_ETC_INSTALL_DIR:PATH=${PREFIX}/etc

OPTIONS_DEFINE=	DEBUG PYTHON RUBY
OPTIONS_SUB=

DEBUG_DESC=	Compile in debugging mode
PYTHON_DESC=	Build python bindings for broccoli
RUBY_DESC=	Build ruby bindings for broccoli

DEBUG_CMAKE_ON=	-D ENABLE_DEBUG:BOOL=true
PYTHON_USE=	python=yes
PYTHON_CMAKE_ON=	-D PY_MOD_INSTALL_DIR:PATH=${PYTHON_SITELIBDIR}
PYTHON_CMAKE_OFF=	-D DISABLE_PYTHON_BINDINGS:BOOL=true
RUBY_USE=	ruby=yes
RUBY_CMAKE_ON=	-D RB_INSTALL_DIR:PATH=${RUBY_SITELIBDIR} \
		-D RB_ARCH_INSTALL_DIR:PATH=${RUBY_SITEARCHLIBDIR}
RUBY_CMAKE_OFF=		-D DISABLE_RUBY_BINDINGS:BOOL=true

post-install::
.if defined(BRO_PREFIX) && ! defined(WITH_PKGNG) && ! exists(${BRO_PREFIX})
	# pkg_install needs PREFIX in order to make a package from STAGEDIR/PREFIX.
	@${MKDIR} ${PREFIX}
.endif
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc
	@${MV} ${STAGEDIR}${PREFIX}/etc/broccoli.conf ${STAGEDIR}${PREFIX}/etc/broccoli.conf.example
.if !empty(${PORT_OPTIONS:MPYTHON}) && defined(BRO_PREFIX)
	# bsd.python.mk isn't PREFIX-safe yet.
	@${MV} ${STAGEDIR}${PYTHON_LIBDIR} ${STAGEDIR}${PYTHONPREFIX_LIBDIR}
.endif

.include <bsd.port.mk>
