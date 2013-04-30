# Ports collection makefile for:	rubygem-rightaws
# Date created:			01 May 2008
# Whom:				Greg Larkin <glarkin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rightaws
PORTVERSION=	1.10.0
PORTREVISION=	1
CATEGORIES=	net rubygems
MASTER_SITES=	RG
DISTNAME=	right_aws-${PORTVERSION}

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	Provides access to Amazon EC2, S3, SQS, and SDB web services

RUN_DEPENDS=	rubygem-righthttpconnection>=1.2.4:${PORTSDIR}/net/rubygem-righthttpconnection

USE_RUBY=	yes
USE_RUBYGEMS=	yes
GEM_NAME=	${DISTNAME}
RUBYGEM_AUTOPLIST=	yes
UNIQUENAME=	${PORTNAME}

OPTIONS=	LIBXML "Use libxml instead of REXML" Off

.include <bsd.port.pre.mk>

.if defined(WITH_LIBXML)
RUN_DEPENDS+=	rubygem-libxml-ruby>=2.3.3:${PORTSDIR}/textproc/rubygem-libxml-ruby
.else
USE_RUBY_FEATURES=	rexml
.endif

.include <bsd.port.post.mk>
