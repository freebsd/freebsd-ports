# New ports collection makefile for:	gmime
# Date created:			7 Apr 2001
# Whom:				Bas Kruit <baskruit@bsltwr.dnsalias.org>
#
# $FreeBSD$
#

PORTNAME=	gmime
PORTVERSION=	1.0.7
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://spruce.sourceforge.net/gmime/sources/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library (written in C) for parsing and creating messages using MIME

LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv

CONFLICTS= 	gmime-2.1.*
USE_X_PREFIX=	YES
GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_GNOME=	glib12
USE_LIBTOOL=	YES
CONFIGURE_ARGS+=--with-libiconv-prefix=${LOCALBASE}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

INSTALLS_SHLIB=	YES

.include <bsd.port.mk>
