# $FreeBSD$

PORTNAME=	icinga2
DISTVERSION=	2.0.1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://github.com/Icinga/${PORTNAME}/archive/v${DISTVERSION}.tar.gz?dummy=/

MAINTAINER=	lme@FreeBSD.org
COMMENT=	Monitoring and management system for hosts, services and networks

LICENSE=	GPLv2

LIB_DEPENDS=	libboost_system.so:${PORTSDIR}/devel/boost-libs \
		libexecinfo.so:${PORTSDIR}/devel/libexecinfo # for better debugging
RUN_DEPENDS=	${LOCALBASE}/libexec/nagios/check_nagios:${PORTSDIR}/net-mgmt/monitoring-plugins \
		${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash

USES=		bison cmake
USE_LDCONFIG=	yes

USE_RC_SUBR=	${PORTNAME}

OPTIONS_SINGLE=		BACKEND
OPTIONS_SINGLE_BACKEND=	MYSQL PGSQL

OPTIONS_DEFAULT=	MYSQL

MYSQL_CMAKE_ON=	-DWITH_MYSQL:BOOL=true
PGSQL_CMAKE_ON=	-DWITH_PGSQL:BOOL=true

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
		-DCMAKE_INSTALL_SYSCONFDIR=${PREFIX}/etc \
		-DCMAKE_INSTALL_LOCALSTATEDIR=${LOCALSTATEDIR} \
		-DCMAKE_INSTALL_MANDIR=${MANPREFIX}/man \

SUB_LIST=	ICINGA2LOGDIR=${ICINGA2LOGDIR} \
		ICINGA2USER=${ICINGA2USER} \
		ICINGA2GROUP=${ICINGA2GROUP} \
		WWWGRP=${WWWGRP}

LINUX_CONFIG=	groups.conf services.conf hosts/localhost.conf

.include <bsd.port.pre.mk>
.if ${OSVERSION} < 1000033
BUILD_DEPENDS+=	flex>=2.5.31:${PORTSDIR}/textproc/flex
CMAKE_ARGS+=	-DFLEX_EXECUTABLE:STRING=${LOCALBASE}/bin/flex
CXXFLAGS+=	-I${LOCALBASE}/include/flex
.endif

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
PLIST_SUB+=	MYSQL=""
.else
PLIST_SUB+=	MYSQL="@comment "
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=	yes
PLIST_SUB+=	PGSQL=""
.else
PLIST_SUB+=	PGSQL="@comment "
.endif

post-patch:
	${REINPLACE_CMD} -e '/^add_subdirectory(initsystem)/d' \
	                 -e '/logrotate\.d/d' ${WRKSRC}/etc/CMakeLists.txt
	${REINPLACE_CMD} 's,/usr/lib/nagios/plugins,${LOCALBASE}/libexec/nagios,g' \
	                 ${WRKSRC}/etc/icinga2/constants.conf
.for f in ${LINUX_CONFIG}
	${REINPLACE_CMD} 's,[Ll]inux,FreeBSD,g' ${WRKSRC}/etc/icinga2/conf.d/${f}
.endfor
.if !${PORT_OPTIONS:MMYSQL}
	${REINPLACE_CMD} '/^add_subdirectory(db_ido_mysql)/d' ${WRKSRC}/components/CMakeLists.txt
.endif
.if !${PORT_OPTIONS:MMYSQL}
	${REINPLACE_CMD} '/^add_subdirectory(db_ido_pgsql)/d' ${WRKSRC}/components/CMakeLists.txt
.endif

.include <bsd.port.post.mk>
