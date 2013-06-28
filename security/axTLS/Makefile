# Created by: Hirohisa Yamaguchi <umq@ueo.co.jp>
# $FreeBSD$

PORTNAME=	axTLS
PORTVERSION=	1.4.9
CATEGORIES=	security devel net
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME:L}/${PORTVERSION}

MAINTAINER=	umq@ueo.co.jp
COMMENT=	SSL/TLS client/server library implementation

LICENSE=	BSD

OPTIONS_DEFINE=	COMPAT_OPENSSL HTTPD TLSWRAP X509 PERL DOCS DEBUG TEST
OPTIONS_SINGLE=	MODE PROT
OPTIONS_SINGLE_MODE=	SERVER_ONLY CERT_VERIFICATION ENABLE_CLIENT \
			FULL_MODE SKELETON_MODE
OPTIONS_SINGLE_PROT=	LOW MEDIUM HIGH
OPTIONS_DEFAULT=	FULL_MODE MEDIUM
COMPAT_OPENSSL_DESC=	OpenSSL compatible API
TLSWRAP_DESC=		Build TLS wrapper like sslwrap
X509_DESC=		Generate X.509 Certificate
PERL_DESC=		Perl bindings or support
DOCS_DESC=		Build and/or install documentation (require doxygen)
TEST_DESC=		Build test suite when available
MODE_DESC=		SSL Library mode
PROT_DESC=		Protocol Preference
SERVER_ONLY_DESC=	Server only (no verification)
CERT_VERIFICATION_DESC=	Server only (with verification)
ENABLE_CLIENT_DESC=	Client/Server enabled
FULL_MODE_DESC=		Client/Server enabled with diagnostics
SKELETON_MODE_DESC=	The smallest library with least performance (experimental)
LOW_DESC=		Use the fastest cipher(s) but at the expense of security
MEDIUM_DESC=		Balance between speed and security
HIGH_DESC=		Use the strongest cipher(s) at the cost of speed

CONFIG_SUB=	PREFIX=\"${PREFIX}\" WWWDIR=\"${WWWDIR}\" \
		HTTP_PORT=${WITH_HTTP_PORT} SSL_PORT=${WITH_SSL_PORT}
NO_OPTIONS_SORT=yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
STAGE=		${WRKSRC}/_stage

WITH_HTTP_PORT?=	80
WITH_SSL_PORT?=		443

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSERVER_ONLY}
CONFIG_SUB+=	SERVER_ONLY=""
.else
CONFIG_SUB+=	SERVER_ONLY="\# "
.endif
.if ${PORT_OPTIONS:MCERT_VERIFICATION}
CONFIG_SUB+=	CERT_VERIFICATION=""
.else
CONFIG_SUB+=	CERT_VERIFICATION="\# "
.endif
.if ${PORT_OPTIONS:MENABLE_CLIENT}
CONFIG_SUB+=	ENABLE_CLIENT=""
.else
CONFIG_SUB+=	ENABLE_CLIENT="\# "
.endif
.if ${PORT_OPTIONS:MFULL_MODE}
CONFIG_SUB+=	FULL_MODE=""
.else
CONFIG_SUB+=	FULL_MODE="\# "
.endif
.if ${PORT_OPTIONS:MSKELETON_MODE}
CONFIG_SUB+=	SKELETON_MODE=""
.else
CONFIG_SUB+=	SKELETON_MODE="\# "
.endif

.if ${PORT_OPTIONS:MHIGH}
CONFIG_SUB+=	PROT_HIGH=""
.else
CONFIG_SUB+=	PROT_HIGH="\# "
.endif
.if ${PORT_OPTIONS:MMEDIUM}
CONFIG_SUB+=	PROT_MEDIUM=""
.else
CONFIG_SUB+=	PROT_MEDIUM="\# "
.endif
.if ${PORT_OPTIONS:MLOW}
CONFIG_SUB+=	PROT_LOW=""
.else
CONFIG_SUB+=	PROT_LOW="\# "
.endif

.if ${PORT_OPTIONS:MCOMPAT_OPENSSL}
CONFIG_SUB+=	COMPAT_OPENSSL=""
.else
CONFIG_SUB+=	COMPAT_OPENSSL="\# "
.endif

.if ${PORT_OPTIONS:MHTTPD}
CONFIG_SUB+=	HTTPD=""
PLIST_SUB+=	HTTPD=""
.else
CONFIG_SUB+=	HTTPD="\# "
PLIST_SUB+=	HTTPD="@comment "
.endif

