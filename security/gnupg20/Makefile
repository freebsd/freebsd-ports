# $FreeBSD$

PORTNAME=	gnupg
PORTVERSION=	2.0.29
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	GNUPG
PKGNAMESUFFIX=	20

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	The GNU Privacy Guard (stable version)

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3=	${WRKSRC}/COPYING
LICENSE_FILE_LGPL3=	${WRKSRC}/COPYING.LIB

LIB_DEPENDS=	libassuan.so:security/libassuan \
		libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error \
		libksba.so:security/libksba \
		libpth.so:devel/pth
BUILD_DEPENDS=	libgpg-error>=1.11:security/libgpg-error
RUN_DEPENDS=	pinentry:security/pinentry

CONFLICTS=	gnupg-2.1.*
CPE_VENDOR=	gnupg

USES=		cpe gmake iconv readline tar:bzip2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-symcryptrun
INFO=		gnupg

OPTIONS_DEFINE=	LDAP SCDAEMON CURL GPGSM KDNS STD_SOCKET NLS DOCS SUID_GPG
OPTIONS_DEFAULT=CURL
NO_OPTIONS_SORT=yes
OPTIONS_SUB=	yes

GPGSM_DESC=	Enable GPGSM (requires LDAP)
LDAP_DESC=	LDAP keyserver interface
KDNS_DESC=	Use DNS CERT helper
SCDAEMON_DESC=	Enable Smartcard daemon (with libusb)
STD_SOCKET_DESC=Use standard socket for agent
SUID_GPG_DESC=	Install GPG setuid

CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_CONFIGURE_WITH=	libcurl=${LOCALBASE}

GPGSM_RUN_DEPENDS=	dirmngr:security/dirmngr
GPGSM_CONFIGURE_ENABLE=	gpgsm
GPGSM_IMPLIES=		LDAP

KDNS_LIB_DEPENDS=	libadns.so:dns/adns
KDNS_CONFIGURE_WITH=	adns=${LOCALBASE}

LDAP_USE=		OPENLDAP=yes
LDAP_CONFIGURE_WITH=	ldap=${LOCALBASE}

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

SCDAEMON_CONFIGURE_ENABLE=	scdaemon

STD_SOCKET_CONFIGURE_ENABLE=	standard-socket

post-patch:
	@${REINPLACE_CMD} -e "/#include <utmp.h>/d" \
		${WRKSRC}/tools/symcryptrun.c

post-install:
	@${MV} ${STAGEDIR}${DATADIR}/*.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
