# Ports collection makefile for:	rubygem-god
# Date created:				23 July 2007
# Whom:					Robert Gogolok <gogo@cs.uni-sb.de>
#
# $FreeBSD$

PORTNAME=	god
PORTVERSION=	0.2.0
CATEGORIES=	sysutils rubygems
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	gogo@cs.uni-sb.de
COMMENT=	Monitoring framework written in Ruby

RUN_DEPENDS=	rubygem-daemons>=1.0.7:${PORTSDIR}/devel/rubygem-daemons
BUILD_DEPENDS=	rubygem-daemons>=1.0.7:${PORTSDIR}/devel/rubygem-daemons \
		rubygem-hoe>=1.2.1:${PORTSDIR}/devel/rubygem-hoe

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/ruby-gems/Makefile.common"
.include <bsd.port.post.mk>
