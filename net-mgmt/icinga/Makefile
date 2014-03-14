# Created by: Chin-San Huang <chinsan@FreeBSD.org>
# $FreeBSD$

PORTNAME=	icinga
PORTVERSION=	1.11.0
CATEGORIES=	net-mgmt
MASTER_SITES=	https://github.com/Icinga/${PORTNAME}-core/releases/download/v${PORTVERSION}/

MAINTAINER=	lme@FreeBSD.org
COMMENT=	Enterprise grade open source monitoring system based on Nagios

LICENSE=	GPLv2

LIB_DEPENDS=	libgd.so:${PORTSDIR}/graphics/gd
RUN_DEPENDS=	${LOCALBASE}/libexec/nagios/check_nagios:${PORTSDIR}/net-mgmt/nagios-plugins

USES=		iconv gmake
USE_AUTOTOOLS=	autoconf libltdl
USE_RC_SUBR=	icinga

GNU_CONFIGURE=	yes

ICINGAUSER?=	icinga
ICINGAGROUP?=	icinga
USERS=		${ICINGAUSER}
GROUPS=		${ICINGAGROUP}
ICINGADIR?=	/var/spool/icinga
ICINGALOGDIR?=	/var/log/icinga

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
		--with-httpd-conf=${EXAMPLESDIR}/apache22 \
		--enable-event-broker \
		--enable-nanosleep

CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib" \
		PERL=${PERL}

INSTALL_TARGET=	install install-config install-eventhandlers install-webconf

PLIST_SUB=	ICINGADIR=${ICINGADIR} \
		ICINGALOGDIR=${ICINGALOGDIR} \
		ICINGAWWWDIR=${ICINGAWWWDIR} \
		ICINGAUSER=${ICINGAUSER} \
		ICINGAGROUP=${ICINGAGROUP} \
		ICINGAHTMURL=${ICINGAHTMURL} \
		ICINGACGIURL=${ICINGACGIURL} \
		WWWGRP=${WWWGRP}

SUB_FILES=	pkg-message

# XXX: Don't remove PREFIX from SUB_LIST here.
SUB_LIST=	PREFIX=${PREFIX} \
		${PLIST_SUB}

OPTIONS_DEFINE=		IDOUTILS
OPTIONS_DEFAULT=	IDOUTILS

IDOUTILS_DESC=		Enable Icinga Data Objects support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIDOUTILS}
LIB_DEPENDS+=		libdbi.so:${PORTSDIR}/databases/libdbi-drivers
CONFIGURE_ARGS+=	--enable-idoutils \
			--enable-ssl \
			--with-dbi-lib=${LOCALBASE}/lib \
			--with-dbi-inc=${LOCALBASE}/include
INSTALL_TARGET+=	install-idoutils
USE_RC_SUBR+=		ido2db
PLIST_SUB+=		IDOUTILS=""
.else
PLIST_SUB+=		IDOUTILS="@comment "
CONFIGURE_ARGS+=	--disable-idoutils
.endif

post-patch:
	@${REINPLACE_CMD} -e 's#/bin/ping#/sbin/ping#' \
		${WRKSRC}/sample-config/cgi.cfg.in
	@${REINPLACE_CMD} -e 's#Linux#${OPSYS}#' \
		${WRKSRC}/sample-config/icinga.cfg.in
	@${REINPLACE_CMD} -e 's#775#755#g; s#664#644#g' \
		${WRKSRC}/html/Makefile.in
# Use correct make(1) syntax to unbreak parallel builds
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} \
		-E 's#cd (.+) && (make|\$$\(MAKE\))#$$(MAKE) -C \1#'

pre-install:
.if ${PORT_OPTIONS:MIDOUTILS}
	@${STRIP_CMD} ${WRKSRC}/module/idoutils/src/ido2db \
		${WRKSRC}/module/idoutils/src/log2ido \
		${WRKSRC}/module/idoutils/src/idomod.so
.endif

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${ICINGAWWWDIR}/ssi
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/idoutils/
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/idoutils/config/
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/idoutils/db
	cd ${WRKSRC}/module/idoutils/config && ${COPYTREE_SHARE} . \
		${STAGEDIR}${EXAMPLESDIR}/idoutils/config
	cd ${WRKSRC}/module/idoutils/db && ${COPYTREE_SHARE} . \
		${STAGEDIR}${EXAMPLESDIR}/idoutils/db

.include <bsd.port.mk>
