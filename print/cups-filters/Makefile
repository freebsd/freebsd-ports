# $FreeBSD$

PORTNAME=	cups-filters
PORTVERSION=	1.13.5
CATEGORIES=	print
MASTER_SITES=	http://www.openprinting.org/download/cups-filters/

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	Additional backends, filters and other software for CUPS

LICENSE=	BSD4CLAUSE GPLv2 GPLv2+ GPLv3 GPLv3+ LGPL20 LGPL21+ MIT
LICENSE_COMB=	multi

LIB_DEPENDS=	liblcms2.so:graphics/lcms2 \
		libqpdf.so:print/qpdf \
		libcupsimage.so:print/cups \
		libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libpoppler.so:graphics/poppler

CONFLICTS=	cups-pstoraster-[0-9]* foomatic-filters-[0-9]*

USES=		compiler:c++11-lib cpe gettext ghostscript gmake gnome libtool \
		iconv pathfix pkgconfig shebangfix tar:xz
CPE_VENDOR=	linuxfoundation
SHEBANG_FILES=	filter/braille/drivers/generic/brftoembosser.in \
		filter/braille/drivers/index/imageubrltoindexv3.in \
		filter/braille/drivers/index/imageubrltoindexv4.in \
		filter/braille/drivers/index/textbrftoindexv3.in \
		filter/braille/filters/imagetobrf.in \
		filter/braille/filters/liblouis1.defs.gen.in \
		filter/braille/filters/texttobrf.in
USE_GNOME=	glib20
USE_RC_SUBR=	cups_browsed
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-shell=/bin/sh
INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib ${ICONV_LIB}
USE_LDCONFIG=	yes

OPTIONS_DEFINE=			BRAILLE COLORD DOCS IJS IMAGEFILTERS
OPTIONS_GROUP=			CUPS_BROWSED
OPTIONS_GROUP_CUPS_BROWSED=	AVAHI LDAP
OPTIONS_SINGLE=			PDFTOPS_RENDERER
OPTIONS_SINGLE_PDFTOPS_RENDERER=GS HYBRID PDFTOPS MUPDF
OPTIONS_DEFAULT=		AVAHI COLORD HYBRID IJS IMAGEFILTERS
OPTIONS_SUB=			yes

BRAILLE_CONFIGURE_ENABLE=	braille
BRAILLE_DESC=			Braille embosser support
BRAILLE_BUILD_DEPENDS=		bash:shells/bash
BRAILLE_LIB_DEPENDS=		liblouis.so:devel/liblouis \
#				liblouisutdml.so:devel/liblouisutdml
BRAILLE_RUN_DEPENDS=		convert:graphics/ImageMagick \
				pdftotext:graphics/poppler-utils \
				bash:shells/bash

COLORD_CONFIGURE_ENABLE=	dbus
COLORD_DESC=			Get ICC color profiles from colord (via D-Bus)
COLORD_LIB_DEPENDS=		libdbus-1.so:devel/dbus
COLORD_RUN_DEPENDS=		colord>0:graphics/colord

IJS_CONFIGURE_ENABLE=		ijs
IJS_DESC=			Support PPD files that use pdftoijs
IJS_LIB_DEPENDS=		libijs.so:print/libijs

IMAGEFILTERS_CONFIGURE_ENABLE=	imagefilters
IMAGEFILTERS_CONFIGURE_WITH=	jpeg png tiff
IMAGEFILTERS_DESC=		Support printing image files
IMAGEFILTERS_LIB_DEPENDS=	libtiff.so:graphics/tiff \
				libpng.so:graphics/png
IMAGEFILTERS_USES=		jpeg

# cups-browsed(8) options

AVAHI_CONFIGURE_ENABLE=		avahi
AVAHI_CONFIGURE_OFF=		--with-browseremoteprotocols=cups
AVAHI_CONFIGURE_ON=		--with-browseremoteprotocols="dnssd cups"
AVAHI_LIB_DEPENDS=		libavahi-client.so:net/avahi-app
AVAHI_SUB_LIST=			AVAHI_DAEMON=avahi_daemon
AVAHI_SUB_LIST_OFF=		AVAHI_DAEMON=

CUPS_BROWSED_DESC=		cups-browsed(8) options

LDAP_CONFIGURE_ENABLE=		ldap
LDAP_USE=			OPENLDAP=yes

# Default PDF-to-PostScript renderer

GS_CONFIGURE_ON=		--with-pdftops=gs
GS_DESC=			Ghostscript gs(1)

HYBRID_BUILD_DEPENDS=		pdftops:graphics/poppler-utils
HYBRID_RUN_DEPENDS=		pdftops:graphics/poppler-utils
HYBRID_CONFIGURE_ON=		--with-pdftops=hybrid --with-pdftops-path=${LOCALBASE}/bin/pdftops
HYBRID_DESC=			Ghostscript or Poppler depending on printer

PDFTOPS_BUILD_DEPENDS=		pdftops:graphics/poppler-utils
PDFTOPS_RUN_DEPENDS=		pdftops:graphics/poppler-utils
PDFTOPS_CONFIGURE_ON=		--with-pdftops=pdftops --with-pdftops-path=${LOCALBASE}/bin/pdftops
PDFTOPS_DESC=			Poppler pdftops(1)

MUPDF_BUILD_DEPENDS=		mutool:graphics/mupdf
MUPDF_RUN_DEPENDS=		mutool:graphics/mupdf
MUPDF_CONFIGURE_ON=		--with-pdftops=mupdf
MUPDF_CONFIGURE_ENABLE=		mutool
MUPDF_DESC=			MuPDF renderer

PDFTOPS_RENDERER_DESC=		Default PDF-to-PostScript renderer

post-patch:
	@${REINPLACE_CMD} 's:-std=c++0x:-std=c++11:' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|' \
		-e 's|README.gz|README|' \
		${WRKSRC}/utils/cups-browsed.8 \
		${WRKSRC}/utils/cups-browsed.conf.5

.include <bsd.port.mk>
