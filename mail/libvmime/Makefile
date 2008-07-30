# New ports collection makefile for:    libvmime
# Date created:				September 17, 2005
# Whom:					delphij@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	libvmime
PORTVERSION=	0.8.1
PORTREVISION=	6
CATEGORIES=	mail
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	vmime

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	An all-in-one Internet mail library

LIB_DEPENDS+=	gnutls.26:${PORTSDIR}/security/gnutls
LIB_DEPENDS+=	gsasl.11:${PORTSDIR}/security/gsasl

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CFLAGS+=	-I${LOCALBASE}/include -D_GLIBCXX__PTHREADS
LDFLAGS+=	-L${LOCALBASE}/lib

.ifndef	DEBUG
CONFIGURE_ARGS+=--disable-debug
.endif

CONFIGURE_ENV+=	EXTRA_CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

DOCSDIR=	${PREFIX}/share/doc/vmime

.include <bsd.port.mk>
