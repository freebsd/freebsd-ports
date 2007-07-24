# ex:ts=8
# Ports collection makefile for:	rubygem-twitter4r
# Date created:			Jul 9, 2007
# Whom:				Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	twitter4r
PORTVERSION=	0.2.3
CATEGORIES=	net rubygems
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Twitter client API in pure Ruby

BUILD_DEPENDS=	rubygem-json>=0.4.3:${PORTSDIR}/devel/rubygem-json
RUN_DEPENDS=	rubygem-json>=0.4.3:${PORTSDIR}/devel/rubygem-json

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/ruby-gems/Makefile.common"
.include <bsd.port.post.mk>
