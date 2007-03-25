# Ports collection makefile for:	rubygem-mechanize
# Date created:				5 Feb 2007
# Whom:					Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	mechanize
PORTVERSION=	0.6.6
CATEGORIES=	www rubygems
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	WWW::Mechanize, a handy web browsing ruby object

BUILD_DEPENDS=	rubygem-hpricot>=0:${PORTSDIR}/www/rubygem-hpricot \
		rubygem-hoe>=1.2.0:${PORTSDIR}/devel/rubygem-hoe
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_RUBY=	yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/ruby-gems/Makefile.common"
.include <bsd.port.post.mk>
