# New ports collection makefile for:	xtraceroute
# Date created:				17 February 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xtraceroute
PORTVERSION=	0.9.0
CATEGORIES=	net
MASTER_SITES=	http://www.dtek.chalmers.se/~d3august/xt/dl/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DATAFILES}

MAINTAINER=	sobomax@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/bin/host:${PORTSDIR}/net/host
LIB_DEPENDS=	gtkgl.5:${PORTSDIR}/x11-toolkits/gtkglarea
RUN_DEPENDS=	${LOCALBASE}/bin/host:${PORTSDIR}/net/host

USE_X_PREFIX=	yes
USE_MESA=	yes
USE_GNOMENG=	yes
USE_GNOME=	gdkpixbuf
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-GL-prefix=${X11BASE}/lib \
		--with-lib-GL \
		--with-host=${LOCALBASE}/bin/host
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
MAKE_ENV=	OLD_PO_FILE_INPUT=1

DATAFILES=	ndg_files.tar.gz

MAN1=		xtraceroute.1

post-install:
	${INSTALL_DATA} ${WRKDIR}/hosts.cache ${PREFIX}/share/xtraceroute
	${INSTALL_DATA} ${WRKDIR}/networks.cache ${PREFIX}/share/xtraceroute

.include <bsd.port.mk>
