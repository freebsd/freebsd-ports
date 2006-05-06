# New ports collection makefile for:   pspp
# Date created:                        22 Apr 2000
# Whom:                                Andrew L. Neporada <andrew@chg.ru>
#
# $FreeBSD$
#

PORTNAME=	pspp
PORTVERSION=	0.4.0
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program for statistical analysis of sampled data

LIB_DEPENDS=	plot.4:${PORTSDIR}/graphics/plotutils \
		gslcblas.0:${PORTSDIR}/math/gsl

USE_PERL5_BUILD=yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

INFO=		pspp

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
BROKEN=		needs at least Perl 5.6
.endif

.include <bsd.port.post.mk>
