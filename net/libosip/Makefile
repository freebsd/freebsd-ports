# ex:ts=8
# Ports collection makefile for:	libosip
# Date created:			Jun 14, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libosip
PORTVERSION=	0.9.7
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	osip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A low layer of SIP implementation

USE_REINPLACE=	yes
USE_LIBTOOL_VER=15
#LIBTOOLFLAGS=	--disable-ltlibs --release-ignore
INSTALLS_SHLIB=	yes

MAN1=	osip.1

post-patch:
	@${REINPLACE_CMD} -e "s|-pthread|${PTHREAD_LIBS}|g" ${WRKSRC}/configure

.include <bsd.port.mk>
