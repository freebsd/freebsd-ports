# Created by: Marcello Coutinho
# $FreeBSD$

PORTNAME=	e2guardian
PORTVERSION=	3.0.4
CATEGORIES=	www
MASTER_SITES=	GH

MAINTAINER=	marcellocoutinho@gmail.com
COMMENT=	Dansguardian fork with many improvements and bug fixes

LICENSE=	GPLv2

BUILD_DEPENDS=	rst2man:${PORTSDIR}/textproc/py-docutils
LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre

USE_GITHUB=	yes
GH_TAGNAME=	${PORTVERSION:S/^/v/}
USES=		pkgconfig iconv
HAS_CONFIGURE=	yes
USE_AUTOTOOLS=	aclocal libtoolize autoheader automake autoconf
ACLOCAL_ARGS=	-I m4
AUTOMAKE_ARGS=	--add-missing --copy --foreign
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
CLAMD_RUN_DEPENDS=		${LOCALBASE}/sbin/clamd:${PORTSDIR}/security/clamav
ICAP_CONFIGURE_ENABLE=		icap
KAV_CONFIGURE_ENABLE=		kavd
NTLM_CONFIGURE_ENABLE=		ntlm
NTLM_RUN_DEPENDS=		${LOCALBASE}/bin/iconv:${PORTSDIR}/converters/libiconv
NTLM_USES=			iconv
DNS_CONFIGURE_ENABLE=		dnsauth
EMAIL_CONFIGURE_ENABLE=		email
DEBUG_CONFIGURE_WITH=		dgdebug
1024_CONFIGURE_ON=		--with-filedescriptors=1024
2048_CONFIGURE_ON=		--with-filedescriptors=2048
4096_CONFIGURE_ON=		--with-filedescriptors=4096
8192_CONFIGURE_ON=		--with-filedescriptors=8192
SSL_LDFLAGS=			-lssl -lcrypto
SSL_CFLAGS=			-D__SSLMITM -D__SSLCERT

.include <bsd.port.pre.mk>

pre-configure:
	@${REINPLACE_CMD} -e 's|.lresolv||g' \
		${WRKSRC}/configure.ac

.if ${PORT_OPTIONS:MCLAMD} || ${PORT_OPTIONS:MICAP} || \
    ${PORT_OPTIONS:MKAV} || ${PORT_OPTIONS:MCLISCAN}
PLIST_SUB+=	SCANNERS=""
.else
PLIST_SUB+=	SCANNERS="@comment "
.endif

post-install:
	@${FIND} ${STAGEDIR}${ETCDIR} -type f \
		\( -name '*.conf' -or -name '*list' \) -exec ${MV} {} {}.sample \;
	@${MV} ${STAGEDIR}${ETCDIR}/lists/authplugins/ipgroups \
		${STAGEDIR}${ETCDIR}/lists/authplugins/ipgroups.sample
	@${MV} ${STAGEDIR}${ETCDIR}/lists/authplugins/portgroups \
		${STAGEDIR}${ETCDIR}/lists/authplugins/portgroups.sample
	@${MV} ${STAGEDIR}${ETCDIR}/lists/bannedrooms/default \
		${STAGEDIR}${ETCDIR}/lists/bannedrooms/default.sample

.include <bsd.port.post.mk>
