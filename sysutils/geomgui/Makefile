# New ports collection makefile for:	geomgui
# Date created:				2005-07-18
# Whom:	Soeren				Straarup <xride@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	geomgui
PORTVERSION=	0.13
CATEGORIES=	sysutils
MASTER_SITES=	http://tinkering.hambrew.net/geomgui/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	xride
USE_BZIP2=	yes

MAINTAINER=	xride@FreeBSD.org
COMMENT=	Viewer for kernel geom layer

LIB_DEPENDS=	gvc:${PORTSDIR}/graphics/graphviz

USE_AUTOTOOLS=	libtool
USE_GNOME=	gtk20 librsvg2
USES=		iconv
GNU_CONFIGURE=	yes

MAN1=	geomgui.1
PLIST_FILES=	bin/geomgui

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|' \
	${WRKSRC}/Makefile.in

.include <bsd.port.mk>
