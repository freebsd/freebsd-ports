# Ports collection makefile for:	p5-Catalyst-Controller-BindLex
# Date created:				17.Oct.2006
# Whom:					Fernan Aguero  <fernan@iib.unsam.edu.ar>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Controller-BindLex
PORTVERSION=	0.03
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:NUFFIN
PKGNAMEPREFIX=	p5-

MAINTAINER=	fernan@iib.unsam.edu.ar
COMMENT=	Stash your lexical goodness

BUILD_DEPENDS=	p5-Catalyst-Runtime>=0:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Array-RefElem>=0:${PORTSDIR}/misc/p5-Array-RefElem \
		p5-Devel-Caller>=0:${PORTSDIR}/devel/p5-Devel-Caller \
		p5-Devel-LexAlias>=0:${PORTSDIR}/devel/p5-Devel-LexAlias \
		p5-PadWalker>=0:${PORTSDIR}/devel/p5-PadWalker \
		p5-Test-use-ok>=0:${PORTSDIR}/devel/p5-Test-use-ok
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=	Catalyst::Controller::BindLex.3

.include <bsd.port.mk>
