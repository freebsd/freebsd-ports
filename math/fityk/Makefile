# ex:ts=8
# Ports collection makefile for:	fityk
# Date created:			Mar 8, 2005
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	fityk
PORTVERSION=	0.5.1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free peak fitting software

BUILD_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot
LIB_DEPENDS=	boost_thread.2:${PORTSDIR}/devel/boost
RUN_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot

USE_GNOME=	gnometarget gtk20
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=		fityk.1

CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500018
LIB_DEPENDS+=	readline.5:${PORTSDIR}/devel/readline
CONFIGURE_ARGS+=	--with-readline=${LOCALBASE}
.endif

.if ${OSVERSION} < 500035
BUILD_DEPENDS+=	${LOCALBASE}/lib/libstlport_gcc.so:${PORTSDIR}/devel/stlport
RUN_DEPENDS+=	${LOCALBASE}/lib/libstlport_gcc.so:${PORTSDIR}/devel/stlport
CFLAGS+=	-fpermissive
CPPFLAGS+=	-I${LOCALBASE}/include/stlport
LDFLAGS+=	-lstlport_gcc
.endif

.if defined(WITH_WXGTK24)
LIB_DEPENDS+=	wx_gtk2-2.4.0:${PORTSDIR}/x11-toolkits/wxgtk24
CONFIGURE_ARGS+=	--with-wx-config=wxgtk2-2.4-config
.else
LIB_DEPENDS+=	wx_gtk2_core-2.6.0:${PORTSDIR}/x11-toolkits/wxgtk26
CONFIGURE_ARGS+=	--with-wx-config=wxgtk2-2.6-config
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|^CPPFLAGS=|#CPPFLAGS=|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|config 3rdparty|config|g' ${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>
