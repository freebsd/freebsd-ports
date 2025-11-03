PORTNAME=	mu
DISTVERSION=	1.12.13
CATEGORIES=	mail
MASTER_SITES=	https://github.com/djcb/${PORTNAME}/releases/download/v${DISTVERSION}/

PATCH_SITES=	https://github.com/djcb/mu/commit/
PATCHFILES=	0a4fabbf446d15b538600dfe7d879cad70ce941e.patch:-p1

MAINTAINER=	rwn@mailo.com
COMMENT=	Mail searching frontend for Xapian
WWW=		https://www.djcbsoftware.nl/code/mu/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libxapian.so:databases/xapian-core \
		libfmt.so:devel/libfmt \
		libgmime-3.0.so:mail/gmime30

USES=		compiler:c++17-lang gnome meson pkgconfig python:build \
		readline shebangfix tar:xz
SHEBANG_FILES=	build-aux/date.py
USE_GNOME=	glib20

OPTIONS_DEFINE=		CLD2 DOCS GUILE MANPAGES MU4E
OPTIONS_DEFAULT=	MANPAGES MU4E
OPTIONS_SUB=		yes

CLD2_DESC=		Install CL2 support
GUILE_DESC=		Install guile support
MU4E_DESC=		Install mu4e e-mail client for emacs

CLD2_LIB_DEPENDS=	libcld2.so:devel/cld2
CLD2_MESON_ENABLED=	cld2

GUILE_USES=		guile:3.0
GUILE_MESON_ENABLED=	guile

MANPAGES_BUILD_DEPENDS=	emacs:editors/emacs@nox

MU4E_RUN_DEPENDS=	emacs:editors/emacs

.include <bsd.port.mk>
