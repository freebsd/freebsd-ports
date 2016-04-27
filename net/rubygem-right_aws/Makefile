# Created by: Greg Larkin <glarkin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	right_aws
PORTVERSION=	3.1.0
PORTREVISION=	1
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Provides access to Amazon EC2, S3, SQS, and SDB web services

LICENSE=	MIT

RUN_DEPENDS=	rubygem-right_http_connection>=1.2.5:net/rubygem-right_http_connection

NO_ARCH=	yes

USE_RUBY=	yes
USES=		gem

OPTIONS_DEFINE=	LIBXML
LIBXML_DESC=	Use libxml instead of REXML

LIBXML_RUN_DEPENDS=	rubygem-libxml-ruby>=0.5.2:textproc/rubygem-libxml-ruby

.include <bsd.port.mk>
