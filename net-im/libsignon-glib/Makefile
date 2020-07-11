# $FreeBSD$

PORTNAME=	libsignon-glib
DISTVERSION=	2.1
CATEGORIES=	net-im
DIST_SUBDIR=	KDE/${GL_ACCOUNT}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	GLib-based client library for applications handling account authentication

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	signond:sysutils/signon-qt5 \
		vapigen:lang/vala
RUN_DEPENDS=	signond:sysutils/signon-qt5


USES=		gnome libtool meson pathfix pkgconfig python tar:bz2
USE_GNOME=	introspection pygobject3
USE_PYTHON=	py3kplist

# gitlab variables
USE_GITLAB=	yes
GL_ACCOUNT=	accounts-sso
GL_COMMIT=	7f9f10a2e7533b74eaf027b26de48818326a1dcf
CFLAGS+=	-Wno-error

CONFIGURE_ARGS=	-Dtests=false

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

DOCS_BUILD_DEPENDS=	gtkdocize:textproc/gtk-doc
DOCS_MESON_TRUE=	docs

BINARY_ALIAS=	python=${PYTHON_CMD}

post-extract:
	# Fix broken tar ball
	${CP} ${WRKSRC}/libsignon-glib/*.xml ${WRKSRC}/libsignon-glib/interfaces

.include <bsd.port.mk>
