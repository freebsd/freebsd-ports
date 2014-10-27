# $FreeBSD$

PORTNAME=	icinga2
DISTVERSION=	2.1.1
PORTREVISION=	3
CATEGORIES=	net-mgmt
MASTER_SITES=	http://github.com/Icinga/${PORTNAME}/archive/v${DISTVERSION}.tar.gz?dummy=/

MAINTAINER=	lme@FreeBSD.org
COMMENT=	Monitoring and management system for hosts, services and networks

LICENSE=	GPLv2

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools${PYTHON_SUFFIX}>0:${PORTSDIR}/devel/py-setuptools${PYTHON_SUFFIX}
LIB_DEPENDS=	libboost_system.so:${PORTSDIR}/devel/boost-libs \
		libexecinfo.so:${PORTSDIR}/devel/libexecinfo # for better debugging
RUN_DEPENDS=	${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash

USES=		alias bison cmake python
USE_LDCONFIG=	yes

USE_RC_SUBR=	${PORTNAME}

OPTIONS_DEFINE=		DOCS EXAMPLES
OPTIONS_MULTI=		BACKEND
OPTIONS_MULTI_BACKEND=	MYSQL PGSQL
OPTIONS_RADIO=		PLUGINS
OPTIONS_RADIO_PLUGINS=	MONPLUGINS NAGPLUGINS

OPTIONS_DEFAULT=	MYSQL PGSQL MONPLUGINS EXAMPLES

MONPLUGINS_RUN_DEPENDS=	${LOCALBASE}/libexec/nagios/check_nagios:${PORTSDIR}/net-mgmt/monitoring-plugins
NAGPLUGINS_RUN_DEPENDS=	${LOCALBASE}/libexec/nagios/check_nagios:${PORTSDIR}/net-mgmt/nagios-plugins

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
		-DICINGA2_PLUGINDIR=${LOCALBASE}/libexec/nagios \
		-DCMAKE_INSTALL_SYSCONFDIR=${PREFIX}/etc \
		-DCMAKE_INSTALL_LOCALSTATEDIR=${LOCALSTATEDIR} \
		-DCMAKE_INSTALL_MANDIR=${MANPREFIX}/man \

SUB_LIST=	ICINGA2LOGDIR=${ICINGA2LOGDIR} \
		ICINGA2USER=${ICINGA2USER} \
		ICINGA2GROUP=${ICINGA2GROUP} \
		WWWGRP=${WWWGRP}

# Config files with references to "Linux"
LINUX_CONFIG=	groups.conf services.conf hosts/localhost.conf

MYSQL_USE=	mysql=yes
PGSQL_USES=	pgsql

OPTIONS_SUB=	yes

.include <bsd.port.options.mk>
.if ${OSVERSION} < 1000033
BUILD_DEPENDS+=	flex>=2.5.31:${PORTSDIR}/textproc/flex
CMAKE_ARGS+=	-DFLEX_EXECUTABLE:STRING=${LOCALBASE}/bin/flex
CXXFLAGS+=	-I${LOCALBASE}/include/flex
.endif

post-patch:
	${REINPLACE_CMD} -e '/^add_subdirectory(initsystem)/d' \
	                 -e '/logrotate\.d/d' ${WRKSRC}/etc/CMakeLists.txt
.for f in ${LINUX_CONFIG}
	${REINPLACE_CMD} 's,[Ll]inux,FreeBSD,g' ${WRKSRC}/etc/icinga2/conf.d/${f}
.endfor
.if !${PORT_OPTIONS:MMYSQL}
	${REINPLACE_CMD} '/^add_subdirectory(db_ido_mysql)/d' ${WRKSRC}/components/CMakeLists.txt
.endif
.if !${PORT_OPTIONS:MMYSQL}
	${REINPLACE_CMD} '/^add_subdirectory(db_ido_pgsql)/d' ${WRKSRC}/components/CMakeLists.txt
.endif

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
.for db in mysql pgsql
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/${db}
	(cd ${WRKSRC}/components/db_ido_${db} && ${COPYTREE_SHARE} schema ${STAGEDIR}${EXAMPLESDIR}/${db})
.endfor
.endif

.include <bsd.port.mk>
