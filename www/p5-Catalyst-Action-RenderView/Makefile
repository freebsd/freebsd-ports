# New ports collection makefile for:	www/p5-Catalyst-Action-RenderView
# Date created:				July 11, 2006
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Action-RenderView
PORTVERSION=	0.08
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	Sensible default end action for Catalyst

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Catalyst-Runtime>=5.7000:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Data-Visitor>=0.08:${PORTSDIR}/devel/p5-Data-Visitor

PERL_CONFIGURE=	5.8.0+

MAN3=	Catalyst::Action::RenderView.3

post-extract:
	@${PERL} -ne 'print unless /^test_requires/' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
