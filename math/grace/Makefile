# New ports collection makefile for: grace
# Version required:	5.0.1
# Date created:		Dec 28 1998
# Whom:			Lars Koeller <lkoeller@cc.fh-lippe.de>
#
# $FreeBSD$
#

DISTNAME=	grace-5.0.3gamma
PKGNAME=	grace-5.0.3g
CATEGORIES=	math print
#
# You never know when and why this caotic team moves it to ../src/old/   :-)
#
MASTER_SITES=	ftp://plasma-gate.weizmann.ac.il/pub/grace/src/ \
		ftp://plasma-gate.weizmann.ac.il/pub/grace/src/old/ \
		ftp://abragam.med.utoronto.ca/pub/mirrors/grace/src/ \
		ftp://abragam.med.utoronto.ca/pub/mirrors/grace/src/old/ \
		ftp://linux.mathematik.tu-darmstadt.de/pub/linux/mirrors/misc/grace/src/old/ \
		ftp://linux.mathematik.tu-darmstadt.de/pub/linux/mirrors/misc/grace/src/

MAINTAINER=	Lars.Koeller@Uni-Bielefeld.DE

BUILD_DEPENDS=  ${X11BASE}/lib/libhlpclient.a:${PORTSDIR}/x11/libhelp
LIB_DEPENDS=	Xbae.7:${PORTSDIR}/x11-toolkits/xbae 	\
		Xpm.4:${PORTSDIR}/graphics/xpm		\
		netcdf.1:${PORTSDIR}/math/netcdf	\
		fftw.2:${PORTSDIR}/math/fftw		\
		pdf.2:${PORTSDIR}/print/pdflib		\
		tiff.4:${PORTSDIR}/graphics/tiff	\
		jpeg.9:${PORTSDIR}/graphics/jpeg	\
		png.3:${PORTSDIR}/graphics/png		\
		t1.1:${PORTSDIR}/devel/t1lib

MAN1=		grace.1 xmgrace.1 gracebat.1 grconvert.1

USE_X_PREFIX=	YES
USE_GMAKE=	YES
REQUIRES_MOTIF=	YES
HAS_CONFIGURE=	YES
CONFIGURE_ARGS=	-prefix=${X11BASE} \
	--enable-extra-incpath=${X11BASE}/include/X11:${LOCALBASE}/include:${LOCALBASE}/include/gd \
	--enable-libhelp \
	--enable-extra-ldpath=${LOCALBASE}/lib \
	--enable-grace-home=${X11BASE}/lib/X11/grace \
	--enable-config=generic

ALL_TARGET=
INSTALL_TARGET= install links

post-patch:
	${CP} ${WRKSRC}/configure ${WRKSRC}/configure.input
	${SED} "s%-lXm %${MOTIFLIB} %" ${WRKSRC}/configure.input > ${WRKSRC}/configure
	${RM} -f ${WRKSRC}/configure.input

post-install:
	${LN} -s ${X11BASE}/lib/X11/grace/doc ${X11BASE}/share/doc/grace

.include <bsd.port.mk>
