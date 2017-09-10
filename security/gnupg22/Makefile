# $FreeBSD$

PORTNAME=	gnupg
PORTVERSION=	2.2.0
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	GNUPG
PKGNAMESUFFIX=	22

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	The GNU Privacy Guard (modern version)

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3=	${WRKSRC}/COPYING
LICENSE_FILE_LGPL3=	${WRKSRC}/COPYING.LGPL3

LIB_DEPENDS=	libassuan.so:security/libassuan \
		libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error \
		libksba.so:security/libksba \
		libnpth.so:devel/npth
BUILD_DEPENDS=	libassuan>=2.4.3:security/libassuan \
		libgpg-error>=1.16:security/libgpg-error
RUN_DEPENDS=	pinentry:security/pinentry

CONFLICTS=	gnupg-2.0.* gnupg-2.1.* dirmngr-[0-9]*
CPE_VENDOR=	gnupg

USES=		compiler:c11 cpe gmake iconv pkgconfig readline sqlite tar:bzip2
CONFIGURE_ARGS=	--disable-ntbtls --disable-wks-tools \
		--enable-gpg-is-gpg2 --enable-symcryptrun
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INFO=		gnupg
TEST_TARGET=	check

OPTIONS_DEFINE=	GNUTLS LDAP SCDAEMON NLS DOCS SUID_GPG
OPTIONS_DEFAULT=GNUTLS SCDAEMON
NO_OPTIONS_SORT=yes
OPTIONS_SUB=	yes

LDAP_DESC=	LDAP keyserver interface
SCDAEMON_DESC=	Enable Smartcard daemon (with libusb)
SUID_GPG_DESC=	Install GPG with suid
# In jail, SUID is required to avoid warning (security.bsd.unprivileged_mlock sysctl is not used in jail).

GNUTLS_CONFIGURE_ENABLE=gnutls
GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls

LDAP_CONFIGURE_WITH=	ldap=${LOCALBASE}
LDAP_LIBS=		-L${LOCALBASE}/lib
LDAP_USE=		OPENLDAP=yes
LDAP_USES=		readline

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext

SCDAEMON_CONFIGURE_ENABLE=	scdaemon

post-install:
	@${MV} ${STAGEDIR}${DATADIR}/help*.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
