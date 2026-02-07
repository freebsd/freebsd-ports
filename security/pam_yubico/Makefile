PORTNAME=	pam_yubico
PORTVERSION=	2.27
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	https://developers.yubico.com/yubico-pam/Releases/

MAINTAINER=	matt@mjslabs.com
COMMENT=	PAM module for authenticating with a Yubico YubiKey
WWW=		https://developers.yubico.com/yubico-pam/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libykclient.so:security/ykclient \
		libyubikey.so:security/libyubikey

USES=		libtool localbase pkgconfig

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
TEST_TARGET=	check

SUB_FILES=	pkg-message
PLIST_FILES=	lib/security/pam_yubico.so \
		share/man/man8/pam_yubico.8.gz
PORTDOCS=	*

OPTIONS_DEFINE=	CR LDAP DOCS STATIC
OPTIONS_DEFAULT=	CR

CR_DESC=	Include Challenge/response support

CR_LIB_DEPENDS=	libykpers-1.so:security/ykpers
CR_CONFIGURE_WITH=	cr
CR_PLIST_FILES=	bin/ykpamcfg \
		share/man/man1/ykpamcfg.1.gz

LDAP_USES=	ldap
LDAP_CONFIGURE_WITH=	ldap

STATIC_CONFIGURE_ENABLE=	static
STATIC_PLIST_FILES=	lib/security/pam_yubico.a

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
