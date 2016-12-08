# Created by: Eric F Crist <ecrist@secure-computing.net>
# $FreeBSD$

PORTNAME=	openvpn
DISTVERSION=	201647
CATEGORIES=	security net
MASTER_SITES=	ftp://ftp.secure-computing.net/pub/FreeBSD/ports/openvpn-devel/ \
		ftp://ftp2.secure-computing.net/pub/FreeBSD/ports/openvpn-devel/
PKGNAMESUFFIX=	-devel

MAINTAINER=	ecrist@secure-computing.net
COMMENT=	Secure IP/Ethernet tunnel daemon

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}${PKGNAMESUFFIX}

CONFLICTS_INSTALL=	openvpn-[0-9]* openvpn-beta-[0-9]* openvpn-polarssl*
GNU_CONFIGURE=		yes
USES=			libtool pkgconfig shebangfix tar:xz
SHEBANG_FILES=		sample/sample-scripts/verify-cn \
			sample/sample-scripts/auth-pam.pl \
			sample/sample-scripts/ucn.pl

# let OpenVPN's configure script pick up the requisite libraries:
CPPFLAGS+=		-I${LOCALBASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib

OPTIONS_DEFINE=		PKCS11 EASYRSA LZO DOCS EXAMPLES
OPTIONS_DEFAULT=	EASYRSA OPENSSL LZO
OPTIONS_SINGLE=		SSL
OPTIONS_SINGLE_SSL=	OPENSSL EMBEDTLS
LZO_DESC=		Enable the LZO compression library
PKCS11_DESC=		Use security/pkcs11-helper
EASYRSA_DESC=		Install security/easy-rsa RSA helper package
EMBEDTLS_DESC=		SSL/TLS support via mbed TLS

EASYRSA_RUN_DEPENDS=	easy-rsa>=0:security/easy-rsa

PKCS11_LIB_DEPENDS=	libpkcs11-helper.so:security/pkcs11-helper
PKCS11_CONFIGURE_ENABLE=	pkcs11

EMBEDTLS_LIB_DEPENDS=	libmbedtls.so.10:security/mbedtls
EMBEDTLS_POLARSSL_CONFIGURE_ON=	--with-crypto-library=embedtls
EMBEDTLS_USE_OFF=	openssl=yes
EMBEDTLS_CONFIGURE_OFF+=--with-crypto-library=openssl

LZO_LIB_DEPENDS=	liblzo2.so:archivers/lzo2
LZO_CONFIGURE_ENABLE=	lzo

USE_RC_SUBR=	openvpn
USE_LDCONFIG=	${PREFIX}/lib

SUB_FILES=	pkg-message

.ifdef (LOG_OPENVPN)
CFLAGS+=	-DLOG_OPENVPN=${LOG_OPENVPN}
.endif

PORTDOCS=	*
PORTEXAMPLES=	*

pre-configure:
.ifdef (LOG_OPENVPN)
		@${ECHO} "Building with LOG_OPENVPN=${LOG_OPENVPN}"
.else
		@${ECHO} ""
		@${ECHO} "You may use the following build options:"
		@${ECHO} ""
		@${ECHO} "      LOG_OPENVPN={Valid syslog facility, default LOG_DAEMON}"
		@${ECHO} "      EXAMPLE:  make LOG_OPENVPN=LOG_LOCAL6"
		@${ECHO} ""
.endif

post-build:
		@# self-tests here
.if !defined(WITHOUT_CHECK)
		@${ECHO} ; ${ECHO} "### Note that you can skip these lengthy selftests with WITHOUT_CHECK=yes ###" ; ${ECHO}
		cd ${WRKSRC} && ${DO_MAKE_BUILD} check
.endif

post-install:
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/openvpn/plugins/openvpn-plugin-auth-pam.so
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/openvpn/plugins/openvpn-plugin-down-root.so
		${MKDIR} ${STAGEDIR}${PREFIX}/include

post-install-DOCS-on:
		${MKDIR} ${STAGEDIR}${DOCSDIR}/
.for i in AUTHORS ChangeLog PORTS
		${INSTALL_MAN} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}/
.endfor

post-install-EXAMPLES-on:
		(cd ${WRKSRC}/sample && ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR}/)
		${CHMOD} ${BINMODE} ${STAGEDIR}${EXAMPLESDIR}/sample-scripts/*

.include <bsd.port.mk>
