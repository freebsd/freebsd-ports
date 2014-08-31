# Created by: Oliver Lehmann <oliver@FreeBSD.org>
# $FreeBSD$

PORTNAME=	garcon
PORTVERSION=	0.2.1
PORTREVISION=	2
CATEGORIES=	sysutils xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=	src/xfce/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Xfce 4 essential utilities and scripts

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		gmake libtool pathfix pkgconfig tar:bzip2
USE_GNOME=	glib20 intltool intlhack
USE_XFCE=	configenv libutil

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

DOCS_CONFIGURE_ENABLE=	gtk-doc-html

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext

.include <bsd.port.mk>
