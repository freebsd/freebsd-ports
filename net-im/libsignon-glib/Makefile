# $FreeBSD$

PORTNAME=	libsignon-glib
PORTVERSION=	1.14
PORTREVISION=	2
CATEGORIES=	net-im
DIST_SUBDIR=	KDE/${GL_ACCOUNT}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	GLib-based client library for applications handling account authentication

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gtkdocize:textproc/gtk-doc \
		signond:sysutils/signon-qt5
RUN_DEPENDS=	signond:sysutils/signon-qt5

GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--disable-tests --enable-gtk-doc

USES=		autoreconf gmake gnome libtool pathfix pkgconfig python tar:bz2
USE_GNOME=	introspection pygobject3
USE_PYTHON=	py3kplist

PATHFIX_MAKEFILEIN=	Makefile.am

# gitlab variables
USE_GITLAB=	yes
GL_ACCOUNT=	accounts-sso
GL_COMMIT=	4e85baaf483268d04bbf835bebeac4ae30c7c327
CFLAGS+=	-Wno-error

# Run gtdocize as done in autogen.sh
pre-configure:
	cd ${CONFIGURE_WRKSRC} && gtkdocize --copy --flavour no-tmpl

.include <bsd.port.mk>
