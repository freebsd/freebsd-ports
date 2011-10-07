# New ports collection makefile for:	www/p5-Catalyst-Action-RenderView
# Date created:				July 11, 2006
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Action-RenderView
PORTVERSION=	0.16
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Sensible default end action for Catalyst

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Catalyst-Runtime>=5.70:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Data-Visitor>=0.24:${PORTSDIR}/devel/p5-Data-Visitor \
		p5-MRO-Compat>=0:${PORTSDIR}/devel/p5-MRO-Compat
BUILD_DEPENDS=	${RUN_DEPENDS}
BUILD_DEPENDS+=	p5-HTTP-Request-AsCGI>=0:${PORTSDIR}/www/p5-HTTP-Request-AsCGI

PERL_CONFIGURE=	yes

MAN3=	Catalyst::Action::RenderView.3

post-extract:
	@${PERL} -i.bak -ne 'print unless /^(test_requires|auto_install|recommends|configure_requires)/' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
