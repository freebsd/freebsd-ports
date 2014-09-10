# Created by: Ju Pengfei <jupengfei@gmail.com>
# $FreeBSD$

PORTNAME=	webkitgtk
PORTVERSION=	1.1.8
PORTREVISION=	4
CATEGORIES=	www python
MASTER_SITES=	GOOGLE_CODE
PROJECTHOST=	pywebkitgtk
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Python bindings for the WebKit GTK+ port

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libwebkitgtk-1.0.so:${PORTSDIR}/www/webkit-gtk2

GNU_CONFIGURE=	yes
USES=		gmake libtool pathfix pkgconfig tar:bzip2
USE_GNOME=	glib20 libxslt pygtk2
USE_PYTHON=	yes

.include <bsd.port.mk>
