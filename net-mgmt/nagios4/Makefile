PORTNAME=	nagios
DISTVERSION=	4.5.11
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	https://assets.nagios.com/downloads/nagioscore/releases/ \
		SF/${PORTNAME}/${PORTNAME}-4.x/${PORTNAME}-${DISTVERSION}
PKGNAMESUFFIX=	4

MAINTAINER=	hard.egg0918@fastmail.com
COMMENT=	Powerful network monitoring system
WWW=		https://www.nagios.org/

LICENSE=	GPLv2

LIB_DEPENDS=	libltdl.so:devel/libltdl \
		libpng.so:graphics/png \
		libgd.so:graphics/gd

USES=		cpe dos2unix gmake jpeg localbase perl5 php ssl
DOS2UNIX_FILES=	contrib/exfoliation/stylesheets/common.css
USE_PERL5=	build
USE_RC_SUBR=	${PORTNAME}

NAGIOSUSER?=	${PORTNAME}
NAGIOSGROUP?=	${PORTNAME}
NAGIOSDIR?=	/var/spool/${PORTNAME}
NAGIOSHTMURL?=	/${PORTNAME}
NAGIOSCGIURL?=	${NAGIOSHTMURL}/cgi-bin

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-command-user=${NAGIOSUSER} \
		--with-command-group=${WWWGRP} \
		--with-nagios-user=${NAGIOSUSER} \
		--with-nagios-group=${NAGIOSGROUP} \
		--with-htmurl=${NAGIOSHTMURL} \
		--with-cgiurl=${NAGIOSCGIURL} \
		--with-lockfile=${NAGIOSDIR}/${PORTNAME}.lock \
		--with-cgibindir=${WWWDIR}/cgi-bin \
		--with-ssl-inc=${OPENSSLINC} \
		--with-ssl-lib=${OPENSSLLIB} \
		--libexecdir=${PREFIX}/libexec/${PORTNAME} \
		--datadir=${WWWDIR} \
		--sysconfdir=${ETCDIR} \
		--localstatedir=${NAGIOSDIR} \
		--with-httpd-conf=${PREFIX}/etc \
		--with-checkresult-dir=${NAGIOSDIR}/checkresults \
		--disable-statuswrl \
		--enable-event-broker \
		ac_cv_lib_iconv_main=no
CONFIGURE_ENV=	PERL=${PERL}

INSTALL_TARGET=	install install-commandmode install-config

CONFLICTS=	${PORTNAME}

.if defined(NAGIOSWWWDIR)
WWWDIR=	${PREFIX}/${NAGIOSWWWDIR}
.endif
SUB_FILES=	pkg-message
SUB_LIST=	NAGIOSDIR=${NAGIOSDIR} \
		NAGIOSUSER=${NAGIOSUSER} \
		NAGIOSGROUP=${NAGIOSGROUP} \
		NAGIOSHTMURL=${NAGIOSHTMURL} \
		NAGIOSCGIURL=${NAGIOSCGIURL}

.if ${NAGIOSUSER} == ${PORTNAME}
USERS=		${NAGIOSUSER}
.endif
.if ${NAGIOSGROUP} == ${PORTNAME}
GROUPS=		${NAGIOSGROUP}
.endif

PLIST_SUB=	NAGIOSDIR=${NAGIOSDIR} \
		NAGIOSUSER=${NAGIOSUSER} \
		NAGIOSGROUP=${NAGIOSGROUP} \
		WWWGRP=${WWWGRP}

OPTIONS_DEFINE=		NANOSLEEP UNHANDLED_HACK COREWINDOW
OPTIONS_DEFAULT=	NAGPLUGINS
OPTIONS_RADIO=		PLUGINS
OPTIONS_RADIO_PLUGINS=	MONPLUGINS NAGPLUGINS

COREWINDOW_DESC=	Enable the corewindow parameter
NANOSLEEP_DESC=		Use nanosleep in event timing
UNHANDLED_HACK_DESC=	Display passive checks in unhandled queries

COREWINDOW_CONFIGURE_ENABLE=	corewindow
MONPLUGINS_RUN_DEPENDS=		${LOCALBASE}/libexec/${PORTNAME}/check_nagios:net-mgmt/monitoring-plugins
NAGPLUGINS_RUN_DEPENDS=		${LOCALBASE}/libexec/${PORTNAME}/check_nagios:net-mgmt/nagios-plugins
NANOSLEEP_CONFIGURE_ENABLE=	nanosleep

post-patch:
	${REINPLACE_CMD} -e 's/\<77\([0-7]\)\>/75\1/g; s/\<66\([0-7]\)\>/64\1/; /chmod/d; \
		/\.cfg$$/s/$$/-sample/' \
		${WRKSRC}/Makefile.in ${WRKSRC}/base/Makefile.in ${WRKSRC}/cgi/Makefile.in \
		${WRKSRC}/contrib/Makefile.in ${WRKSRC}/html/Makefile.in

post-patch-UNHANDLED_HACK-on:
	${REINPLACE_CMD} -e 's#;serviceprops=42\&#;serviceprops=10\&#g' -e \
		's#;hostprops=42\"#;hostprops=10\"#g' ${WRKSRC}/html/side.php

post-install:
	@${RMDIR} ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}
	@${MV} ${STAGEDIR}${WWWDIR}/config.inc.php ${STAGEDIR}${WWWDIR}/config.inc.php.sample

.include <bsd.port.mk>
