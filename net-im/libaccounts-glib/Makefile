# Created by: Tobias C. Berner <tcberner@gmail.com>
# $FreeBSD$

PORTNAME=	libaccounts-glib
PORTVERSION=	1.21
PORTREVISION=	2
CATEGORIES=	net-im
DIST_SUBDIR=	KDE/${GL_ACCOUNT}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Accounts and SSO framework for Linux and POSIX based platforms

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib

GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--disable-tests
INSTALL_TARGET=	install-strip

USES=		autoreconf gmake gnome libtool pathfix pkgconfig python sqlite:3
USE_GNOME=	pygobject3 introspection libxml2
USE_PYTHON=	py3kplist
CFLAGS_powerpc64=	-Wno-error

# GitLab variables.
USE_GITLAB=	yes
GL_ACCOUNT=	accounts-sso
GL_COMMIT=	00254a604a7c7bd38c41794a80ad8930e90f21aa

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

DOCS_BUILD_DEPENDS=	gtkdocize:textproc/gtk-doc
DOCS_CONFIGURE_ENABLE=	gtk-doc

# Run gtdocize as done in autogen.sh. When DOCS is off, the
# unexpanded GTK_DOC_CHECK macro remains, so comment it out instead.
# Also drop the docs/ files from AC_CONFIG_FILES.
pre-configure-DOCS-on:
	cd ${CONFIGURE_WRKSRC} && gtkdocize --copy --flavour no-tmpl

pre-configure-DOCS-off:
	@${TOUCH} ${WRKSRC}/gtk-doc.make
	@${REINPLACE_CMD} -e 's/docs//g' ${WRKSRC}/Makefile.am
	@${REINPLACE_CMD} -e 's/^GTK_DOC_CHECK/# GTK_DOC_CHECK/' \
		-e '/^.docs\//d' ${WRKSRC}/configure.ac

.include <bsd.port.mk>
