# ex:ts=8
# New ports collection makefile for:	snownews
# Date created:			Nov 3 2003
# Whom:				Cheng-Lung Sung <clsung@dragon2.net>
#
# $FreeBSD$
#

PORTNAME=	snownews
PORTVERSION=	1.5.6.1
CATEGORIES=	www
MASTER_SITES=	http://kiza.kcore.de/software/snownews/download/

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A text mode RSS newsreader

USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	libxml2
USE_REINPLACE=	yes

MAN1=		snownews.1
MANLANG=	"" de nl fr it ru_RU.KOI8-R

post-patch:
	@${REINPLACE_CMD} -e 's|CFLAGS=|CFLAGS+=|g' ${WRKSRC}/platform_settings
	@${REINPLACE_CMD} -e 's|gcc|${CC}|' ${WRKSRC}/Makefile

.include <bsd.port.mk>
