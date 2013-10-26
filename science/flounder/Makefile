# Created by: ijliao
# $FreeBSD$

PORTNAME=	flounder
PORTVERSION=	0.40
PORTREVISION=	16
CATEGORIES=	science
MASTER_SITES=	http://www.enel.ucalgary.ca/People/vigmond/flounder/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A quick way to visualize regularly spaced 4D data

LIB_DEPENDS=	gif:${PORTSDIR}/graphics/giflib \
		png15:${PORTSDIR}/graphics/png \
		fltk:${PORTSDIR}/x11-toolkits/fltk

OPTIONS_DEFINE=	GNUPLOT GRACE
OPTIONS_DEFAULT=GNUPLOT GRACE
GRACE_DESC=	Plotting via GRACE

USE_GL=		glut
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

PLIST_FILES=	bin/flounder bin/igbhead

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGNUPLOT}
BUILD_DEPENDS+=	gnuplot:${PORTSDIR}/math/gnuplot
RUN_DEPENDS+=	gnuplot:${PORTSDIR}/math/gnuplot
CONFIGURE_ARGS+=	--enable-gnuplot
.endif

.if ${PORT_OPTIONS:MGRACE}
BUILD_DEPENDS+=	xmgrace:${PORTSDIR}/math/grace
RUN_DEPENDS+=	xmgrace:${PORTSDIR}/math/grace
CONFIGURE_ARGS+=	--enable-grace
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|-lungif|-lgif|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|cmdline.o.*|cmdline.o| ; \
		 /getopt.o/d ; \
		 /getopt1.o/d ; \
		 s|g++ |$$(CXX) | ; \
		 s|-g | |' ${WRKSRC}/utils/Makefile
	@${REINPLACE_CMD} -e \
		's|^main(|int main(|' ${WRKSRC}/utils/igbhead.cc

do-install:
	cd ${WRKSRC}/src && ${INSTALL_PROGRAM} flounder ${PREFIX}/bin
	cd ${WRKSRC}/utils && ${INSTALL_PROGRAM} igbhead ${PREFIX}/bin

.include <bsd.port.mk>
