# Created by: Lars Koeller <Lars.Koeller@Uni-Bielefeld.de>
# $FreeBSD$

PORTNAME=	grace
PORTVERSION=	5.1.25
PORTREVISION=	5
CATEGORIES=	math print
MASTER_SITES=	ftp://ftp.fu-berlin.de/unix/graphics/grace/src/stable/ \
		ftp://ftp.ntua.gr/pub/graphics/grace/src/stable/ \
		ftp://ftp.u-aizu.ac.jp/pub/SciEng/math/grace/src/stable/ \
		ftp://plasma-gate.weizmann.ac.il/pub/grace/src/stable/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Powerful 2D plotting tool (successor of xmgr)

LICENSE=	GPLv2

LIB_DEPENDS=	libt1.so:devel/t1lib \
		libpng.so:graphics/png \
		libXbae.so:x11-toolkits/xbae
RUN_DEPENDS=	xdg-open:devel/xdg-utils

USES=		gmake jpeg motif
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-grace-home=${DATADIR} \
		--with-extra-incpath=${LOCALBASE}/include \
		--with-extra-ldpath=${LOCALBASE}/lib \
		--with-helpviewer="xdg-open %s" \
		--without-bundled-xbae
MAKE_ARGS=	LINUXDOC="${TRUE}" PDFLATEX="${TRUE}"

DESKTOP_ENTRIES="XMgrace" "2D Plotting tool for scientific data" \
		"${PREFIX}/share/pixmaps/mini-xmgr3.xpm" "xmgrace" \
		 "" ""

OPTIONS_DEFINE=		DOCS EXAMPLES FFTW NETCDF PDF XMHTML
OPTIONS_DEFAULT=	FFTW NETCDF PDF XMHTML

FFTW_CONFIGURE_WITH=	fftw
FFTW_LIB_DEPENDS=	libfftw.so:math/fftw
NETCDF_CONFIGURE_ENABLE=	netcdf
NETCDF_LIB_DEPENDS=	libnetcdf.so:science/netcdf
PDF_DESC=		PDF output
PDF_CONFIGURE_ENABLE=	pdfdrv
PDF_LIB_DEPENDS=	libpdf.so:print/pdflib
XMHTML_DESC=		XmHTML based on-line help
XMHTML_CONFIGURE_ENABLE=	xmhtml
XMHTML_LIB_DEPENDS=	libXmHTML.so:x11-toolkits/xmhtml

post-configure:
	${REINPLACE_CMD} -e \
		'/SCRIPTS/s|INSTALL_PROGRAM|INSTALL_SCRIPT|' \
		${WRKSRC}/auxiliary/Makefile
	${REINPLACE_CMD} -e \
		'/cd /!s|$$(GRACE_HOME)/doc|${DOCSDIR}| ; \
		 /cd /s|$$(GRACE_HOME)/doc|$$(DESTDIR)$$(PREFIX)/man/man1| ; \
		 /^install/s|$$(MANPAGES)||' \
		${WRKSRC}/doc/Makefile
	${REINPLACE_CMD} -e \
		's|$$(GRACE_HOME)/examples|${EXAMPLESDIR}| ; \
		 /DOTEST/s|INSTALL_PROGRAM|INSTALL_SCRIPT|' \
		${WRKSRC}/examples/Makefile
	${REINPLACE_CMD} -e \
		's|$$(GRACE_HOME)/include|$$(PREFIX)/include| ; \
		 s|$$(GRACE_HOME)/lib|$$(PREFIX)/lib|' \
		${WRKSRC}/grace_np/Makefile
	${FIND} ${WRKSRC} -name Makefile | ${XARGS} ${REINPLACE_CMD} -e \
		's|$$(GRACE_HOME)/bin|$$(PREFIX)/bin|'

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/[c-g]*.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_DATA} ${FILESDIR}/mini-xmgr3.xpm \
		${STAGEDIR}${PREFIX}/share/pixmaps
	${LN} -sf xmgrace ${STAGEDIR}${PREFIX}/bin/grace
	${LN} -sf grace.1 ${STAGEDIR}${MANPREFIX}/man/man1/xmgrace.1
	${LN} -sf ${DOCSDIR} ${STAGEDIR}${DATADIR}/doc
	${LN} -sf ${EXAMPLESDIR} ${STAGEDIR}${DATADIR}/examples

.include <bsd.port.mk>
