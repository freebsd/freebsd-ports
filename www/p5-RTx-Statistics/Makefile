# New ports collection makefile for:	www/p5-RTx-Statistics
# Date created:				10-JAN-2006
# Whom:					Vivek Khera <vivek@khera.org>
#
# $FreeBSD$
#

PORTNAME=	RTx-Statistics
PORTVERSION=	0.1.8
PORTREVISION=	4
CATEGORIES=	www perl5
MASTER_SITES=	http://opensvn.csie.org/RTx_Statistics/releases/${PORTVERSION}/
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	RTx::Statistics - Produces statistical information based on RT3 data

# This module is not compatible with rt-3.8.0 or later.
BUILD_DEPENDS=	${SITE_PERL}/GD/Graph.pm:${PORTSDIR}/graphics/p5-GD-Graph \
		${RT_PATH}/lib/RT.pm:${PORTSDIR}/www/rt36
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.3+

RT_PATH?=	${LOCALBASE}/rt3
PLIST_SUB=	RT_PATH=${RT_PATH}  RTPLIST=${RT_PATH:S/^${PREFIX}\///}

do-configure:
	@cd ${CONFIGURE_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} \
		${PERL5} Makefile.PL

.include <bsd.port.mk>
