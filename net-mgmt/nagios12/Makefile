# New ports collection makefile for:	nagios
# Date created:				19 May 2002
# Whom:					Blaz Zupan <blaz@si.FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nagios
PORTVERSION=	1.2
PORTREVISION=	6
PORTEPOCH=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	SF

MAINTAINER=	jarrod@netleader.com.au
COMMENT=	Extremely powerful network monitoring system

DEPRECATED=	Obsolete version, consider migration to net-mgmt/nagios
EXPIRATION_DATE=	2009-04-17

LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd
RUN_DEPENDS=	${LOCALBASE}/libexec/nagios/check_nagios:${PORTSDIR}/net-mgmt/nagios-plugins

GNU_CONFIGURE=	yes
USE_RC_SUBR=	nagios
USE_PERL5_BUILD=yes

NAGIOSUSER?=	nagios
NAGIOSGROUP?=	nagios
NAGIOSDIR?=	/var/spool/nagios

OPTIONS=	MYSQL "MySQL suport" off \
		PGSQL "PostgreSQL suport" off \
		FILE_PERFDATA "Save performance data to files" off

CONFLICTS=	nagios-[23].* nagios-devel-*
LATEST_LINK=	nagios12

.include <bsd.port.pre.mk>

CPPFLAGS=	-I${LOCALBASE}/include
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}" \
		CFLAGS="${CPPFLAGS} ${CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib -lgd"
CONFIGURE_ARGS=	--with-command-user=${NAGIOSUSER} \
		--with-command-grp=www \
		--with-nagios-user=${NAGIOSUSER} \
		--with-nagios-grp=${NAGIOSGROUP} \
		--with-template-objects \
		--sbindir=${PREFIX}/share/nagios/cgi-bin \
		--libexecdir=${PREFIX}/libexec/nagios \
		--datadir=${PREFIX}/share/nagios \
		--sysconfdir=${PREFIX}/etc/nagios \
		--localstatedir=${NAGIOSDIR} \
		--prefix=${PREFIX}

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
CONFIGURE_ARGS+=	--with-mysql-lib=${LOCALBASE}/lib/mysql \
		--with-mysql-inc=${LOCALBASE}/include/mysql \
		--with-mysql-xdata
.else
CONFIGURE_ARGS+=	--with-template-extinfo
.endif

.if defined(WITH_FILE_PERFDATA)
CONFIGURE_ARGS+=--with-file-perfdata
.endif

.if defined(WITH_PGSQL)
USE_PGSQL=	yes
CONFIGURE_ARGS+=--with-pgsql-lib=${LOCALBASE}/pgsql \
		--with-pgsql-inc=${LOCALBASE}/pgsql \
		--with-pgsql-xdata
.endif

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

INSTALL_TARGET=	all install config install-config install-commandmode

pre-install:
	@${SH} ${PKGINSTALL} ${DISTNAME} PRE-INSTALL

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
