# New ports collection makefile for: grace
# Version required:	5.0.1
# Date created:		Dec 28 1998
# Whom:			Lars Koeller <lkoeller@cc.fh-lippe.de>
#
# $FreeBSD$
#

DISTNAME=	grace-5.0.2beta
PKGNAME=	grace-5.0.2b
CATEGORIES=	math print
#
# You never know when and why this caotic team moves it to ../src/old/   :-)
#
MASTER_SITES=	ftp://ftp.uni-bielefeld.de/pub/systems/FreeBSD/lkoeller/ \
		ftp://plasma-gate.weizmann.ac.il/pub/grace/src/ \
		ftp://plasma-gate.weizmann.ac.il/pub/grace/src/old/ \
		ftp://abragam.med.utoronto.ca/pub/mirrors/grace/src/ \
		ftp://abragam.med.utoronto.ca/pub/mirrors/grace/src/old/ \
		ftp://linux.mathematik.tu-darmstadt.de/pub/linux/mirrors/misc/grace/src/old/ \
		ftp://linux.mathematik.tu-darmstadt.de/pub/linux/mirrors/misc/grace/src/

MAINTAINER=	Lars.Koeller@Uni-Bielefeld.DE

BUILD_DEPENDS=	${X11BASE}/lib/libhlpclient.a:${PORTSDIR}/x11/libhelp \
		${LOCALBASE}/lib/libmfhdf.a:${PORTSDIR}/graphics/hdf \
		${LOCALBASE}/lib/libgd.a:${PORTSDIR}/graphics/gd
LIB_DEPENDS=	Xbae.6:${PORTSDIR}/x11-toolkits/xbae 	\
		Xpm.4:${PORTSDIR}/graphics/xpm		\
		fftw.2:${PORTSDIR}/math/fftw		\
		pdf.2:${PORTSDIR}/print/pdflib		\
		tiff.4:${PORTSDIR}/graphics/tiff

BROKEN=		"rstdrv.o: undefined reference to gdImageGif"

USE_X_PREFIX=	YES
USE_GMAKE=	YES
REQUIRES_MOTIF=	YES
HAS_CONFIGURE=	YES
CONFIGURE_ARGS=	-prefix=${X11BASE} \
	--enable-extra-incpath=${X11BASE}/include/X11:${LOCALBASE}/include:${LOCALBASE}/include/gd \
	--enable-extra-ldpath=${LOCALBASE}/lib --enable-libhelp \
	--enable-mfhdf --enable-grace-home=${X11BASE}/lib/X11/grace

ALL_TARGET=
INSTALL_TARGET= install links

post-patch:
	${MV} ${WRKSRC}/configure ${WRKSRC}/configure.input
	${SED} "s%-lXm %${MOTIFLIB} %" ${WRKSRC}/configure.input > ${WRKSRC}/configure
	${CHMOD} 755 ${WRKSRC}/configure
	${RM} -f ${WRKSRC}/configure.input

.include <bsd.port.mk>
