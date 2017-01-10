# $FreeBSD$

PORTNAME=	gnupg
PORTVERSION=	2.1.16
#PORTREVISION=	0
CATEGORIES=	security
MASTER_SITES=	GNUPG
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}.sig
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	The GNU Privacy Guard

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3=	${WRKSRC}/COPYING
LICENSE_FILE_LGPL3=	${WRKSRC}/COPYING.LIB

LIB_DEPENDS=	libassuan.so:security/libassuan \
		libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error \
		libksba.so:security/libksba \
		libnpth.so:devel/npth
BUILD_DEPENDS=	libassuan>=2.4.3:security/libassuan \
		libgpg-error>=1.16:security/libgpg-error
RUN_DEPENDS=	pinentry>0:security/pinentry

GNU_CONFIGURE=	YES
USES=		compiler:c11 cpe gmake iconv pkgconfig sqlite tar:bzip2
USE_LDCONFIG=	YES
# libreadline.so.8 is placed in /lib, but --with-readline argument
# will be treated as $value/lib, so try using /usr instead.
# Otherwise, $PREFIX/lib/libreadline.so.6 will be linked when
# devel/readline is installed.
CONFIGURE_ARGS+=	--disable-ntbtls --enable-symcryptrun --with-readline=/usr \
			--disable-wks-tools
CONFLICTS=	gnupg-2.0.* dirmngr-*
CPE_VENDOR=	gnupg

OPTIONS_DEFINE=		GNUTLS LDAP SCDAEMON KDNS NLS DOCS SUID_GPG
LDAP_DESC=		LDAP keyserver interface
SCDAEMON_DESC=		Enable Smartcard daemon (with libusb)
KDNS_DESC=		Use DNS CERT helper
SUID_GPG_DESC=		Install GPG with suid
OPTIONS_DEFAULT=	GNUTLS
NO_OPTIONS_SORT=	YES
OPTIONS_SUB=		YES
# In jail, SUID is required to avoid warning (security.bsd.unprivileged_mlock sysctl is not used in jail).

DOCS_CONFIGURE_ENABLE=	doc
DOCS_INFO=		gnupg
GNUTLS_CONFIGURE_ENABLE=gnutls
GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
KDNS_LIB_DEPENDS=	libadns.so:dns/adns
KDNS_CONFIGURE_ON=	--with-adns=${LOCALBASE}
LDAP_CONFIGURE_ENABLE=	ldap
LDAP_CONFIGURE_ON=	--with-ldap=${LOCALBASE}
LDAP_LIBS=		-L${LOCALBASE}/lib
LDAP_USE=		OPENLDAP=yes
NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls
SCDAEMON_CONFIGURE_ENABLE=	scdaemon

verify:	checksum
	gpg2 --verify ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}.sig

.include <bsd.port.mk>
