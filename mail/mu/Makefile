# Created by: rea@FreeBSD.org
# $FreeBSD$

PORTNAME=	mu
PORTVERSION=	0.9.16
DISTVERSIONPREFIX=	v
CATEGORIES=	mail

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Mail searching frontend for Xapian

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libxapian.so:databases/xapian-core \
		libgmime-2.6.so:mail/gmime26

USE_GITHUB=	yes
GH_ACCOUNT=	djcb

USES=		autoreconf gmake libtool makeinfo pkgconfig
USE_GNOME=	glib20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-silent-rules --disable-gtk --disable-mu4e
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		DOCS GUILE
OPTIONS_SUB=		yes

GUILE_LIB_DEPENDS=	libguile-2.0.so:lang/guile2
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
