# New ports collection makefile for: arprelease
# Date created:		02 Aug 2001
# Whom:			nbm
#
# $FreeBSD$
#

PORTNAME=	arprelease
PORTVERSION=	1.0
CATEGORIES=	net
MASTER_SITES= 	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	arprelease

MAINTAINER=	nbm@FreeBSD.org

BUILD_DEPENDS=	libnet-config:${PORTSDIR}/net/libnet

LIBNET_CONFIG=	libnet-config

do-build:
	(cd ${WRKSRC} && \
		${CC} ${CFLAGS} -I${LOCALBASE}/include -L${LOCALBASE}/lib \
		-o arprelease arprelease.c \
		`${LIBNET_CONFIG} --defines` `${LIBNET_CONFIG} --libs`)

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/arprelease ${PREFIX}/bin

.include <bsd.port.mk>
