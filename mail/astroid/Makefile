# $FreeBSD$

PORTNAME=	astroid
DISTVERSIONPREFIX=	v
DISTVERSION=	0.15
PORTREVISION=	4
CATEGORIES=	mail

MAINTAINER=	mylan.connolly@gmail.com
COMMENT=	Graphical email client for notmuch, inspired by sup and others

LICENSE=	GPLv3+ LGPL21+
LICENSE_COMB=	dual
LICENSE_FILE_GPLv3+ =	${WRKSRC}/COPYING.GPL-3.0+
LICENSE_FILE_LGPL21+ =	${WRKSRC}/COPYING.LGPL-2.1+

BUILD_DEPENDS=	scdoc:textproc/scdoc \
		notmuch>0:mail/notmuch
LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libjavascriptcoregtk-4.0.so:www/webkit2-gtk3 \
		libgmime-3.0.so:mail/gmime30 \
		libgnutls.so:security/gnutls \
		libpcre2-8.so:devel/pcre2 \
		libpeas-1.0.so:devel/libpeas \
		libprotobuf.so:devel/protobuf \
		libsass.so:textproc/libsass \
		libsoup-2.4.so:devel/libsoup
RUN_DEPENDS=	notmuch:mail/notmuch

USES=		cmake compiler:c11 desktop-file-utils gettext-runtime gnome \
		pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	astroidmail
GH_PROJECT=	astroid
USE_GNOME=	atk atkmm cairo cairomm gdkpixbuf2 glib20 glibmm gtk30 gtkmm30 introspection libsigc++20 pango pangomm vte3

INSTALLS_ICONS=	yes

.include <bsd.port.mk>
