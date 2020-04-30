# Created by: Blaz Zupan <blaz@si.FreeBSD.org>
# $FreeBSD$

PORTNAME=	nagios
PORTVERSION=	4.4.6
PORTEPOCH=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	https://assets.nagios.com/downloads/nagioscore/releases/ \
		SF/${PORTNAME}/${PORTNAME}-4.x/${PORTNAME}-${PORTVERSION}
PKGNAMESUFFIX=	4

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Powerful network monitoring system

LICENSE=	GPLv2

LIB_DEPENDS=	libltdl.so:devel/libltdl \
		libpng.so:graphics/png \
		libgd.so:graphics/gd

USES=		cpe gmake jpeg perl5 php
USE_PERL5=	build
USE_PHP=	xml filter
USE_RC_SUBR=	nagios

CONFLICTS=	nagios-[123].* nagios-devel-*

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-command-user=${NAGIOSUSER} \
		--with-command-group=${WWWGRP} \
		--with-nagios-user=${NAGIOSUSER} \
		--with-nagios-group=${NAGIOSGROUP} \
		--with-htmurl=${NAGIOSHTMURL} \
		--with-cgiurl=${NAGIOSCGIURL} \
		--with-lockfile=${NAGIOSDIR}/nagios.lock \
		--with-cgibindir=${WWWDIR}/cgi-bin \
		--libexecdir=${PREFIX}/libexec/nagios \
		--datadir=${WWWDIR} \
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
		NAGIOSUSER=${NAGIOSUSER} \
		NAGIOSGROUP=${NAGIOSGROUP} \
		WWWGRP=${WWWGRP}
SUB_LIST=	NAGIOSDIR=${NAGIOSDIR} \
		NAGIOSUSER=${NAGIOSUSER} \
		NAGIOSGROUP=${NAGIOSGROUP} \
		NAGIOSHTMURL=${NAGIOSHTMURL} \
		NAGIOSCGIURL=${NAGIOSCGIURL}

SUB_FILES=	pkg-message

NAGIOSUSER?=	nagios
NAGIOSGROUP?=	nagios
NAGIOSDIR?=	/var/spool/nagios

.if defined(NAGIOSWWWDIR)
WWWDIR=	${PREFIX}/${NAGIOSWWWDIR}
.endif
NAGIOSHTMURL?=	/nagios
NAGIOSCGIURL?=	${NAGIOSHTMURL}/cgi-bin

USERS=		${NAGIOSUSER}
GROUPS=		${NAGIOSGROUP}

OPTIONS_DEFINE=	NANOSLEEP UNHANDLED_HACK COREWINDOW
OPTIONS_RADIO=		PLUGINS
OPTIONS_RADIO_PLUGINS=	MONPLUGINS NAGPLUGINS
OPTIONS_DEFAULT=	NAGPLUGINS
NANOSLEEP_DESC=		Use nanosleep in event timing
UNHANDLED_HACK_DESC=	Display passive checks in unhandled queries
COREWINDOW_DESC=	Enable the corewindow parameter

MONPLUGINS_RUN_DEPENDS=	${LOCALBASE}/libexec/nagios/check_nagios:net-mgmt/monitoring-plugins
NAGPLUGINS_RUN_DEPENDS=	${LOCALBASE}/libexec/nagios/check_nagios:net-mgmt/nagios-plugins
COREWINDOW_CONFIGURE_ENABLE=	corewindow

OPTIONS_SUB=

NANOSLEEP_CONFIGURE_ENABLE=	nanosleep

post-patch:
	${REINPLACE_CMD} -e 's/\<77\([0-7]\)\>/75\1/g; s/\<66\([0-7]\)\>/64\1/; /chmod/d; \
		/\.cfg$$/s/$$/-sample/' \
		${WRKSRC}/Makefile.in ${WRKSRC}/base/Makefile.in ${WRKSRC}/cgi/Makefile.in ${WRKSRC}/contrib/Makefile.in ${WRKSRC}/html/Makefile.in

post-patch-UNHANDLED_HACK-on:
	${REINPLACE_CMD} -e 's#;serviceprops=42\&#;serviceprops=10\&#g' -e \
		's#;hostprops=42\"#;hostprops=10\"#g' ${WRKSRC}/html/side.php

post-install:
	@${RMDIR} ${STAGEDIR}${PREFIX}/libexec/nagios
	@${MV} ${STAGEDIR}${WWWDIR}/config.inc.php ${STAGEDIR}${WWWDIR}/config.inc.php.sample

.include <bsd.port.mk>
