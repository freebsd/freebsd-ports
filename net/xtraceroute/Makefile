# New ports collection makefile for:	xtraceroute
# Date created:				17 February 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xtraceroute
PORTVERSION=	0.9.1
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www.dtek.chalmers.se/~d3august/xt/dl/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DATAFILES}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	3D graphical version of the traceroute program

BUILD_DEPENDS=	${LOCALBASE}/bin/host:${PORTSDIR}/dns/host
RUN_DEPENDS=	${BUILD_DEPENDS}
LIB_DEPENDS=	gtkgl.5:${PORTSDIR}/x11-toolkits/gtkglarea

USE_X_PREFIX=	yes
USE_GNOME=	gdkpixbuf
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-GL-prefix=${X11BASE}/lib \
		--with-lib-GL \
		--with-host=${LOCALBASE}/bin/host
CONFIGURE_ENV+=	CPPFLAGS="${CFLAGS} -I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
MAKE_ENV+=	OLD_PO_FILE_INPUT=1

DATAFILES=	ndg_files.tar.gz

MAN1=		xtraceroute.1

post-patch:
	@${TOUCH} ${WRKSRC}/po/*

post-install:
	${INSTALL_DATA} ${WRKDIR}/hosts.cache ${PREFIX}/share/xtraceroute
	${INSTALL_DATA} ${WRKDIR}/networks.cache ${PREFIX}/share/xtraceroute

.include <bsd.port.mk>
