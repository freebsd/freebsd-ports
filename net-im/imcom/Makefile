# New ports collection makefile for:	imcom
# Date created:				Jun 09 2002
# Whom:					Martijn Lina
#
# $FreeBSD$

PORTNAME=	imcom
PORTVERSION=	0.93
CATEGORIES=	net
MASTER_SITES=	http://imcom.floobin.cx/files/

MAINTAINER=	martijn@pacno.net

USE_PYTHON=	yes

pre-install:
	@cd ${WRKSRC} ; \
	${RM} -rf docs/CVS; \
	${RM} -rf docs/*~

.include <bsd.port.mk>
