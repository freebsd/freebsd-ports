# New ports collection makefile for: publicfile-0.52
# Date created:		24 Jan 2000
# Whom:			Neil Blakey-Milner
#
# $FreeBSD$
#

PORTNAME=	publicfile
PORTVERSION= 	0.52
CATEGORIES=	ftp
MASTER_SITES=	http://cr.yp.to/publicfile/

MAINTAINER=	nbm@FreeBSD.org

ALL_TARGET=	it
INSTALL_TARGET=	setup check

post-patch:
	@echo "${CC} ${CFLAGS}" > ${WRKSRC}/conf-cc
	@echo "${CC} -s" > ${WRKSRC}/conf-ld
	@echo "${PREFIX}" > ${WRKSRC}/conf-home

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
