# Created by: Rodrigo Graeff <delphus@gmail.com>
# $FreeBSD$

PORTNAME=	gdmap
PORTVERSION=	0.7.5
PORTREVISION=	7
CATEGORIES=	sysutils gnome
MASTER_SITES=	SF

MAINTAINER=	delphus@gmail.com
COMMENT=	Graphical disk map Utility

BUILD_DEPENDS=	p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser

USE_GNOME=	gnomeprefix gnomehack gtk20
USES=		gmake perl5 pkgconfig
GNU_CONFIGURE=	yes

MAN1=	gdmap.1

post-patch:
	@${REINPLACE_CMD} -e 's,<sys/vfs.h>,<sys/statvfs.h>,' \
		${WRKSRC}/src/gui_main.c
	@${REINPLACE_CMD} -e 's|-D.*_DISABLE_DEPRECATED||g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
