# ex:ts=8
# Ports collection makefile for:	subconv
# Date created:			Apr 5, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	subconv
PORTVERSION=	0.2.1
CATEGORIES=	multimedia
MASTER_SITES=	http://linux.bydg.org/~yogin/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Subconv converts DivX subtitles from one format to another

USE_PYTHON=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/subconv ${PREFIX}/bin

.include <bsd.port.mk>
