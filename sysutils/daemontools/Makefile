# New ports collection makefile for:	daemontools
# Date created:		09 June 1998
# Whom:			Dom Mitchell <dom@myrddin.demon.co.uk>
#
# $FreeBSD$
#

PORTNAME=	daemontools
PORTVERSION=	0.70
CATEGORIES=	sysutils
MASTER_SITES=	http://cr.yp.to/daemontools/

MAINTAINER=	nbm@FreeBSD.org

NO_PACKAGE=	Unsure of djb\'s license

ALL_TARGET=	it
INSTALL_TARGET=	setup check

post-patch:
	@echo "${CC} ${CFLAGS}" > ${WRKSRC}/conf-cc
	@echo "${CC} -s" > ${WRKSRC}/conf-ld
	@echo "${PREFIX}" > ${WRKSRC}/conf-home

.include <bsd.port.mk>
