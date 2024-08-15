PORTNAME=	mpop
DISTVERSION=	1.4.20
CATEGORIES=	mail
MASTER_SITES=	https://marlam.de/mpop/releases/

MAINTAINER=	mew14930xvi@inbox.lv
COMMENT=	Small and fast POP3 client
WWW=		https://marlam.de/mpop/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe gmake makeinfo pkgconfig tar:xz
CPE_VENDOR=	martin_lambers
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tls=no
INFO=		mpop

OPTIONS_DEFINE=		GSASL IDN LIBSECRET MPOPD NLS
OPTIONS_DEFAULT=	GNUTLS IDN MPOPD
OPTIONS_RADIO=		TLS
OPTIONS_RADIO_TLS=	GNUTLS LIBTLS OPENSSL
OPTIONS_SUB=		yes

GSASL_DESC=		${SASL_DESC} via GNU SASL
LIBSECRET_DESC=		GNOME password management
LIBTLS_DESC=		SSL/TLS support via libtls
MPOPD_DESC=		Include minimal POP3 server

GNUTLS_LIB_DEPENDS=		libgnutls.so:security/gnutls
GNUTLS_CONFIGURE_ON=		--with-tls=gnutls
GSASL_LIB_DEPENDS=		libgsasl.so:security/libgsasl
GSASL_CONFIGURE_WITH=		libgsasl
IDN_LIB_DEPENDS=		libidn2.so:dns/libidn2
IDN_CONFIGURE_WITH=		libidn
LIBSECRET_LIB_DEPENDS=		libsecret-1.so:security/libsecret
LIBSECRET_CONFIGURE_WITH=	libsecret
LIBTLS_LIB_DEPENDS=		libtls.so:security/${"${SSL_DEFAULT:Mlibressl*}":?libressl:libretls}
LIBTLS_CONFIGURE_ON=		--with-tls=libtls
MPOPD_CONFIGURE_WITH=		mpopd
NLS_USES=			gettext
NLS_CONFIGURE_ENABLE=		nls
OPENSSL_USES=			ssl
OPENSSL_CONFIGURE_ON=		--with-tls=openssl
OPENSSL_CONFIGURE_ENV=		${OPENSSLINC:M/usr/include:C,.+,libssl_CFLAGS=" ",} \
				${OPENSSLLIB:M/usr/lib:C,.+,libssl_LIBS="-lssl -lcrypto",}

post-patch:
	@${REINPLACE_CMD} -E -e 's,/etc/ssl/certs,${LOCALBASE}/share/certs,' \
		-e '/crt/s/ca(\\?)-certificates/ca\1-root\1-nss/' \
		${WRKSRC}/doc/mpop*

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/mpoprc.example ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
