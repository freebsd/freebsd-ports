# New ports collection makefile for:	nagios
# Date created:				19 May 2002
# Whom:					Blaz Zupan <blaz@si.FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nagios
PORTVERSION=	3.0.6
PORTREVISION=	3
CATEGORIES=	net-mgmt
MASTER_SITES=	SF

MAINTAINER=	jarrod@netleader.com.au
COMMENT=	Extremely powerful network monitoring system

LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd
RUN_DEPENDS=	${LOCALBASE}/libexec/nagios/check_nagios:${PORTSDIR}/net-mgmt/nagios-plugins

USE_ICONV=	yes
USE_PERL5_BUILD=	yes
USE_AUTOTOOLS=	autoconf:262 libltdl:22
USE_RC_SUBR=	nagios

CONFLICTS=	nagios-[12].* nagios-devel-*

OPTIONS=	EMBEDDED_PERL "Enable embedded Perl [requires Perl 5.8.0+]" off \
		NANOSLEEP "Use nanosleep in event timing" off \
		EVENT_BROKER "Enable event broker functionality" off \
		UNHANDLED_HACK "Display passive checks in unhandled queries" off

GNU_CONFIGURE=	yes

NAGIOSUSER?=	nagios
NAGIOSGROUP?=	nagios
NAGIOSDIR?=	/var/spool/nagios

NAGIOSUID=	181
NAGIOSGID=	${NAGIOSUID}

NAGIOSWWWDIR?=	www/nagios
NAGIOSHTMURL?=	/nagios
NAGIOSCGIURL?=	${NAGIOSHTMURL}/cgi-bin

.include <bsd.port.pre.mk>

CPPFLAGS=	-I${LOCALBASE}/include -fPIC
CFLAGS+=	${CPPFLAGS}

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
		--with-checkresult-dir=${NAGIOSDIR}/checkresults

CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" \
		CFLAGS="${CFLAGS}" \
		LDFLAGS="${LDFLAGS}" \
		LIBS="-L${LOCALBASE}/lib" \
		PERL=${PERL}

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

SUB_FILES=	pkg-install \
		pkg-deinstall \
		pkg-message

### XXX: Subtle bug with removing PREFIX from here
SUB_LIST=	PREFIX=${PREFIX} \
		${PLIST_SUB}

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
	@${REINPLACE_CMD} -e 's#\&serviceprops=42\&#\&serviceprops=10\&#g' \
		-e 's#\&hostprops=42\"#\&hostprops=10\"#g' ${WRKSRC}/html/side.html.in
.endif

pre-install:
	@${SH} ${PKGINSTALL} ${DISTNAME} PRE-INSTALL

post-install:
	@${CHMOD} 775 ${NAGIOSDIR} ${NAGIOSDIR}/archives ${NAGIOSDIR}/checkresults ${NAGIOSDIR}/rw
	@${CHOWN} ${NAGIOSUSER}:${NAGIOSGROUP} ${NAGIOSDIR} ${NAGIOSDIR}/archives ${NAGIOSDIR}/checkresults
	@${CHOWN} ${NAGIOSUSER}:${WWWGRP} ${NAGIOSDIR}/rw
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
