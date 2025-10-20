PORTNAME=	mu
DISTVERSIONPREFIX=	v
DISTVERSION=	1.12.13
CATEGORIES=	mail

MAINTAINER=	rwn@mailo.com
COMMENT=	Mail searching frontend for Xapian
WWW=		https://www.djcbsoftware.nl/code/mu/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libxapian.so:databases/xapian-core \
		libgmime-3.0.so:mail/gmime30 \
		libcld2.so:devel/cld2

BUILD_DEPENDS=	emacs:editors/emacs

USES=		meson compiler:c++17-lang gnome makeinfo pkgconfig readline shebangfix python:3.8+
USE_GITHUB=	yes
GH_ACCOUNT=	djcb

USE_GNOME=	glib20
USE_LDCONFIG=	yes

SHEBANG_GLOB=	*.py

OPTIONS_DEFINE=		DOCS GUILE MU4E
OPTIONS_DEFAULT=	DOCS GUILE MU4E
OPTIONS_SUB=		yes

GUILE_USES=		guile:3.0
GUILE_MESON_ENABLED=	guile
GUILE_INFO=		mu-guile mu-scm

MU4E_DESC=		Install mu4e e-mail client for emacs
MU4E_INFO=		mu4e

post-stage-MU4E-off:
	${RM} ${STAGEDIR}${PREFIX}/share/info/mu4e.info

post-stage-GUILE-off:
	${RM} ${STAGEDIR}${PREFIX}/share/info/mu-guile.info
	${RM} ${STAGEDIR}${PREFIX}/share/info/mu-scm.info

.include <bsd.port.mk>
