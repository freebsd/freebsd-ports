# New ports collection makefile for:	mod_auth_kerb
# Date created:				19 October 2001
# Whom:					wollman
#
# $FreeBSD$
#

# Shamelessly stolen from will's mod_auth_any port.

PORTNAME=	mod_auth_kerb
PORTVERSION=	5.3
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=modauthkerb

MAINTAINER=	apache@FreeBSD.org
COMMENT=	An Apache module for authenticating users with Kerberos v5

#
# This module allows users to send their Kerberos password in
# plain text; it should only be used over an encrypted connection
# (i.e., HTTP over SSL/TLS).  Thus, we require as a dependency
# a version of Apache which can do this.
#
USE_APACHE=	1.3+
USE_GMAKE=	yes
# Don't fsck with CFLAGS
CFLAGS:=
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if exists(${PREFIX}/sbin/apxs)
APACHE_MODULE_DIR!=${PREFIX}/sbin/apxs -q LIBEXECDIR
.else
APACHE_MODULE_DIR=libexec/apache
.endif
PLIST_SUB+=	APMODDIR=${APACHE_MODULE_DIR:S/^${PREFIX}\///}

.if defined(KRB5_HOME) && exists(${KRB5_HOME}/lib/libgssapi_krb5.a)
CONFIGURE_ARGS+=	--with-krb5=${KRB5_HOME} --without-krb4
.elif defined(HEIMDAL_HOME) && exists(${HEIMDAL_HOME}/lib/libgssapi.a)
CONFIGURE_ARGS+=	--with-krb5=${HEIMDAL_HOME} --without-krb4
.elif exists(${DESTDIR}/usr/lib/libkrb5.a) && exists(${DESTDIR}/usr/bin/krb5-config)
CONFIGURE_ARGS+=	--with-krb5=${DESTDIR}/usr --without-krb4
.else
LIB_DEPENDS+=	krb5:${PORTSDIR}/security/krb5
CONFIGURE_ARGS+=	--with-krb5=${LOCALBASE} --without-krb4
.endif

.include <bsd.port.post.mk>
