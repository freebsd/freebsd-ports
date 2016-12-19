# $FreeBSD$

PORTNAME=	icinga2
DISTVERSIONPREFIX=	v
DISTVERSION=	2.6.0
PORTREVISION=	1
CATEGORIES=	net-mgmt

MAINTAINER=	lme@FreeBSD.org
COMMENT=	Monitoring and management system for hosts, services and networks

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libyajl.so:devel/yajl
RUN_DEPENDS=	${LOCALBASE}/bin/bash:shells/bash

BROKEN_powerpc64=	does not build
BROKEN_FreeBSD_9=	does not configure (Your version of GCC (4.2.1) is too old for building Icinga 2 (GCC >= 4.6.0 is required).)

USE_GITHUB=	yes
GH_ACCOUNT=	icinga

USES=		alias bison cmake execinfo libedit
USE_LDCONFIG=	yes

USE_RC_SUBR=	${PORTNAME}

OPTIONS_DEFINE=		DOCS
OPTIONS_GROUP=		BACKEND
OPTIONS_GROUP_BACKEND=	MYSQL PGSQL
OPTIONS_RADIO=		PLUGINS
OPTIONS_RADIO_PLUGINS=	MONPLUGINS NAGPLUGINS

OPTIONS_DEFAULT=	MYSQL PGSQL MONPLUGINS

MONPLUGINS_RUN_DEPENDS=	${LOCALBASE}/libexec/nagios/check_nagios:net-mgmt/monitoring-plugins
NAGPLUGINS_RUN_DEPENDS=	${LOCALBASE}/libexec/nagios/check_nagios:net-mgmt/nagios-plugins

MYSQL_CMAKE_ON=	-DICINGA2_WITH_MYSQL:BOOL=true
PGSQL_CMAKE_ON=	-DICINGA2_WITH_PGSQL:BOOL=true

ICINGA2USER?=	icinga
ICINGA2GROUP?=	icinga
USERS=		${ICINGA2USER}
GROUPS=		${ICINGA2GROUP}

LOCALSTATEDIR?=	/var
ICINGA2LOGDIR?=	/var/log/${PORTNAME}

CMAKE_ARGS+=	-DICINGA2_USER=${ICINGA2USER} \
		-DICINGA2_GROUP=${ICINGA2GROUP} \
		-DICINGA2_COMMAND_USER=${ICINGA2USER} \
		-DICINGA2_COMMAND_GROUP=${ICINGA2USER} \
		-DICINGA2_PLUGINDIR=${LOCALBASE}/libexec/nagios \
		-DICINGA2_RUNDIR=/var/run \
		-DCMAKE_INSTALL_SYSCONFDIR=${PREFIX}/etc \
		-DCMAKE_INSTALL_LOCALSTATEDIR=${LOCALSTATEDIR} \
		-DCMAKE_INSTALL_MANDIR=${MANPREFIX}/man \
		-DCMAKE_EXE_LINKER_FLAGS=${PREFIX}/lib/icinga2 \
		-DCMAKE_MODULE_LINKER_FLAGS=${PREFIX}/lib/icinga2 \
		-DCMAKE_SHARED_LINKER_FLAGS=${PREFIX}/lib/icinga2 \
		-DCMAKE_STATIC_LINKER_FLAGS=${PREFIX}/lib/icinga2

SUB_LIST=	ICINGA2LOGDIR=${ICINGA2LOGDIR} \
		ICINGA2USER=${ICINGA2USER} \
		ICINGA2GROUP=${ICINGA2GROUP} \
		WWWGRP=${WWWGRP}

PLIST_SUB=	ICINGA2USER=${ICINGA2USER} \
		ICINGA2GROUP=${ICINGA2GROUP} \
		WWWGRP=${WWWGRP}

SUB_FILES=	pkg-message ${PORTNAME}-newsyslog

# Config files with references to "Linux"
LINUX_CONFIG=	groups.conf services.conf hosts.conf

MYSQL_USES=	mysql
PGSQL_USES=	pgsql

OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MMYSQL} && ! ${PORT_OPTIONS:MPGSQL}
PLIST_SUB+=	DBBACKEND="@comment "
.else
PLIST_SUB+=	DBBACKEND=""
.endif

.if ${OSVERSION} < 1000033
BUILD_DEPENDS+=	flex>=2.5.31:textproc/flex
CMAKE_ARGS+=	-DFLEX_EXECUTABLE:STRING=${LOCALBASE}/bin/flex
CXXFLAGS+=	-I${LOCALBASE}/include/flex
.endif

post-patch:
.for f in ${LINUX_CONFIG}
	${REINPLACE_CMD} 's,[Ll]inux,FreeBSD,g' ${WRKSRC}/etc/icinga2/conf.d/${f}
.endfor
.if ${OSVERSION} < 1000000
	${REINPLACE_CMD} 's|,--no-export-dynamic||' ${WRKSRC}/CMakeLists.txt
.endif

pre-install:
	${FIND} ${WRKSRC}/etc -type f -name "*.conf" -exec ${MV} {} {}.sample \;
	${FIND} ${WRKSRC}/etc/icinga2/scripts -type f -name "*.sh" \
		-exec ${MV} {} {}.sample \;

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/newsyslog/
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-newsyslog ${STAGEDIR}${EXAMPLESDIR}/newsyslog/${PORTNAME}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/vim/vimfiles
	(cd ${WRKSRC}/tools/syntax/vim && ${COPYTREE_SHARE} . \
		${STAGEDIR}${PREFIX}/share/vim/vimfiles)

.include <bsd.port.mk>
