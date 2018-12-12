# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fsearch
DISTVERSION=	0.1beta2
PORTREVISION=	2
CATEGORIES=	sysutils

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Search utility focusing on performance and advanced features

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/License

BUILD_DEPENDS=	${LOCALBASE}/share/aclocal/ax_check_compile_flag.m4:devel/autoconf-archive
LIB_DEPENDS=	libpcre.so:devel/pcre

USE_GITHUB=	yes
GH_ACCOUNT=	cboxdoerfer

USES=		autoreconf compiler:c++11-lang gettext gmake pkgconfig
GNU_CONFIGURE=	yes
USE_GNOME=	cairo gdkpixbuf2 gtk30 intltool

.include <bsd.port.mk>
