# New ports collection makefile for:	snort
# Date created:		Mon Aug  2 12:04:08 CEST 1999
# Whom:			Dirk Froemberg <dirk@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	snort
PORTVERSION=	2.6.1.5
CATEGORIES=	security
MASTER_SITES=	http://www.snort.org/dl/current/

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Lightweight network intrusion detection system

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre

CONFLICTS?=	snort-1.* snort-2.0.* snort-2.1.* snort-2.2.* snort-2.3.* \
		snort-2.4.*

OPTIONS=	DYNAMIC "Enable dynamic plugin support" on \
		FLEXRESP "Flexible response to events" off \
		FLEXRESP2 "Flexible response to events (version 2)" off \
		MYSQL "Enable MySQL support" off \
		ODBC "Enable ODBC support" off \
		POSTGRESQL "Enable PostgreSQL support" off \
		PRELUDE "Enable Prelude NIDS integration" off

USE_RC_SUBR=	snort.sh
SUB_FILES=	pkg-message
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="${LDFLAGS}"
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

CONFIG_DIR?=	${PREFIX}/etc/snort
CONFIG_FILES=	classification.config gen-msg.map generators reference.config \
		sid sid-msg.map snort.conf threshold.conf unicode.map
RULES_DIR=	${PREFIX}/etc/snort/rules
LOGS_DIR=	${DESTDIR}/var/log/snort

MAN8=		snort.8
DOCS=		RELEASE.NOTES doc/AUTHORS doc/BUGS doc/CREDITS \
		doc/README* doc/USAGE doc/*.pdf

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500036
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-src-sf_snort_plugin_api.h
.endif

.if defined(WITH_FLEXRESP)
LIBNET_CONFIG?=		${LOCALBASE}/bin/libnet10-config
.elif defined(WITH_FLEXRESP2)
LIBNET_CONFIG?=		${LOCALBASE}/bin/libnet11-config
.endif

.if exists(${LIBNET_CONFIG})
LIBNET_CFLAGS!=	${LIBNET_CONFIG} --cflags
LIBNET_LIBS!=	${LIBNET_CONFIG} --libs
LIBNET_INCDIR=	${LIBNET_CFLAGS:M-I*:S/-I//}
LIBNET_LIBDIR=	${LIBNET_LIBS:M-L*:S/-L//}
.endif

.if !defined(WITHOUT_DYNAMIC)
USE_AUTOTOOLS=	libtool:15
USE_LDCONFIG=	yes
CONFIGURE_ARGS+=	--enable-dynamicplugin
PLIST_SUB+=	DYNAMIC=""
.else
PLIST_SUB+=	DYNAMIC="@comment "
.endif

.if defined(WITH_FLEXRESP)
.if defined(WITH_FLEXRESP2)
IGNORE=			options FLEXRESP and FLEXRESP2 are mutually exclusive
.endif
BUILD_DEPENDS+=		${LIBNET_CONFIG}:${PORTSDIR}/net/libnet10
CONFIGURE_ARGS+=	--enable-flexresp \
			--with-libnet-includes=${LIBNET_INCDIR} \
			--with-libnet-libraries=${LIBNET_LIBDIR}
.endif

.if defined(WITH_FLEXRESP2)
BROKEN=			FLEXRESP2 patch file does not incorporate cleanly
PATCH_SITES+=		http://cerberus.sourcefire.com/~jeff/archives/snort/sp_respond2/
PATCHFILES+=		sp_respond2.diff.gz
BUILD_DEPENDS+=		${LIBNET_CONFIG}:${PORTSDIR}/net/libnet \
			libdnet*>=1.10_1:${PORTSDIR}/net/libdnet
CONFIGURE_ARGS+=	--enable-flexresp2 \
			--with-libnet-includes=${LIBNET_INCDIR} \
			--with-libnet-libraries=${LIBNET_LIBDIR}
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=		yes
CONFIGURE_ARGS+=	--with-mysql=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--with-mysql=no
.endif

.if defined(WITH_ODBC)
LIB_DEPENDS+=		odbc.1:${PORTSDIR}/databases/unixODBC
CONFIGURE_ARGS+=	--with-odbc=${LOCALBASE}
LDFLAGS+=		${PTHREAD_LIBS}
.else
CONFIGURE_ARGS+=	--with-odbc=no
.endif

.if defined(WITH_POSTGRESQL)
USE_PGSQL=		yes
CONFIGURE_ARGS+=	--with-postgresql=${LOCALBASE}
.if exists(/usr/lib/libssl.a) && exists(/usr/lib/libcrypto.a)
LDFLAGS+=		-lssl -lcrypto
.endif
.else
CONFIGURE_ARGS+=	--with-postgresql=no
.endif

.if defined(WITH_PRELUDE)
LIB_DEPENDS+=		prelude.12:${PORTSDIR}/security/libprelude
CONFIGURE_ARGS+=	--enable-prelude
PLIST_SUB+=		PRELUDE=""
.else
CONFIGURE_ARGS+=	--disable-prelude
PLIST_SUB+=		PRELUDE="@comment "
.endif

post-patch:
	${FIND} ${WRKSRC} -name 'Makefile.in' | ${XARGS} ${REINPLACE_CMD} -e \
	    's|lib/snort_|lib/snort/|g'
	${REINPLACE_CMD} "s,/etc/snort.conf,${CONFIG_DIR}/snort.conf," \
		${WRKSRC}/src/snort.c ${WRKSRC}/snort.8
	${REINPLACE_CMD} -e 's|lib/snort_|lib/snort/|g' ${WRKSRC}/etc/snort.conf
.if defined(WITH_FLEXRESP) || defined(WITH_FLEXRESP2)
	${REINPLACE_CMD} -e 's|libnet-config|${LIBNET_CONFIG}|g' ${WRKSRC}/configure
.endif
.if defined(WITHOUT_DYNAMIC)
	${REINPLACE_CMD} -e "s,-am: install-libLTLIBRARIES,-am:," \
		${WRKSRC}/src/dynamic-plugins/sf_engine/Makefile.in
.endif

pre-configure:
.if defined(WITHOUT_DYNAMIC)
	@${CAT} ${PATCHDIR}/pkg-message-dynamicplugin
	@sleep 5
.endif

post-install:
.if !defined(WITHOUT_DYNAMIC)
	@${LIBTOOL} --finish ${LOCALBASE}/snort/dynamicpreprocessor
.endif
	[ -d ${CONFIG_DIR} ] || ${MKDIR} ${CONFIG_DIR}
	[ -d ${EXAMPLESDIR} ] || ${MKDIR} ${EXAMPLESDIR}
	[ -d ${RULES_DIR} ] || ${MKDIR} ${RULES_DIR}
	[ -d ${LOGS_DIR} ] || ${MKDIR} ${LOGS_DIR}
.for f in ${CONFIG_FILES}
	${INSTALL_DATA} ${WRKSRC}/etc/${f} ${CONFIG_DIR}/${f}-sample
	${INSTALL_DATA} ${WRKSRC}/etc/${f} ${EXAMPLESDIR}/${f}-sample
	@if [ ! -f ${CONFIG_DIR}/${f} ]; then \
		${CP} -p ${CONFIG_DIR}/${f}-sample ${CONFIG_DIR}/${f} ; \
	fi
.endfor
	${INSTALL_DATA} ${WRKSRC}/schemas/create* ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
