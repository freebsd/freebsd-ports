# New ports collection makefile for:	py-webkitgtk
# Date created:				07 Mar 2010
# Whom:					Ju Pengfei <jupengfei@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	webkitgtk
PORTVERSION=	1.1.8
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Python bindings for the WebKit GTK+ port

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	webkitgtk-1.0:${PORTSDIR}/www/webkit-gtk2

PROJECTHOST=	pywebkitgtk

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GNOME=	glib20 libxslt pkgconfig pygtk2
USE_GMAKE=	yes
USE_PYTHON=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|${PREFIX}/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
