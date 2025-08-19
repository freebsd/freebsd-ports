PORTNAME=	cups-filters
PORTVERSION=	1.28.17
PORTREVISION=	10
CATEGORIES=	print
MASTER_SITES=	https://github.com/OpenPrinting/cups-filters/releases/download/${DISTVERSION}/

PATCH_SITES=	https://github.com/OpenPrinting/cups-filters/commit/
PATCHFILES=	9799398713b941557642d0b2bdbef360837ece0c.diff:-p1 \
		93e60d3df358c0ae6f3dba79e1c9684657683d89.diff:-p1 \
		d72184e725591f10e2b404b36fe3bf5bc304a299.diff:-p1 \
		e25fd59a7daed00b6a9f235bd5818116fca28e30.diff:-p1 \
		0cce0968980e8fdd9053cba436a66246b2303a84.diff:-p1 \
		7b191cb1d4d0fc97ccbbd0fe43eec2544fe0c11e.diff:-p1 \
		7992eb7c6e4abeffd766f54c98cbb2cbb45c5c04.diff:-p1 \
		770ec883e68e505c1d1856a42b78f9323dc326a6.diff:-p1 \
		2076627d33477212f21352ad39e9d305adb63af3.diff:-p1 \
		10fb02eaaee52e0be9b16917b38aa8ec5bddd87f.diff:-p1 \
		b7461ec2a8d1f2aa627b24e01e118ec4cca78ec0.diff:-p1 \
		6fd2bdfbdce76149af531ce9fca9062304238451.patch:-p1 \
		3534e01cb41ddfa61ac78d32052b8822df71d97d.patch:-p1 \
		b378f09c9b8aaa8dccb5eb557938b30da874101d.patch:-p1 \
		c8522bb128546a1910bca538a504a2c9363ebb22.patch:-p1 \
		dccb537afe85af3ea01e3f274974d9d1f53f8e14.patch:-p1 \
		d5cc66b410a3246e74b71f718e86504d08e4bfa3.patch:-p1 \
		86b060d2ac20d6dee757c609286cfaaa17d65428.patch:-p1 \
		d43610f82e1757b45925a8830ac297ff9dc4abca.patch:-p1

MAINTAINER=	tijl@FreeBSD.org
COMMENT=	Additional backends, filters and other software for CUPS
WWW=		https://wiki.linuxfoundation.org/openprinting/cups-filters

LICENSE=	BSD4CLAUSE GPLv2 GPLv2+ GPLv3 GPLv3+ LGPL20 LGPL21+ MIT
LICENSE_COMB=	multi

BUILD_DEPENDS=	${LOCALBASE}/share/fonts/dejavu/DejaVuSans.ttf:x11-fonts/dejavu
LIB_DEPENDS=	liblcms2.so:graphics/lcms2 \
		libqpdf.so:print/qpdf \
		libcups.so:print/cups \
		libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig

USES=		autoreconf compiler:c++11-lib cpe gettext-tools gmake gnome \
		iconv libtool localbase pkgconfig shebangfix tar:xz
USE_GNOME=	glib20
USE_LDCONFIG=	yes
USE_RC_SUBR=	cups_browsed

CONFLICTS=	foomatic-filters # bin/foomatic-rip

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
CONFIGURE_ARGS=	--with-shell=/bin/sh \
		--with-pdftops-path=${LOCALBASE}/bin/pdftops \
		--with-test-font-path=${LOCALBASE}/share/fonts/dejavu/DejaVuSans.ttf
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=			BRAILLE COLORD DOCS
OPTIONS_GROUP=			FILTERS CUPS_BROWSED
OPTIONS_GROUP_FILTERS=		GHOSTSCRIPT IMAGES MUPDF POPPLER
OPTIONS_GROUP_CUPS_BROWSED=	AVAHI LDAP
OPTIONS_SINGLE=			PDFTOPS
OPTIONS_SINGLE_PDFTOPS=		PSGHOSTSCRIPT PSHYBRID PSMUPDF PSPOPPLER
OPTIONS_DEFAULT=		COLORD GHOSTSCRIPT IMAGES POPPLER AVAHI LDAP \
				PSHYBRID
OPTIONS_SUB=			yes

