# $FreeBSD$

PORTNAME=	gssapi
PORTVERSION=	2.1.26
PORTREVISION=	7
CATEGORIES=	security ipv6
MASTER_SITES=	ftp://ftp.cyrusimap.org/cyrus-sasl/ \
		http://cyrusimap.org/releases/
PKGNAMEPREFIX=	cyrus-sasl-
DISTNAME=	${PKGNAMEPREFIX}${PORTVERSION}

MAINTAINER=	ume@FreeBSD.org
COMMENT=	SASL GSSAPI authentication plugin

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libsasl2.so:${PORTSDIR}/security/cyrus-sasl2

CYRUS_SASL2_DIR=${MASTERDIR}/../cyrus-sasl2
DISTINFO_FILE=	${CYRUS_SASL2_DIR}/distinfo
PATCHDIR=	${CYRUS_SASL2_DIR}/files
INSTALL_WRKSRC=	${WRKSRC}/plugins

USES=		libtool:build
USE_LDCONFIG=	yes
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc \
		--with-plugindir=${PREFIX}/lib/sasl2 \
		--with-dbpath=${PREFIX}/etc/sasldb2 \
		--with-lib-subdir=lib \
		--includedir=${PREFIX}/include \
		--enable-static \
		--with-rc4=openssl
CONFIGURE_ARGS+=--with-dblib=none \
		--disable-anon \
		--disable-cram \
		--disable-digest \
		--disable-krb4 \
		--disable-ntlm \
		--disable-otp \
		--disable-plain \
		--disable-scram

MAKE_ENV+=	INSTALL_STRIP_FLAG=${STRIP}

OPTIONS_SINGLE=		KERBEROS
OPTIONS_SINGLE_KERBEROS=BASE HEIMDAL MIT
OPTIONS_DEFAULT=	BASE
BASE_DESC=		Use Heimdal in base
BASE_USES=		gssapi
BASE_CONFIGURE_ENABLE=	gssapi
HEIMDAL_DESC=		Use Heimdal from ports
HEIMDAL_USES=		gssapi:heimdal,flags
HEIMDAL_CONFIGURE_ON=	--enable-gssapi="${GSSAPIBASEDIR}" \
			--with-gss_impl=heimdal
MIT_DESC=		Use MIT Kerberos V5
MIT_USES=		gssapi:mit
MIT_CONFIGURE_ON=	--enable-gssapi="${GSSAPIBASEDIR}" \
			--with-gss_impl=mit

PLIST_FILES=	lib/sasl2/libgssapiv2.a \
		lib/sasl2/libgssapiv2.so \
		lib/sasl2/libgssapiv2.so.3 \
		lib/sasl2/libgssapiv2.so.3.0.0

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MHEIMDAL}
PLIST_FILES+=	lib/sasl2/libgs2.a \
		lib/sasl2/libgs2.so \
		lib/sasl2/libgs2.so.3 \
		lib/sasl2/libgs2.so.3.0.0
.endif

.if ${OPENSSLBASE} == /usr
CONFIGURE_ARGS+=--with-openssl=yes
.else
CONFIGURE_ARGS+=--with-openssl=${OPENSSLBASE}
.endif

LIBTOOL=	${LOCALBASE}/bin/libtool

post-patch:
	@${REINPLACE_CMD} \
		-e "/^LIBTOOL=/s|\$$(top_builddir)/libtool|${LIBTOOL}|g" \
		${WRKSRC}/configure

do-build:
	cd ${WRKSRC}/include && ${MAKE}
	cd ${WRKSRC}/plugins && ${MAKE}

.include <bsd.port.post.mk>
