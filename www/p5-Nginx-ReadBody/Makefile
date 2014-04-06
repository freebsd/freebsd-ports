# Created by: jupengfei <jupengfei@gmail.com>
# $FreeBSD$

PORTNAME=	Nginx-ReadBody
PORTVERSION=	0.07
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TPABA/Nginx
PKGNAMEPREFIX=	p5-

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Nginx embeded perl module to read and evaluate a request body

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

OPTIONS_DEFINE=	NGINX_DEVEL
NGINX_DEVEL_DESC=	Use nginx-devel

USES=		perl5
USE_PERL5=	configure

NGINX_DEVEL_RUN_DEPENDS=	nginx:${PORTSDIR}/www/nginx-devel
NGINX_DEVEL_RUN_DEPENDS_OFF=	nginx:${PORTSDIR}/www/nginx

.include <bsd.port.mk>
