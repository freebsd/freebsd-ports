# Created by: Blaz Zupan <blaz@si.FreeBSD.org>
# $FreeBSD$

PORTNAME=	nagios
PORTVERSION=	3.5.1
PORTREVISION=	12
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-3.x/${PORTNAME}-${PORTVERSION}

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Powerful network monitoring system

LICENSE=	GPLv2

LIB_DEPENDS=	libltdl.so:devel/libltdl \
		libgd.so:graphics/gd

PORTSCOUT=	limit:^3.

USES=		cpe perl5 php
USE_PERL5=	build
USE_RC_SUBR=	nagios

CONFLICTS=	nagios-[12].* nagios-devel-* nagios4-*

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
		ac_cv_lib_iconv_main=no
CONFIGURE_ENV=	PERL=${PERL}

CPPFLAGS+=	-I${LOCALBASE}/include
CFLAGS+=	${CPPFLAGS}
LIBS+=		-L${LOCALBASE}/lib

MAKE_JOBS_UNSAFE=	yes

INSTALL_TARGET=	install install-commandmode install-config
PLIST_SUB=	NAGIOSDIR=${NAGIOSDIR} \
		NAGIOSWWWDIR=${NAGIOSWWWDIR} \
		NAGIOSUSER=${NAGIOSUSER} \
		NAGIOSGROUP=${NAGIOSGROUP} \
		WWWGRP=${WWWGRP}

SUB_FILES=	pkg-message

# XXX: Don't remove PREFIX from SUB_LIST here.
SUB_LIST=	PREFIX=${PREFIX} \
		NAGIOSHTMURL=${NAGIOSHTMURL} \
		NAGIOSCGIURL=${NAGIOSCGIURL} \
		${PLIST_SUB}

NAGIOSUSER?=	nagios
NAGIOSGROUP?=	nagios
NAGIOSDIR?=	/var/spool/nagios

NAGIOSWWWDIR?=	www/nagios
NAGIOSHTMURL?=	/nagios
NAGIOSCGIURL?=	${NAGIOSHTMURL}/cgi-bin

USERS=		${NAGIOSUSER}
GROUPS=		${NAGIOSGROUP}

OPTIONS_DEFINE=	EMBEDDED_PERL NANOSLEEP EVENT_BROKER UNHANDLED_HACK
OPTIONS_RADIO=		PLUGINS
OPTIONS_RADIO_PLUGINS=	MONPLUGINS NAGPLUGINS
OPTIONS_DEFAULT=	NAGPLUGINS
EMBEDDED_PERL_DESC=	Enable embedded Perl [requires Perl 5.8.0+]
NANOSLEEP_DESC=		Use nanosleep in event timing
EVENT_BROKER_DESC=	Enable event broker functionality
UNHANDLED_HACK_DESC=	Display passive checks in unhandled queries

MONPLUGINS_RUN_DEPENDS=	${LOCALBASE}/libexec/nagios/check_nagios:net-mgmt/monitoring-plugins
NAGPLUGINS_RUN_DEPENDS=	${LOCALBASE}/libexec/nagios/check_nagios:net-mgmt/nagios-plugins

OPTIONS_SUB=

EMBEDDED_PERL_USE=	perl5=run
EMBEDDED_PERL_CONFIGURE_ENABLE=	embedded-perl
EMBEDDED_PERL_CONFIGURE_WITH=	perlcache
NANOSLEEP_CONFIGURE_ENABLE=	nanosleep
EVENT_BROKER_CONFIGURE_ENABLE=	event-broker

post-extract:
	@${MV} ${WRKDIR}/${PORTNAME} ${WRKSRC}

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} '/^INSTALL_OPTS=/d' ${WRKSRC}/configure
.if ${PORT_OPTIONS:MUNHANDLED_HACK}
	@${REINPLACE_CMD} -e 's#;serviceprops=42\&#;serviceprops=10\&#g' \
		-e 's#;hostprops=42\"#;hostprops=10\"#g' ${WRKSRC}/html/side.php
.endif

post-install:
	@${MV} ${STAGEDIR}${PREFIX}/${NAGIOSWWWDIR}/config.inc.php ${STAGEDIR}${PREFIX}/${NAGIOSWWWDIR}/config.inc.php.sample

.include <bsd.port.mk>
