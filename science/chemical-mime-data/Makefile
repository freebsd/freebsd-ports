# New ports collection makefile for:	chemical-mime-data
# Date created:				21 May 2007
# Whom:					Pav Lucistnik <pav@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	chemical-mime-data
PORTVERSION=	0.1.94
PORTREVISION=	2
CATEGORIES=	science
MASTER_SITES=	SF/chemical-mime/${PORTNAME}/${PORTVERSION}

MAINTAINER=	pav@FreeBSD.org
COMMENT=	A collection of chemical MIME types for UNIX desktops

BUILD_DEPENDS=	${LOCALBASE}/share/mime/magic:${PORTSDIR}/misc/shared-mime-info \
		${LOCALBASE}/libdata/pkgconfig/librsvg-2.0.pc:${PORTSDIR}/graphics/librsvg2 \
		xsltproc:${PORTSDIR}/textproc/libxslt
RUN_DEPENDS=	${LOCALBASE}/share/mime/magic:${PORTSDIR}/misc/shared-mime-info

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomemimedata intltool
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib -lintl"
INSTALLS_ICONS=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|*-*-solaris*|*| ; s|rsvg|rsvg-convert|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|(datadir)/pkgconfig|(prefix)/libdata/pkgconfig|' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|-f png $$< |-f png $$< > |' ${WRKSRC}/icons/hicolor/Makefile.in

.include <bsd.port.mk>
