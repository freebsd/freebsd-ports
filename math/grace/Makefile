# New ports collection makefile for: grace
# Date created:		Dec 28 1998
# Whom:			Lars Köller <Lars.Koeller@Uni-Bielefeld.de>
#
# $FreeBSD$
#

PORTNAME=	grace
PORTVERSION=	5.1.18
PORTREVISION=	0
CATEGORIES=	math print
#
MASTER_SITES=	ftp://plasma-gate.weizmann.ac.il/pub/grace/src/stable/ \
		ftp://linux.mathematik.tu-darmstadt.de/pub/linux/mirrors/misc/grace/src/stable/

MAINTAINER=	Lars.Koeller@Uni-Bielefeld.DE
COMMENT=	A powerful plotting tool (successor of xmgr)

LIB_DEPENDS=	Xbae:${PORTSDIR}/x11-toolkits/xbae 	\
		netcdf.1:${PORTSDIR}/math/netcdf	\
		fftw.2:${PORTSDIR}/math/fftw		\
		tiff.4:${PORTSDIR}/graphics/tiff	\
		jpeg.9:${PORTSDIR}/graphics/jpeg	\
		png.5:${PORTSDIR}/graphics/png		\
		t1:${PORTSDIR}/devel/t1lib		\
		XmHTML.1:${PORTSDIR}/x11-toolkits/xmhtml \
		pdf.7:${PORTSDIR}/print/pdflib

MAN1=		convcal.1 grace.1 xmgrace.1 gracebat.1 grconvert.1

USE_X_PREFIX=	YES
USE_GMAKE=	YES
USE_MOTIF=	YES
USE_REINPLACE=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	\
	--with-extra-incpath=${X11BASE}/include/X11:${LOCALBASE}/include \
	--with-extra-ldpath=${LOCALBASE}/lib --without-bundled_xbae \
	--enable-grace-home=${X11BASE}/lib/X11/grace
ALL_TARGET=	# empty
INSTALL_TARGET=	install links

post-patch:
	@${REINPLACE_CMD} -e "s%-lXm %${MOTIFLIB} %" ${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	if [ ! -e ${DOCSDIR} ]; then \
	    ${LN} -s ${X11BASE}/lib/X11/grace/doc ${DOCSDIR}; \
	fi
.endif

.include <bsd.port.mk>
