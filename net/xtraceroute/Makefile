# New ports collection makefile for:   xtraceroute
# Date created:        17 February 2000
# Whom:                Maxim Sobolev <sobomax@altavista.net>
#
# $FreeBSD$
#

PORTNAME=	xtraceroute
PORTVERSION=	0.8.14
CATEGORIES=	net
MASTER_SITES=	http://www.dtek.chalmers.se/~d3august/xt/dl/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DATAFILES}

MAINTAINER=	sobomax@altavista.net

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		GL.14:${PORTSDIR}/graphics/Mesa3 \
		gtkgl.4:${PORTSDIR}/x11-toolkits/gtkglarea \
		tiff.4:${PORTSDIR}/graphics/tiff

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-GL-prefix=${X11BASE}/lib \
		--with-lib-MesaGL
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		GTK_CONFIG="${GTK_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib"

DATAFILES=	ndg_files.tar.gz

MAN1=		xtraceroute.1

post-install:
		${INSTALL_DATA} ${WRKDIR}/hosts.cache ${PREFIX}/share/xtraceroute
		${INSTALL_DATA} ${WRKDIR}/networks.cache ${PREFIX}/share/xtraceroute

.include <bsd.port.mk>
