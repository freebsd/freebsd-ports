# Created by: Marcel Kaiser <mk@nic-nac-project.org>
# $FreeBSD$

PORTNAME=	dsbmc
PORTVERSION=	0.2.2
CATEGORIES=	sysutils
MASTER_SITES=	http://freeshell.de/~mk/download/

MAINTAINER=	mk@nic-nac-project.org
COMMENT=	GTK+ client for DSBMD that lets you mount media, and more

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2
RUN_DEPENDS=	dsbmd>=0.3:sysutils/dsbmd

USES=		tar:tgz pkgconfig
USE_GNOME=	cairo gdkpixbuf2 gtk20

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_MAKE_ARGS_OFF=	-DWITHOUT_GETTEXT

.include <bsd.port.mk>
