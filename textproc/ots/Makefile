# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ots
PORTVERSION=	0.5.0
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	SF/lib${PORTNAME}/lib${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open Text Summarizer

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt

USE_GNOME=	glib20 libxml2
USE_LDCONFIG=	yes
USES=		gettext pkgconfig
USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-shared
MAKE_ARGS=	pkgconfigdir="${PREFIX}/libdata/pkgconfig"
MAKE_JOBS_UNSAFE=yes

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|doc||' ${WRKSRC}/Makefile.in

post-build:
	@${REINPLACE_CMD} -e '/old_library/d' ${WRKSRC}/src/libots-1.la

.include <bsd.port.mk>
