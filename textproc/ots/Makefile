# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ots
PORTVERSION=	0.5.0
PORTREVISION=	5
CATEGORIES=	textproc
MASTER_SITES=	SF/lib${PORTNAME}/lib${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open Text Summarizer

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpopt.so:devel/popt

USES=		autoreconf gettext libtool pathfix pkgconfig
PATHFIX_MAKEFILEIN=	Makefile.am
USE_GNOME=	glib20 libxml2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip
MAKE_JOBS_UNSAFE=yes

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|doc||' ${WRKSRC}/Makefile.am
	@${REINPLACE_CMD} -e '\|doc/Makefile|d' ${WRKSRC}/configure.in

.include <bsd.port.mk>
