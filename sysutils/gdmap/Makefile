# Created by: Rodrigo Graeff <delphus@gmail.com>
# $FreeBSD$

PORTNAME=	gdmap
PORTVERSION=	0.8.1
PORTREVISION=	1
CATEGORIES=	sysutils gnome
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical disk map Utility

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-XML-Parser>=0:textproc/p5-XML-Parser

USES=		gettext gmake pathfix perl5 pkgconfig
USE_PERL5=	build
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lm

post-patch:
	@${REINPLACE_CMD} -e \
		's|-D.*_DISABLE_DEPRECATED||g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|<sys/vfs.h>|<sys/statvfs.h>|' \
		${WRKSRC}/src/gui_main.c
	@${REINPLACE_CMD} -e \
		's|=\(gdmap_icon.png\)|=${PREFIX}/share/pixmaps/\1|' \
		${WRKSRC}/data/gdmap.desktop.in

.include <bsd.port.mk>
