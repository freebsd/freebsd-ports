# New ports collection makefile for:	p5-Data-TreeDumper-Renderer-DHTML
# Date Created:				26 Dec 2005
# Whom:					Zach Thompson <hideo@lastamericanempire.com>
#
# $FreeBSD$
#

PORTNAME=	Data-TreeDumper-Renderer-DHTML
PORTVERSION=	0.07
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	hideo@lastamericanempire.com
COMMENT=	DHTML renderer for Data::TreeDumper

BUILD_DEPENDS=	${SITE_PERL}/Data/TreeDumper.pm:${PORTSDIR}/devel/p5-Data-TreeDumper
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Data::TreeDumper::Renderer::DHTML.3

.include <bsd.port.mk>
