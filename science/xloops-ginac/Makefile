# ex:ts=8
# Ports collection makefile for:	xloops
# Date created:			Oct 15, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	xloops
PORTVERSION=	0.1.3
CATEGORIES=	science
MASTER_SITES=	http://wwwthep.physik.uni-mainz.de/~xloops/
PKGNAMESUFFIX=	-ginac
DISTNAME=	${PORTNAME}-ginac-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	A program calculating Feynman diagrams

LIB_DEPENDS=	ginac:${PORTSDIR}/math/GiNaC

USE_LIBTOOL=	yes
USE_GMAKE=	yes

post-install:
	@${RMDIR} ${DOCSDIR}

.include <bsd.port.mk>
