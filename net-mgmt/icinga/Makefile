# New ports collection makefile for:	icinga
# Date created:				2012/02/10
# Whom:					chinsan
#
# $FreeBSD$
#

PORTNAME=	icinga
PORTVERSION=	1.3.0
CATEGORIES=	net-mgmt
MASTER_SITES=	SF

MAINTAINER=	chinsan@FreeBSD.org
COMMENT=	Enterprise grade open source monitoring system based on nagios

LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd
RUN_DEPENDS=	${LOCALBASE}/libexec/nagios/check_nagios:${PORTSDIR}/net-mgmt/nagios-plugins

LICENSE=	GPLv2

USE_ICONV=	yes
USE_PERL5_BUILD=	yes
USE_AUTOTOOLS=	autoconf libltdl
USE_RC_SUBR=	icinga

OPTIONS=	EMBEDDED_PERL "Enable embedded Perl [requires Perl 5.8.0+]" off \
		NANOSLEEP "Use nanosleep in event timing" off \
		EVENT_BROKER "Enable event broker functionality" off \
		UNHANDLED_HACK "Display passive checks in unhandled queries" off \

GNU_CONFIGURE=	yes

ICINGAUSER?=	icinga
ICINGAGROUP?=	icinga
ICINGADIR?=	/var/spool/icinga

ICINGAUID=	183
ICINGAGID=	${ICINGAUID}

ICINGAWWWDIR?=	www/icinga
ICINGAHTMURL?=	/icinga
ICINGACGIURL?=	${ICINGAHTMURL}/cgi-bin

.include <bsd.port.pre.mk>

CPPFLAGS=	-I${LOCALBASE}/include -fPIC
CFLAGS+=	${CPPFLAGS}

CONFIGURE_ARGS=	--with-command-user=${ICINGAUSER} \
		--with-command-group=${WWWGRP} \
		--with-icinga-user=${ICINGAUSER} \
		--with-icinga-group=${ICINGAGROUP} \
		--with-htmurl=${ICINGAHTMURL} \
		--with-cgiurl=${ICINGACGIURL} \
		--sbindir=${PREFIX}/${ICINGAWWWDIR}/cgi-bin \
		--libexecdir=${PREFIX}/libexec/icinga \
		--datarootdir=${PREFIX}/${ICINGAWWWDIR} \
		--datadir=${PREFIX}/${ICINGAWWWDIR} \
		--sysconfdir=${PREFIX}/etc/icinga \
		--localstatedir=${ICINGADIR} \
		--with-httpd-conf=${PREFIX}/etc \
		--with-checkresult-dir=${ICINGADIR}/checkresults \
		--disable-statuswrl

CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" \
		CFLAGS="${CFLAGS}" \
		LDFLAGS="${LDFLAGS}" \
		LIBS="-L${LOCALBASE}/lib" \
		PERL=${PERL}

MAKE_JOBS_UNSAFE=	yes

INSTALL_TARGET=	install install-commandmode install-config

PLIST_SUB=	ICINGADIR=${ICINGADIR} \
		ICINGAWWWDIR=${ICINGAWWWDIR} \
		ICINGAUSER=${ICINGAUSER} \
		ICINGAGROUP=${ICINGAGROUP} \
		ICINGAUID=${ICINGAUID} \
		ICINGAGID=${ICINGAGID} \
		ICINGAHTMURL=${ICINGAHTMURL} \
		ICINGACGIURL=${ICINGACGIURL} \
		WWWGRP=${WWWGRP}

SUB_FILES=	pkg-install \
		pkg-deinstall \
		pkg-message

# XXX: Don't remove PREFIX from SUB_LIST here.
SUB_LIST=	PREFIX=${PREFIX} \
		${PLIST_SUB}

USE_PHP=	yes

.if defined(WITH_EMBEDDED_PERL)
USE_PERL5=	5.8.0+
CONFIGURE_ARGS+=	--enable-embedded-perl \
		--with-perlcache
PLIST_SUB+=	EMBEDDED_PERL=""
.else
PLIST_SUB+=	EMBEDDED_PERL="@comment "
.endif

.if defined(WITH_NANOSLEEP)
CONFIGURE_ARGS+=	--enable-nanosleep
.endif

.if defined(WITH_EVENT_BROKER)
CONFIGURE_ARGS+=	--enable-event-broker
.else
CONFIGURE_ARGS+=	--disable-event-broker
.endif

post-patch:
.if defined(WITH_UNHANDLED_HACK)
	@${REINPLACE_CMD} -e 's#;serviceprops=42\&#;serviceprops=10\&#g' \
		-e 's#;hostprops=42\"#;hostprops=10\"#g' ${WRKSRC}/html/menu.html.in
	@${REINPLACE_CMD} -e 's#Linux#FreeBSD#' ${WRKSRC}/sample-config/icinga.cfg.in
	@${REINPLACE_CMD} -e 's#775#755#g; s#664#644#g' ${WRKSRC}/html/Makefile.in
	@${REINPLACE_CMD} -e 's#/bin/ping#/sbin/ping#' ${WRKSRC}/*
	@${FIND} ${WRKSRC} -name '*.orig' -delete
.endif

pre-su-install:
	@${SH} ${PKGINSTALL} ${DISTNAME} PRE-INSTALL

post-install:
	@${CHMOD} 775 ${ICINGADIR} ${ICINGADIR}/archives ${ICINGADIR}/checkresults ${ICINGADIR}/rw
	@${CHOWN} ${ICINGAUSER}:${ICINGAGROUP} ${ICINGADIR} ${ICINGADIR}/archives ${ICINGADIR}/checkresults
	@${CHOWN} ${ICINGAUSER}:${WWWGRP} ${ICINGADIR}/rw
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
