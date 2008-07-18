# Ports collection makefile for:	rubygem-rightaws
# Date created:			01 May 2008
# Whom:				Greg Larkin <glarkin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rightaws
PORTVERSION=	1.7.1
CATEGORIES=	net rubygems
MASTER_SITES=	RF
MASTER_SITE_SUBDIR=	rightaws
DISTNAME=	right_aws-${PORTVERSION}

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	Provides access to Amazon EC2, S3, SQS, and SDB web services

RUN_DEPENDS=	rubygem-righthttpconnection>=1.2.1:${PORTSDIR}/net/rubygem-righthttpconnection

USE_RUBY=	yes
USE_RUBYGEMS=	yes
GEM_NAME=	${DISTNAME}
UNIQUENAME=	${PORTNAME}

OPTIONS=	LIBXML "Use libxml instead of REXML" Off

.include <bsd.port.pre.mk>

.if defined(WITH_LIBXML)
RUN_DEPENDS+=	${RUBY_PKGNAMEPREFIX}libxml>=0:${PORTSDIR}/textproc/ruby-libxml
.else
USE_RUBY_FEATURES=	rexml
.endif

.include <bsd.port.post.mk>
