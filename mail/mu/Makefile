PORTNAME=	mu
DISTVERSIONPREFIX=	v
DISTVERSION=	1.12.13
CATEGORIES=	mail

MAINTAINER=	rwn@mailo.com
COMMENT=	Mail searching frontend for Xapian
WWW=		https://www.djcbsoftware.nl/code/mu/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	emacs:editors/emacs@nox

LIB_DEPENDS=	libxapian.so:databases/xapian-core \
		libfmt.so:devel/libfmt \
		libgmime-3.0.so:mail/gmime30

USES=		meson compiler:c++17-lang gnome \
		makeinfo pkgconfig \
		readline shebangfix python:build

USE_GITHUB=	yes
GH_ACCOUNT=	djcb

USE_GNOME=	glib20

SHEBANG_GLOB=	*.py

OPTIONS_DEFINE=		DOCS MU4E GUILE CLD2
OPTIONS_DEFAULT=	MU4E
OPTIONS_SUB=		yes

MU4E_DESC=		Install mu4e e-mail client for emacs
GUILE_DESC=		Install guile support
CLD2_DESC=		Install CL2 support

MU4E_RUN_DEPENDS=	emacs:editors/emacs
MU4E_INFO=		mu4e

GUILE_USES=		guile:3.0
GUILE_MESON_ENABLED=	guile
GUILE_INFO=		mu-guile mu-scm

CLD2_MESON_ENABLED=	cld2
CLD2_LIB_DEPENDS=	libcld2.so:devel/cld2

post-stage-GUILE-off:
	${RM} ${STAGEDIR}${PREFIX}/share/info/mu-guile.info
	${RM} ${STAGEDIR}${PREFIX}/share/info/mu-scm.info

post-stage-MU4E-off:
	${RM} ${STAGEDIR}${PREFIX}/share/info/mu4e.info

.include <bsd.port.mk>
