# New ports collection makefile for:	osslsigncode
# Date created:		9 November 2006
# Whom:			snb@threerings.net
#
# $FreeBSD$
#

PORTNAME=	osslsigncode
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	security devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION}

MAINTAINER=	snb@FreeBSD.org
COMMENT=	OpenSSL-based signcode utility

PLIST_FILES=	bin/osslsigncode

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_OPENSSL=	yes

.if !defined(WITHOUT_CURL)
LIB_DEPENDS+=	curl.5:${PORTSDIR}/ftp/curl
.endif

.include <bsd.port.mk>
