# $FreeBSD$

PORTNAME=	gnupg
PORTVERSION=	2.0.22
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
GNU_CONFIGURE=	YES
USES=		gmake iconv
USE_LDCONFIG=	YES
CONFIGURE_ARGS+=	--enable-symcryptrun

OPTIONS_DEFINE=		PINENTRY LDAP SCDAEMON CURL GPGSM KDNS STD_SOCKET NLS DOCS SUID_GPG
PINENTRY_DESC=		Use pinentry
LDAP_DESC=		LDAP keyserver interface
SCDAEMON_DESC=		Enable Smartcard daemon (with libusb)
CURL_DESC=		Use the real curl library (worked around if no)
GPGSM_DESC=		Enable GPGSM (requires LDAP)
KDNS_DESC=		Use DNS CERT helper
STD_SOCKET_DESC=	Use standard socket for agent
SUID_GPG_DESC=		Install GPG with suid
OPTIONS_DEFAULT=	CURL
NO_OPTIONS_SORT=	YES
OPTIONS_SUB=		YES

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MDOCS}
CONFIGURE_ARGS+=	--disable-doc
.else
INFO=		gnupg
.endif

.if ${PORT_OPTIONS:MPINENTRY}
RUN_DEPENDS+=	pinentry>0:${PORTSDIR}/security/pinentry
.endif

.if ${PORT_OPTIONS:MGPGSM}
RUN_DEPENDS+=	dirmngr:${PORTSDIR}/security/dirmngr
PORT_OPTIONS+=	LDAP
.else
CONFIGURE_ARGS+=--disable-gpgsm
.endif

.if ${PORT_OPTIONS:MLDAP}
USE_OPENLDAP=	YES
CONFIGURE_ARGS+=--with-ldap=${LOCALBASE}
.else
CONFIGURE_ARGS+=--disable-ldap
.endif

.if ${PORT_OPTIONS:MKDNS}
LIB_DEPENDS+=	libadns.so:${PORTSDIR}/dns/adns
CONFIGURE_ARGS+=	--with-adns=${LOCALBASE}
.else
CONFIGURE_SUB=	-e '/GPGKEYS_KDNS=/s/".*"/""/'
.endif

.if ${PORT_OPTIONS:MSTD_SOCKET}
CONFIGURE_ARGS+=--enable-standard-socket
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
CONFIGURE_ARGS+=--enable-nls
.else
CONFIGURE_ARGS+=--disable-nls
.endif

.if ${PORT_OPTIONS:MSCDAEMON}
CONFIGURE_ARGS+=--enable-scdaemon
.else
CONFIGURE_ARGS+=--disable-scdaemon
.endif

.if ${PORT_OPTIONS:MCURL}
LIB_DEPENDS+=	curl:${PORTSDIR}/ftp/curl
CONFIGURE_ARGS+=--with-libcurl=${LOCALBASE}
.else
CONFIGURE_ARGS+=--without-libcurl
.endif

verify:	checksum
	gpg2 --verify ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}.sig

post-patch:
	@${REINPLACE_CMD} -e "s@-lpthread@${PTHREAD_LIBS}@g" ${CONFIGURE_SUB} \
		${WRKSRC}/acinclude.m4 ${WRKSRC}/aclocal.m4 ${WRKSRC}/configure
	@${REINPLACE_CMD} -e "/#include <utmp.h>/d" \
		${WRKSRC}/tools/symcryptrun.c

.include <bsd.port.mk>