BRAILLE_CONFIGURE_ENABLE=	braille
BRAILLE_DESC=			Braille embosser support
BRAILLE_USES=			magick:run
BRAILLE_BUILD_DEPENDS=		bash:shells/bash
BRAILLE_LIB_DEPENDS=		liblouis.so:devel/liblouis \
#				liblouisutdml.so:devel/liblouisutdml
BRAILLE_RUN_DEPENDS=		pdftotext:graphics/poppler-utils \
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

IMAGES_CONFIGURE_ENABLE=	exif imagefilters
IMAGES_CONFIGURE_WITH=		jpeg png tiff
IMAGES_DESC=			Accept JPEG, PNG, and TIFF files as input
IMAGES_LIB_DEPENDS=		libexif.so:graphics/libexif \
				libpng.so:graphics/png \
				libtiff.so:graphics/tiff
IMAGES_USES=			jpeg

MUPDF_BUILD_DEPENDS=		mutool:graphics/mupdf
MUPDF_RUN_DEPENDS=		mutool:graphics/mupdf
MUPDF_CONFIGURE_ENABLE=		mutool
MUPDF_DESC=			PDF-to-raster using MuPDF

POPPLER_CONFIGURE_ENABLE=	poppler
POPPLER_DESC=			PDF-to-raster using Poppler
POPPLER_LIB_DEPENDS=		libpoppler-cpp.so:graphics/poppler

# cups-browsed(8) options

CUPS_BROWSED_DESC=		cups-browsed(8) options

AVAHI_CONFIGURE_ENABLE=		avahi
AVAHI_CONFIGURE_OFF=		--with-browseremoteprotocols=none
AVAHI_CONFIGURE_ON=		--with-browseremoteprotocols=dnssd
AVAHI_DESC=			Discover Zeroconf/Bonjour network printers
AVAHI_LIB_DEPENDS=		libavahi-client.so:net/avahi-app
AVAHI_SUB_LIST=			AVAHI_DAEMON=avahi_daemon
AVAHI_SUB_LIST_OFF=		AVAHI_DAEMON=

LDAP_CONFIGURE_ENABLE=		ldap
LDAP_DESC=			Get printer locations from an LDAP server
LDAP_USES=			ldap

# Default PDF-to-PostScript renderer

PDFTOPS_DESC=			Default PDF-to-PostScript renderer

PSGHOSTSCRIPT_CONFIGURE_ON=	--with-pdftops=gs
PSGHOSTSCRIPT_DESC=		Ghostscript gs(1)
PSGHOSTSCRIPT_IMPLIES=		GHOSTSCRIPT

PSHYBRID_BUILD_DEPENDS=		pdftops:graphics/poppler-utils
PSHYBRID_RUN_DEPENDS=		pdftops:graphics/poppler-utils
PSHYBRID_CONFIGURE_ON=		--with-pdftops=hybrid
PSHYBRID_DESC=			Ghostscript or Poppler depending on printer
PSHYBRID_IMPLIES=		GHOSTSCRIPT

PSMUPDF_CONFIGURE_ON=		--with-pdftops=mupdf
PSMUPDF_DESC=			MuPDF mutool(1)
PSMUPDF_IMPLIES=		MUPDF

PSPOPPLER_BUILD_DEPENDS=	pdftops:graphics/poppler-utils
PSPOPPLER_RUN_DEPENDS=		pdftops:graphics/poppler-utils
PSPOPPLER_CONFIGURE_ON=		--with-pdftops=pdftops
PSPOPPLER_DESC=			Poppler pdftops(1)

.include <bsd.port.pre.mk>

#.if ${OPSYS} == FreeBSD
.if ${COMPILER_TYPE} == clang
CFLAGS+=	-Wno-error=dynamic-exception-spec
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|' \
		-e 's|/etc|${PREFIX}&|' \
		-e 's|README.gz|README|' \
		${WRKSRC}/utils/cups-browsed.8 \
		${WRKSRC}/utils/cups-browsed.conf.5 \
		${WRKSRC}/utils/driverless.1

post-install:
	@${MV} ${STAGEDIR}${PREFIX}/etc/cups/cups-browsed.conf \
		${STAGEDIR}${PREFIX}/etc/cups/cups-browsed.conf.sample

.include <bsd.port.post.mk>
