# ex:ts=8
# Ports collection makefile for:	libosip2
# Date created:			Nov 7, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libosip2
PORTVERSION=	2.0.4
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNU} \
		http://osip.atosc.org/download/%SUBDIR%/
MASTER_SITE_SUBDIR=	osip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	oSIP is an implementation of SIP

USE_REINPLACE=	yes
USE_LIBTOOL=	yes
LIBTOOLFLAGS=	--disable-ltlibs --release-ignore
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-debug --disable-trace
INSTALLS_SHLIB=	yes

MAN1=	osip.1

post-patch:
	@${REINPLACE_CMD} -e "s|-pthread|${PTHREAD_LIBS}|g" ${WRKSRC}/configure

.include <bsd.port.mk>
