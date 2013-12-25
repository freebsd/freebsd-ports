# Created by: Muhammad Moinur Rahman <5u623l20@gmail.com>
# $FreeBSD$

PORTNAME=	ntopng
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	SF/ntop/${PORTNAME}:source1 \
		http://geolite.maxmind.com/download/geoip/database/:source2 \
		http://geolite.maxmind.com/download/geoip/database/GeoLiteCityv6-beta/:source3 \
		http://download.maxmind.com/download/geoip/database/asnum/:source4
DISTFILES=	${DISTNAME}_6932.tgz:source1 \
		GeoLiteCity.dat.gz:source2 \
		GeoLiteCityv6.dat.gz:source3 \
		GeoIPASNum.dat.gz:source4 \
		GeoIPASNumv6.dat.gz:source4
EXTRACT_ONLY=	${DISTNAME}_6932.tgz

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Network monitoring tool with command line and web interfaces

LICENSE=	GPLv3

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		geoiplookup:${PORTSDIR}/net/GeoIP
LIB_DEPENDS=	libcairo.so:${PORTSDIR}/graphics/cairo \
		libluajit-5.1.so:${PORTSDIR}/lang/luajit \
		libzmq.so:${PORTSDIR}/devel/ntopng-zmq

IGNOREFILES=	GeoLiteCity.dat.gz GeoLiteCityv6.dat.gz \
		GeoIPASNum.dat.gz GeoIPASNumv6.dat.gz

CPPFLAGS+=	-I${LOCALBASE}/include/luajit-2.0
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes
USE_GCC=	any
USE_GNOME=	intltool
USE_LDCONFIG=	yes
USES=	 	gmake pathfix pkgconfig
WRKSRC=		${WRKDIR}/${DISTNAME}_6932

USE_RC_SUBR=	ntopng

post-extract:
	@${CP} ${DISTDIR}/GeoLiteCity.dat.gz ${WRKDIR}
	@${CP} ${DISTDIR}/GeoLiteCityv6.dat.gz ${WRKDIR}
	@${CP} ${DISTDIR}/GeoIPASNum.dat.gz ${WRKDIR}
	@${CP} ${DISTDIR}/GeoIPASNumv6.dat.gz ${WRKDIR}
	@${RM} ${WRKSRC}/scripts/lua/modules/redis.lua
	@${CP} ${WRKSRC}/third-party/redis-lua/src/redis.lua ${WRKSRC}/scripts/lua/modules/redis.lua
	@${FIND} ${WRKSRC} -name "*~" -delete
	@cd ${WRKDIR} && ${GUNZIP_CMD} GeoLiteCity.dat.gz GeoLiteCityv6.dat.gz GeoIPASNum.dat.gz GeoIPASNumv6.dat.gz

post-patch:
	@${REINPLACE_CMD} -e "s#/bin/bash#/usr/local/bin/bash#" ${WRKSRC}/third-party/rrdtool-1.4.7/Makefile \
		${WRKSRC}/third-party/rrdtool-1.4.7/config.status ${WRKSRC}/third-party/rrdtool-1.4.7/src/Makefile \
		${WRKSRC}/third-party/rrdtool-1.4.7/bindings/Makefile ${WRKSRC}/third-party/rrdtool-1.4.7/doc/Makefile \
		${WRKSRC}/third-party/rrdtool-1.4.7/examples/Makefile \
	       	${WRKSRC}/third-party/rrdtool-1.4.7/examples/rrdcached/Makefile
	@${REINPLACE_CMD} -e "s#%%LUAJIT_LIB%%#LUAJIT_LIB=${LOCALBASE}/lib/libluajit-5.1.a#" ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "s#%%ZEROMQ_LIB%%#ZEROMQ_LIB=${LOCALBASE}/lib/libzmq.a#" ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "s#%%STAGEDIR%%%%DATADIR%%#${STAGEDIR}${DATADIR}#" ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "s#%%STAGEDIR%%%%PREFIX%%#${STAGEDIR}${PREFIX}#" ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "s#%%WRKSRC%%#${WRKSRC}#" ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "s#%%WRKDIR%%#${WRKDIR}#" ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "s#%%PORTNAME%%#${PORTNAME}#" ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "s#%%LOCALBASE%%#${LOCALBASE}#" ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "s#%%INSTALL_PROGRAM%%#${INSTALL_PROGRAM}#" ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "s#%%INSTALL_MAN%%#${INSTALL_MAN}#" ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "s#%%INSTALL_SCRIPT%%#${INSTALL_SCRIPT}#" ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "s#%%INSTALL_DATA%%#${INSTALL_DATA}#" ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "s#%%G++%%#${CXX}#" ${WRKSRC}/Makefile.in

pre-build:
	cd ${WRKSRC}/third-party/json-c && ${MAKE} clean && ./configure && ${MAKE}
	cd ${WRKSRC}/third-party/rrdtool-1.4.7 && ${MAKE} clean \
	&& ./configure --disable-rrd_graph \
	--disable-libdbi --disable-libwrap --disable-rrdcgi --disable-libtool-lock \
	--disable-nls --disable-rpath --disable-perl --disable-ruby --disable-lua \
	--disable-tcl --disable-python --disable-dependency-tracking && \
	cd src && ${GMAKE} librrd_th.la
	cd ${WRKSRC}/third-party/credis-0.2.3 && ${GMAKE} clean && ${GMAKE}

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${DATADIR}/httpdocs
	${MKDIR} ${STAGEDIR}${DATADIR}/httpdocs/geoip
	${MKDIR} ${STAGEDIR}${DATADIR}/scripts
	cd ${WRKSRC}/httpdocs && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/httpdocs
	cd ${WRKSRC}/scripts && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/scripts

.include <bsd.port.mk>
