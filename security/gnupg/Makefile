# New ports collection makefile for:	gnupg
# Date created:		Sep 30, 1998
# Whom:			kuriyama@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	gnupg
PORTVERSION=	2.0.19
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNUPG}
MASTER_SITE_SUBDIR=	gnupg
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}.sig
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	The GNU Privacy Guard

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3=	${WRKSRC}/COPYING
LICENSE_FILE_LGPL3=	${WRKSRC}/COPYING.LIB

LIB_DEPENDS=	assuan:${PORTSDIR}/security/libassuan \
		gcrypt:${PORTSDIR}/security/libgcrypt \
		gpg-error:${PORTSDIR}/security/libgpg-error \
		ksba:${PORTSDIR}/security/libksba \
		pth:${PORTSDIR}/devel/pth

USE_BZIP2=	YES
USE_GMAKE=	YES
GNU_CONFIGURE=	YES
USE_ICONV=	YES
USE_LDCONFIG=	YES
CONFIGURE_ARGS+=	--enable-symcryptrun
.if defined(NOPORTDOCS)
CONFIGURE_ARGS+=	--disable-doc
.else
MAN1=		gpg2.1 gpgsm.1 gpgv2.1 gpg-agent.1 scdaemon.1 watchgnupg.1 \
		gpgconf.1 gpg-preset-passphrase.1 gpg-connect-agent.1 \
		gpgparsemail.1 symcryptrun.1 gpgsm-gencert.sh.1
MAN8=		addgnupghome.8 applygnupgdefaults.8
INFO=		gnupg
.endif

OPTIONS_DEFINE=		PINENTRY LDAP SCDAEMON CURL GPGSM KDNS STD_SOCKET NLS
PINENTRY_DESC=		Use pinentry
LDAP_DESC=		LDAP keyserver interface
SCDAEMON_DESC=		Enable Smartcard daemon (with libusb)
CURL_DESC=		Use the real curl library (worked around if no)
GPGSM_DESC=		Enable GPGSM (requires LDAP)
KDNS_DESC=		Use DNS CERT helper
STD_SOCKET_DESC=	Use standard socket for agent
OPTIONS_DEFAULT=	CURL
NO_OPTIONS_SORT=	YES

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPINENTRY}
RUN_DEPENDS+=	pinentry>0:${PORTSDIR}/security/pinentry
.endif

.if ${PORT_OPTIONS:MGPGSM}
RUN_DEPENDS+=	dirmngr:${PORTSDIR}/security/dirmngr
PORT_OPTIONS+=	LDAP
PLIST_SUB+=	GPGSM=""
.else
CONFIGURE_ARGS+=--disable-gpgsm
PLIST_SUB+=	GPGSM="@comment "
.endif

.if ${PORT_OPTIONS:MLDAP}
USE_OPENLDAP=	YES
CONFIGURE_ARGS+=--with-ldap=${LOCALBASE}
PLIST_SUB+=	LDAP=""
.else
CONFIGURE_ARGS+=--disable-ldap
PLIST_SUB+=	LDAP="@comment "
.endif

.if ${PORT_OPTIONS:MKDNS}
LIB_DEPENDS+=	adns:${PORTSDIR}/dns/adns
PLIST_SUB+=	ADNS=""
.else
CONFIGURE_SUB=	-e '/GPGKEYS_KDNS=/s/".*"/""/'
PLIST_SUB+=	ADNS="@comment "
.endif

.if ${PORT_OPTIONS:MSTD_SOCKET}
CONFIGURE_ARGS+=--enable-standard-socket
.endif

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	YES
CONFIGURE_ARGS+=--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MSCDAEMON}
CONFIGURE_ARGS+=--enable-scdaemon
. if ${OSVERSION} < 800069
LIB_DEPENDS+=	usb-0.1:${PORTSDIR}/devel/libusb
. endif
PLIST_SUB+=	SCDAEMON=""
.else
CONFIGURE_ARGS+=--disable-scdaemon
PLIST_SUB+=	SCDAEMON="@comment "
.endif

.if ${PORT_OPTIONS:MCURL}
CONFIGURE_ARGS+=--without-libcurl
.else
LIB_DEPENDS+=	curl:${PORTSDIR}/ftp/curl
CONFIGURE_ARGS+=--with-libcurl=${LOCALBASE}
.endif

verify:	checksum
	gpg2 --verify ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}.sig

post-patch:
	@${REINPLACE_CMD} -e "s@-lpthread@${PTHREAD_LIBS}@g" ${CONFIGURE_SUB} \
		${WRKSRC}/acinclude.m4 ${WRKSRC}/aclocal.m4 ${WRKSRC}/configure
	@${REINPLACE_CMD} -e "/#include <utmp.h>/d" \
		${WRKSRC}/tools/symcryptrun.c

post-install:
	PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.if defined(WITH_SUID_GPG)
	${CHMOD} u+s ${PREFIX}/bin/gpg2
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
