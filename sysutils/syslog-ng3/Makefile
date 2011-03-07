# New ports collection makefile for:	syslog-ng
# Date created:		10 november 1006
# Whom:			Ivan Lago <ivan.lago@ifom-ieo-campus.it>
#
# $FreeBSD$
#

PORTNAME=	syslog-ng
PORTVERSION=	3.2.2
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.balabit.com/downloads/files/syslog-ng/sources/$(PORTVERSION)/source/
PKGNAMESUFFIX=	3
DISTFILES=	$(PORTNAME)_$(PORTVERSION).tar.gz

MAINTAINER=	cy@FreeBSD.org
COMMENT=	A powerful syslogd replacement

CONFLICTS?=	syslog-ng-[0-9]* syslog-ng[0124-9]-[0-9]* \
		syslog-ng[0-9]-devel-[0-9]*

OPTIONS=	SYS_SSL "Build with OpenSSL support (from system)" off \
		PORTS_SSL "Build with OpenSSL support (from ports)" off \
		TCP_WRAPPERS "Build with TCP Wrappers" off \
		SQL "Build with database (libdbi) support" off \
		SPOOF "Build with spoof source support" off \
		IPV6 "Build with IPV6 support" on \
		PCRE "Build with PCRE support" on

.include <bsd.port.options.mk>

LIB_DEPENDS=	evtlog.0:${PORTSDIR}/sysutils/eventlog

MAN1=		loggen.1 pdbtool.1 syslog-ng-ctl.1
MAN5=		syslog-ng.conf.5
MAN8=		syslog-ng.8

USE_RC_SUBR=	syslog-ng.sh
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	glib20
SUB_FILES=	pkg-message

CONFIGURE_ARGS=	--sysconfdir=${LOCALBASE}/etc --localstatedir=/var/db \
		--enable-dynamic-linking --with-libnet=${LOCALBASE}/bin
CONFIGURE_ENV=	CFLAGS="`${LIBNET_CONFIG} --cflags` -I${LOCALBASE}/include ${CFLAGS}" \
		LDFLAGS="`${LIBNET_CONFIG} --libs` ${LDFLAGS}"

.if defined(WITH_SYS_SSL) && defined(WITH_PORTS_SSL)
BROKEN=		SYS_SSL and PORTS_SSL are mutually exclusive
.endif

.if defined(WITH_SYS_SSL) || defined(WITH_PORTS_SSL)
USE_OPENSSL=            yes
CONFIGURE_ARGS+=        --enable-ssl
CONFIGURE_ENV+=         OPENSSL_CFLAGS="${OPENSSL_CFLAGS}" \
                        OPENSSL_LIBS="${OPENSSL_LDFLAGS} -lcrypto -lssl"
PLIST_FILES=		lib/syslog-ng//libafsocket-tls.la lib/syslog-ng//libafsocket-tls.so
.else
CONFIGURE_args+=        --disable-ssl
.endif

.if defined(WITH_PORTS_SSL)
WITH_OPENSSL_PORT=      yes
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_TCP_WRAPPERS)
CONFIGURE_ARGS+=	--enable-tcp-wrapper
.else
CONFIGURE_ARGS+=	--disable-tcp-wrapper
.endif

.if defined(WITH_SPOOF)
BUILD_DEPENDS=		${LIBNET_CONFIG}:${PORTSDIR}/net/libnet-devel
LIBNET_CONFIG?=		${LOCALBASE}/bin/libnet115-config
CONFIGURE_ARGS+=	--enable-spoof-source
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
LIB_DEPENDS+=		pcre.0:${PORTSDIR}/devel/pcre
.else
CONFIGURE_ARGS+=	--disable-pcre
.endif

.if defined(WITH_SQL)
LIB_DEPENDS+=		dbi.1:${PORTSDIR}/databases/libdbi
CONFIGURE_ENV+=		LIBDBI_LIBS="-ldbi"
CONFIGURE_ARGS+=	--enable-sql
PLIST_FILES=		lib/syslog-ng/libafsql.la lib/syslog-ng/libafsql.so
.else
CONFIGURE_ARGS+=	--disable-sql
.endif

post-patch:
	@${REINPLACE_CMD} -e 's:libnet-config:libnet115-config:g' ${WRKSRC}/configure
	@${MV} ${WRKSRC}/scl/syslog-ng.conf ${WRKSRC}/scl/syslog-ng.conf.dist
.if ${OSVERSION} >= 900007
	@${REINPLACE_CMD} \
		-e 's|utmp|utmpx|' -e 's|getutent|getutxent|' \
		-e 's|ut_name|ut_user|' \
		${WRKSRC}/configure ${WRKSRC}/src/afuser.c \
		${WRKSRC}/src/utils.c ${WRKSRC}/src/utils.h
.endif

post-install:
.if !defined(NOPORTDOCS)
	${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} \
			${PREFIX}/share/doc/syslog-ng \
			${PREFIX}/share/doc/syslog-ng/sgml
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${PREFIX}/share/doc/syslog-ng
	${INSTALL_DATA} ${WRKSRC}/COPYING ${PREFIX}/share/doc/syslog-ng
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${PREFIX}/share/doc/syslog-ng
	${INSTALL_DATA} ${WRKSRC}/NEWS ${PREFIX}/share/doc/syslog-ng
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/syslog-ng
.endif
	@if [ ! -f ${PREFIX}/etc/syslog-ng.conf.sample ]; then \
		${INSTALL_DATA} ${FILESDIR}/syslog-ng.conf.sample ${PREFIX}/etc; \
	fi
	@if [ ! -f ${PREFIX}/etc/syslog-ng.conf ]; then \
		${CP} ${PREFIX}/etc/syslog-ng.conf.sample ${PREFIX}/etc/syslog-ng.conf; \
	fi
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
