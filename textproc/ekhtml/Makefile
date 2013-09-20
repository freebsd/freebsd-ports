# Created by: Ditesh Shashikant Gathani <ditesh@gathani.org>
# $FreeBSD$

PORTNAME=	ekhtml
PORTVERSION=	0.3.2
CATEGORIES=	textproc
MASTER_SITES=	SF

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	El-Kabong is a speedy, yet forgiving, SAX-style HTML parser

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	include/ekhtml.h lib/libekhtml.a \
		lib/libekhtml.la lib/libekhtml.so \
		lib/libekhtml.so.0

NO_STAGE=	yes
.include <bsd.port.mk>
