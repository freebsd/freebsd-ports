PORTNAME=	gpsim
DISTVERSION=	0.32.1
CATEGORIES=	misc
MASTER_SITES=	https://download.sourceforge.net/project/gpsim/gpsim/0.32.0/ # SF

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Software simulator for Microchip PIC microcontrollers
WWW=		https://gpsim.sourceforge.net/

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

BUILD_DEPENDS=	gpasm:devel/gputils
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libpopt.so:devel/popt
RUN_DEPENDS=	gpasm:devel/gputils

USES=		compiler:c++11-lang gmake gnome libtool localbase:ldflags pathfix pkgconfig readline
USE_CXXSTD=	c++11
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk20 pango
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

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
