# Created by: Blaz Zupan <blaz@si.FreeBSD.org>
# $FreeBSD$

PORTNAME=	nagios
PORTVERSION=	4.0.8
PORTREVISION=	4
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-4.x/${PORTNAME}-${PORTVERSION}
PKGNAMESUFFIX=	4

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Powerful network monitoring system

LICENSE=	GPLv2

LIB_DEPENDS=	libltdl.so:${PORTSDIR}/devel/libltdl \
		libgd.so:${PORTSDIR}/graphics/gd

USES=		cpe gmake perl5
USE_PERL5=	build
USE_PHP=	xml
USE_RC_SUBR=	nagios

CONFLICTS=	nagios-[123].* nagios-devel-*

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-command-user=${NAGIOSUSER} \
		--with-command-group=${WWWGRP} \
		--with-nagios-user=${NAGIOSUSER} \
		--with-nagios-group=${NAGIOSGROUP} \
		--with-htmurl=${NAGIOSHTMURL} \
		--with-cgiurl=${NAGIOSCGIURL} \
		--sbindir=${PREFIX}/${NAGIOSWWWDIR}/cgi-bin \
		--libexecdir=${PREFIX}/libexec/nagios \
		--datadir=${PREFIX}/${NAGIOSWWWDIR} \
		--sysconfdir=${PREFIX}/etc/nagios \
		--localstatedir=${NAGIOSDIR} \
		--with-httpd-conf=${PREFIX}/etc \
		--with-checkresult-dir=${NAGIOSDIR}/checkresults \
		--disable-statuswrl \
		--enable-event-broker \
		ac_cv_lib_iconv_main=no
CONFIGURE_ENV=	PERL=${PERL}

CPPFLAGS+=	-I${LOCALBASE}/include
CFLAGS+=	${CPPFLAGS}
LIBS+=		-L${LOCALBASE}/lib

INSTALL_TARGET=	install install-commandmode install-config
PLIST_SUB=	NAGIOSDIR=${NAGIOSDIR} \
		NAGIOSWWWDIR=${NAGIOSWWWDIR} \
		NAGIOSUSER=${NAGIOSUSER} \
		NAGIOSGROUP=${NAGIOSGROUP} \
		WWWGRP=${WWWGRP}
SUB_LIST=	NAGIOSDIR=${NAGIOSDIR} \
		NAGIOSWWWDIR=${PREFIX}/${NAGIOSWWWDIR} \
		NAGIOSUSER=${NAGIOSUSER} \
		NAGIOSGROUP=${NAGIOSGROUP} \
		NAGIOSHTMURL=${NAGIOSHTMURL} \
		NAGIOSCGIURL=${NAGIOSCGIURL}

SUB_FILES=	pkg-message

NAGIOSUSER?=	nagios
NAGIOSGROUP?=	nagios
NAGIOSDIR?=	/var/spool/nagios

NAGIOSWWWDIR?=	www/nagios
NAGIOSHTMURL?=	/nagios
NAGIOSCGIURL?=	${NAGIOSHTMURL}/cgi-bin

USERS=		${NAGIOSUSER}
GROUPS=		${NAGIOSGROUP}

OPTIONS_DEFINE=	NANOSLEEP UNHANDLED_HACK
OPTIONS_RADIO=		PLUGINS
OPTIONS_RADIO_PLUGINS=	MONPLUGINS NAGPLUGINS
OPTIONS_DEFAULT=	NAGPLUGINS
NANOSLEEP_DESC=		Use nanosleep in event timing
UNHANDLED_HACK_DESC=	Display passive checks in unhandled queries

MONPLUGINS_RUN_DEPENDS=	${LOCALBASE}/libexec/nagios/check_nagios:${PORTSDIR}/net-mgmt/monitoring-plugins
NAGPLUGINS_RUN_DEPENDS=	${LOCALBASE}/libexec/nagios/check_nagios:${PORTSDIR}/net-mgmt/nagios-plugins

OPTIONS_SUB=

NANOSLEEP_CONFIGURE_ENABLE=	nanosleep

# sed -e 's#;serviceprops=42\&#;serviceprops=10\&#g' -e \
#	 's#;hostprops=42\"#;hostprops=10\"#g' ${WRKSRC}/html/side.php
UNHANDLED_HACK_EXTRA_PATCHES=	${PATCHDIR}/extra-patch-html__side.php

post-install:
	@${MV} ${STAGEDIR}${PREFIX}/${NAGIOSWWWDIR}/config.inc.php ${STAGEDIR}${PREFIX}/${NAGIOSWWWDIR}/config.inc.php.sample

.include <bsd.port.mk>
