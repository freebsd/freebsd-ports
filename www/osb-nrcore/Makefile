# New ports collection makefile for:	osb-nrcore
# Date created:		2004-11-29
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	osb-nrcore
PORTVERSION=	0.5.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gtk-webcore

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Gtk-Webcore's browser engine

LIB_DEPENDS=	jscore.0:${PORTSDIR}/lang/osb-jscore

USE_INC_LIBTOOL_VER=15
USE_REINPLACE=	yes
USE_GNOME=	gtk20 gnomehack
USE_GCC=	3.4
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS} -DNDEBUG" \
		LDFLAGS="${PTHREAD_LIBS}"

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread||; s|-nostdinc++||; \
		s|-fPIC||' ${WRKSRC}/configure

.include <bsd.port.mk>
