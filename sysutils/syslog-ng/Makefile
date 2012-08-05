# New ports collection makefile for:	syslog-ng
# Date created:		10 November 2006
# Whom:			Ivan Lago <ivan.lago@ifom-ieo-campus.it>
#
# $FreeBSD$
#

PORTNAME=	syslog-ng
PORTVERSION=	3.3.5
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.balabit.com/downloads/files/syslog-ng/sources/$(PORTVERSION)/source/
DISTFILES=	$(PORTNAME)_$(PORTVERSION).tar.gz

MAINTAINER=	cy@FreeBSD.org
COMMENT=	A powerful syslogd replacement

CONFLICTS?=	syslog-ng-[0-9]* syslog-ng[0-9]-[0-9]* \
		syslog-ng-devel-[0-9]*
WRKSRC=		$(WRKDIR)/$(PORTNAME)-$(PORTVERSION)

OPTIONS=	SYS_SSL "Build with OpenSSL support (from system)" off \
		PORTS_SSL "Build with OpenSSL support (from ports)" on \
		TCP_WRAPPERS "Build with TCP Wrappers" off \
		SQL "Build with database (libdbi) support" off \
		SPOOF "Build with spoof source support" off \
		IPV6 "Build with IPV6 support" on \
		PCRE "Build with PCRE support" on \
		JSON_C "Build with JSON-C support" off \
		JSON_GLIB "Build with JSON-GLIB support" off \

.include <bsd.port.options.mk>

LIB_DEPENDS=	evtlog.0:${PORTSDIR}/sysutils/eventlog

MAN1=		loggen.1 pdbtool.1 syslog-ng-ctl.1
MAN5=		syslog-ng.conf.5
MAN8=		syslog-ng.8

USE_LDCONFIG=	yes
USE_RC_SUBR=	syslog-ng
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	glib20 gnomehack
SUB_FILES=	pkg-message

CONFIGURE_ARGS=	--sysconfdir=${LOCALBASE}/etc --localstatedir=/var/db \
		--enable-dynamic-linking

.if defined(WITH_SYS_SSL) && defined(WITH_PORTS_SSL)
BROKEN=		SYS_SSL and PORTS_SSL are mutually exclusive
.endif

.if defined(WITH_SYS_SSL) || defined(WITH_PORTS_SSL)
USE_OPENSSL=		yes
CONFIGURE_ARGS+=	--enable-ssl
CONFIGURE_ENV+=		OPENSSL_CFLAGS="${OPENSSL_CFLAGS}" \
			OPENSSL_LIBS="${OPENSSL_LDFLAGS} -lcrypto -lssl"
PLIST_FILES+=		lib/syslog-ng/libafsocket-tls.la lib/syslog-ng/libafsocket-tls.so
.else
CONFIGURE_ARGS+=	--disable-ssl
.endif

.if defined(WITH_PORTS_SSL)
WITH_OPENSSL_PORT=	yes
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_TCP_WRAPPERS)
CONFIGURE_ARGS+=	--enable-tcp-wrapper
.else
CONFIGURE_ARGS+=	--disable-tcp-wrapper
.endif

.if defined(WITH_SPOOF)
BUILD_DEPENDS=		${LIBNET_CONFIG}:${PORTSDIR}/net/libnet-devel
LIBNET_CONFIG?=		${LOCALBASE}/bin/libnet116-config
CONFIGURE_ARGS+=	--enable-spoof-source --with-libnet=${LOCALBASE}/bin
CFLAGS+=		`${LIBNET_CONFIG} --cflags` -I${LOCALBASE}/include
LDFLAGS+=		`${LIBNET_CONFIG} --libs`
.else
CONFIGURE_ARGS+=	--disable-spoof-source
.endif

.if defined(WITH_IPV6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if defined(WITH_PCRE)
CONFIGURE_ARGS+=	--enable-pcre
LIB_DEPENDS+=		pcre.1:${PORTSDIR}/devel/pcre
.else
CONFIGURE_ARGS+=	--disable-pcre
.endif

.if defined(WITH_SQL)
LIB_DEPENDS+=		dbi.1:${PORTSDIR}/databases/libdbi
CONFIGURE_ENV+=		LIBDBI_LIBS="-ldbi"
CONFIGURE_ARGS+=	--enable-sql
PLIST_FILES+=		lib/syslog-ng/libafsql.la lib/syslog-ng/libafsql.so
.else
CONFIGURE_ARGS+=	--disable-sql
.endif

.if defined(WITH_JSON_C) && defined(WITH_JSON_GLIB)
BROKEN=		JSON_C and JSON_GLIB are mutually exclusive
.endif

.if defined(WITH_JSON_GLIB)
LIB_DEPENDS+=		json-glib-1.0.0:${PORTSDIR}/devel/json-glib
CONFIGURE_ARGS+=	--enable-json --with-json=json-glib
PLIST_FILES+=		lib/syslog-ng/libtfjson.la lib/syslog-ng/libtfjson.so
.elif defined(WITH_JSON_C)
LIB_DEPENDS+=		json.0:${PORTSDIR}/devel/json-c
CONFIGURE_ARGS+=	--enable-json --with-json=json-c
PLIST_FILES+=		lib/syslog-ng/libtfjson.la lib/syslog-ng/libtfjson.so
.else
CONFIGURE_ARGS+=	--disable-json
.endif

.if ${OSVERSION} >= 900034
CONFIGURE_ARGS+=        --disable-linux-caps
.endif

post-patch:
	@${REINPLACE_CMD} -e 's:libnet-config:libnet116-config:g' ${WRKSRC}/configure
	@${LN} ${WRKSRC}/scl/syslog-ng.conf ${WRKSRC}/scl/syslog-ng.conf.dist
.if ${OSVERSION} >= 900007
	@${REINPLACE_CMD} \
		-e 's|utmp|utmpx|' -e 's|getutent|getutxent|' \
		-e 's|ut_name|ut_user|' \
		${WRKSRC}/configure ${WRKSRC}/modules/afuser/afuser.c \
		${WRKSRC}/lib/utils.c ${WRKSRC}/lib/utils.h
.endif


post-install:
.if !defined(NOPORTDOCS)
	${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} \
			${PREFIX}/share/doc/syslog-ng \
			${PREFIX}/share/doc/syslog-ng
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${PREFIX}/share/doc/syslog-ng
	${INSTALL_DATA} ${WRKSRC}/COPYING ${PREFIX}/share/doc/syslog-ng
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${PREFIX}/share/doc/syslog-ng
	${INSTALL_DATA} ${WRKSRC}/NEWS ${PREFIX}/share/doc/syslog-ng
.endif
	@if [ ! -f ${PREFIX}/etc/syslog-ng.conf.sample ]; then \
		${INSTALL_DATA} ${FILESDIR}/syslog-ng.conf.sample ${PREFIX}/etc; \
	fi
	@if [ ! -f ${PREFIX}/etc/syslog-ng.conf.dist ]; then \
		${INSTALL_DATA} ${WRKSRC}/scl/syslog-ng.conf.dist ${PREFIX}/etc; \
	fi
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
