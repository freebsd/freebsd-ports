# Created by: Jarrod Sayers <jarrod@netleader.com.au>
# $FreeBSD$

PORTNAME=	nagios
DISTVERSIONPREFIX=HEAD-
DISTVERSION=	20101122
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.downtools.com.au/~jarrod/nagios/
PKGNAMESUFFIX=	-devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Powerful network monitoring system

LIB_DEPENDS=	gd:${PORTSDIR}/graphics/gd
RUN_DEPENDS=	${LOCALBASE}/libexec/nagios/check_nagios:${PORTSDIR}/net-mgmt/nagios-plugins

MASTER_SITE_FREEBSD=	yes
LATEST_LINK=	nagios-devel

USES=		iconv perl5
USE_PERL5=	build
USE_AUTOTOOLS=	autoconf libltdl
USE_RC_SUBR=	nagios

CONFLICTS=	nagios-[123].*

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSIONPREFIX:C/-$//}

OPTIONS_DEFINE=	EMBEDDED_PERL NANOSLEEP EVENT_BROKER UNHANDLED_HACK
EMBEDDED_PERL_DESC=	Embedded Perl
NANOSLEEP_DESC=		Use nanosleep in event timing
EVENT_BROKER_DESC=	Event broker functionality
UNHANDLED_HACK_DESC=	Display passive checks in unhandled queries

GNU_CONFIGURE=	yes
WANT_PHP_MOD=	yes

NAGIOSUSER?=	nagios
NAGIOSGROUP?=	nagios
NAGIOSDIR?=	/var/spool/nagios

NAGIOSUID=	181
NAGIOSGID=	${NAGIOSUID}

NAGIOSHTMURL?=	/nagios
NAGIOSCGIURL?=	${NAGIOSHTMURL}/cgi-bin

NO_STAGE=	yes
.include <bsd.port.pre.mk>

CPPFLAGS+=	-I${LOCALBASE}/include -fPIC
CFLAGS+=	${CPPFLAGS}

CONFIGURE_ARGS=	--with-command-user=${NAGIOSUSER} \
		--with-command-group=${WWWGRP} \
		--with-nagios-user=${NAGIOSUSER} \
		--with-nagios-group=${NAGIOSGROUP} \
		--with-htmurl=${NAGIOSHTMURL} \
		--with-cgiurl=${NAGIOSCGIURL} \
		--sbindir=${WWWDIR}/cgi-bin \
		--libexecdir=${PREFIX}/libexec/nagios \
		--datarootdir=${WWWDIR} \
		--datadir=${WWWDIR} \
		--sysconfdir=${ETCDIR} \
		--localstatedir=${NAGIOSDIR} \
		--with-httpd-conf=${PREFIX}/etc \
		--with-checkresult-dir=${NAGIOSDIR}/checkresults \
		--disable-statuswrl

CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib" \
		PERL=${PERL}

MAKE_JOBS_UNSAFE=	yes

INSTALL_TARGET=	install install-commandmode install-config

PLIST_SUB=	NAGIOSDIR=${NAGIOSDIR} \
		NAGIOSUSER=${NAGIOSUSER} \
		NAGIOSGROUP=${NAGIOSGROUP} \
		NAGIOSUID=${NAGIOSUID} \
		NAGIOSGID=${NAGIOSGID} \
		NAGIOSHTMURL=${NAGIOSHTMURL} \
		NAGIOSCGIURL=${NAGIOSCGIURL} \
		WWWGRP=${WWWGRP}

SUB_FILES=	pkg-install \
		pkg-deinstall \
		pkg-message

# XXX: Don't remove PREFIX from SUB_LIST here.
SUB_LIST=	PREFIX=${PREFIX} \
		${PLIST_SUB}

USE_PHP=	yes

.if ${PORT_OPTIONS:MEMBEDDED_PERL}
USE_PERL5+=	run
CONFIGURE_ARGS+=	--enable-embedded-perl \
		--with-perlcache
PLIST_SUB+=	EMBEDDED_PERL=""
.else
PLIST_SUB+=	EMBEDDED_PERL="@comment "
.endif

.if ${PORT_OPTIONS:MNANOSLEEP}
CONFIGURE_ARGS+=	--enable-nanosleep
.endif

.if ${PORT_OPTIONS:MEVENT_BROKER}
CONFIGURE_ARGS+=	--enable-event-broker
.else
CONFIGURE_ARGS+=	--disable-event-broker
.endif

post-patch:
.if ${PORT_OPTIONS:MUNHANDLED_HACK}
	@${REINPLACE_CMD} -e 's#;serviceprops=42\&#;serviceprops=10\&#g' \
		-e 's#;hostprops=42\"#;hostprops=10\"#g' ${WRKSRC}/html/side.php
.endif

pre-su-install:
	@${SH} ${PKGINSTALL} ${DISTNAME} PRE-INSTALL

post-install:
	@${CHMOD} 775 ${NAGIOSDIR} ${NAGIOSDIR}/archives ${NAGIOSDIR}/checkresults ${NAGIOSDIR}/rw
	@${CHOWN} ${NAGIOSUSER}:${NAGIOSGROUP} ${NAGIOSDIR} ${NAGIOSDIR}/archives ${NAGIOSDIR}/checkresults
	@${CHOWN} ${NAGIOSUSER}:${WWWGRP} ${NAGIOSDIR}/rw
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
