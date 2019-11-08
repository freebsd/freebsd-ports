# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	parano
PORTVERSION=	0.3.5
PORTREVISION=	7
CATEGORIES=	security
MASTER_SITES=	BERLIOS

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gnome program to deal with hashfiles

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GNOME=	pygnome2 intltool
USES=		desktop-file-utils gettext gmake gnome localbase python:2.7 \
		shared-mime-info shebangfix
SHEBANG_FILES=	src/parano.py
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-update-mime-database
NO_ARCH=	yes

.include <bsd.port.mk>
