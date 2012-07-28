# New ports collection makefile for:	icinga
# Date created:				2012/02/10
# Whom:					chinsan
#
# $FreeBSD$
#

PORTNAME=	icinga
PORTVERSION=	1.7.1
CATEGORIES=	net-mgmt
MASTER_SITES=	SF

MAINTAINER=	lme@FreeBSD.org
COMMENT=	Enterprise grade open source monitoring system based on nagios

LICENSE=	GPLv2

LIB_DEPENDS=	gd:${PORTSDIR}/graphics/gd
RUN_DEPENDS=	${LOCALBASE}/libexec/nagios/check_nagios:${PORTSDIR}/net-mgmt/nagios-plugins

USE_ICONV=	yes
USE_PERL5_BUILD=	yes
USE_AUTOTOOLS=	autoconf libltdl
USE_RC_SUBR=	icinga

GNU_CONFIGURE=	yes

ICINGAUSER?=	icinga
ICINGAGROUP?=	icinga
ICINGADIR?=	/var/spool/icinga
ICINGALOGDIR?=	/var/log/icinga

ICINGAUID=	183
ICINGAGID=	${ICINGAUID}

ICINGAWWWDIR?=	www/icinga
ICINGAHTMURL?=	/icinga
ICINGACGIURL?=	${ICINGAHTMURL}/cgi-bin

CPPFLAGS+=	-I${LOCALBASE}/include -fPIC
CFLAGS+=	${CPPFLAGS}

CONFIGURE_ARGS=	--with-command-user=${ICINGAUSER} \
		--with-command-group=${WWWGRP} \
		--with-icinga-user=${ICINGAUSER} \
		--with-icinga-group=${ICINGAGROUP} \
		--with-htmurl=${ICINGAHTMURL} \
		--with-cgiurl=${ICINGACGIURL} \
		--sbindir=${PREFIX}/${ICINGAWWWDIR}/cgi-bin \
		--datarootdir=${PREFIX}/${ICINGAWWWDIR} \
		--datadir=${PREFIX}/${ICINGAWWWDIR} \
		--sysconfdir=${PREFIX}/etc/icinga \
		--localstatedir=${ICINGADIR} \
		--with-checkresult-dir=${ICINGADIR}/checkresults \
		--libexecdir=${PREFIX}/libexec/icinga \
		--with-plugin-dir=${LOCALBASE}/libexec/nagios \
		--with-log-dir=${ICINGALOGDIR} \
		--enable-event-broker

CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib" \
		PERL=${PERL}

MAKE_JOBS_UNSAFE=	yes

INSTALL_TARGET=	install install-commandmode install-config install-eventhandlers

PLIST_SUB=	ICINGADIR=${ICINGADIR} \
		ICINGALOGDIR=${ICINGALOGDIR} \
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

OPTIONS_DEFINE=		EMBEDDED_PERL NANOSLEEP UNHANDLED_HACK IDOUTILS PGSQL MYSQL APACHE
OPTIONS_DEFAULT=	EMBEDDED_PERL IDOUTILS

EMBEDDED_PERL_DESC=	Enable embedded Perl
NANOSLEEP_DESC=		Use nanosleep in event timing
UNHANDLED_HACK_DESC=	Display passive checks in unhandled queries
APACHE_DESC=		Depend on Apache and install webconfig

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEMBEDDED_PERL}
USE_PERL5=	5.8.0+
CONFIGURE_ARGS+=	--enable-embedded-perl \
		--with-perlcache
PLIST_SUB+=	EMBEDDED_PERL=""
.else
PLIST_SUB+=	EMBEDDED_PERL="@comment "
.endif

.if ${PORT_OPTIONS:MNANOSLEEP}
CONFIGURE_ARGS+=	--enable-nanosleep
.endif

.if ${PORT_OPTIONS:MIDOUTILS}
LIB_DEPENDS+=		dbi:${PORTSDIR}/databases/libdbi-drivers
CONFIGURE_ARGS+=	--enable-idoutils \
			--enable-ssl \
			--with-dbi-lib=${LOCALBASE}/lib \
			--with-dbi-inc=${LOCALBASE}/include
INSTALL_TARGET+=	install-idoutils
USE_RC_SUBR+=		ido2db
PLIST_SUB+=	IDOUTILS=""
.else
PLIST_SUB+=	IDOUTILS="@comment "
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=		yes
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=		yes
CONFIGURE_ARGS+=	--enable-pgsql
.endif

.if ${PORT_OPTIONS:MAPACHE}
USE_APACHE=	22+
CONFIGURE_ARGS+=	--with-httpd-conf=${LOCALBASE}/${APACHEETCDIR}/extra
INSTALL_TARGET+=	install-webconf
PLIST_SUB+=		APACHE=""
.else
PLIST_SUB+=		APACHE="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's#/bin/ping#/sbin/ping#' ${WRKSRC}/sample-config/cgi.cfg.in
	@${REINPLACE_CMD} -e 's#Linux#FreeBSD#' ${WRKSRC}/sample-config/icinga.cfg.in
	@${REINPLACE_CMD} -e 's#775#755#g; s#664#644#g' ${WRKSRC}/html/Makefile.in
.if ${PORT_OPTIONS:MUNHANDLED_HACK}
	@${REINPLACE_CMD} -e 's#;serviceprops=42\&#;serviceprops=10\&#g' \
		-e 's#;hostprops=42\"#;hostprops=10\"#g' ${WRKSRC}/html/menu.html.in
.endif
	@${FIND} ${WRKSRC} -name '*.orig' -delete

pre-su-install:
	@${SH} ${PKGINSTALL} ${DISTNAME} PRE-INSTALL

post-install:
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}/idoutils/
	${MKDIR} ${EXAMPLESDIR}/idoutils/config/
	${MKDIR} ${EXAMPLESDIR}/idoutils/db
	cd ${WRKSRC}/module/idoutils/config && ${COPYTREE_SHARE} . ${EXAMPLESDIR}/idoutils/config
	cd ${WRKSRC}/module/idoutils/db     && ${COPYTREE_SHARE} . ${EXAMPLESDIR}/idoutils/db
.endif
	@${CHMOD} 775 ${ICINGADIR} ${ICINGALOGDIR}/archives ${ICINGADIR}/checkresults ${ICINGADIR}/rw
	@${CHMOD} g+s ${ICINGADIR}/rw
	@${CHOWN} ${ICINGAUSER}:${ICINGAGROUP} ${ICINGADIR} ${ICINGALOGDIR}/archives ${ICINGADIR}/checkresults
	@${CHOWN} ${ICINGAUSER}:${WWWGRP} ${ICINGADIR}/rw
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
