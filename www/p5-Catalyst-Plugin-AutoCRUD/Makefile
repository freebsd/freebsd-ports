# New ports collection makefile for:	Catalyst-Plugin-AutoCRUD
# Whom:			gugu
# Date created:		03 December 2009
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-AutoCRUD
PORTVERSION=	1.112.770
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Instant AJAX web front-end for DBIx::Class

BUILD_DEPENDS=	p5-Catalyst-Action-RenderView>=0:${PORTSDIR}/www/p5-Catalyst-Action-RenderView \
		p5-Catalyst-Model-DBIC-Schema>=0:${PORTSDIR}/www/p5-Catalyst-Model-DBIC-Schema \
		p5-Catalyst-Runtime>=5.70:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Catalyst-View-JSON>=0:${PORTSDIR}/www/p5-Catalyst-View-JSON \
		p5-Catalyst-View-TT>=0:${PORTSDIR}/www/p5-Catalyst-View-TT \
		p5-DBIx-Class-Schema-Loader>=0:${PORTSDIR}/databases/p5-DBIx-Class-Schema-Loader \
		p5-Data-Page>=0:${PORTSDIR}/databases/p5-Data-Page \
		p5-MRO-Compat>=0:${PORTSDIR}/devel/p5-MRO-Compat
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Catalyst::Plugin::AutoCRUD.3

.include <bsd.port.mk>
