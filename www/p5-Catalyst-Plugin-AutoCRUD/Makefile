# New ports collection makefile for:  Catalyst-Plugin-AutoCRUD
# Whom: gugu
# Date created: 03 December 2009
# $FreeBSD$
# Generated with portupload. Do not edit directly, please

PORTNAME=	Catalyst-Plugin-AutoCRUD
PORTVERSION=	0.67
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	andrey@kostenko.name
COMMENT=	Instant AJAX web front-end for DBIx::Class

BUILD_DEPENDS=	p5-Catalyst-Action-RenderView>=0:${PORTSDIR}/www/p5-Catalyst-Action-RenderView \
		p5-Catalyst-Model-DBIC-Schema>=0:${PORTSDIR}/www/p5-Catalyst-Model-DBIC-Schema \
		p5-Catalyst-Runtime>=5.70:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Catalyst-View-JSON>=0:${PORTSDIR}/www/p5-Catalyst-View-JSON \
		p5-Catalyst-View-TT>=0:${PORTSDIR}/www/p5-Catalyst-View-TT \
		p5-MRO-Compat>=0:${PORTSDIR}/devel/p5-MRO-Compat
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.1+

MAN3=		Catalyst::Plugin::AutoCRUD.3

.include <bsd.port.mk>
