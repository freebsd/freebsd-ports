# ex:ts=8
# Ports collection makefile for:	libosip2
# Date created:			Nov 7, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libosip2
PORTVERSION=	2.2.3
CATEGORIES=	net
MASTER_SITES=	http://www.antisip.com/download/ \
		${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	osip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A low layer of SIP implementation

CONFLICTS=	libosip-3*

USE_GNOME=	gnomehack gnometarget pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-debug --disable-trace
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|-pthread|${PTHREAD_LIBS}|g" ${WRKSRC}/configure
	@${REINPLACE_CMD} -e "/^SUBDIRS/s| help | |g" ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
