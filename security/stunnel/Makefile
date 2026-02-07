PORTNAME=	stunnel
DISTVERSION=	5.76
PORTEPOCH=	1
CATEGORIES=	security
MASTER_SITES=	https://www.stunnel.org/downloads/archive/5.x/ \
		https://ftp.nluug.nl/pub/networking/stunnel/archive/5.x/ \
		http://www.usenix.org.uk/mirrors/stunnel/archive/5.x/

MAINTAINER=	zi@FreeBSD.org
COMMENT=	SSL encryption wrapper for standard network daemons
WWW=		https://www.stunnel.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING.md

BROKEN_SSL=	libressl libressl-devel
BROKEN_SSL_REASON=	missing upstream support

USES=		cpe libtool perl5 shebangfix ssl
SHEBANG_FILES=	src/stunnel3.in
USE_PERL5=	build
USE_LDCONFIG=	yes

USE_RC_SUBR=	stunnel

GNU_CONFIGURE=	yes

STUNNEL_USER?=	stunnel
STUNNEL_GROUP?=	stunnel
STUNNEL_PIDFILE=/var/run/stunnel/stunnel.pid

USERS=		${STUNNEL_USER}
GROUPS=		${STUNNEL_GROUP}

SUB_FILES=	daemon.conf
SUB_LIST=	STUNNEL_PIDFILE=${STUNNEL_PIDFILE} \
		STUNNEL_USER=${STUNNEL_USER} \
		STUNNEL_GROUP=${STUNNEL_GROUP}

CONFIGURE_ARGS=	--localstatedir=/var/tmp \
		--enable-static \
		--disable-systemd \
		--with-ssl="${OPENSSLBASE}"

OPTIONS_DEFINE=		DOCS EXAMPLES FIPS IPV6 LIBWRAP
OPTIONS_SINGLE=		THREAD
OPTIONS_SINGLE_THREAD=	FORK PTHREAD UCONTEXT
OPTIONS_DEFAULT=	PTHREAD

FIPS_DESC=		Enable OpenSSL FIPS mode
FORK_DESC=		Use the fork(3) threading model
PTHREAD_DESC=		Use the pthread(3) threading model
UCONTEXT_DESC=		Use the ucontext(3) threading model

FIPS_CONFIGURE_ENABLE=	fips

FORK_CONFIGURE_ON=	--with-threads=fork

IPV6_CONFIGURE_ENABLE=	ipv6

PTHREAD_CONFIGURE_ON=	--with-threads=pthread

LIBWRAP_CONFIGURE_ENABLE=	libwrap

UCONTEXT_CONFIGURE_ON=	--with-threads=ucontext

post-patch:
	@${REINPLACE_CMD} -e '\
	    s|nobody|${STUNNEL_USER}|g; \
	    s|;include |include |g' \
	    ${PATCH_WRKSRC}/tools/stunnel.conf-sample.in
	@${REINPLACE_CMD} -e 's|@DEFAULT_GROUP@|${STUNNEL_GROUP}|g' \
	    ${PATCH_WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '\
	    s|@DEFAULT_GROUP@|${STUNNEL_GROUP}|g; \
	    s|install-confDATA install-data-local|install-confDATA|g; \
	    s|stunnel.logrotate||g; \
	    s|stunnel.rh.init||g' \
	    ${PATCH_WRKSRC}/tools/Makefile.in

post-patch-DOCS-off:
	@${REINPLACE_CMD} -e 's|install-data-am: install-docDATA|install-data-am:|g' \
	    ${PATCH_WRKSRC}/Makefile.in

post-patch-EXAMPLES-off:
	@${REINPLACE_CMD} -e 's|install-dist_bashcompDATA install-examplesDATA|install-dist_bashcompDATA|g' \
	    ${PATCH_WRKSRC}/tools/Makefile.in

post-patch-EXAMPLES-on:
	@${REINPLACE_CMD} -e 's|$$(docdir)/examples|${EXAMPLESDIR}|g' \
	    ${PATCH_WRKSRC}/tools/Makefile.in

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/stunnel/libstunnel.so
	${MKDIR} ${STAGEDIR}${ETCDIR}/conf.d/
	${INSTALL_DATA} ${WRKDIR}/daemon.conf ${STAGEDIR}${ETCDIR}/conf.d/00-daemon.conf

cert:
	@${ECHO} ""
	@${ECHO} "**************************************************************************"
	@${ECHO} "The new certificate will be saved into ${ETCDIR}/stunnel.pem"
	@${ECHO} "**************************************************************************"
	@${ECHO} ""
	@(cd ${WRKSRC}/tools/; make cert)

.include <bsd.port.mk>
