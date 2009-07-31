# New ports collection makefile for:	gdmap
# Date created:		13 Oct 2005
# Whom:			Rodrigo Graeff <delphus@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	gdmap
PORTVERSION=	0.7.5
PORTREVISION=	4
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gdmap

MAINTAINER=	delphus@gmail.com
COMMENT=	Graphical disk map Utility

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser

USE_GNOME=	gnomeprefix gnomehack gtk20
USE_GMAKE=	yes
USE_PERL5=	yes
GNU_CONFIGURE=	yes

MAN1=	gdmap.1

post-patch:
	@${REINPLACE_CMD} -e 's,<sys/vfs.h>,<sys/statvfs.h>,' \
		${WRKSRC}/src/gui_main.c
	@${REINPLACE_CMD} -e 's|-D.*_DISABLE_DEPRECATED||g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
