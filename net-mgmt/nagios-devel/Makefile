# New ports collection makefile for:	nagios-devel
# Date created:				14 July 2007
# Whom:					Jarrod Sayers <jarrod@netleader.com.au>
#
# $FreeBSD$
#

PORTNAME=	nagios
DISTVERSION=	3.0.3
CATEGORIES=	net-mgmt
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	nagios

MAINTAINER=	jarrod@netleader.com.au
COMMENT=	Extremely powerful network monitoring system

LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd
RUN_DEPENDS=	${LOCALBASE}/libexec/nagios/check_nagios:${PORTSDIR}/net-mgmt/nagios-plugins

LATEST_LINK=	nagios-devel

USE_ICONV=	yes
USE_PERL5_BUILD=	yes
USE_AUTOTOOLS=	autoconf:261 libltdl:15
USE_RC_SUBR=	nagios.sh

CONFLICTS=	nagios-[12].*

OPTIONS=	EMBEDDED_PERL "Enable embedded Perl [requires Perl 5.8+]" off \
		NANOSLEEP "Use nanosleep in event timing" off

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

SUB_LIST=	PREFIX=${PREFIX} \
		${PLIST_SUB}

.if defined(WITH_EMBEDDED_PERL)
.if ${PERL_LEVEL} >= 500800
USE_PERL5=	yes
CONFIGURE_ARGS+=	--enable-embedded-perl \
		--with-perlcache
.else
IGNORE=		embedded Perl requires Perl 5.8 or higher (see lang/perl5.8)
.endif
PLIST_SUB+=	EMBEDDED_PERL=""
.else
PLIST_SUB+=	EMBEDDED_PERL="@comment "
.endif

.if defined(WITH_NANOSLEEP)
CONFIGURE_ARGS+=	--enable-nanosleep
.endif

pre-install:
	@${SH} ${PKGINSTALL} ${DISTNAME} PRE-INSTALL

post-install:
	@${CHMOD} 775 ${NAGIOSDIR} ${NAGIOSDIR}/archives ${NAGIOSDIR}/checkresults ${NAGIOSDIR}/rw
	@${CHOWN} ${NAGIOSUSER}:${NAGIOSGROUP} ${NAGIOSDIR} ${NAGIOSDIR}/archives ${NAGIOSDIR}/checkresults
	@${CHOWN} ${NAGIOSUSER}:${WWWGRP} ${NAGIOSDIR}/rw
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
