# Created by: Lars Köller <Lars.Koeller@Uni-Bielefeld.de>
# $FreeBSD$

PORTNAME=	grace
PORTVERSION=	5.1.23
PORTREVISION=	6
CATEGORIES=	math print
MASTER_SITES=	ftp://ftp.fu-berlin.de/unix/graphics/grace/src/stable/ \
		ftp://ftp.ntua.gr/pub/graphics/grace/src/stable/ \
		ftp://ftp.u-aizu.ac.jp/pub/SciEng/math/grace/src/stable/ \
		ftp://plasma-gate.weizmann.ac.il/pub/grace/src/stable/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Powerful 2D plotting tool (successor of xmgr)

LICENSE=	GPLv2

LIB_DEPENDS=	libt1.so:${PORTSDIR}/devel/t1lib \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libpng15.so:${PORTSDIR}/graphics/png \
		libXbae.so:${PORTSDIR}/x11-toolkits/xbae
RUN_DEPENDS=	xdg-open:${PORTSDIR}/devel/xdg-utils

USE_GCC=	any
USES=		gmake motif
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-grace-home=${DATADIR} \
		--with-extra-incpath=${LOCALBASE}/include \
		--with-extra-ldpath=${LOCALBASE}/lib \
		--with-helpviewer="xdg-open %s" \
		--without-bundled-xbae
ALL_TARGET=	# empty

OPTIONS_DEFINE=	FFTW NETCDF PDF XMHTML DOCS EXAMPLES
OPTIONS_DEFAULT=FFTW NETCDF PDF XMHTML

FFTW_CONFIGURE_WITH=	fftw
FFTW_LIB_DEPENDS=	libfftw.so:${PORTSDIR}/math/fftw

NETCDF_CONFIGURE_ENABLE=netcdf
NETCDF_LIB_DEPENDS=	libnetcdf.so:${PORTSDIR}/science/netcdf

PDF_DESC=		PDF output
PDF_CONFIGURE_ENABLE=	pdfdrv
PDF_LIB_DEPENDS=	libpdf.so:${PORTSDIR}/print/pdflib

XMHTML_DESC=		XmHTML based on-line help
XMHTML_CONFIGURE_ENABLE=xmhtml
XMHTML_LIB_DEPENDS=	libXmHTML.so:${PORTSDIR}/x11-toolkits/xmhtml

post-configure:
	@${REINPLACE_CMD} -e '/SCRIPTS/ s|INSTALL_PROGRAM|BSD_INSTALL_SCRIPT|' \
		${WRKSRC}/auxiliary/Makefile
	@${REINPLACE_CMD} -e '/cd /! s|$$(GRACE_HOME)/doc|${DOCSDIR}|' \
		-e '/cd / s|$$(GRACE_HOME)/doc|$$(DESTDIR)$$(PREFIX)/man/man1|' \
		-e '/^install/ s|$$(MANPAGES)||' \
		${WRKSRC}/doc/Makefile
	@${REINPLACE_CMD} -e 's|$$(GRACE_HOME)/examples|${EXAMPLESDIR}|' \
		-e '/DOTEST/ s|INSTALL_PROGRAM|BSD_INSTALL_SCRIPT|' \
		${WRKSRC}/examples/Makefile
	@${REINPLACE_CMD} -e 's|$$(GRACE_HOME)/include|$$(PREFIX)/include|' \
		-e 's|$$(GRACE_HOME)/lib|$$(PREFIX)/lib|' \
		${WRKSRC}/grace_np/Makefile
	@${FIND} ${WRKSRC} -name Makefile -exec ${REINPLACE_CMD} \
		's|$$(GRACE_HOME)/bin|$$(PREFIX)/bin|' {} \;

post-install:
	@${LN} -sf xmgrace ${STAGEDIR}${PREFIX}/bin/grace
	${INSTALL_MAN} ${WRKSRC}/doc/*.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${LN} -sf ${DOCSDIR} ${STAGEDIR}${DATADIR}/doc
	@${LN} -sf ${EXAMPLESDIR} ${STAGEDIR}${DATADIR}/examples

.include <bsd.port.mk>
