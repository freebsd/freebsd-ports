# New ports collection makefile for:    mod_auth_kerb
# Date created:             19 October 2001
# Whom:                 wollman
#
# $FreeBSD$
#


# Shamelessly stolen from will's mod_auth_any port.

PORTNAME=	mod_auth_kerb
PORTVERSION=	5.4
CATEGORIES=	www
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=modauthkerb

MAINTAINER=	apache@FreeBSD.org
COMMENT=	An Apache module for authenticating users with Kerberos v5

MAKE_JOBS_SAFE=  yes

LATEST_LINK=   mod_auth_kerb2

USE_APACHE=	2.0+
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

PORTSCOUT=	limit:^5.3

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

.include <bsd.port.mk>