.if ${PORT_OPTIONS:MTLSWRAP}
CONFIG_SUB+=	TLSWRAP=""
PLIST_SUB+=	TLSWRAP=""
.else
CONFIG_SUB+=	TLSWRAP="\# "
PLIST_SUB+=	TLSWRAP="@comment "
.endif

.if ${PORT_OPTIONS:MX509}
CONFIG_SUB+=	X509=""
.else
CONFIG_SUB+=	X509="\# "
.endif

.if ${PORT_OPTIONS:MPERL}
BUILD_DEPENDS+=	swig:${PORTSDIR}/devel/swig13
CONFIG_SUB+=	PERL=""
PLIST_SUB+=	PERL=""
USE_PERL5=	yes
.else
CONFIG_SUB+=	PERL="\# "
PLIST_SUB+=	PERL="@comment "
.endif

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen
PORTDOCS=	*
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIG_SUB+=	DEBUG=""
.else
CONFIG_SUB+=	DEBUG="\# "
.endif

.if ${PORT_OPTIONS:MTEST}
. if ${PORT_OPTIONS:MCERT_VERIFICATION} || \
	${PORT_OPTIONS:MENABLE_CLIENT} || \
	${PORT_OPTIONS:MFULL_MODE}
CONFIG_SUB+=	TEST_PERF=""
. else
CONFIG_SUB+=	TEST_PERF="\# "
. endif
. if ${PORT_OPTIONS:MFULL_MODE} && empty(PORT_OPTIONS:MX509)
CONFIG_SUB+=	TEST_SSL=""
. else
CONFIG_SUB+=	TEST_SSL="\# "
. endif
.else
CONFIG_SUB+=	TEST_PERF="\# " \
		TEST_SSL="\# "
.endif

_CONFIG_SUB_TEMP=	${CONFIG_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/}

do-configure:
	@${SED} ${_CONFIG_SUB_TEMP} \
	-e '/^\([^#]*\) is not set$$/s//\1=y/' \
	${FILESDIR}/data-.config.in > ${WRKSRC}/config/.config
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} \
	${MAKEFILE} ${_MAKE_JOBS} ${MAKE_ARGS} oldconfig

do-install:
	${INSTALL_LIB} ${STAGE}/libaxtls.a ${PREFIX}/lib/
	${INSTALL_LIB} ${STAGE}/libaxtls.so.1.2 ${PREFIX}/lib/
	${LN} -fs ${PREFIX}/lib/libaxtls.so.1.2 ${PREFIX}/lib/libaxtls.so.1
	${LN} -fs ${PREFIX}/lib/libaxtls.so.1 ${PREFIX}/lib/libaxtls.so
	${INSTALL_PROGRAM} ${STAGE}/axssl ${PREFIX}/bin/
.if ${PORT_OPTIONS:MHTTPD}
	${INSTALL_PROGRAM} ${STAGE}/htpasswd ${PREFIX}/bin/axhtpasswd
	${INSTALL_PROGRAM} ${STAGE}/axhttpd ${PREFIX}/bin/
.endif
.if ${PORT_OPTIONS:MTLSWRAP}
	${INSTALL_PROGRAM} ${STAGE}/axtlswrap ${PREFIX}/bin/
.endif
.if ${PORT_OPTIONS:MPERL}
	@${MKDIR} ${PREFIX}/${SITE_PERL_REL}/${PERL_ARCH}/auto
	${INSTALL_SCRIPT} ${STAGE}/axssl.pl ${PREFIX}/bin/
	${INSTALL_SCRIPT} ${STAGE}/axtlsp.pm ${PREFIX}/${SITE_PERL_REL}/${PERL_ARCH}/
	${INSTALL_LIB} ${STAGE}/libaxtlsp.so ${PREFIX}/${SITE_PERL_REL}/${PERL_ARCH}/auto/
.endif
	@${MKDIR} ${PREFIX}/include/axTLS
	${INSTALL_DATA} ${WRKSRC}/crypto/*.h ${PREFIX}/include/axTLS/
	${INSTALL_DATA} ${WRKSRC}/ssl/*.h ${PREFIX}/include/axTLS/
	${RM} ${PREFIX}/include/axTLS/cert.h
	${RM} ${PREFIX}/include/axTLS/private_key.h
	${RM} ${PREFIX}/include/axTLS/os_port.h
	${INSTALL_DATA} ${WRKSRC}/config/config.h ${PREFIX}/include/axTLS/
.if ${PORT_OPTIONS:MDOCS}
	cd ${WRKSRC} && ${GMAKE} docs
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/docsrc/html && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif

regression-test: build
	cd ${WRKSRC} && ${GMAKE} test

.include <bsd.port.mk>
