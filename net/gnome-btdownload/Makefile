# New ports collection makefile for:	gnome-btdownload
# Date created:				21 October 2003
# Whom:					Mezz <mezz7@cox.net>
#
# $FreeBSD$
#

PORTNAME=	gnome-btdownload
PORTVERSION=	0.0.11
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gnome-bt

MAINTAINER=	mezz@FreeBSD.org
COMMENT=	A simple Gnome interface designed as a mime-sink for BitTorrent files

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/BitTorrent/__init__.py:${PORTSDIR}/net/py-bittorrent-core

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PYTHON=	yes
USE_REINPLACE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnomeprefix pygnome2
GNU_CONFIGURE=	yes

MAN1=		gnome-btdownload.1

post-patch:
	@${REINPLACE_CMD} -e 's|%%X11PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/src/${PORTNAME}

.include <bsd.port.mk>
