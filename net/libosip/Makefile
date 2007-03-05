# ex:ts=8
# Ports collection makefile for:	libosip
# Date created:			Jun 14, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libosip
PORTVERSION=	3.0.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNU} \
		http://www.antisip.com/download/
MASTER_SITE_SUBDIR=	osip
DISTNAME=	${PORTNAME}2-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A low layer of SIP implementation

CONFLICTS=	libosip2-2*

WRKSRC=	${WRKDIR}/${PORTNAME}2-${PORTVERSION}

USE_GNOME=	gnomehack gnometarget pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-debug --disable-trace
USE_AUTOTOOLS=	libtool:15
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|-pthread|${PTHREAD_LIBS}|g" ${WRKSRC}/configure
	@${REINPLACE_CMD} -e "/^SUBDIRS/s| help | |g" ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
