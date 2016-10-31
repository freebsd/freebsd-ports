# Created by: Pav Lucistnik <pav@FreeBSD.org>
# $FreeBSD$

PORTNAME=	chemical-mime-data
PORTVERSION=	0.1.94
PORTREVISION=	7
CATEGORIES=	science
MASTER_SITES=	SF/chemical-mime/${PORTNAME}/${PORTVERSION}

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Collection of chemical MIME types for UNIX desktops

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/librsvg-2.0.pc:graphics/librsvg2

USES=		gettext-tools gmake pathfix pkgconfig tar:bzip2 shared-mime-info
USE_GNOME=	gnomemimedata intlhack libxslt:build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-update-database
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALLS_ICONS=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|*-*-solaris*|*| ; s|rsvg|rsvg-convert|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-f png $$< |-f png $$< > |' ${WRKSRC}/icons/hicolor/Makefile.in

.include <bsd.port.mk>
