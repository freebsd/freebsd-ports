# New ports collection makefile for:	xtraceroute
# Date created:				17 February 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xtraceroute
PORTVERSION=	0.8.14
CATEGORIES=	net
MASTER_SITES=	http://www.dtek.chalmers.se/~d3august/xt/dl/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DATAFILES}

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	gtkgl.5:${PORTSDIR}/x11-toolkits/gtkglarea \
		tiff.4:${PORTSDIR}/graphics/tiff

USE_X_PREFIX=	yes
USE_MESA=	yes
USE_GTK=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-GL-prefix=${X11BASE}/lib \
		--with-lib-GL
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

DATAFILES=	ndg_files.tar.gz

MAN1=		xtraceroute.1

post-install:
	${INSTALL_DATA} ${WRKDIR}/hosts.cache ${PREFIX}/share/xtraceroute
	${INSTALL_DATA} ${WRKDIR}/networks.cache ${PREFIX}/share/xtraceroute

.include <bsd.port.mk>
