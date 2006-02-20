# New ports collection makefile for:	www/p5-RTx-Statistics
# Date created:				10-JAN-2006
# Whom:					Vivek Khera <vivek@khera.org>
#
# $FreeBSD$
#

PORTNAME=	RTx-Statistics
PORTVERSION=	0.1.8
CATEGORIES=	www perl5
MASTER_SITES=	ftp://anonftp.mqsoftware.com/kfh/RT/
PKGNAMEPREFIX=	p5-

MAINTAINER=	vivek@khera.org
COMMENT=	RTx::Statistics - Produces statistical information based on RT3 data

BUILD_DEPENDS=	${SITE_PERL}/GD/Graph.pm:${PORTSDIR}/graphics/p5-GD-Graph \
		${RT_PATH}/lib/RT.pm:${PORTSDIR}/www/rt34
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

RT_PATH?=	${LOCALBASE}/rt3
PLIST_SUB=	RT_PATH=${RT_PATH}  RTPLIST=${RT_PATH:S/^${PREFIX}\///}

do-configure:
	@cd ${CONFIGURE_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} \
		${PERL5} Makefile.PL

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500803
IGNORE=	requires at least Perl5.8.3 due to dependencies
.endif

.include <bsd.port.post.mk>
