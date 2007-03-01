# New ports collection makefile for:	gmp-ecm
# Date created:		2006-06-03
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	gmp-ecm
PORTVERSION=	6.1.2
CATEGORIES=	math
MASTER_SITES=	http://gforge.inria.fr/frs/download.php/1498/
DISTNAME=	ecm-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Elliptic Curve Method for Integer Factorization

LIB_DEPENDS=	gmp:${PORTSDIR}/math/libgmp4

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-gmp=${LOCALBASE}

.include <bsd.port.mk>
