# Created by: mr

PORTNAME=	oleo
PORTVERSION=	1.99.16
PORTREVISION=	14
CATEGORIES=	math
MASTER_SITES=	GNU

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU spreadsheet for X11 and terminals

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgsl.so:math/gsl

USES=		bison:alias localbase ncurses perl5
USE_PERL5=	build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-xlt --without-sciplot
# With -O2 configure hangs at "checking for working mktime..."
CONFIGURE_ENV=	CFLAGS="${CFLAGS:C/-O2//} -fwrapv"
MAKE_ARGS+=	DESTDIR="${STAGEDIR}"

BINARY_ALIAS=	makeinfo=false # disable detecting local makeinfo

INFO=		oleo

OPTIONS_DEFINE=	CUPS MOTIF NLS
OPTIONS_SUB=	yes

CUPS_LIB_DEPENDS=	libcups.so:print/cups

MOTIF_LIB_DEPENDS=	libplot.so:graphics/plotutils \
			libXbae.so:x11-toolkits/xbae \
			libXmHTML.so:x11-toolkits/xmhtml \
			libpng.so:graphics/png \
			libXft.so:x11-fonts/libXft \
			libfontconfig.so:x11-fonts/fontconfig
MOTIF_USES=		jpeg motif xorg
MOTIF_USE=		XORG=ice,sm,x11,xext,xpm,xt
MOTIF_CONFIGURE_WITH=	motif x
MOTIF_LIBS=		-lXft -lfontconfig

NLS_USES=		gettext
NLS_LIBS=		-lintl
NLS_CONFIGURE_ENABLE=	nls
NLS_USES_OFF=		gettext-tools

pre-configure:
	@${GREP} -lR "malloc\.h" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|malloc\.h|stdlib.h|g'
.for pof in en fr nl
	@${REINPLACE_CMD} -e "s|CHARSET|ISO-8859-1|;s|ENCODING|8bit|"	\
		${WRKSRC}/po/${pof}.po
.endfor
	@${REINPLACE_CMD} -e "s|am: install-docDATA|am:|" ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "s|install-info-am install-htmlDATA|install-info-am|" \
		${WRKSRC}/doc/Makefile.in
	${REINPLACE_CMD} -e "s|gslblas|gslcblas|" ${WRKSRC}/configure

.include <bsd.port.mk>
