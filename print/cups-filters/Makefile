# $FreeBSD$

PORTNAME=	cups-filters
PORTVERSION=	1.25.12
CATEGORIES=	print
MASTER_SITES=	https://www.openprinting.org/download/cups-filters/

MAINTAINER=	tijl@FreeBSD.org
COMMENT=	Additional backends, filters and other software for CUPS

LICENSE=	BSD4CLAUSE GPLv2 GPLv2+ GPLv3 GPLv3+ LGPL20 LGPL21+ MIT
LICENSE_COMB=	multi

LIB_DEPENDS=	liblcms2.so:graphics/lcms2 \
		libqpdf.so:print/qpdf \
		libcupsimage.so:print/cups \
		libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig

USES=		compiler:c++11-lib cpe gmake gnome iconv libtool localbase \
		pkgconfig shebangfix tar:xz
USE_GNOME=	glib20
USE_LDCONFIG=	yes
USE_RC_SUBR=	cups_browsed

CONFLICTS=	cups-pstoraster-[0-9]* foomatic-filters-[0-9]*

CPE_VENDOR=	linuxfoundation
SHEBANG_FILES=	filter/braille/drivers/generic/brftoembosser.in \
		filter/braille/drivers/index/imageubrltoindexv3.in \
		filter/braille/drivers/index/imageubrltoindexv4.in \
		filter/braille/drivers/index/textbrftoindexv3.in \
		filter/braille/filters/brftopagedbrf.in \
		filter/braille/filters/imagetobrf.in \
		filter/braille/filters/liblouis1.defs.gen.in \
		filter/braille/filters/musicxmltobrf.in \
		filter/braille/filters/texttobrf.in \
		filter/braille/filters/vectortobrf.in \
		filter/braille/filters/vectortopdf.in

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-shell=/bin/sh --with-pdftops-path=${LOCALBASE}/bin/pdftops
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE= 		BRAILLE COLORD DOCS
OPTIONS_GROUP=			FILTERS CUPS_BROWSED
OPTIONS_GROUP_FILTERS=		GHOSTSCRIPT IMAGES MUPDF POPPLER
OPTIONS_GROUP_CUPS_BROWSED=	AVAHI LDAP
OPTIONS_SINGLE= 		PDFTOPS
OPTIONS_SINGLE_PDFTOPS= 	PSGHOSTSCRIPT PSHYBRID PSMUPDF PSPOPPLER
OPTIONS_DEFAULT=		COLORD GHOSTSCRIPT IMAGES AVAHI LDAP PSHYBRID
OPTIONS_SUB=			yes

BRAILLE_CONFIGURE_ENABLE=	braille
BRAILLE_DESC=			Braille embosser support
BRAILLE_BUILD_DEPENDS=		bash:shells/bash
BRAILLE_LIB_DEPENDS=		liblouis.so:devel/liblouis \
#				liblouisutdml.so:devel/liblouisutdml
BRAILLE_RUN_DEPENDS=		convert:graphics/ImageMagick6 \
				pdftotext:graphics/poppler-utils \
				bash:shells/bash

COLORD_CONFIGURE_ENABLE=	dbus
COLORD_DESC=			Get ICC color profiles from colord (via D-Bus)
COLORD_LIB_DEPENDS=		libdbus-1.so:devel/dbus
COLORD_RUN_DEPENDS=		colord>0:graphics/colord

# Filters

FILTERS_DESC=			Filters

GHOSTSCRIPT_CONFIGURE_ENABLE=	ghostscript
GHOSTSCRIPT_DESC=		PS-to-PDF and PS/PDF-to-raster using Ghostscript
GHOSTSCRIPT_USES=		ghostscript

IMAGES_CONFIGURE_ENABLE=	imagefilters
IMAGES_CONFIGURE_WITH=		jpeg png tiff
IMAGES_DESC=			Accept JPEG, PNG, and TIFF files as input
IMAGES_LIB_DEPENDS=		libtiff.so:graphics/tiff \
				libpng.so:graphics/png
IMAGES_USES=			jpeg

MUPDF_BUILD_DEPENDS=		mutool:graphics/mupdf
MUPDF_RUN_DEPENDS=		mutool:graphics/mupdf
MUPDF_CONFIGURE_ENABLE= 	mutool
MUPDF_DESC=			PDF-to-raster using MuPDF

POPPLER_CONFIGURE_ENABLE=	poppler
POPPLER_DESC=			PDF-to-raster using Poppler
POPPLER_LIB_DEPENDS=		libpoppler-cpp.so:graphics/poppler

# cups-browsed(8) options

CUPS_BROWSED_DESC=		cups-browsed(8) options

AVAHI_CONFIGURE_ENABLE= 	avahi
AVAHI_CONFIGURE_OFF=		--with-browseremoteprotocols=cups
AVAHI_CONFIGURE_ON=		--with-browseremoteprotocols="dnssd cups"
AVAHI_DESC=			Discover Zeroconf/Bonjour network printers
AVAHI_LIB_DEPENDS=		libavahi-client.so:net/avahi-app
AVAHI_SUB_LIST= 		AVAHI_DAEMON=avahi_daemon
AVAHI_SUB_LIST_OFF=		AVAHI_DAEMON=

LDAP_CONFIGURE_ENABLE=		ldap
LDAP_DESC=			Get printer locations from an LDAP server
LDAP_USE=			OPENLDAP=yes

# Default PDF-to-PostScript renderer

PDFTOPS_DESC=			Default PDF-to-PostScript renderer

PSGHOSTSCRIPT_CONFIGURE_ON=	--with-pdftops=gs
PSGHOSTSCRIPT_DESC=		Ghostscript gs(1)
PSGHOSTSCRIPT_IMPLIES=		GHOSTSCRIPT

PSHYBRID_BUILD_DEPENDS= 	pdftops:graphics/poppler-utils
PSHYBRID_RUN_DEPENDS=		pdftops:graphics/poppler-utils
PSHYBRID_CONFIGURE_ON=		--with-pdftops=hybrid
PSHYBRID_DESC=			Ghostscript or Poppler depending on printer
PSHYBRID_IMPLIES=		GHOSTSCRIPT

PSMUPDF_CONFIGURE_ON=		--with-pdftops=mupdf
PSMUPDF_DESC=			MuPDF mutool(1)
PSMUPDF_IMPLIES=		MUPDF

PSPOPPLER_BUILD_DEPENDS=	pdftops:graphics/poppler-utils
PSPOPPLER_RUN_DEPENDS=		pdftops:graphics/poppler-utils
PSPOPPLER_CONFIGURE_ON= 	--with-pdftops=pdftops
PSPOPPLER_DESC= 		Poppler pdftops(1)

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|' \
		-e 's|README.gz|README|' \
		${WRKSRC}/utils/cups-browsed.8 \
		${WRKSRC}/utils/cups-browsed.conf.5 \
		${WRKSRC}/utils/driverless.1

.include <bsd.port.mk>
