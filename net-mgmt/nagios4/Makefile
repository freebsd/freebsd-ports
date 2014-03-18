# Created by: Blaz Zupan <blaz@si.FreeBSD.org>
# $FreeBSD$

PORTNAME=	nagios
PORTVERSION=	4.0.4
PORTREVISION=	1
PKGNAMESUFFIX=	4
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-4.x/${PORTNAME}-${PORTVERSION}

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Powerful network monitoring system

LICENSE=	GPLv2

LIB_DEPENDS=	libgd.so:${PORTSDIR}/graphics/gd

USES=		gmake iconv perl5 uidfix
USE_PERL5=	build
USE_AUTOTOOLS=	autoconf libltdl
USE_PHP=	xml
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
		--disable-statuswrl \
		--enable-event-broker
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib" \
		PERL=${PERL}

CPPFLAGS+=	-I${LOCALBASE}/include -fPIC
CFLAGS+=	${CPPFLAGS}

INSTALL_TARGET=	install install-commandmode install-config
PLIST_SUB=	NAGIOSDIR=${NAGIOSDIR} \
		NAGIOSWWWDIR=${NAGIOSWWWDIR} \
		NAGIOSUSER=${NAGIOSUSER} \
		NAGIOSGROUP=${NAGIOSGROUP} \
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

NAGIOSWWWDIR?=	www/nagios
NAGIOSHTMURL?=	/nagios
NAGIOSCGIURL?=	${NAGIOSHTMURL}/cgi-bin

USERS=		${NAGIOSUSER}
GROUPS=		${NAGIOSGROUP}

OPTIONS_DEFINE=	NANOSLEEP UNHANDLED_HACK
NANOSLEEP_DESC=		Use nanosleep in event timing
UNHANDLED_HACK_DESC=	Display passive checks in unhandled queries

OPTIONS_SUB=

NANOSLEEP_CONFIGURE_ENABLE=	nanosleep

# sed -e 's#;serviceprops=42\&#;serviceprops=10\&#g' -e \
#	 's#;hostprops=42\"#;hostprops=10\"#g' ${WRKSRC}/html/side.php
UNHANDLED_HACK_EXTRA_PATCHES=	${PATCHDIR}/extra-patch-html__side.php

post-install:
	@${MV} ${STAGEDIR}${PREFIX}/${NAGIOSWWWDIR}/config.inc.php ${STAGEDIR}${PREFIX}/${NAGIOSWWWDIR}/config.inc.php.sample

.include <bsd.port.mk>
