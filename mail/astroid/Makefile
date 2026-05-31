PORTNAME=	astroid
DISTVERSIONPREFIX=	v
DISTVERSION=	0.17
PORTREVISION=	4
CATEGORIES=	mail

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	ad5b290816c57cae153ebf2dfbd64e8c7924344c.patch:-p1

MAINTAINER=	mylan.connolly@gmail.com
COMMENT=	Graphical email client for notmuch, inspired by sup and others
WWW=		https://astroidmail.github.io/

LICENSE=	GPLv3+ LGPL21+
LICENSE_COMB=	dual
LICENSE_FILE_GPLv3+ =	${WRKSRC}/COPYING.GPL-3.0+
LICENSE_FILE_LGPL21+ =	${WRKSRC}/COPYING.LGPL-2.1+

BUILD_DEPENDS=	scdoc:textproc/scdoc \
		notmuch>0:mail/notmuch
LIB_DEPENDS=	libboost_filesystem.so:devel/boost-libs \
		libjavascriptcoregtk-4.1.so:www/webkit2-gtk@41 \
		libgmime-3.0.so:mail/gmime30 \
		libgnutls.so:security/gnutls \
		libpcre2-8.so:devel/pcre2 \
		libpeas-1.0.so:devel/libpeas1 \
		libprotobuf.so:devel/protobuf \
		libsass.so:textproc/libsass \
		libsoup-2.4.so:devel/libsoup
RUN_DEPENDS=	notmuch:mail/notmuch

USES=		cmake compiler:c++17-lang desktop-file-utils \
		gettext-runtime gnome pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	astroidmail
USE_GNOME=	atk atkmm cairo cairomm gdkpixbuf glib20 glibmm gtk30 \
		gtkmm30 libsigc++20 pango pangomm vte3

USE_CXXSTD=	c++17

.include <bsd.port.mk>
