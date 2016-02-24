# $FreeBSD$

PORTNAME=	srp
PORTVERSION=	2.1.26
#PORTREVISION=	0
CATEGORIES=	security ipv6
MASTER_SITES=	ftp://ftp.cyrusimap.org/cyrus-sasl/ \
		http://cyrusimap.org/releases/
PKGNAMEPREFIX=	cyrus-sasl-
DISTNAME=	${PKGNAMEPREFIX}${PORTVERSION}

MAINTAINER=	ume@FreeBSD.org
COMMENT=	SASL SRP authentication plugin

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libsasl2.so:${PORTSDIR}/security/cyrus-sasl2

CYRUS_SASL2_DIR=${MASTERDIR}/../cyrus-sasl2
DISTINFO_FILE=	${CYRUS_SASL2_DIR}/distinfo
PATCHDIR=	${CYRUS_SASL2_DIR}/files
INSTALL_WRKSRC=	${WRKSRC}/plugins

USES=		libtool
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
		--disable-gssapi \
		--disable-krb4 \
		--disable-ntlm \
		--disable-otp \
		--disable-plain \
		--disable-scram
CONFIGURE_ARGS+=--enable-srp

MAKE_ENV+=	INSTALL_STRIP_FLAG=${STRIP}

OPTIONS_DEFINE=			SRP_SETPASS
OPTIONS_DEFAULT=		SRP_SETPASS
SRP_SETPASS_DESC=		setting SRP secrets with saslpasswd
SRP_SETPASS_CONFIGURE_ENABLE=	srp-setpass

PLIST_FILES=	lib/sasl2/libsrp.a \
		lib/sasl2/libsrp.so \
		lib/sasl2/libsrp.so.3 \
		lib/sasl2/libsrp.so.3.0.0

.include <bsd.port.pre.mk>

.if ${OPENSSLBASE} == /usr
CONFIGURE_ARGS+=--with-openssl=yes
.else
CONFIGURE_ARGS+=--with-openssl=${OPENSSLBASE}
.endif

do-build:
	cd ${WRKSRC}/include && ${MAKE}
	cd ${WRKSRC}/plugins && ${MAKE}

.include <bsd.port.post.mk>
