# Created by: Blaz Zupan <blaz@si.FreeBSD.org>
# $FreeBSD$

PORTNAME=	nagios
PORTVERSION=	3.4.3
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-3.x/${PORTNAME}-${PORTVERSION}

MAINTAINER=	jarrod@downtools.com.au
COMMENT=	Extremely powerful network monitoring system

LICENSE=	GPLv2

LIB_DEPENDS=	gd:${PORTSDIR}/graphics/gd
RUN_DEPENDS=	${LOCALBASE}/libexec/nagios/check_nagios:${PORTSDIR}/net-mgmt/nagios-plugins

USE_ICONV=	yes
USE_PERL5_BUILD=yes
USE_AUTOTOOLS=	autoconf libltdl
USE_PHP=	yes
USE_RC_SUBR=	nagios

CONFLICTS=	nagios-[12].* nagios-devel-*

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-command-user=${NAGIOSUSER} \
		--with-command-group=${WWWGRP} \
		--with-nagios-user=${NAGIOSUSER} \
		--with-nagios-group=${NAGIOSGROUP} \
		--with-htmurl=${NAGIOSHTMURL} \
		--with-cgiurl=${NAGIOSCGIURL} \
		--sbindir=${PREFIX}/${NAGIOSWWWDIR}/cgi-bin \
		--libexecdir=${PREFIX}/libexec/nagios \
		--datarootdir=${PREFIX}/${NAGIOSWWWDIR} \
		--datadir=${PREFIX}/${NAGIOSWWWDIR} \
		--sysconfdir=${PREFIX}/etc/nagios \
		--localstatedir=${NAGIOSDIR} \
		--with-httpd-conf=${PREFIX}/etc \
		--with-checkresult-dir=${NAGIOSDIR}/checkresults \
		--disable-statuswrl
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib" \
		PERL=${PERL}

CPPFLAGS+=	-I${LOCALBASE}/include -fPIC
CFLAGS+=	${CPPFLAGS}

MAKE_JOBS_UNSAFE=	yes

INSTALL_TARGET=	install install-commandmode install-config
PLIST_SUB=	NAGIOSDIR=${NAGIOSDIR} \
		NAGIOSWWWDIR=${NAGIOSWWWDIR} \
		NAGIOSUSER=${NAGIOSUSER} \
		NAGIOSGROUP=${NAGIOSGROUP} \
		NAGIOSUID=${NAGIOSUID} \
		NAGIOSGID=${NAGIOSGID} \
		NAGIOSHTMURL=${NAGIOSHTMURL} \
		NAGIOSCGIURL=${NAGIOSCGIURL} \
		WWWGRP=${WWWGRP}

SUB_FILES=	pkg-message

# XXX: Don't remove PREFIX from SUB_LIST here.
SUB_LIST=	PREFIX=${PREFIX} \
		${PLIST_SUB}

NAGIOSUSER?=	nagios
NAGIOSGROUP?=	nagios
NAGIOSDIR?=	/var/spool/nagios

NAGIOSUID=	181
NAGIOSGID=	${NAGIOSUID}

NAGIOSWWWDIR?=	www/nagios
NAGIOSHTMURL?=	/nagios
NAGIOSCGIURL?=	${NAGIOSHTMURL}/cgi-bin

USERS=		${NAGIOSUSER}
GROUPS=		${NAGIOSGROUP}

OPTIONS_DEFINE=	EMBEDDED_PERL NANOSLEEP EVENT_BROKER UNHANDLED_HACK
EMBEDDED_PERL_DESC=	Enable embedded Perl [requires Perl 5.8.0+]
NANOSLEEP_DESC=		Use nanosleep in event timing
EVENT_BROKER_DESC=	Enable event broker functionality
UNHANDLED_HACK_DESC=	Display passive checks in unhandled queries

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEMBEDDED_PERL}
USE_PERL5=	yes
CONFIGURE_ARGS+=--enable-embedded-perl \
		--with-perlcache
PLIST_SUB+=	EMBEDDED_PERL=""
.else
PLIST_SUB+=	EMBEDDED_PERL="@comment "
.endif

.if ${PORT_OPTIONS:MNANOSLEEP}
CONFIGURE_ARGS+=--enable-nanosleep
.endif

.if ${PORT_OPTIONS:MEVENT_BROKER}
CONFIGURE_ARGS+=--enable-event-broker
.else
CONFIGURE_ARGS+=--disable-event-broker
.endif

post-extract:
	@${MV} ${WRKDIR}/${PORTNAME} ${WRKSRC}

post-patch:
.if ${PORT_OPTIONS:MUNHANDLED_HACK}
	@${REINPLACE_CMD} -e 's#;serviceprops=42\&#;serviceprops=10\&#g' \
		-e 's#;hostprops=42\"#;hostprops=10\"#g' ${WRKSRC}/html/side.php
.endif

post-install:
	@${CHMOD} 775 ${NAGIOSDIR} ${NAGIOSDIR}/archives ${NAGIOSDIR}/checkresults ${NAGIOSDIR}/rw
	@${CHOWN} ${NAGIOSUSER}:${NAGIOSGROUP} ${NAGIOSDIR} ${NAGIOSDIR}/archives ${NAGIOSDIR}/checkresults
	@${CHOWN} ${NAGIOSUSER}:${WWWGRP} ${NAGIOSDIR}/rw
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
