# Created by: Lars Köller <Lars.Koeller@Uni-Bielefeld.de>
# $FreeBSD$

PORTNAME=	grace
PORTVERSION=	5.1.23
PORTREVISION=	3
CATEGORIES=	math print
MASTER_SITES=	ftp://ftp.fu-berlin.de/unix/graphics/grace/src/stable/ \
		ftp://ftp.ntua.gr/pub/graphics/grace/src/stable/ \
		ftp://ftp.u-aizu.ac.jp/pub/SciEng/math/grace/src/stable/ \
		ftp://plasma-gate.weizmann.ac.il/pub/grace/src/stable/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Powerful 2D plotting tool (successor of xmgr)

LICENSE=	GPLv2

LIB_DEPENDS=	t1:${PORTSDIR}/devel/t1lib \
		jpeg:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png \
		Xbae:${PORTSDIR}/x11-toolkits/xbae
RUN_DEPENDS=	xdg-open:${PORTSDIR}/devel/xdg-utils

OPTIONS_DEFINE=	FFTW NETCDF PDF XMHTML DOCS EXAMPLES
OPTIONS_DEFAULT=FFTW NETCDF PDF XMHTML
PDF_DESC=	PDF output
XMHTML_DESC=	Use XmHTML widget for on-line help

USE_GCC=	any
USES=		gmake motif
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-grace-home=${DATADIR} \
		--with-extra-incpath=${LOCALBASE}/include \
		--with-extra-ldpath=${LOCALBASE}/lib \
		--with-helpviewer="xdg-open %s" \
		--without-bundled-xbae
ALL_TARGET=	# empty

MAN1=		convcal.1 grace.1 grconvert.1
MLINKS=		grace.1 gracebat.1 \
		grace.1 xmgrace.1

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFFTW}
LIB_DEPENDS+=	fftw:${PORTSDIR}/math/fftw
CONFIGURE_ARGS+=	--with-fftw
.else
CONFIGURE_ARGS+=	--without-fftw
.endif

.if ${PORT_OPTIONS:MNETCDF}
LIB_DEPENDS+=	netcdf:${PORTSDIR}/science/netcdf
CONFIGURE_ARGS+=	--enable-netcdf
.else
CONFIGURE_ARGS+=	--disable-netcdf
.endif

.if ${PORT_OPTIONS:MPDF}
LIB_DEPENDS+=	pdf:${PORTSDIR}/print/pdflib
CONFIGURE_ARGS+=	--enable-pdfdrv
.else
CONFIGURE_ARGS+=	--disable-pdfdrv
.endif

.if ${PORT_OPTIONS:MXMHTML}
LIB_DEPENDS+=	XmHTML:${PORTSDIR}/x11-toolkits/xmhtml
CONFIGURE_ARGS+=	--enable-xmhtml
.else
CONFIGURE_ARGS+=	--disable-xmhtml
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/xmgrace ${PREFIX}/bin
	@${LN} -sf xmgrace ${PREFIX}/bin/grace
	@${LN} -sf xmgrace ${PREFIX}/bin/gracebat
	${INSTALL_PROGRAM} ${WRKSRC}/auxiliary/convcal ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/grconvert/grconvert ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/auxiliary/fdf2fit ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/*.1 ${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/grace_np/grace_np.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/grace_np/libgrace_np.a ${PREFIX}/lib
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/gracerc ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/gracerc.user ${DATADIR}
	@${MKDIR} ${DATADIR}/auxiliary
	${INSTALL_DATA} ${WRKSRC}/auxiliary/README ${DATADIR}/auxiliary
	${INSTALL_DATA} ${WRKSRC}/auxiliary/convcal.c ${DATADIR}/auxiliary
	${INSTALL_DATA} ${WRKSRC}/auxiliary/magic.grace ${DATADIR}/auxiliary
	@${MKDIR} ${DATADIR}/fonts
	${INSTALL_DATA} ${WRKSRC}/fonts/FontDataBase ${DATADIR}/fonts
	@${MKDIR} ${DATADIR}/fonts/enc
	${INSTALL_DATA} ${WRKSRC}/fonts/enc/*.enc ${DATADIR}/fonts/enc
	@${MKDIR} ${DATADIR}/fonts/type1
	${INSTALL_DATA} ${WRKSRC}/fonts/type1/*.afm ${DATADIR}/fonts/type1
	${INSTALL_DATA} ${WRKSRC}/fonts/type1/*.pfb ${DATADIR}/fonts/type1
	@${MKDIR} ${DATADIR}/templates
	${INSTALL_DATA} ${WRKSRC}/templates/*.agr ${DATADIR}/templates
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@${TAR} -C ${WRKSRC}/doc --exclude "*Makefile*" --exclude "*.1" \
		-cf - . | ${TAR} -C ${DOCSDIR} --unlink -xf -
	@${FIND} ${DOCSDIR} -exec ${CHOWN} ${SHAREOWN}:${SHAREGRP} {} \;
	@${FIND} ${DOCSDIR} -type f -exec ${CHMOD} ${SHAREMODE} {} \;
	@${LN} -sf ${DOCSDIR} ${DATADIR}/doc
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	@${TAR} -C ${WRKSRC}/examples --exclude "*Makefile*" \
		-cf - . | ${TAR} -C ${EXAMPLESDIR} --unlink -xf -
	@${FIND} ${EXAMPLESDIR} -exec ${CHOWN} ${SHAREOWN}:${SHAREGRP} {} \;
	@${FIND} ${EXAMPLESDIR} -type f -exec ${CHMOD} ${SHAREMODE} {} \;
	@${LN} -sf ${EXAMPLESDIR} ${DATADIR}/examples
.endif

.include <bsd.port.mk>
