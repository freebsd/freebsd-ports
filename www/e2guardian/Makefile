# Created by: Marcello Coutinho
# $FreeBSD$

PORTNAME=	e2guardian
PORTVERSION=	5.2.2
DISTVERSIONPREFIX=	v
CATEGORIES=	www

MAINTAINER=	marcellocoutinho@gmail.com
COMMENT=	Dansguardian fork with many improvements and bug fixes

LICENSE=	GPLv2

BUILD_DEPENDS=	rst2man:textproc/py-docutils@${PY_FLAVOR}
LIB_DEPENDS=	libpcre.so:devel/pcre

USES=		autoreconf compiler:c++11-lang libtool pkgconfig python
USE_GITHUB=	yes

USE_RC_SUBR=	e2guardian
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var \
		--with-logdir=/var/log \
		--with-piddir=/var/run

OPTIONS_DEFINE=	CLISCAN CLAMD ICAP KAV AVAST NTLM DNS EMAIL DEBUG DOCS SSL
OPTIONS_DEFAULT=CLAMD DNS
OPTIONS_SUB=	yes

CLISCAN_DESC=	Enable support for CLI content scanners
CLAMD_DESC=	Enable ClamD AV content scanner
ICAP_DESC=	Enable ICAP AV content scanner support
KAV_DESC=	Enable Kaspersky AV support
AVAST_DESC=	Enable AvastD content scanner
NTLM_DESC=	Include NTLM authentication plugin
DNS_DESC=	Include DNS authetication plugin
EMAIL_DESC=	Enable e-mail reporting support
DEBUG_DESC=	Enable debug build mode

CONFDIR=	${PREFIX}/etc/e2guardian

CPPFLAGS+=	-I${LOCALBASE}/include
CFLAGS+=	-I${LOCALBASE}/include

CLISCAN_CONFIGURE_ENABLE=	commandline
CLAMD_CONFIGURE_ENABLE=		clamd=yes
CLAMD_RUN_DEPENDS=		${LOCALBASE}/sbin/clamd:security/clamav
ICAP_CONFIGURE_ENABLE=		icap
KAV_CONFIGURE_ENABLE=		kavd
AVAST_CONFIGURE_ENABLE=		avastd
NTLM_CONFIGURE_ENABLE=		ntlm
NTLM_RUN_DEPENDS=		${LOCALBASE}/bin/iconv:converters/libiconv
NTLM_USES=			iconv
DNS_CONFIGURE_ENABLE=		dnsauth
EMAIL_CONFIGURE_ENABLE=		email
DEBUG_CONFIGURE_ENABLE=		dgdebug
SSL_LDFLAGS=			-lssl -lcrypto
SSL_CFLAGS=			-D__SSLMITM -D__SSLCERT

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCLAMD} || ${PORT_OPTIONS:MICAP} || \
    ${PORT_OPTIONS:MKAV} || ${PORT_OPTIONS:MCLISCAN} || \
    ${PORT_OPTIONS:MAVAST}
PLIST_SUB+=	SCANNERS=""
.else
PLIST_SUB+=	SCANNERS="@comment "
.endif

SUB_FILES=	pkg-message pkg-install

pre-configure:
	@cd ${WRKSRC} && ${SH} ${WRKSRC}/autogen.sh

post-install:
	@${FIND} ${STAGEDIR}${ETCDIR} -type f \
		\( -name '*.conf' -or -name '*list' -or -name '*.story' \) \
		-exec ${MV} {} {}.sample \;
	@${MV} ${STAGEDIR}${ETCDIR}/lists/authplugins/ipgroups \
		${STAGEDIR}${ETCDIR}/lists/authplugins/ipgroups.sample
	@${MV} ${STAGEDIR}${ETCDIR}/lists/authplugins/portgroups \
		${STAGEDIR}${ETCDIR}/lists/authplugins/portgroups.sample
	@${MV} ${STAGEDIR}${ETCDIR}/lists/bannedrooms/default \
		${STAGEDIR}${ETCDIR}/lists/bannedrooms/default.sample
	@${MV} ${STAGEDIR}${ETCDIR}/lists/bannedsitelistwithbypass \
		${STAGEDIR}${ETCDIR}/lists/bannedsitelistwithbypass.sample
	@${MV} ${STAGEDIR}${ETCDIR}/lists/exceptionvirusextensionlist.sample \
		${STAGEDIR}${ETCDIR}/lists/contentscanners/
	@${MV} ${STAGEDIR}${ETCDIR}/lists/exceptionvirussiteiplist.sample \
		${STAGEDIR}${ETCDIR}/lists/contentscanners/
.include <bsd.port.mk>
