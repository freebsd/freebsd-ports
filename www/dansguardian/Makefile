# Created by: Freddie Cash <fcash@sd73.bc.ca>
# $FreeBSD$

PORTNAME=	dansguardian
PORTVERSION=	2.10.1.1
PORTREVISION=	6
CATEGORIES=	www
MASTER_SITES=	# empty, see below

MAINTAINER=	garga@FreeBSD.org
COMMENT=	A fast, feature-rich web content filter for Squid proxy servers

LICENSE=	GPLv2

RUN_DEPENDS=	${LOCALBASE}/sbin/squid:${PORTSDIR}/www/squid
LIB_DEPENDS+=	libpcre.so:${PORTSDIR}/devel/pcre

USE_RC_SUBR=	dansguardian
USES=		pkgconfig iconv shebangfix

CONFLICTS=	dansguardian-devel-2.12.*

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var \
		--with-logdir=/var/log \
		--with-piddir=/var/run \
		${ICONV_CONFIGURE_BASE} \
		--enable-fancydm

PORTDOCS=	*

SHEBANG_FILES=	${WRKSRC}/data/dansguardian.pl

OPTIONS_DEFINE=	APACHE TRICKLE CLISCAN CLAMD ICAP KAV NTLM EMAIL DEBUG DOCS
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

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MCLAMD} || ${PORT_OPTIONS:MICAP} || \
    ${PORT_OPTIONS:MKAV} || ${PORT_OPTIONS:MCLISCAN}
PLIST_SUB+=		SCANNERS=""
.else
PLIST_SUB+=		SCANNERS="@comment "
.endif

# User needs to manually download the distfile
.if !(exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}))
IGNORE=	commercial source download is restricted.  Please visit and read ${DG_URL} and download ${DISTNAME}${EXTRACT_SUFX} into ${DISTDIR} before running make
.endif

post-patch:
.if empty(PORT_OPTIONS:MDOCS)
	@${REINPLACE_CMD} -e '/install-data-am/ s|install-dist_docDATA||' \
		${WRKSRC}/doc/Makefile.in
.endif

.include <bsd.port.post.mk>
