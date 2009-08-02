# New ports collection makefile for:	nagios
# Date created:				19 May 2002
# Whom:					Blaz Zupan <blaz@si.FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nagios
PORTVERSION=	2.12
PORTREVISION=	5
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

CONFLICTS=	nagios-[13].* nagios-devel-*
NO_LATEST_LINK=	yes

OPTIONS=	EMBEDDED_PERL "Enable embedded Perl [requires Perl 5.8+]" OFF \
		NANOSLEEP "Use nanosleep in event timing" OFF

GNU_CONFIGURE=	yes

NAGIOSUSER?=	nagios
NAGIOSGROUP?=	nagios
NAGIOSDIR?=	/var/spool/nagios

NAGIOSUID=	181
NAGIOSGID=	${NAGIOSUID}

NAGIOSWWWDIR?=	www/nagios
NAGIOSHTMURL?=	/nagios
NAGIOSCGIURL?=	${NAGIOSHTMURL}/cgi-bin

# Suggested NAGIOSHOMEURL values:
# Home:              main.html
# Tactical Overview: ${NAGIOSCGIURL}/tac.cgi
# Service Detail:    ${NAGIOSCGIURL}/status.cgi?host=all
# Host Detail:       ${NAGIOSCGIURL}/status.cgi?hostgroup=all&style=hostdetail
# Status Map:        ${NAGIOSCGIURL}/statusmap.cgi?host=all
NAGIOSHOMEURL?=	main.html

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
		--prefix=${PREFIX}

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

post-patch:
	@${REINPLACE_CMD} -e 's#"main.html"#"${NAGIOSHOMEURL:S/\//\\\//g:S/&/\\&/g}"#' \
		${WRKSRC}/html/index.html.in

pre-install:
	@${SH} ${PKGINSTALL} ${DISTNAME} PRE-INSTALL

post-install:
	@${CHMOD} 775 ${NAGIOSDIR} ${NAGIOSDIR}/archives ${NAGIOSDIR}/rw
	@${CHOWN} ${NAGIOSUSER}:${NAGIOSGROUP} ${NAGIOSDIR} ${NAGIOSDIR}/archives
	@${CHOWN} ${NAGIOSUSER}:${WWWGRP} ${NAGIOSDIR}/rw
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
