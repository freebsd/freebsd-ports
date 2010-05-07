# New ports collection makefile for:	p5-Nginx-ReadBody
# Date created:				2010-04-19
# Whom:					jupengfei <jupengfei@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Nginx-ReadBody
PORTVERSION=	0.07
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/T/TP/TPABA/Nginx
PKGNAMEPREFIX=	p5-

MAINTAINER=	jupengfei@gmail.com
COMMENT=	Nginx embeded perl module to read and evaluate a request body

OPTIONS=	NGINX_DEVEL	"Use nginx-devel" off

.include <bsd.port.options.mk>

.if defined(WITH_NGINX_DEVEL)
RUN_DEPENDS+=	nginx:${PORTSDIR}/www/nginx-devel
.else
RUN_DEPENDS+=	nginx:${PORTSDIR}/www/nginx
.endif

PERL_CONFIGURE=	YES

pre-everything::
		@${CAT} ${PKGMESSAGE}

MAN3=		Nginx::ReadBody.3 \
		Nginx::ReadBody::Russian.3

.include <bsd.port.mk>
