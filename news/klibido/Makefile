# New ports collection makefile for:   klibido
# Date created:        2 December 2004
# Whom:                conrads@cox.net
#
# $FreeBSD$
#

PORTNAME=	klibido
PORTVERSION=	0.2.5
PORTREVISION=	9
CATEGORIES=	news
MASTER_SITES=	SF

MAINTAINER=	conrads@cox.net
COMMENT=	A very fast and efficient KDE/QT-based downloader for Usenet binaries

LIB_DEPENDS=	uu.3:${PORTSDIR}/converters/uulib \
		db-4.4:${PORTSDIR}/databases/db44

USE_KDELIBS_VER=3
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
INSTALLS_ICONS=	yes
USE_GETTEXT=	yes

LDFLAGS+=	-L${LOCALBASE}/lib/db44 ${PTHREAD_LIBS}
CFLAGS+=	-I${LOCALBASE}/include/db44 ${PTHREAD_CFLAGS}
CXXFLAGS+=	-I${LOCALBASE}/include/db44

post-install:
.if defined(NOPORTDOCS)
	${RM} -rf ${PREFIX}/share/doc/HTML/en/klibido
.endif

.include <bsd.port.mk>
