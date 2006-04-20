# ex:ts=8
# Ports collection makefile for:	fityk
# Date created:			Mar 8, 2005
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	fityk
PORTVERSION=	0.7.3
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free peak fitting software

BUILD_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot
LIB_DEPENDS=	boost_thread.3:${PORTSDIR}/devel/boost \
		wx_gtk2_core-2.6.0:${PORTSDIR}/x11-toolkits/wxgtk26
RUN_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot

USE_BZIP2=	yes
USE_GNOME=	gnometarget gtk20
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS+=	--with-wx-config=wxgtk2-2.6-config

MAN1=		fityk.1
PLIST_FILES=	bin/cfityk \
		bin/fityk \
		%%DATADIR%%/fityk_tips.txt \
		%%DATADIR%%/fitykhelp.htb
PLIST_DIRS=	%%DATADIR%%

CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		does not compile on 4.x
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|^CPPFLAGS=|#CPPFLAGS=|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|config 3rdparty|config|g ; \
		 s|^install-data-am:|install-data-am:#|g' ${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>
