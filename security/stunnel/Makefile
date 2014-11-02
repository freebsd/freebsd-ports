# Created by: Martti Kuparinen <martti.kuparinen@ericsson.com>
# $FreeBSD$

PORTNAME=	stunnel
PORTVERSION=	5.07
CATEGORIES=	security
MASTER_SITES=	https://www.stunnel.org/downloads/%SUBDIR%/ \
		http://mirrors.zerg.biz/stunnel/%SUBDIR%/ \
		http://mirrors.go-part.com/stunnel/%SUBDIR%/ \
		http://ftp.nluug.nl/pub/networking/stunnel/%SUBDIR%/ \
		ftp://ftp.nluug.nl/pub/networking/stunnel/%SUBDIR%/ \
		http://ftp.nluug.nl/pub/networking/stunnel/%SUBDIR%/ \
		ftp://ftp.surfnet.nl/pub/networking/stunnel/%SUBDIR%/ \
		http://ftp.surfnet.nl/pub/networking/stunnel/%SUBDIR%/ \
		ftp://stunnel.mirt.net/stunnel/%SUBDIR%/ \
		http://www.namesdir.com/mirrors/stunnel/%SUBDIR%/ \
		http://stunnel.cybermirror.org/%SUBDIR%/ \
		http://mirrors.zerg.biz/stunnel/%SUBDIR%/ \
		http://mirrors.rit.edu/zi/

MAINTAINER=	zi@FreeBSD.org
COMMENT=	SSL encryption wrapper for standard network daemons

# FIXME: IMHO, there really ought to be a GPL-2+ option or some such.
LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

USES=		shebangfix libtool
USE_RC_SUBR=	stunnel
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var/tmp --enable-static --disable-systemd
SHEBANG_FILES=	src/stunnel3.in

OPTIONS_DEFINE=			IPV6 LIBWRAP SSL_PORT FIPS DOCS EXAMPLES
OPTIONS_SINGLE=			THREAD
OPTIONS_SINGLE_THREAD=		FORK PTHREAD UCONTEXT
OPTIONS_DEFAULT=		PTHREAD

IPV6_CONFIGURE_ENABLE=		ipv6
LIBWRAP_CONFIGURE_ENABLE=	libwrap
SSL_PORT_CONFIGURE_ON=		--with-ssl="${OPENSSLBASE}"
SSL_PORT_CONFIGURE_OFF=		--with-ssl=/usr
SSL_PORT_USE=			OPENSSL=yes
FIPS_CONFIGURE_ENABLE=		fips

SSL_PORT_DESC=			Use OpenSSL from the ports collection
FORK_DESC=			Use the fork(3) threading model
PTHREAD_DESC=			Use the pthread(3) threading model
UCONTEXT_DESC=			Use the ucontext(3) threading model
FIPS_DESC=			Enable OpenSSL FIPS mode

.include <bsd.port.options.mk>

STUNNEL_USER?=	stunnel
STUNNEL_GROUP?=	stunnel

USERS=		${STUNNEL_USER}
GROUPS=		${STUNNEL_GROUP}

.if ${PORT_OPTIONS:MSSL_PORT}
WITH_OPENSSL_PORT=	yes
.endif

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MLIBWRAP}
LDFLAGS+=		-lwrap
.endif

.if ${PORT_OPTIONS:MUCONTEXT}
CONFIGURE_ARGS+=--with-threads=ucontext
CPPFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}
.elif ${PORT_OPTIONS:MFORK}
CONFIGURE_ARGS+=--with-threads=fork
.else
CONFIGURE_ARGS+=--with-threads=pthread
CPPFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}
.endif

post-patch:
# place files under /var/tmp so that this can be run by an unprivileged
# user stunnel and group stunnel
	@${REINPLACE_CMD} -E -e 's|\@prefix\@/var/lib/stunnel/|/var/tmp/stunnel|; \
		s|nobody|stunnel|;s|nogroup|stunnel|' \
		${WRKSRC}/tools/stunnel.conf-sample.in
	@${REINPLACE_CMD} -E -e 's|\$$\(prefix\)/var/run/stunnel/stunnel.pid|$$(localstatedir)/stunnel.pid|' \
		${WRKSRC}/src/Makefile.in
	@${FIND} ${WRKSRC} -type f -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -E -e 's,@(ACLOCAL|AUTO(MAKE|CONF|HEADER))@,/usr/bin/true,'
	@${REINPLACE_CMD} -E -e 's|install-confDATA install-data-local|install-confDATA|g' \
		${WRKSRC}/tools/Makefile.in
.if empty(PORT_OPTIONS:MDOCS)
	@${REINPLACE_CMD} -E -e 's/ install-docDATA/ /' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -E -e '/install-data-am/s,install-docDATA,,' ${WRKSRC}/doc/Makefile.in
.endif
.if empty(PORT_OPTIONS:MEXAMPLES)
	@${REINPLACE_CMD} -E -e 's/([^n])install-examplesDATA/\1/' \
		${WRKSRC}/tools/Makefile.in
.else
	@${REINPLACE_CMD} -E -e 's|\$$\(docdir\)/examples|${EXAMPLESDIR}|g' ${WRKSRC}/tools/Makefile.in
.endif

post-build:
	@${STRIP_CMD} ${WRKSRC}/src/.libs/libstunnel.so

cert:
	@${ECHO} ""
	@${ECHO} "**************************************************************************"
	@${ECHO} "The new certificate will be saved into ${ETCDIR}/stunnel.pem"
	@${ECHO} "**************************************************************************"
	@${ECHO} ""
	@(cd ${WRKSRC}/tools/; make install-data-local)

.include <bsd.port.post.mk>
