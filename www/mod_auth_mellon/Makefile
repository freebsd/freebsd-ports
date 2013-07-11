# Created by: Tom Judge <tom@tomjudge.com>
# $FreeBSD$

PORTNAME=		mod_auth_mellon
PORTVERSION=		0.5.0
PORTREVISION=	1
CATEGORIES=		www
MASTER_SITES=		http://modmellon.googlecode.com/files/
DIST_SUBDIR=		apache2

MAINTAINER=		tj@FreeBSD.org
COMMENT=		Apache auth module for identifying SSO users

LIB_DEPENDS=		lasso.8:${PORTSDIR}/security/lasso \
			curl:${PORTSDIR}/ftp/curl

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-apxs2=${APXS}
CONFIGURE_ENV+=		OPENSSL_CFLAGS="-Wall" OPENSSL_LIBS="-lssl"

USE_APACHE=		22

PLIST_FILES=		${APACHEMODDIR}/mod_auth_mellon.so

.include <bsd.port.mk>
