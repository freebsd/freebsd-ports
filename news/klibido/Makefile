# New ports collection makefile for:   klibido
# Date created:        2 December 2004
# Whom:                conrads@cox.net
#
# $FreeBSD$
#

PORTNAME=		klibido
PORTVERSION=		0.2.3
CATEGORIES=		news
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=		conrads@cox.net
COMMENT=		A very fast and efficient KDE/QT-based downloader for Usenet binaries

LIB_DEPENDS=		uu.3:${PORTSDIR}/converters/uulib \
			db-4.2.2:${PORTSDIR}/databases/db42

USE_KDELIBS_VER=	3
USE_XLIB=		yes
USE_GMAKE=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ENV=		CFLAGS="${CFLAGS} -I${LOCALBASE}/include/db42 ${PTHREAD_CFLAGS}" \
			CXXFLAGS="${CXXFLAGS} -I${LOCALBASE}/include/db42" \
			LDFLAGS="-L${LOCALBASE}/lib/db42 ${PTHREAD_LIBS}"

.include <bsd.port.mk>
