# New ports collection makefile for:	mod_auth_mellon
# Date created:				2010-20-8
# Whom:					Tom Judge <tom@tomjudge.com>
#
# $FreeBSD$
#

PORTNAME=		mod_auth_mellon
PORTVERSION=		0.3.0
CATEGORIES=		www
MASTER_SITES=		http://modmellon.googlecode.com/files/
DIST_SUBDIR=		apache2

MAINTAINER=		tom@tomjudge.com
COMMENT=		Apache auth module for identifying SSO users

LIB_DEPENDS=		lasso.8:${PORTSDIR}/security/lasso \
			curl.6:${PORTSDIR}/ftp/curl

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-apxs2=${APXS}
CONFIGURE_ENV+=		OPENSSL_CFLAGS="-Wall" OPENSSL_LIBS="-lssl"

USE_APACHE=		2.2+

PLIST_FILES=		${APACHEMODDIR}/mod_auth_mellon.so

post-configure:
	@${REINPLACE_CMD} -e 's|-pthread|-Wl,-pthread|g' \
	    -e 's| -L| -Wl,-L|g' \
	    ${WRKSRC}/Makefile

.include <bsd.port.mk>
