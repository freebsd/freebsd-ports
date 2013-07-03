# Created by: Greg Larkin <glarkin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rightaws
PORTVERSION=	3.1.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG
DISTNAME=	right_aws-${PORTVERSION}

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	Provides access to Amazon EC2, S3, SQS, and SDB web services

LICENSE=	MIT

RUN_DEPENDS=	rubygem-righthttpconnection>=1.2.5:${PORTSDIR}/net/rubygem-righthttpconnection

USE_RUBY=	yes
USE_RUBYGEMS=	yes
GEM_NAME=	${DISTNAME}
RUBYGEM_AUTOPLIST=	yes
UNIQUENAME=	${PORTNAME}

OPTIONS_DEFINE=	LIBXML
LIBXML_DESC=	Use libxml instead of REXML

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLIBXML}
RUN_DEPENDS+=	rubygem-libxml-ruby>=0.5.2:${PORTSDIR}/textproc/rubygem-libxml-ruby
.else
USE_RUBY_FEATURES=	rexml
.endif

.include <bsd.port.mk>
