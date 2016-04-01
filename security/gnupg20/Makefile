# $FreeBSD$

PORTNAME=	gnupg
PORTVERSION=	2.0.29
#PORTREVISION=	0
CATEGORIES=	security
MASTER_SITES=	GNUPG
PKGNAMESUFFIX=	20
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}.sig
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	The GNU Privacy Guard

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3=	${WRKSRC}/COPYING
LICENSE_FILE_LGPL3=	${WRKSRC}/COPYING.LIB

LIB_DEPENDS=	libassuan.so:security/libassuan \
		libgcrypt.so:security/libgcrypt \
		libksba.so:security/libksba \
		libpth.so:devel/pth
BUILD_DEPENDS=	libgpg-error>=1.11:security/libgpg-error
RUN_DEPENDS=	pinentry>0:security/pinentry

GNU_CONFIGURE=	YES
USES=		cpe gmake iconv tar:bzip2
USE_LDCONFIG=	YES
CONFIGURE_ARGS+=	--enable-symcryptrun
CONFLICTS=	gnupg-2.1.*
CPE_VENDOR=	gnupg

OPTIONS_DEFINE=		LDAP SCDAEMON CURL GPGSM KDNS STD_SOCKET NLS DOCS SUID_GPG
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

DOCS_CONFIGURE_ENABLE=	doc
GPGSM_RUN_DEPENDS=	dirmngr:security/dirmngr
GPGSM_CONFIGURE_ENABLE=	gpgsm
KDNS_LIB_DEPENDS=	libadns.so:dns/adns
KDNS_CONFIGURE_ON=	--with-adns=${LOCALBASE}
STD_SOCKET_CONFIGURE_ENABLE=	standard-socket
NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls
SCDAEMON_CONFIGURE_ENABLE=	scdaemon
CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_CONFIGURE_ON=	--with-libcurl=${LOCALBASE}
CURL_CONFIGURE_OFF=	--without-libcurl

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
INFO=		gnupg
.endif

.if ${PORT_OPTIONS:MGPGSM}
PORT_OPTIONS+=	LDAP
.endif

.if ${PORT_OPTIONS:MLDAP}
USE_OPENLDAP=	YES
CONFIGURE_ARGS+=--with-ldap=${LOCALBASE}
.else
CONFIGURE_ARGS+=--disable-ldap
.endif

.if ! ${PORT_OPTIONS:MKDNS}
CONFIGURE_SUB=	-e '/GPGKEYS_KDNS=/s/".*"/""/'
.endif

verify:	checksum
	gpg2 --verify ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}.sig

post-patch:
	@${REINPLACE_CMD} -e "/#include <utmp.h>/d" \
		${WRKSRC}/tools/symcryptrun.c

.include <bsd.port.mk>
