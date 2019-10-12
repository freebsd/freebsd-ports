# $FreeBSD$

PORTNAME=	libudisks
PORTVERSION=	2.8.4
# Obviates the need to specify GH_TAGNAME and repeat the version number later
DISTVERSIONPREFIX=	udisks-
CATEGORIES=	sysutils

MAINTAINER=	pauamma@gundo.com
COMMENT=	Library to manipulate storage devices, from udisks

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/COPYING

# pkaction takes care of libpolkit-agent-1 and libpolkit-gobject-1
# which are what we really want (see UDISKSCTL_LIB_DEPENDS).
BUILD_DEPENDS=	bash:shells/bash \
		gtkdocize:textproc/gtk-doc \
		pkaction:sysutils/polkit

# For some reason, configure wants autopoint from gettext-tools even when
# NLS is disabled.
USES=		autoreconf:build gettext-tools:build gmake gnome \
		libtool:build pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	storaged-project
GH_PROJECT=	udisks

USE_GNOME=	glib20 introspection

USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
# config.status errors out without --disable-dependency-tracking, with or
# without USES=gmake. --with-libintl-prefix is needed because otherwise
# configure won't find libintl when PREFIX != LOCALBASE.
CONFIGURE_ARGS=	--disable-daemon --disable-dependency-tracking \
		--with-libintl-prefix=${LOCALBASE}

OPTIONS_DEFINE=	UDISKSCTL NLS DOCS
OPTIONS_DEFAULT=	UDISKSCTL NLS DOCS
OPTIONS_SUB=	yes
DOCS_CONFIGURE_ENABLE=	gtk-doc
NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext-runtime
UDISKSCTL_DESC=	Install udisksctl command line utility
UDISKSCTL_LIB_DEPENDS=	libpolkit-agent-1.so:sysutils/polkit \
			libpolkit-gobject-1.so:sysutils/polkit

pre-configure:
	cd ${WRKSRC} && ${SETENV} NOCONFIGURE=1 ./autogen.sh

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libudisks2.so.0.0.0

post-install-UDISKSCTL-on:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/udisksctl

# Pacify "make stage-qa".
post-install-UDISKSCTL-off:
	${RM} ${STAGEDIR}${PREFIX}/bin/udisksctl

.include <bsd.port.mk>
