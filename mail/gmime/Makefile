# New ports collection makefile for:	gmime
# Date created:			7 Apr 2001
# Whom:				Bas Kruit <baskruit@bsltwr.dnsalias.org>
#
# $FreeBSD$
#

PORTNAME=	gmime
PORTVERSION=	1.0.8
CATEGORIES=	mail
MASTER_SITES=	http://spruce.sourceforge.net/gmime/sources/v1.0/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library (written in C) for parsing and creating messages using MIME

CONFLICTS=	gmime-2.1.*
USE_X_PREFIX=	YES
GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_GNOME=	glib12
USE_ICONV=	yes
USE_LIBTOOL_VER=15
CFLAGS+=	-L${LOCALBASE}/lib # req'd to find iconv
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}
MAKE_ARGS=	confexecdir=${PREFIX}/etc

INSTALLS_SHLIB=	YES

.include <bsd.port.mk>
