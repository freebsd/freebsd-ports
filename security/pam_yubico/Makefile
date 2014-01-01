# $FreeBSD$

PORTNAME=	pam_yubico
PORTVERSION=	2.14
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://opensource.yubico.com/yubico-pam/releases/

MAINTAINER=	matt@mjslabs.com
COMMENT=	PAM module for authenticating with a Yubico YubiKey

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libykclient.so:${PORTSDIR}/security/ykclient \
		libyubikey.so:${PORTSDIR}/security/libyubikey

GNU_CONFIGURE=	yes
USES=		pkgconfig

PLIST_FILES=	lib/security/pam_yubico.la \
		lib/security/pam_yubico.so
PLIST_DIRS=	lib/security
SUB_FILES=	pkg-message
PORTDOCS=	*

OPTIONS_DEFINE=	CR LDAP DOCS STATIC
CR_DESC=	Include Challenge/response support
OPTIONS_DEFAULT=	CR

CR_CONFIGURE_WITH=	cr
CR_LIB_DEPENDS=	libykpers-1.so:${PORTSDIR}/security/ykpers
CR_PLIST_FILES=	bin/ykpamcfg \
		man/man1/ykpamcfg.1.gz

LDAP_CONFIGURE_WITH=	ldap
LDAP_USE=	OPENLDAP=yes
LDAP_LDFLAGS=	-L${LOCALBASE}/lib

STATIC_CONFIGURE_ENABLE=	static
STATIC_PLIST_FILES=	lib/security/pam_yubico.a

regression-test: build
	@(cd ${WRKSRC}; ${MAKE} check)

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
