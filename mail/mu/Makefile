PORTNAME=	mu
PORTVERSION=	1.8.13
PORTREVISION=	3
DISTVERSIONPREFIX=	v
CATEGORIES=	mail

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Mail searching frontend for Xapian
WWW=		https://www.djcbsoftware.nl/code/mu/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libxapian.so:databases/xapian-core \
		libgmime-3.0.so:mail/gmime30 \
		libgc-threaded.so:devel/boehm-gc-threaded \
		libjson-glib-1.0.so:devel/json-glib

USES=		autoreconf compiler:c++14-lang gettext-runtime gmake gnome \
		libtool makeinfo pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	djcb
USE_GNOME=	glib20

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	--disable-mu4e
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		DOCS GUILE
OPTIONS_DEFAULT=	DOCS GUILE
OPTIONS_SUB=		yes

GUILE_USES=		guile:3.0
GUILE_USE=		ldconfig=yes
GUILE_CONFIGURE_ENABLE=	guile
GUILE_INFO=		mu-guile

post-install:
	cd ${FILESDIR} && ${INSTALL_SCRIPT} mu-ask \
	    ${STAGEDIR}${PREFIX}/bin

post-install-GUILE-on:
	${FIND} ${STAGEDIR}${PREFIX}/lib -name "*.so.*" -type f | \
	    ${XARGS} ${STRIP_CMD}

.include <bsd.port.mk>
