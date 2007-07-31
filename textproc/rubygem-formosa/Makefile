# ex:ts=8
# Ports collection makefile for:	formosa
# Date created:			Jul 31, 2007
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	formosa
PORTVERSION=	0.0.1
CATEGORIES=	textproc rubygems
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	lukhnos@gmail.com
COMMENT=	A collection of libraries for Taiwanese languages processing

RUN_DEPENDS=	rubygem-activesupport>=1.4.2:${PORTSDIR}/devel/rubygem-activesupport

GEM_NAME=	${DISTNAME}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/ruby-gems/Makefile.common"
.include <bsd.port.post.mk>
