# Created by: Ditesh Shashikant Gathani <ditesh@gathani.org>
# $FreeBSD$

PORTNAME=	ekhtml
PORTVERSION=	0.3.2
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	SF

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	El-Kabong is a speedy, yet forgiving, SAX-style HTML parser

GNU_CONFIGURE=	yes
USES=		gmake libtool
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	include/ekhtml.h lib/libekhtml.a \
		lib/libekhtml.so lib/libekhtml.so.0 \
		lib/libekhtml.so.0.0.0

.include <bsd.port.mk>
