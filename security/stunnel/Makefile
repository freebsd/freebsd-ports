PORTNAME=	stunnel
DISTVERSION=	5.75
PORTEPOCH=	1
CATEGORIES=	security
MASTER_SITES=	https://www.stunnel.org/downloads/archive/5.x/ \
		https://ftp.nluug.nl/pub/networking/stunnel/archive/5.x/ \
		http://www.usenix.org.uk/mirrors/stunnel/archive/5.x/

MAINTAINER=	zi@FreeBSD.org
COMMENT=	SSL encryption wrapper for standard network daemons
WWW=		https://www.stunnel.org/

LICENSE=	GPLv2+

BROKEN_SSL=	libressl libressl-devel
BROKEN_SSL_REASON=	missing upstream support

USES=		cpe libtool perl5 shebangfix ssl
USE_PERL5=	build
USE_LDCONFIG=	yes
USE_RC_SUBR=	stunnel

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--localstatedir=/var/tmp --enable-static --disable-systemd \
		--with-ssl="${OPENSSLBASE}"
SHEBANG_FILES=	src/stunnel3.in
SUB_FILES=	daemon.conf
SUB_LIST=	STUNNEL_PIDFILE=${STUNNEL_PIDFILE} \
		STUNNEL_USER=${STUNNEL_USER} \
		STUNNEL_GROUP=${STUNNEL_GROUP}

OPTIONS_DEFINE=			DOCS EXAMPLES FIPS IPV6 LIBWRAP
OPTIONS_SINGLE=			THREAD
OPTIONS_SINGLE_THREAD=		FORK PTHREAD UCONTEXT
OPTIONS_DEFAULT=		PTHREAD

FIPS_CONFIGURE_ENABLE=		fips
IPV6_CONFIGURE_ENABLE=		ipv6
LIBWRAP_CONFIGURE_ENABLE=	libwrap

FIPS_DESC=			Enable OpenSSL FIPS mode
FORK_DESC=			Use the fork(3) threading model
PTHREAD_DESC=			Use the pthread(3) threading model
UCONTEXT_DESC=			Use the ucontext(3) threading model

STUNNEL_PIDFILE=/var/run/stunnel/stunnel.pid
STUNNEL_USER?=	stunnel
STUNNEL_GROUP?=	stunnel

USERS=		${STUNNEL_USER}
GROUPS=		${STUNNEL_GROUP}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLIBWRAP}
LDFLAGS+=		-lwrap
.endif

.if ${PORT_OPTIONS:MUCONTEXT}
CONFIGURE_ARGS+=--with-threads=ucontext
LDFLAGS+=	-lpthread
.elif ${PORT_OPTIONS:MFORK}
CONFIGURE_ARGS+=--with-threads=fork
.else
CONFIGURE_ARGS+=--with-threads=pthread
LDFLAGS+=	-lpthread
.endif

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MFIPS} && ${SSL_DEFAULT:Mlibressl*}
IGNORE=		LibreSSL does not support FIPS standard
.endif

.if ${SSL_DEFAULT:Mlibressl*}
NO_PACKAGE=	The stunnel license restricts distribution when linked to non-OpenSSL non-base SSL-libraries
.endif

post-patch:
# place files under /var/tmp so that this can be run by an unprivileged
# user stunnel and group stunnel
	@${REINPLACE_CMD} -E -e 's|\@prefix\@/var/lib/stunnel/|/var/tmp/stunnel|; \
		s|nobody|stunnel|;s|nogroup|stunnel|;s|;include |include |' \
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

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}/conf.d/
	${INSTALL_DATA} ${WRKDIR}/daemon.conf ${STAGEDIR}${ETCDIR}/conf.d/00-daemon.conf

cert:
	@${ECHO} ""
	@${ECHO} "**************************************************************************"
	@${ECHO} "The new certificate will be saved into ${ETCDIR}/stunnel.pem"
	@${ECHO} "**************************************************************************"
	@${ECHO} ""
	@(cd ${WRKSRC}/tools/; make cert)

.include <bsd.port.post.mk>
