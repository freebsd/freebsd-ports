# $FreeBSD$

PORTNAME=	libzeitgeist
PORTVERSION=	0.3.18
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://launchpadlibrarian.net/100152436/ \
	https://launchpad.net/${PORTNAME}/${PORTVERSION:R}/${PORTVERSION}/+download/ \
	LOCAL/olivierd

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Zeitgeist client library

GNU_CONFIGURE=	yes
USES=		gettext gmake libtool pathfix pkgconfig
USE_GNOME=	glib20 gnomehier intltool intlhack
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
