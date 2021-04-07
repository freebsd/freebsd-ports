PORTNAME=	pam_yubico
PORTVERSION=	2.26
CATEGORIES=	security
MASTER_SITES=	https://developers.yubico.com/yubico-pam/Releases/

MAINTAINER=	matt@mjslabs.com
COMMENT=	PAM module for authenticating with a Yubico YubiKey

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libykclient.so:security/ykclient \
		libyubikey.so:security/libyubikey

GNU_CONFIGURE=	yes
USES=		libtool localbase pkgconfig
TEST_TARGET=	check

PLIST_FILES=	lib/security/pam_yubico.so \
		man/man8/pam_yubico.8.gz
SUB_FILES=	pkg-message
PORTDOCS=	*

OPTIONS_DEFINE=	CR LDAP DOCS STATIC
CR_DESC=	Include Challenge/response support
OPTIONS_DEFAULT=	CR

CR_CONFIGURE_WITH=	cr
CR_LIB_DEPENDS=	libykpers-1.so:security/ykpers
CR_PLIST_FILES=	bin/ykpamcfg \
		man/man1/ykpamcfg.1.gz

LDAP_CONFIGURE_WITH=	ldap
LDAP_USE=	OPENLDAP=yes

STATIC_CONFIGURE_ENABLE=	static
STATIC_PLIST_FILES=	lib/security/pam_yubico.a

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
