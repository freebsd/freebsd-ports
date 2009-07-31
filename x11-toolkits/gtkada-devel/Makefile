# New ports collection makefile for:   gtkada
# Date Created:			27 Nov 2000
# Whom:				Samuel Tardieu <sam@inf.enst.fr>
#
# $FreeBSD$
#

PORTNAME=	gtkada
PORTVERSION=	20060615
PORTREVISION=	5
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://sitola.fi.muni.cz/~hopet/gtkada/
PKGNAMESUFFIX=	-devel
DISTNAME=	GtkAda-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	hopet@ics.muni.cz
COMMENT=	Gtk2 binding for Ada

BUILD_DEPENDS=	gnatgcc:${PORTSDIR}/lang/gnat

CONFLICTS=	gtkada-[0-9]* gtkada-gcc-[0-9]*

WRKSRC=		${WRKDIR}/GtkAda

USE_GL=		gl
USE_GNOME=	gtk20 libglade2 libgnomeui
USE_GMAKE=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-GL=Gl

EXTRA_PATCHES=	${FILESDIR}/obsolescence.patch

post-patch:
	@${REINPLACE_CMD} -e 's|lib/pkgconfig|libdata/pkgconfig|' ${WRKSRC}/projects/Makefile

.include <bsd.port.mk>
