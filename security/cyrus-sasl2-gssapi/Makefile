# $FreeBSD$

PORTNAME=	gssapi
PORTVERSION=	2.1.26
#PORTREVISION=	0
CATEGORIES=	security ipv6
MASTER_SITES=	ftp://ftp.cyrusimap.org/cyrus-sasl/
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

USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
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
BASE_CONFIGURE_ENABLE=	gssapi
HEIMDAL_DESC=		Use Heimdal from ports
HEIMDAL_CONFIGURE_ON=	--enable-gssapi=${HEIMDAL_HOME} \
			--with-gss_impl=heimdal
HEIMDAL_BUILD_DEPENDS=	${HEIMDAL_HOME}/lib/libgssapi.so:${PORTSDIR}/security/heimdal
HEIMDAL_RUN_DEPENDS=	${HEIMDAL_BUILD_DEPENDS}
HEIMDAL_LDFLAGS=	"-R${HEIMDAL_HOME}/lib"
MIT_DESC=		Use MIT Kerberos V5
MIT_CONFIGURE_ON=	--enable-gssapi=${KRB5_HOME} --with-gss_impl=mit
MIT_LIB_DEPENDS=	libkrb5support.so:${PORTSDIR}/security/krb5
MIT_LDFLAGS=		"-R${KRB5_HOME}/lib"

PLIST_FILES=	lib/sasl2/libgssapiv2.a \
		lib/sasl2/libgssapiv2.la \
		lib/sasl2/libgssapiv2.so \
		lib/sasl2/libgssapiv2.so.3

.if !defined(HEIMDAL_HOME)
HEIMDAL_HOME=	${PREFIX}
.endif
.if !defined(KRB5_HOME)
KRB5_HOME=	${PREFIX}
.endif

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MHEIMDAL}
PLIST_FILES+=	lib/sasl2/libgs2.a \
		lib/sasl2/libgs2.la \
		lib/sasl2/libgs2.so \
		lib/sasl2/libgs2.so.3
.endif

.if ${OPENSSLBASE} == /usr
CONFIGURE_ARGS+=--with-openssl=yes
.else
CONFIGURE_ARGS+=--with-openssl=${OPENSSLBASE}
.endif

do-build:
	cd ${WRKSRC}/include && ${MAKE}
	cd ${WRKSRC}/plugins && ${MAKE}

.include <bsd.port.post.mk>
