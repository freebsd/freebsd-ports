# New ports collection makefile for:	gmp-ecm
# Date created:		2006-06-03
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	gmp-ecm
PORTVERSION=	6.2.0
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://gforge.inria.fr/frs/download.php/4663/
DISTNAME=	ecm-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Elliptic Curve Method for Integer Factorization

LIB_DEPENDS=	gmp:${PORTSDIR}/math/libgmp4

WRKSRC=		${WRKDIR}/ecm-${PORTVERSION:R}

USE_GNOME=	gnometarget
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	ac_cv_prog_XSLTPROC=no \
		--with-gmp=${LOCALBASE}

MAN1=		ecm.1
PLIST_FILES=	bin/ecm include/ecm.h lib/libecm.a lib/libecm.la

.include <bsd.port.mk>
