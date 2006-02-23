# New ports collection makefile for:    libvmime
# Date created:				September 17, 2005
# Whom:					delphij@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	libvmime
PORTVERSION=	0.8.0
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	vmime

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	An all-in-one Internet mail library

# XXX Need a newer gnutls version before enabling this
#LIB_DEPENDS+=	gnutls.12:${PORTSDIR}/security/gnutls
LIB_DEPENDS+=	gsasl.9:${PORTSDIR}/security/gsasl

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
USE_GCC=	3.3+
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.ifndef	DEBUG
CONFIGURE_ARGS+=--disable-debug
.endif

# XXX Need a newer gnutls version
CONFIGURE_ARGS+=--disable-tls

CONFIGURE_ENV+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

DOCSDIR=	${PREFIX}/share/doc/vmime

.include <bsd.port.mk>
