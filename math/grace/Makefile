# New ports collection makefile for: grace
# Date created:		Dec 28 1998
# Whom:			Lars Köller <Lars.Koeller@Uni-Bielefeld.de>
#
# $FreeBSD$
#

PORTNAME=	grace
PORTVERSION=	5.1.10
CATEGORIES=	math print
#
# You never know when and why it is moved to ../src/old/   :-)
#
MASTER_SITES=	ftp://plasma-gate.weizmann.ac.il/pub/grace/src/ \
		ftp://plasma-gate.weizmann.ac.il/pub/grace/src/old/ \
		ftp://abragam.med.utoronto.ca/pub/mirrors/grace/src/ \
		ftp://abragam.med.utoronto.ca/pub/mirrors/grace/src/old/ \
		ftp://linux.mathematik.tu-darmstadt.de/pub/linux/mirrors/misc/grace/src/old/ \
		ftp://linux.mathematik.tu-darmstadt.de/pub/linux/mirrors/misc/grace/src/

MAINTAINER=	Lars.Koeller@Uni-Bielefeld.DE

LIB_DEPENDS=	Xbae:${PORTSDIR}/x11-toolkits/xbae 	\
		netcdf.1:${PORTSDIR}/math/netcdf	\
		fftw.2:${PORTSDIR}/math/fftw		\
		tiff.4:${PORTSDIR}/graphics/tiff	\
		jpeg.9:${PORTSDIR}/graphics/jpeg	\
		png.5:${PORTSDIR}/graphics/png		\
		t1:${PORTSDIR}/devel/t1lib		\
		XmHTML.1:${PORTSDIR}/x11-toolkits/xmhtml \
		pdf.4:${PORTSDIR}/print/pdflib

MAN1=		convcal.1 grace.1 xmgrace.1 gracebat.1 grconvert.1

USE_X_PREFIX=	YES
USE_GMAKE=	YES
USE_MOTIF=	YES
HAS_CONFIGURE=	YES
CONFIGURE_ARGS=	-prefix=${X11BASE} \
	--with-extra-incpath=${X11BASE}/include/X11:${LOCALBASE}/include \
	--with-extra-ldpath=${LOCALBASE}/lib --without-bundled_xbae \
	--enable-grace-home=${X11BASE}/lib/X11/grace

ALL_TARGET=
INSTALL_TARGET= install links

post-patch:
	${CP} ${WRKSRC}/configure ${WRKSRC}/configure.input
	${SED} "s%-lXm %${MOTIFLIB} %" ${WRKSRC}/configure.input > ${WRKSRC}/configure
	${RM} -f ${WRKSRC}/configure.input

post-install:
.if !defined(NOPORTDOCS)
	if [ ! -e ${X11BASE}/share/doc/grace ]; then \
	    ${LN} -s ${X11BASE}/lib/X11/grace/doc ${X11BASE}/share/doc/grace; \
	fi
.endif

.include <bsd.port.mk>
