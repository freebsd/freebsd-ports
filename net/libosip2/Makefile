# ex:ts=8
# Ports collection makefile for:	libosip2
# Date created:			Nov 7, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libosip2
PORTVERSION=	2.2.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	osip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A low layer of SIP implementation

USE_GNOME=	gnomehack gnometarget pkgconfig
USE_REINPLACE=	yes
USE_LIBTOOL_VER=	15
CONFIGURE_ARGS=	--disable-debug --disable-trace
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|-pthread|${PTHREAD_LIBS}|g" ${WRKSRC}/configure
	@${REINPLACE_CMD} -e "/^SUBDIRS/s| help | |g" ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
