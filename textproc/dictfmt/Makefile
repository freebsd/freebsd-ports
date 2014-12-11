# Created by: Kimura Fuyuki <fuyuki@hadaly.org>
# $FreeBSD$

PORTNAME=	dictfmt
PORTVERSION=	1.12.1
CATEGORIES=	textproc
MASTER_SITES=	SF/dict/dictd/dictd-${PORTVERSION}
DISTNAME=	dictd-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Formats a DICT protocol dictionary database

LICENSE=	GPLv2

LIB_DEPENDS=	libmaa.so:${PORTSDIR}/devel/libmaa

ALL_TARGET=	dictfmt
CPPFLAGS+=	-I${LOCALBASE}/include
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install.dictfmt
LIBS+=		-L${LOCALBASE}/lib
USES=		gmake libtool:build

.include <bsd.port.mk>
