PORTNAME=	libudisks
DISTVERSION=	2.10.2
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/storaged-project/udisks/releases/download/udisks-${DISTVERSION}/
DISTNAME=	udisks-${DISTVERSION}

MAINTAINER=	pauamma@gundo.com
COMMENT=	Library to manipulate storage devices, from udisks
WWW=		https://www.freedesktop.org/wiki/Software/udisks/

LICENSE=	GPLv2+ LGPL20+
# LGPL for libudisks, GPL for the command-line utilities.
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING

# pkaction takes care of libpolkit-agent-1 and libpolkit-gobject-1
# which are what we really want (see UDISKSCTL_LIB_DEPENDS).
BUILD_DEPENDS=	bash:shells/bash \
		pkaction:sysutils/polkit

# For some reason, configure wants autopoint from gettext-tools even when
# NLS is disabled.
USES=		gettext-tools:build gmake gnome libtool pathfix pkgconfig \
		tar:bz2
USE_GNOME=	glib20
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
# --with-libintl-prefix is needed because otherwise
# configure won't find libintl when PREFIX != LOCALBASE.
CONFIGURE_ARGS=	--disable-daemon \
		--enable-introspection=no \
		--with-html-dir=${PREFIX}/share/doc \
		--with-libintl-prefix=${LOCALBASE}

DOCSDIR=	${PREFIX}/share/doc/udisks2

PLIST_SUB=	DISTVERSION=${DISTVERSION}
PORTDOCS=	*

OPTIONS_DEFINE=		UDISKSCTL NLS DOCS
OPTIONS_DEFAULT=	UDISKSCTL NLS DOCS
OPTIONS_SUB=		yes

UDISKSCTL_DESC=		Install udisksctl command line utility

NLS_USES=		gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

UDISKSCTL_BUILD_DEPENDS=	gtkdocize:textproc/gtk-doc \
				xsltproc:textproc/libxslt
UDISKSCTL_LIB_DEPENDS=		libpolkit-agent-1.so:sysutils/polkit \
				libpolkit-gobject-1.so:sysutils/polkit
UDISKSCTL_CONFIGURE_ENABLE=	man

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libudisks2.so

post-install-UDISKSCTL-on:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/udisksctl

# Pacify "make stage-qa".
post-install-UDISKSCTL-off:
	${RM} ${STAGEDIR}${PREFIX}/bin/udisksctl

.include <bsd.port.mk>
