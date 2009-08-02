# New ports collection makefile for:	geomgui
# Date created:				2005-07-18
# Whom:	Soeren				Straarup <xride@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	geomgui
PORTVERSION=	0.12
PORTREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	http://geomgui.xride.dk/files/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	xride

MAINTAINER=	xride@FreeBSD.org
COMMENT=	Viewer for kernel geom layer

LIB_DEPENDS=	gvc:${PORTSDIR}/graphics/graphviz

USE_AUTOTOOLS=	libtool:22
USE_GNOME=	gtk20 librsvg2
USE_ICONV=	yes
GNU_CONFIGURE=	yes

MAN1=	geomgui.1
PLIST_FILES=	bin/geomgui

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|' \
	${WRKSRC}/Makefile.in

.include <bsd.port.mk>
