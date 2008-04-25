# New ports collection makefile for:   pspp
# Date created:                        22 Apr 2000
# Whom:                                Andrew L. Neporada <andrew@chg.ru>
#
# $FreeBSD$
#

PORTNAME=	pspp
PORTVERSION=	0.4.0.1
CATEGORIES=	math
MASTER_SITES=	GNU

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program for statistical analysis of sampled data

LIB_DEPENDS=	plot.4:${PORTSDIR}/graphics/plotutils \
		gslcblas.0:${PORTSDIR}/math/gsl

USE_GNOME=	gnometarget
USE_PERL5_BUILD=yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

INFO=		pspp

.include <bsd.port.mk>
