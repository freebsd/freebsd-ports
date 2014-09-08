# Created by: rea@FreeBSD.org
# $FreeBSD$

PORTNAME=	mu
PORTVERSION=	0.9.9.6
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	GH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mail searching frontend for Xapian

LICENSE=	GPLv3

LIB_DEPENDS=	libxapian.so:${PORTSDIR}/databases/xapian-core \
		libgmime-2.6.so:${PORTSDIR}/mail/gmime26

USE_GITHUB=	yes
GH_ACCOUNT=	djcb
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	${PORTVERSION:S/^/v/}
GH_COMMIT=	ab58307

USES=		gmake libtool makeinfo pkgconfig
USE_GNOME=	glib20
USE_AUTOTOOLS=	libtoolize aclocal autoheader automake autoconf
AUTOMAKE_ARGS=	--add-missing
CONFIGURE_ARGS=	--disable-silent-rules --disable-gtk

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=		GUILE MU4E
OPTIONS_SUB=		yes

GUILE_LIB_DEPENDS=	libguile-2.0.so:${PORTSDIR}/lang/guile2
GUILE_USE=		ldconfig=yes
GUILE_CONFIGURE_ENABLE=	guile
GUILE_INFO=		mu-guile
MU4E_DESC=		Email cluent for Emacs
MU4E_USE=		emacs=yes
MU4E_CONFIGURE_ENABLE=	mu4e
MU4E_INFO=		mu4e

post-install:
	(cd ${FILESDIR} && ${INSTALL_SCRIPT} mu-ask \
		${STAGEDIR}${PREFIX}/bin)

.include <bsd.port.mk>
