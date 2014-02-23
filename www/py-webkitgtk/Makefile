# Created by: Ju Pengfei <jupengfei@gmail.com>
# $FreeBSD$

PORTNAME=	webkitgtk
PORTVERSION=	1.1.8
PORTREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Python bindings for the WebKit GTK+ port

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libwebkitgtk-1.0.so:${PORTSDIR}/www/webkit-gtk2

PROJECTHOST=	pywebkitgtk

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GNOME=	glib20 libxslt pygtk2
USES=		gmake pathfix pkgconfig
USE_PYTHON=	yes

.include <bsd.port.mk>
