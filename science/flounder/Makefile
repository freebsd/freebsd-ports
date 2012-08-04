# ex:ts=8
# Ports collection Makefile for:	flounder
# Date created:			Oct 14, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	flounder
PORTVERSION=	0.40
PORTREVISION=	14
CATEGORIES=	science
MASTER_SITES=	http://www.enel.ucalgary.ca/People/vigmond/flounder/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A quick way to visualize regularly spaced 4D data

LIB_DEPENDS=	fltk.1:${PORTSDIR}/x11-toolkits/fltk \
		gif:${PORTSDIR}/graphics/giflib \
		png15:${PORTSDIR}/graphics/png

USE_GL=		glut
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS} -lstdc++
USE_GMAKE=	yes

.if !defined(WITHOUT_PLOT)
BUILD_DEPENDS+=	gnuplot:${PORTSDIR}/math/gnuplot
RUN_DEPENDS+=	gnuplot:${PORTSDIR}/math/gnuplot
CONFIGURE_ARGS+=	--enable-gnuplot
.endif

.if !defined(WITHOUT_GRACE)
BUILD_DEPENDS+=	xmgrace:${PORTSDIR}/math/grace
RUN_DEPENDS+=	xmgrace:${PORTSDIR}/math/grace
CONFIGURE_ARGS+=	--enable-grace
.endif

post-patch:
	${REINPLACE_CMD} -e "s|-lungif|-lgif|" ${WRKSRC}/configure

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
BROKEN=		Does not compile on alpha
.endif

.include <bsd.port.post.mk>
