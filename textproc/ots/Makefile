# New ports collection makefile for:	ots
# Date created:		9 June 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ots
PORTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	SF/libots

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open Text Summarizer

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt

USE_GNOME=	glib20 libxml2
USE_LDCONFIG=	yes
USE_GETTEXT=	yes
USE_AUTOTOOLS=	libtool:22
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--disable-shared
MAKE_ARGS=	pkgconfigdir="${PREFIX}/libdata/pkgconfig"

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|doc||' ${WRKSRC}/Makefile.in

post-build:
	@${REINPLACE_CMD} -e '/old_library/d' ${WRKSRC}/src/libots-1.la

.include <bsd.port.mk>
