# New ports collection makefile for:	sslproxy
# Version required:	1998_Jun_14
# Date created:		11 February 1999
# Whom:			Alex Le Heux
#
# $Id$
#

DISTNAME=	sslproxy.1998_Jun_14
PKGNAME=	sslproxy-19980614
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.obdev.at/pub/Products/sslproxy/

MAINTAINER=	alexlh@funk.org

BUILD_DEPENDS=	${PREFIX}/include/openssl/ssl.h:${PORTSDIR}/security/openssl
RUN_DEPENDS=	${PREFIX}/lib/libssl.a:${PORTSDIR}/security/openssl

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sslproxy ${PREFIX}/bin/sslproxy

.include <bsd.port.mk>
