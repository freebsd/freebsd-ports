# New ports collection makefile for:	mod_auth_kerb
# Date created:				19 October 2001
# Whom:					wollman
#
# $FreeBSD$
#

# Shamelessly stolen from will's mod_auth_any port.

PORTNAME=	mod_auth_kerb
PORTVERSION=	5.0.r6
DISTNAME=	mod_auth_kerb-5.0-rc6
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
LIB_DEPENDS=	krb5.3:${PORTSDIR}/security/krb5

USE_APACHE=	yes

KRB5_HOME?=	${LOCALBASE}

# Don't fsck with CFLAGS
CFLAGS:=

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-krb5=${KRB5_HOME} --without-krb4

.include <bsd.port.mk>
