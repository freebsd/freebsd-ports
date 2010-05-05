# New ports collection makefile for:	syslog-ng
# Date created:		10 november 1006
# Whom:			Ivan Lago <ivan.lago@ifom-ieo-campus.it>
#
# $FreeBSD$
#

PORTNAME=	syslog-ng
PORTVERSION=	3.1.1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.balabit.com/downloads/files/syslog-ng/sources/$(PORTVERSION)/source/
PKGNAMESUFFIX=	3
DISTFILES=	$(PORTNAME)_$(PORTVERSION).tar.gz

MAINTAINER=	cy@FreeBSD.org
COMMENT=	A powerful syslogd replacement

OPTIONS=	SSL "Build with OpenSSL support (from ports)" off \
		TCP_WRAPPERS "Build with TCP Wrappers" off \
		SPOOF "Build with spoof source support" on \
		IPV6 "Build with IPV6 support" on \
		PCRE "Build with PCRE support" on \
		SQL "Build with database (libdbi) support" off

.include <bsd.port.options.mk>

BUILD_DEPENDS=	${LIBNET_CONFIG}:${PORTSDIR}/net/libnet
LIB_DEPENDS=	evtlog.0:${PORTSDIR}/sysutils/eventlog

MAN1=		pdbtool.1
MAN5=		syslog-ng.conf.5
MAN8=		syslog-ng.8

USE_RC_SUBR=	syslog-ng.sh
GNU_CONFIGURE=	yes
USE_GNOME=	glib20
SUB_FILES=	pkg-message

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet11-config

CONFIGURE_ARGS=	--sysconfdir=${LOCALBASE}/etc --localstatedir=/var/db \
		--enable-dynamic-linking --with-libnet=${LOCALBASE}/bin
CONFIGURE_ENV=	CFLAGS="`${LIBNET_CONFIG} --cflags` -I${LOCALBASE}include ${CFLAGS}" \
		LDFLAGS="`${LIBNET_CONFIG} --libs` ${LDFLAGS}"

.if defined(WITH_SSL)
USE_OPENSSL=		yes
WITH_OPENSSL_PORT=	yes
CONFIGURE_ARGS+=	--enable-ssl
CONFIGURE_ENV+=		OPENSSL_CFLAGS="${OPENSSL_CFLAGS}" \
			OPENSSL_LIBS="${OPENSSL_LDFLAGS} -lcrypto -lssl"
.else
CONFIGURE_args+=	--disable-ssl
.endif

.if defined(WITH_TCP_WRAPPERS)
CONFIGURE_ARGS+=	--enable-tcp-wrapper
.else
CONFIGURE_ARGS+=	--disable-tcp-wrapper
.endif

.if defined(WITH_SPOOF)
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
.else
CONFIGURE_ARGS+=	--disable-pcre
.endif

.if defined(WITH_SQL)
LIB_DEPENDS=		dbi.0:${PORTSDIR}/databases/libdbi
CONFIGURE_ENV+=		LIBDBI_LIBS="-ldbi"
CONFIGURE_ARGS+=	--enable-sql
.else
CONFIGURE_ARGS+=	--disable-sql
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's:__PREFIX__:${PREFIX}:g' ${WRKSRC}/src/syslog-ng.h
	@${REINPLACE_CMD} -e 's:libnet-config:libnet11-config:g' ${WRKSRC}/configure
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
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
