# New ports collection makefile for:	gmp-ecm
# Date created:		2006-06-03
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	gmp-ecm
PORTVERSION=	6.1
CATEGORIES=	math
MASTER_SITES=	http://gforge.inria.fr/frs/download.php/736/
DISTNAME=	ecm-${PORTVERSION}

MAINTAINER=	gslin@gslin.org
COMMENT=	Elliptic Curve Method for Integer Factorization

LIB_DEPENDS=	gmp.7:${PORTSDIR}/math/libgmp4

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-gmp=${LOCALBASE}

.include <bsd.port.mk>
