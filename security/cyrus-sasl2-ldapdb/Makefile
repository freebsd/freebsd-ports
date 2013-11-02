# $FreeBSD$

PORTNAME=	ldapdb
PORTVERSION=	2.1.26
PORTREVISION=	1
CATEGORIES=	security ipv6
MASTER_SITES=	ftp://ftp.cyrusimap.org/cyrus-sasl/
PKGNAMEPREFIX=	cyrus-sasl-
DISTNAME=	${PKGNAMEPREFIX}${PORTVERSION}

MAINTAINER=	ume@FreeBSD.org
COMMENT=	SASL LDAPDB auxprop plugin

LICENSE=	BSD
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

.if defined(WITH_OPENLDAP_VER)
WANT_OPENLDAP_VER=	${WITH_OPENLDAP_VER}
.endif
USE_OPENLDAP=	yes

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
CONFIGURE_ARGS+=--enable-ldapdb --with-ldap=${LOCALBASE}
MAKE_ENV+=	INSTALL_STRIP_FLAG=${STRIP}

PLIST_FILES=	lib/sasl2/libldapdb.a \
		lib/sasl2/libldapdb.la \
		lib/sasl2/libldapdb.so \
		lib/sasl2/libldapdb.so.3

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
