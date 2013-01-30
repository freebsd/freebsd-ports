# $FreeBSD$

PORTNAME=	pam_yubico
PORTVERSION=	2.12
CATEGORIES=	security
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	matt@mjslabs.com
COMMENT=	PAM module for authenticating with a Yubico YubiKey

LICENSE=	BSD

LIB_DEPENDS=	ykclient:${PORTSDIR}/security/ykclient \
		ykpers-1:${PORTSDIR}/security/ykpers \
		yubikey:${PORTSDIR}/security/libyubikey

GNU_CONFIGURE=	yes
USE_PKGCONFIG=	build

PLIST_FILES=	include/drop_privs.h \
		include/util.h \
		lib/security/pam_yubico.la \
		lib/security/pam_yubico.so
PLIST_DIRS=	lib/security
SUB_FILES=	pkg-message
PORTDOCS=	*

PROJECTHOST=	yubico-pam

OPTIONS_DEFINE=	CR LDAP DOCS
CR_DESC=	Include Challenge/response support
OPTIONS_DEFAULT=	CR LDAP

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCR}
CONFIGURE_ARGS+=	--with-cr
MAN1=		ykpamcfg.1
PLIST_FILES+=	bin/ykpamcfg
.else
CONFIGURE_ARGS+=	--without-cr
.endif

.if ${PORT_OPTIONS:MLDAP}
CONFIGURE_ARGS+=	--with-ldap
.else
CONFIGURE_ARGS+=	--without-ldap
.endif

regression-test: build
	@(cd ${WRKSRC}; ${MAKE} check)

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
