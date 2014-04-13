# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sassc
PORTVERSION=	1.0.1
#PORTREVISION=	0
CATEGORIES=	textproc

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Wrapper around libsass

LICENSE=	MIT

LIB_DEPENDS=	libsass.so:${PORTSDIR}/textproc/libsass

AUTOMAKE_ARGS=	--add-missing

CPPFLAGS+=	-I${LOCALBASE}/include

GH_ACCOUNT=	hcatlin
GH_COMMIT=	9451dd7
GH_TAGNAME=	v${PORTVERSION}

LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/sassc

USE_AUTOTOOLS=	aclocal autoconf autoheader automake libtoolize
USE_GITHUB=	yes

.include <bsd.port.mk>
