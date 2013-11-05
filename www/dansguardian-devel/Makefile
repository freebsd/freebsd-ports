# Created by: Freddie Cash <fjwcash@gmail.com>
# $FreeBSD$

PORTNAME=	dansguardian
PORTVERSION=	2.12.0.3
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	SF/dansguardian
PKGNAMESUFFIX=	-devel

MAINTAINER=	garga@FreeBSD.org
COMMENT=	A fast, feature-rich web content filter for Squid proxy servers

LICENSE=	GPLv2

RUN_DEPENDS=	${LOCALBASE}/sbin/squid:${PORTSDIR}/www/squid
LIB_DEPENDS+=	libpcre.so:${PORTSDIR}/devel/pcre

USE_RC_SUBR=	dansguardian
USES=		iconv pkgconfig shebangfix
USE_BZIP2=	yes

CONFLICTS=	dansguardian-2.10.*

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var \
		--with-logdir=/var/log \
		--with-piddir=/var/run \
		${ICONV_CONFIGURE_BASE} \
		--enable-fancydm

PORTDOCS=	*

SHEBANG_FILES=	${WRKSRC}/data/dansguardian.pl

OPTIONS_DEFINE=	APACHE TRICKLE CLISCAN CLAMD ICAP KAV NTLM EMAIL DEBUG SSL DOCS
OPTIONS_DEFAULT=APACHE TRICKLE DOCS
OPTIONS_SUB=	yes

APACHE_DESC=	Enable Apache support for access denied page
TRICKLE_DESC=	Enable the trickle download manager
CLISCAN_DESC=	Enable support for CLI content scanners
CLAMD_DESC=	Enable ClamAV daemon support (clamd)
ICAP_DESC=	Enable ICAP AV content scanner support (testing)
KAV_DESC=	Enable Kaspersky AV support (testing)
EMAIL_DESC=	Enable e-mail reporting support

DG_URL=		http://dansguardian.org/index.php?page=copyright2
CONFDIR=	${PREFIX}/etc/dansguardian

RESTRICTED=	Redistribution and commercial download is restricted.  Check ${DG_URL} for more info

APACHE_USE=			APACHE_RUN=22+
TRICKLE_CONFIGURE_ENABLE=	trickledm
CLISCAN_CONFIGURE_ENABLE=	commandline
CLAMD_CONFIGURE_ENABLE=		clamd
CLAMD_RUN_DEPENDS=		${LOCALBASE}/sbin/clamd:${PORTSDIR}/security/clamav
ICAP_CONFIGURE_ENABLE=		icap
KAV_CONFIGURE_ENABLE=		kavd
NTLM_CONFIGURE_ENABLE=		ntlm
EMAIL_CONFIGURE_ENABLE=		email
DEBUG_CONFIGURE_ON=		--with-dgdebug
DEBUG_CONFIGURE_OFF=		--with-dgdebug=off
SSL_LDFLAGS=			-lssl -lcrypto
SSL_CFLAGS=			-D__SSLMITM -D__SSLCERT

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MCLAMD} || ${PORT_OPTIONS:MICAP} || \
    ${PORT_OPTIONS:MKAV} || ${PORT_OPTIONS:MCLISCAN}
PLIST_SUB+=		SCANNERS=""
.else
PLIST_SUB+=		SCANNERS="@comment "
.endif

post-patch:
.if empty(PORT_OPTIONS:MDOCS)
	@${REINPLACE_CMD} -e '/install-data-am/ s|install-dist_docDATA||' \
		${WRKSRC}/doc/Makefile.in
.endif
.if ${PORT_OPTIONS:MSSL}
	@${REINPLACE_CMD} -e 's|ifdef __SSLCERT|ifdef __SSLCERT_ERROR_AUTH|' \
		${WRKSRC}/src/Auth.cpp
.endif

.include <bsd.port.post.mk>
