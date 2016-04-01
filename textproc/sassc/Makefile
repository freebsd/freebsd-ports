# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sassc
PORTVERSION=	1.0.1
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Wrapper around libsass

LICENSE=	MIT

LIB_DEPENDS=	libsass.so:textproc/libsass

USE_GITHUB=	yes
GH_ACCOUNT=	sass

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USES=		autoreconf libtool

PLIST_FILES=	bin/sassc

.include <bsd.port.mk>
