# Created by: jupengfei <jupengfei@gmail.com>
# $FreeBSD$

PORTNAME=	Nginx-ReadBody
PORTVERSION=	0.07
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TPABA/Nginx
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Nginx embeded perl module to read and evaluate a request body

OPTIONS_DEFINE=	NGINX_DEVEL
NGINX_DEVEL_DESC=	Use nginx-devel

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNGINX_DEVEL}
RUN_DEPENDS+=	nginx:${PORTSDIR}/www/nginx-devel
.else
RUN_DEPENDS+=	nginx:${PORTSDIR}/www/nginx
.endif

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
