# ex:ts=8
# Ports collection makefile for:	libosip
# Date created:			Jun 14, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libosip
PORTVERSION=	0.8.9
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	osip

MAINTAINER=	ports@FreeBSD.org

USE_REINPLACE=	yes
USE_LIBTOOL=	yes
LIBTOOLFLAGS=	--disable-ltlibs --release-ignore
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|-lpthread|${PTHREAD_LIBS}|g" ${WRKSRC}/configure

.include <bsd.port.mk>
