PORTNAME=	libaccounts-glib
DISTVERSION=	1.27
PORTREVISION=	1
CATEGORIES=	net-im
DIST_SUBDIR=	KDE/${GL_ACCOUNT}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Accounts and SSO framework for Linux and POSIX based platforms
WWW=		https://gitlab.com/accounts-sso

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	checkmk:devel/check

USES=		gnome meson pathfix pkgconfig sqlite:3 vala:build
USE_GITLAB=	yes
GL_ACCOUNT=	accounts-sso
GL_TAGNAME=	26c54322304e9df598b2ba67427433a2e68b823e
USE_GNOME=	introspection libxml2
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	-Dtests=false

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

DOCS_BUILD_DEPENDS=	gtkdocize:textproc/gtk-doc
DOCS_MESON_TRUE=	docs

.include <bsd.port.mk>
