# New ports collection makefile for:	gmime
# Date created:			7 Apr 2001
# Whom:				Bas Kruit <baskruit@bsltwr.dnsalias.org>
#
# $FreeBSD$
#

PORTNAME=	gmime
PORTVERSION=	0.6.0
CATEGORIES=	mail
MASTER_SITES=	http://bsltwr.dnsalias.org/ftp/pub/gmime/ \
		http://spruce.sourceforge.net/gmime/sources/

MAINTAINER=	baskruit@bsltwr.dnsalias.org

USE_X_PREFIX=	YES
GNU_CONFIGURE=  YES
USE_GMAKE=	YES
USE_GTK=	YES
USE_LIBTOOL=	YES
CONFIGURE_ARGS+=--with-libiconv=${LOCALBASE}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

INSTALLS_SHLIB=	YES

.include <bsd.port.mk>
