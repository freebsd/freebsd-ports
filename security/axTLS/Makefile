# Created by: Hirohisa Yamaguchi <umq@ueo.co.jp>
# $FreeBSD$

PORTNAME=	axTLS
PORTVERSION=	1.4.9
PORTREVISION=	2
CATEGORIES=	security devel net
MASTER_SITES=	SF/${PORTNAME:tl}/${PORTVERSION}

MAINTAINER=	umq@ueo.co.jp
COMMENT=	SSL/TLS client/server library implementation

LICENSE=	BSD3CLAUSE

OPTIONS_DEFINE=	COMPAT_OPENSSL HTTPD TLSWRAP X509 PERL DOCS DEBUG TEST
OPTIONS_SINGLE=	MODE PROT
OPTIONS_SINGLE_MODE=	SERVER_ONLY CERT_VERIFICATION ENABLE_CLIENT \
			FULL_MODE SKELETON_MODE
OPTIONS_SINGLE_PROT=	PROT_LOW PROT_MEDIUM PROT_HIGH
OPTIONS_DEFAULT=	FULL_MODE PROT_MEDIUM
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
PROT_LOW_DESC=		Use the fastest cipher(s) but at the expense of security
PROT_MEDIUM_DESC=		Balance between speed and security
PROT_HIGH_DESC=		Use the strongest cipher(s) at the cost of speed

CONFIG_SUB=	PREFIX=\"${PREFIX}\" WWWDIR=\"${WWWDIR}\" \
		HTTP_PORT=${WITH_HTTP_PORT} SSL_PORT=${WITH_SSL_PORT}
NO_OPTIONS_SORT=yes
USES=		gmake
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
STAGE=		${WRKSRC}/_stage

WITH_HTTP_PORT?=	80
WITH_SSL_PORT?=		443

PERL_BUILD_DEPENDS=	swig3.0:devel/swig30
PERL_BINARY_ALIAS=	swig=swig3.0
PERL_USES=	perl5
DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen

OPTIONS_SUB=	yes
PORTDOCS=	*

.include <bsd.port.options.mk>

.for i in SERVER_ONLY CERT_VERIFICATION ENABLE_CLIENT FULL_MODE \
	SKELETON_MODE PROT_HIGH PROT_MEDIUM PROT_LOW COMPAT_OPENSSL \
	HTTPD TLSWRAP X509 PERL DEBUG
.  if ${PORT_OPTIONS:M${i}}
CONFIG_SUB+=	${i}=""
.  else
CONFIG_SUB+=	${i}="\# "
.  endif
.endfor

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

post-patch:
	${REINPLACE_CMD} -e '/^CC/s|gcc|${CC}|; /^HOSTCC/s|gcc|${CC}|' \
		${WRKSRC}/config/Rules.mak

do-configure:
	@${SED} ${_CONFIG_SUB_TEMP} \
	-e '/^\([^#]*\) is not set$$/s//\1=y/' \
	${FILESDIR}/data-.config.in > ${WRKSRC}/config/.config
	${DO_MAKE_BUILD} -C ${WRKSRC} oldconfig

post-build:
.if ${PORT_OPTIONS:MDOCS}
	${DO_MAKE_BUILD} -C ${WRKSRC} docs
.endif

do-install:
	${INSTALL_DATA} ${STAGE}/libaxtls.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${STAGE}/libaxtls.so.1.2 ${STAGEDIR}${PREFIX}/lib
	${LN} -s libaxtls.so.1.2 ${STAGEDIR}${PREFIX}/lib/libaxtls.so.1
	${LN} -fs libaxtls.so.1 ${STAGEDIR}${PREFIX}/lib/libaxtls.so
	${INSTALL_PROGRAM} ${STAGE}/axssl ${STAGEDIR}${PREFIX}/bin
.if ${PORT_OPTIONS:MHTTPD}
	${INSTALL_PROGRAM} ${STAGE}/htpasswd ${STAGEDIR}${PREFIX}/bin/axhtpasswd
	${INSTALL_PROGRAM} ${STAGE}/axhttpd ${STAGEDIR}${PREFIX}/bin
.endif
.if ${PORT_OPTIONS:MTLSWRAP}
	${INSTALL_PROGRAM} ${STAGE}/axtlswrap ${STAGEDIR}${PREFIX}/bin
.endif
.if ${PORT_OPTIONS:MPERL}
	@${MKDIR} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto
	${INSTALL_SCRIPT} ${STAGE}/axssl.pl ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${STAGE}/axtlsp.pm ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}
	${INSTALL_LIB} ${STAGE}/libaxtlsp.so ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto
.endif
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/axTLS
	${INSTALL_DATA} ${WRKSRC}/crypto/*.h ${STAGEDIR}${PREFIX}/include/axTLS
	${INSTALL_DATA} ${WRKSRC}/ssl/*.h ${STAGEDIR}${PREFIX}/include/axTLS
	${RM} ${STAGEDIR}${PREFIX}/include/axTLS/cert.h
	${RM} ${STAGEDIR}${PREFIX}/include/axTLS/private_key.h
	${RM} ${STAGEDIR}${PREFIX}/include/axTLS/os_port.h
	${INSTALL_DATA} ${WRKSRC}/config/config.h ${STAGEDIR}${PREFIX}/include/axTLS
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docsrc/html && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}
.endif

regression-test: build
	${DO_MAKE_BUILD} -C ${WRKSRC} test
	cd ${WRKSRC} && ${MAKE_CMD} test

.include <bsd.port.mk>
