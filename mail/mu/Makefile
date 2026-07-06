PORTNAME=	mu
DISTVERSION=	1.14.2
CATEGORIES=	mail
MASTER_SITES=	https://github.com/djcb/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	rwn@mailo.com
COMMENT=	Mail searching frontend for Xapian
WWW=		https://www.djcbsoftware.nl/code/mu/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	cli11>0:devel/cli11
LIB_DEPENDS=	libxapian.so:databases/xapian-core14 \
		libfmt.so:devel/libfmt \
		libgmime-3.0.so:mail/gmime30

USES=		compiler:c++20-lang gnome meson pkgconfig python:build \
		readline shebangfix tar:xz
USE_GNOME=	glib20
SHEBANG_FILES=	build-aux/date.py

OPTIONS_DEFINE=		CLD2 DOCS GUILE MANPAGES MU4E
OPTIONS_DEFAULT=	MANPAGES MU4E
OPTIONS_SUB=		yes

CLD2_DESC=		Install CL2 support
GUILE_DESC=		Install guile support
MU4E_DESC=		Install mu4e e-mail client for emacs

CLD2_LIB_DEPENDS=	libcld2.so:devel/cld2
CLD2_MESON_ENABLED=	cld2

GUILE_USES=		guile:3.0
GUILE_MESON_ENABLED=	scm

MANPAGES_BUILD_DEPENDS=	emacs:editors/emacs@nox

MU4E_BUILD_DEPENDS=	emacs:editors/emacs@nox

.include <bsd.port.mk>
