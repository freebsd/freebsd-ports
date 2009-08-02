# New ports collection makefile for:   ekhtml
# Date created:        21 December 2007
# Whom:                Ditesh Shashikant Gathani <ditesh@gathani.org>
#
# $FreeBSD$
#

PORTNAME=	ekhtml
PORTVERSION=	0.3.2
CATEGORIES=	textproc
MASTER_SITES=	SF

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	El-Kabong is a speedy, yet forgiving, SAX-style HTML parser

USE_AUTOTOOLS=	libtool:22
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_LDCONFIG=	yes

PLIST_FILES=	include/ekhtml.h lib/libekhtml.a \
		lib/libekhtml.la lib/libekhtml.so \
		lib/libekhtml.so.0

.include <bsd.port.mk>
