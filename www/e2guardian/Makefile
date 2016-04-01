# Created by: Marcello Coutinho
# $FreeBSD$

PORTNAME=	e2guardian
PORTVERSION=	3.4.0.1
DISTVERSIONPREFIX=	v
PORTREVISION=	0
CATEGORIES=	www

MAINTAINER=	marcellocoutinho@gmail.com
COMMENT=	Dansguardian fork with many improvements and bug fixes

LICENSE=	GPLv2

BUILD_DEPENDS=	rst2man:textproc/py-docutils
LIB_DEPENDS=	libpcre.so:devel/pcre

USE_GITHUB=	yes
USES=		autoreconf libtool iconv pkgconfig
USE_RC_SUBR=	e2guardian
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var \
		--with-logdir=/var/log \
		--with-piddir=/var/run \
		--enable-fancydm

OPTIONS_DEFINE=	APACHE TRICKLE CLISCAN CLAMD ICAP KAV NTLM DNS EMAIL DEBUG SSL DOCS
OPTIONS_DEFAULT=TRICKLE DOCS 1024
OPTIONS_SUB=	yes

APACHE_DESC=	Enable Apache support for access denied page
TRICKLE_DESC=	Enable the trickle download manager
CLISCAN_DESC=	Enable support for CLI content scanners
CLAMD_DESC=	Enable ClamD AV content scanner
ICAP_DESC=	Enable ICAP AV content scanner support
KAV_DESC=	Enable Kaspersky AV support
NTLM_DESC=	Include NTLM authentication plugin
DNS_DESC=	Include DNS authetication plugin
EMAIL_DESC=	Enable e-mail reporting support

OPTIONS_RADIO=	DESCRIPTORS
OPTIONS_RADIO_DESCRIPTORS=	1024 2048 4096 8192

1024_DESC=	Enable default file descriptors
2048_DESC=	Enable 2048 file descriptors
4096_DESC=	Enable 4096 file descriptors
8192_DESC=	Enable 8192 file descriptors

CONFDIR=	${PREFIX}/etc/e2guardian

CPPFLAGS+=	-I${LOCALBASE}/include
CFLAGS+=	-I${LOCALBASE}/include

APACHE_USE=			APACHE_RUN=22+
TRICKLE_CONFIGURE_ENABLE=	trickledm
CLISCAN_CONFIGURE_ENABLE=	commandline
CLAMD_CONFIGURE_ENABLE=		clamd=yes
CLAMD_RUN_DEPENDS=		${LOCALBASE}/sbin/clamd:security/clamav
ICAP_CONFIGURE_ENABLE=		icap
KAV_CONFIGURE_ENABLE=		kavd
NTLM_CONFIGURE_ENABLE=		ntlm
NTLM_RUN_DEPENDS=		${LOCALBASE}/bin/iconv:converters/libiconv
NTLM_USES=			iconv
DNS_CONFIGURE_ENABLE=		dnsauth
EMAIL_CONFIGURE_ENABLE=		email
DEBUG_CONFIGURE_ON=		--with-dgdebug=on
1024_CONFIGURE_ON=		--with-filedescriptors=1024
2048_CONFIGURE_ON=		--with-filedescriptors=2048
4096_CONFIGURE_ON=		--with-filedescriptors=4096
8192_CONFIGURE_ON=		--with-filedescriptors=8192
SSL_LDFLAGS=			-lssl -lcrypto
SSL_CFLAGS=			-D__SSLMITM -D__SSLCERT

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCLAMD} || ${PORT_OPTIONS:MICAP} || \
    ${PORT_OPTIONS:MKAV} || ${PORT_OPTIONS:MCLISCAN}
PLIST_SUB+=	SCANNERS=""
.else
PLIST_SUB+=	SCANNERS="@comment "
.endif

post-extract:
.if ${PORT_OPTIONS:M2048} || ${PORT_OPTIONS:M4096} || ${PORT_OPTIONS:M8192}
	@${ECHO_MSG} ""
	@${ECHO_MSG} "######################################################"
	@${ECHO_MSG} "WARNING! Filedescriptors option higher then 1024."
	@${ECHO_MSG} "Check/raise FD_SETSIZE in /usr/include/sys/select.h"
	@${ECHO_MSG} "before preceeding with e2guardian compilation"
	@${ECHO_MSG} "######################################################"
	@${ECHO_MSG} ""
	@sleep 3
.endif

pre-configure:
	@cd ${WRKSRC} && ${SH} ${WRKSRC}/autogen.sh

post-install:
	@${FIND} ${STAGEDIR}${ETCDIR} -type f \
		\( -name '*.conf' -or -name '*list' \) -exec ${MV} {} {}.sample \;
	@${MV} ${STAGEDIR}${ETCDIR}/lists/authplugins/ipgroups \
		${STAGEDIR}${ETCDIR}/lists/authplugins/ipgroups.sample
	@${MV} ${STAGEDIR}${ETCDIR}/lists/authplugins/portgroups \
		${STAGEDIR}${ETCDIR}/lists/authplugins/portgroups.sample
	@${MV} ${STAGEDIR}${ETCDIR}/lists/bannedrooms/default \
		${STAGEDIR}${ETCDIR}/lists/bannedrooms/default.sample

.include <bsd.port.mk>
