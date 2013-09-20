# Created by: Tomoyuki Sakurai <tomoyukis@reallyenglish.com>
# $FreeBSD$

PORTNAME=	dClass
PORTVERSION=	2.2.2
#PORTREVISION=	0
CATEGORIES=	www
MASTER_SITES=	RG

MAINTAINER=	tomoyukis@reallyenglish.com
COMMENT=	Pattern Classification Engine

USE_GITHUB=	yes
GH_ACCOUNT=	TheWeatherChannel
GH_PROJECT=	dClass
#GH_TAGNAME=	${PORTVERSION}
GH_COMMIT=	54cda75

USE_GMAKE=	yes
USE_GCC=	yes
BUILD_WRKSRC=	${WRKSRC}/src
CFLAGS+=	-fPIC
MAKE_JOBS_UNSAFE=	yes
USE_LDCONFIG=	yes

OPTIONS_DEFAULT=	VARNISH
OPTIONS_DEFINE=	VARNISH
VARNISH_DESC=	build varnish plugin

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MVARNISH}
CFLAGS+=	-I${PREFIX}/include
USE_PYTHON=	yes
BUILD_DEPENDS+=	varnish>=3.0.0:${PORTSDIR}/www/varnish
RUN_DEPENDS+=	varnish>=3.0.0:${PORTSDIR}/www/varnish
MAKE_ARGS+=	VMODPY=${PREFIX}/share/varnish/vmod.py PYTHON=${PYTHON_CMD}
PLIST_SUB+=	VARNISH=""
.else
PLIST_SUB+=	VARNISH="@comment "
.endif

post-build:
.if ${PORT_OPTIONS:MVARNISH}
	${CP} ${FILESDIR}/extra-patch-servers__src__vcc_if.c ${WRKSRC}/servers/src/
	(cd ${WRKSRC}/servers/src && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${_MAKE_JOBS} ${MAKE_ARGS} ${ALL_TARGET})
.endif

do-install:
	${INSTALL_DATA} ${BUILD_WRKSRC}/libdclass.so ${PREFIX}/lib
	${INSTALL_DATA} ${BUILD_WRKSRC}/libdclass.a  ${PREFIX}/lib
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/dclass_client ${PREFIX}/bin
	${INSTALL} -d ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DATADIR}
	${INSTALL} -d ${DATADIR}/dtrees
	${INSTALL} -d ${DATADIR}/openddr
	cd ${WRKSRC}/dtrees  && ${COPYTREE_SHARE} . ${DATADIR}/dtrees
	cd ${WRKSRC}/openddr && ${COPYTREE_SHARE} . ${DATADIR}/openddr
.if ${PORT_OPTIONS:MVARNISH}
	${INSTALL_DATA} ${WRKSRC}/servers/src/libvmod_dclass.so ${PREFIX}/lib/varnish/vmods
	${INSTALL} -d ${DATADIR}/varnish
	${INSTALL_DATA} ${WRKSRC}/servers/varnish/dclass.vcl ${DATADIR}/varnish
.endif

.include <bsd.port.mk>
