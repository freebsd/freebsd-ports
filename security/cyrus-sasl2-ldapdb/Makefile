# New ports collection makefile for:	cyrus-sasl2-ldapdb
# Date created:				May 18 2005
# Whom:					ume@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	ldapdb
PORTVERSION=	2.1.23
#PORTREVISION=	0
CATEGORIES=	security ipv6
MASTER_SITES=	ftp://ftp.andrew.cmu.edu/pub/cyrus-mail/%SUBDIR%/ \
		ftp://ftp.westbend.net/pub/cyrus-mail/%SUBDIR%/ \
		http://www.transit.hanse.de/mirror/ftp.andrew.cmu.edu/pub/cyrus-mail/%SUBDIR%/
MASTER_SITE_SUBDIR=	. OLD-VERSIONS/sasl
PKGNAMEPREFIX=	cyrus-sasl-
DISTNAME=	${PKGNAMEPREFIX}${PORTVERSION}

MAINTAINER=	ume@FreeBSD.org
COMMENT=	SASL LDAPDB auxprop plugin

LIB_DEPENDS=	sasl2.2:${PORTSDIR}/security/cyrus-sasl2

CYRUS_SASL2_DIR=${MASTERDIR}/../cyrus-sasl2
MD5_FILE=	${CYRUS_SASL2_DIR}/distinfo
PATCHDIR=	${CYRUS_SASL2_DIR}/files
INSTALL_WRKSRC=	${WRKDIR}/${DISTNAME}/plugins

USE_LDCONFIG=	yes

USE_AUTOTOOLS=	libtool:15
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes

.if defined(WITH_OPENLDAP_VER)
WANT_OPENLDAP_VER=	${WITH_OPENLDAP_VER}
.endif
USE_OPENLDAP=	yes

CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc \
		--with-plugindir=${PREFIX}/lib/sasl2 \
		--with-dbpath=${PREFIX}/etc/sasldb2 \
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
		--disable-plain

CONFIGURE_ARGS+=--enable-ldapdb --with-ldap=${LOCALBASE}

PLIST_FILES=	lib/sasl2/libldapdb.a \
		lib/sasl2/libldapdb.la \
		lib/sasl2/libldapdb.so \
		lib/sasl2/libldapdb.so.2

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
