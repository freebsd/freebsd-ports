# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	gpsim
DISTVERSION=	0.31.0
CATEGORIES=	misc
MASTER_SITES=	SF

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Software simulator for Microchip PIC microcontrollers

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

BUILD_DEPENDS=	gpasm:devel/gputils
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libpopt.so:devel/popt
RUN_DEPENDS=	gpasm:devel/gputils

USES=		compiler:c++11-lang gmake gnome libtool localbase:ldflags pathfix pkgconfig readline
USE_CXXSTD=	c++11
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk20 pango
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

CONFLICTS_BUILD=	ga

DESKTOP_ENTRIES=	"GPSim" "" "" "gpsim" "Development;GTK;" ""

OPTIONS_DEFINE=		DOCS EXAMPLES

PORTDOCS=	*
PORTEXAMPLES=	*

post-patch:
.for i in gpsim/Makefile.in modules/Makefile.in
	@${REINPLACE_CMD} -e \
		's|-lstdc++||' ${WRKSRC}/${i}
.endfor

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in AUTHORS ChangeLog PROCESSORS README* doc/gpsim.pdf
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} \
		${STAGEDIR}${DOCSDIR})
.endfor

post-install-EXAMPLES-on:
.for i in led_test logic_test mod_test usart_gui usart_test
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/modules/${i}
	(cd ${WRKSRC}/examples/modules/${i} && ${INSTALL_DATA} *.asm *.stc \
		${STAGEDIR}${EXAMPLESDIR}/modules/${i})
.endfor
.for i in digital_stim p16f628_test stack_test
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/projects/${i}
	(cd ${WRKSRC}/examples/projects/${i} && ${INSTALL_DATA} *.asm *.stc \
		${STAGEDIR}${EXAMPLESDIR}/projects/${i})
.endfor

.include <bsd.port.mk>
