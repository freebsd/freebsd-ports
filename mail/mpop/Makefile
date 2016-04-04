# Created by: Sylvio Cesar <sylvio@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mpop
DISTVERSION=	1.2.4
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTVERSION}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Small and fast POP3 client

LICENSE=	GPLv3+

USES=		cpe gmake makeinfo pkgconfig tar:xz
CPE_VENDOR=	martin_lambers
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-silent-rules --with-tls=no

INFO=		mpop

OPTIONS_DEFINE=		GSASL IDN LIBSECRET NLS
OPTIONS_RADIO=		TLS
OPTIONS_RADIO_TLS=	GNUTLS OPENSSL
OPTIONS_DEFAULT=	IDN OPENSSL
OPTIONS_SUB=		yes

GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_CONFIGURE_ON=	--with-tls=gnutls
GSASL_DESC=		${SASL_DESC} via GNU SASL
GSASL_LIB_DEPENDS=	libgsasl.so:security/gsasl
GSASL_CONFIGURE_WITH=	libgsasl
IDN_LIB_DEPENDS=	libidn.so:dns/libidn
IDN_CONFIGURE_WITH=	libidn
LIBSECRET_DESC=		GNOME password management
LIBSECRET_LIB_DEPENDS=	libsecret-1.so:security/libsecret
LIBSECRET_CONFIGURE_WITH=	libsecret
NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls
OPENSSL_USE=		openssl=yes
OPENSSL_CONFIGURE_ENV=	${OPENSSLINC:M/usr/include:C,.+,libssl_CFLAGS=" ",} \
			${OPENSSLLIB:M/usr/lib:C,.+,libssl_LIBS="-lssl -lcrypto",}
OPENSSL_CONFIGURE_ON=	--with-tls=openssl

post-patch:
	@${REINPLACE_CMD} -Ee 's/Debian/${OPSYS}/' \
		-e 's,/etc/ssl/certs,${LOCALBASE}/share/certs,' \
		-e '/crt/s/ca(\\?)-certificates/ca\1-root\1-nss/' \
		-e 's/ca\\?-certificates/ca_root_nss/' \
		${WRKSRC}/doc/mpop*

.include <bsd.port.mk>
