# Created by: Ju Pengfei <jupengfei@gmail.com>
# $FreeBSD$

PORTNAME=	webkitgtk
PORTVERSION=	1.1.8
PORTREVISION=	7
CATEGORIES=	www python
MASTER_SITES=	https://pkgs.fedoraproject.org/repo/extras/pywebkitgtk/pywebkitgtk-1.1.8.tar.bz2/19f3c184eebcfde1c9d1ce56bbe75cf2/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python bindings for the WebKit GTK+ port

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libwebkitgtk-1.0.so:www/webkit-gtk2

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		gmake libtool pathfix pkgconfig python:2.7 tar:bzip2
USE_GNOME=	glib20 libxslt pygtk2
USE_PYTHON=	flavors

.include <bsd.port.mk>
