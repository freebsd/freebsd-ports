# New ports collection makefile for:	Dancer-Plugin-Feed
# Date created:		01 March 2011
# Whom:			Grzegorz Blach <magik@roorback.net>
#
# $FreeBSD$
#

PORTNAME=	Dancer-Plugin-Feed
PORTVERSION=	0.1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/H/HO/HOBBESTIG/
PKGNAMEPREFIX=	p5-

MAINTAINER=	magik@roorback.net
COMMENT=	Dancer plugin for generating RSS or Atom feeds

RUN_DEPENDS=    p5-Dancer>=1.175:${PORTSDIR}/www/p5-Dancer \
		p5-XML-Feed>0:${PORTSDIR}/textproc/p5-XML-Feed
BUILD_DEPENDS=  ${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Dancer::Plugin::Feed.3

.include <bsd.port.mk>
