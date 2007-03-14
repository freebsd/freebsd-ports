# New ports collection makefile for:	mod_auth_kerb
# Date created:				19 October 2001
# Whom:					wollman
#
# $FreeBSD$
#

# Shamelessly stolen from will's mod_auth_any port.

PORTNAME=	mod_auth_kerb
PORTVERSION=	5.1
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
CONFIGURE_ARGS+=--with-krb5=${KRB5_HOME} --without-krb4
OPTIONS+=	BASE_KERBEROS5	"Use the base Kerberos 5 (Heimdal)"
.if exists(/usr/lib/libkrb5.so)
OPTIONS+=	on
.else
OPTIONS+=	off
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700014
BROKEN=		Does not compile on FreeBSD >= 7.0
.endif

.if exists(${PREFIX}/sbin/apxs)
APACHE_MODULE_DIR!=${PREFIX}/sbin/apxs -q LIBEXECDIR
.else
APACHE_MODULE_DIR=libexec/apache
.endif
PLIST_SUB+=	APMODDIR=${APACHE_MODULE_DIR:S/^${PREFIX}\///}
.if defined(WITH_BASE_KERBEROS5)
KRB5_HOME=	/usr
.else
LIB_DEPENDS+=	krb5.3:${PORTSDIR}/security/krb5
KRB5_HOME=	${LOCALBASE}
.endif

.include <bsd.port.post.mk>
